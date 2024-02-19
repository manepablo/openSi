/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2024 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <fmt/format.h>

#include <kiid.h>
#include <io/kicad/kicad_io_utils.h>
#include <richio.h>
#include <string_utils.h>

namespace KICAD_FORMAT {

void FormatBool( OUTPUTFORMATTER* aOut, int aNestLevel, const wxString& aKey, bool aValue,
                 char aSuffix )
{
    aOut->Print( aNestLevel, "(%ls %s)%c", aKey.wc_str(), aValue ? "yes" : "no", aSuffix );
}


void FormatUuid( OUTPUTFORMATTER* aOut, const KIID& aUuid, char aSuffix )
{
    if( aSuffix )
        aOut->Print( 0, "(uuid \"%s\")%c", TO_UTF8( aUuid.AsString() ), aSuffix );
    else
        aOut->Print( 0, "(uuid \"%s\")", TO_UTF8( aUuid.AsString() ) );

}

/*
 * Formatting rules:
 * - All extra (non-indentation) whitespace is trimmed
 * - Indentation is one tab
 * - Starting a new list (open paren) starts a new line with one deeper indentation
 * - Lists with no inner lists go on a single line
 * - End of multi-line lists (close paren) goes on a single line at same indentation as its start
 *
 * For example:
 * (first
 *  (second
 *   (third list)
 *   (another list)
 *  )
 *  (fifth)
 *  (sixth thing with lots of tokens
 *   (and a sub list)
 *  )
 * )
 */
void Prettify( std::string& aSource, char aQuoteChar )
{
    // Configuration
    const char indentChar = '\t';
    const int  indentSize = 1;

    // In order to visually compress PCB files, it is helpful to special-case long lists of (xy ...)
    // lists, which we allow to exist on a single line until we reach column 99.
    const int  xySpecialCaseColumnLimit = 99;

    // If whitespace occurs inside a list after this threshold, it will be converted into a newline
    // and the indentation will be increased.  This is mainly used for image and group objects,
    // which contain potentially long sets of string tokens within a single list.
    const int  consecutiveTokenWrapThreshold = 72;

    std::string formatted;
    formatted.reserve( aSource.length() );

    auto cursor = aSource.begin();
    auto seek = cursor;

    int  listDepth = 0;
    char lastNonWhitespace = 0;
    bool inQuote = false;
    bool hasInsertedSpace = false;
    bool inMultiLineList = false;
    bool inXY = false;
    int  column = 0;
    int  backslashCount = 0;    // Count of successive backslash read since any other char

    auto isWhitespace = []( const char aChar )
            {
                return ( aChar == ' ' || aChar == '\t' || aChar == '\n' || aChar == '\r' );
            };

    auto nextNonWhitespace =
            [&]( std::string::iterator aIt )
            {
                seek = aIt;

                while( seek != aSource.end() && isWhitespace( *seek ) )
                    seek++;

                if( seek == aSource.end() )
                    return (char)0;

                return *seek;
            };

    auto isXY =
            [&]( std::string::iterator aIt )
            {
                seek = aIt;

                if( ++seek == aSource.end() || *seek != 'x' )
                    return false;

                if( ++seek == aSource.end() || *seek != 'y' )
                    return false;

                if( ++seek == aSource.end() || *seek != ' ' )
                    return false;

                return true;
            };

    while( cursor != aSource.end() )
    {
        char next = nextNonWhitespace( cursor );

        if( isWhitespace( *cursor ) && !inQuote )
        {
            if( !hasInsertedSpace           // Only permit one space between chars
                && listDepth > 0            // Do not permit spaces in outer list
                && lastNonWhitespace != '(' // Remove extra space after start of list
                && next != ')'              // Remove extra space before end of list
                && next != '(' )            // Remove extra space before newline
            {
                if( inXY || column < consecutiveTokenWrapThreshold )
                {
                    // Note that we only insert spaces here, no matter what kind of whitespace is in
                    // the input.  Newlines will be inserted as needed by the logic below.
                    formatted.push_back( ' ' );
                    column++;
                }
                else
                {
                    formatted += fmt::format( "\n{}",
                                              std::string( listDepth * indentSize, indentChar ) );
                    column = listDepth * indentSize;
                    inMultiLineList = true;
                }

                hasInsertedSpace = true;
            }
        }
        else
        {
            hasInsertedSpace = false;

            if( *cursor == '(' && !inQuote )
            {
                bool currentIsXY = isXY( cursor );

                if( listDepth == 0 )
                {
                    formatted.push_back( '(' );
                    column++;
                }
                else if( inXY && currentIsXY && column < xySpecialCaseColumnLimit )
                {
                    // List-of-points special case
                    formatted += " (";
                    column += 2;
                    inXY = true;
                }
                else
                {
                    formatted += fmt::format( "\n{}(",
                                              std::string( listDepth * indentSize, indentChar ) );
                    column = listDepth * indentSize + 1;
                }

                inXY = currentIsXY;
                listDepth++;
            }
            else if( *cursor == ')' && !inQuote )
            {
                if( listDepth > 0 )
                    listDepth--;

                if( lastNonWhitespace == ')' || inMultiLineList )
                {
                    formatted += fmt::format( "\n{})",
                                              std::string( listDepth * indentSize, indentChar ) );
                    column = listDepth * indentSize + 1;
                    inMultiLineList = false;
                }
                else
                {
                    formatted.push_back( ')' );
                    column++;
                }
            }
            else
            {
                // The output formatter escapes double-quotes (like \")
                // But a corner case is a sequence like \\"
                // therefore a '\' is attached to a '"' if a odd number of '\' is detected
                if( *cursor == '\\' )
                    backslashCount++;
                else if( *cursor == aQuoteChar && ( backslashCount & 1 ) == 0 )
                    inQuote = !inQuote;

                if( *cursor != '\\' )
                    backslashCount = 0;

                formatted.push_back( *cursor );
                column++;
            }

            lastNonWhitespace = *cursor;
        }

        ++cursor;
    }

    aSource = std::move( formatted );
}

} // namespace KICAD_FORMAT
