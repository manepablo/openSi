/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2015 Jean-Pierre Charras, jaen-pierre.charras at wanadoo.fr
 * Copyright (C) 2015 Wayne Stambaugh <stambaughw@gmail.com>
 * Copyright (C) 2004-2023 KiCad Developers, see change_log.txt for contributors.
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

#include <pgm_base.h>
#include <font/font.h>
#include <settings/settings_manager.h>
#include <eeschema_settings.h>
#include <sch_draw_panel.h>
#include <widgets/msgpanel.h>
#include <lib_symbol.h>

const int fill_tab[3] = { 'N', 'F', 'f' };


LIB_ITEM::LIB_ITEM( KICAD_T aType, LIB_SYMBOL* aSymbol, int aUnit, int aConvert ) :
        EDA_ITEM( aSymbol, aType ),
        m_unit( aUnit ),
        m_bodyStyle( aConvert ),
        m_private( false )
{
}


wxString LIB_ITEM::GetUnitDescription( int aUnit )
{
    if( aUnit == 0 )
        return _( "All" );
    else
        return LIB_SYMBOL::LetterSubReference( aUnit, 'A' );
}


wxString LIB_ITEM::GetBodyStyleDescription( int aBodyStyle )
{
    if( aBodyStyle == 0 )
        return _( "All" );
    else if( aBodyStyle == LIB_ITEM::BODY_STYLE::DEMORGAN )
        return _( "Alternate" );
    else if( aBodyStyle == LIB_ITEM::BODY_STYLE::BASE )
        return _( "Standard" );
    else
        return wxT( "?" );
}


void LIB_ITEM::GetMsgPanelInfo( EDA_DRAW_FRAME* aFrame, std::vector<MSG_PANEL_ITEM>& aList )
{
    wxString msg;

    aList.emplace_back( _( "Type" ), GetTypeName() );

    if( LIB_SYMBOL* parent = GetParent() )
    {
        if( parent->GetUnitCount() )
            aList.emplace_back( _( "Unit" ), GetUnitDescription( m_unit ) );

        if( parent->HasAlternateBodyStyle() )
            aList.emplace_back( _( "Body Style" ), GetBodyStyleDescription( m_bodyStyle ) );
    }

    if( IsPrivate() )
        aList.emplace_back( _( "Private" ), wxEmptyString );
}


int LIB_ITEM::compare( const LIB_ITEM& aOther, int aCompareFlags ) const
{
    if( Type() != aOther.Type() )
        return Type() - aOther.Type();

    // When comparing unit LIB_ITEM objects, we ignore the unit number.
    if( !( aCompareFlags & COMPARE_FLAGS::UNIT ) && m_unit != aOther.m_unit )
        return m_unit - aOther.m_unit;

    if( !( aCompareFlags & COMPARE_FLAGS::UNIT ) && m_bodyStyle != aOther.m_bodyStyle )
        return m_bodyStyle - aOther.m_bodyStyle;

    if( IsPrivate() != aOther.IsPrivate() )
        return IsPrivate() < aOther.IsPrivate();

    return 0;
}


bool LIB_ITEM::cmp_items::operator()( const LIB_ITEM* aFirst, const LIB_ITEM* aSecond ) const
{
    return aFirst->compare( *aSecond, LIB_ITEM::COMPARE_FLAGS::EQUALITY ) < 0;
}


bool LIB_ITEM::operator==( const LIB_ITEM& aOther ) const
{
    if( Type() != aOther.Type() )
        return false;

    return compare( aOther, LIB_ITEM::COMPARE_FLAGS::EQUALITY ) == 0;
}


bool LIB_ITEM::operator<( const LIB_ITEM& aOther ) const
{
    if( Type() != aOther.Type() )
        return Type() < aOther.Type();

    return ( compare( aOther ) < 0 );
}


LIB_ITEM* LIB_ITEM::Duplicate() const
{
    LIB_ITEM* dupe = static_cast<LIB_ITEM*>( Clone() );
    const_cast<KIID&>( dupe->m_Uuid ) = KIID();

    return dupe;
}


bool LIB_ITEM::HitTest( const BOX2I& aRect, bool aContained, int aAccuracy ) const
{
    if( m_flags & (STRUCT_DELETED | SKIP_STRUCT ) )
        return false;

    BOX2I sel = aRect;

    if ( aAccuracy )
        sel.Inflate( aAccuracy );

    if( aContained )
        return sel.Contains( GetBoundingBox() );

    return sel.Intersects( GetBoundingBox() );
}


const wxString& LIB_ITEM::GetDefaultFont() const
{
    EESCHEMA_SETTINGS* cfg = Pgm().GetSettingsManager().GetAppSettings<EESCHEMA_SETTINGS>();

    return cfg->m_Appearance.default_font;
}


const KIFONT::METRICS& LIB_ITEM::GetFontMetrics() const
{
    return KIFONT::METRICS::Default();
}


void LIB_ITEM::Print( const RENDER_SETTINGS* aSettings, const VECTOR2I& aOffset, void* aData,
                      const TRANSFORM& aTransform, bool aDimmed )
{
    print( aSettings, aOffset, aData, aTransform, aDimmed );
}


void LIB_ITEM::ViewGetLayers( int aLayers[], int& aCount ) const
{
    // Basic fallback
    aCount      = 3;
    aLayers[0]  = LAYER_DEVICE;
    aLayers[1]  = LAYER_DEVICE_BACKGROUND;
    aLayers[2]  = LAYER_SELECTION_SHADOWS;
}
