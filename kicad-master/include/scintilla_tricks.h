/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2020-2023 KiCad Developers, see change_log.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef SCINTILLA_TRICKS_H
#define SCINTILLA_TRICKS_H


#include <wx/stc/stc.h>
#include <functional>

/**
 * Add cut/copy/paste, dark theme, autocomplete and brace highlighting to a wxStyleTextCtrl
 * instance.
 */
class SCINTILLA_TRICKS : public wxEvtHandler
{
public:

    SCINTILLA_TRICKS( wxStyledTextCtrl* aScintilla, const wxString& aBraces, bool aSingleLine,
                      std::function<void( wxKeyEvent& )> onAcceptHandler =
                            []( wxKeyEvent& aEvent )
                            { },
                      std::function<void( wxStyledTextEvent& )> onCharAddedHandler =
                            []( wxStyledTextEvent& )
                            { } );

    wxStyledTextCtrl* Scintilla() const { return m_te; }

    void DoTextVarAutocomplete( std::function<void( const wxString& crossRef,
                                                    wxArrayString* tokens )> aTokenProvider );

    void DoAutocomplete( const wxString& aPartial, const wxArrayString& aTokens );

    void CancelAutocomplete();

protected:
    void setupStyles();

    int firstNonWhitespace( int aLine, int* aWhitespaceCount = nullptr );

    void onCharHook( wxKeyEvent& aEvent );
    void onChar( wxStyledTextEvent& aEvent );
    void onModified( wxStyledTextEvent& aEvent );
    void onScintillaUpdateUI( wxStyledTextEvent& aEvent );
    void onThemeChanged( wxSysColourChangedEvent &aEvent );

protected:
    wxStyledTextCtrl*     m_te;
    wxString              m_braces;
    int                   m_lastCaretPos;
    int                   m_lastSelStart;
    int                   m_lastSelEnd;
    bool                  m_suppressAutocomplete;
    bool                  m_singleLine;            // Treat <return> as OK, and skip special tab
                                                   //  stop handling (including monospaced font).

    // Process <return> in singleLine, and <shift> + <return> irrespective.
    std::function<void( wxKeyEvent& aEvent )>        m_onAcceptHandler;
    std::function<void( wxStyledTextEvent& aEvent )> m_onCharAddedHandler;
};

#endif  // SCINTILLA_TRICKS_H
