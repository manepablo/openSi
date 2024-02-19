/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2017-2023 KiCad Developers, see AUTHORS.txt for contributors.
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

#include <widgets/gal_options_panel.h>
#include <settings/app_settings.h>
#include <eda_draw_frame.h>

#include <config_map.h>

/*
 * Spin control parameters
 */
static const double gridThicknessMin = 0.5;
static const double gridThicknessMax = 10.0;
static const double gridThicknessStep = 0.5;

static const int gridMinSpacingMin = 5;
static const int gridMinSpacingMax = 200;
static const int gridMinSpacingStep = 5;


///TODO: These are duplicated in gal_display_options - Unify!
static const UTIL::CFG_MAP<KIGFX::GRID_STYLE> gridStyleSelectMap =
{
    { KIGFX::GRID_STYLE::DOTS,        0 },  // Default
    { KIGFX::GRID_STYLE::LINES,       1 },
    { KIGFX::GRID_STYLE::SMALL_CROSS, 2 },
};


static const UTIL::CFG_MAP<KIGFX::GRID_SNAPPING> gridSnapConfigVals =
{
    { KIGFX::GRID_SNAPPING::ALWAYS,     0 },
    { KIGFX::GRID_SNAPPING::WITH_GRID,  1 },
    { KIGFX::GRID_SNAPPING::NEVER,      2 }
};


GAL_OPTIONS_PANEL::GAL_OPTIONS_PANEL( wxWindow* aParent, APP_SETTINGS_BASE* aAppSettings ) :
    GAL_OPTIONS_PANEL_BASE( aParent ),
    m_cfg( aAppSettings )
{
    // Rendering engine
#ifdef __WXMAC__
    // On MAC, Cairo render does not work.
    m_renderingSizer->Show( false );
#endif
    // Grid settings subpanel
    int selection = 0;  // default selection

    for( double size = gridThicknessMin; size <= gridThicknessMax; size += gridThicknessStep )
    {
        m_gridThicknessList.push_back( size );
        m_gridLineWidth->Append( wxString::Format( wxT( "%.1f" ), size ) );

        if( m_cfg->m_Window.grid.line_width == size )
            selection = m_gridLineWidth->GetCount() - 1;
    }

    m_gridLineWidth->SetSelection( selection );

    m_gridMinSpacing->SetRange( gridMinSpacingMin, gridMinSpacingMax );
    m_gridMinSpacing->SetIncrement( gridMinSpacingStep );
}


bool GAL_OPTIONS_PANEL::TransferDataToWindow()
{
#ifndef __WXMAC__
    auto canvasType = static_cast<EDA_DRAW_PANEL_GAL::GAL_TYPE>( m_cfg->m_Graphics.canvas_type );

    if( canvasType == EDA_DRAW_PANEL_GAL::GAL_TYPE_OPENGL )
        m_rbAccelerated->SetValue( true );
    else
        m_rbFallback->SetValue( true );
#endif

    m_gridSnapOptions->SetSelection( m_cfg->m_Window.grid.snap );

    if( m_cfg->m_Window.grid.style == 0 )
        m_rbDots->SetValue( true );
    else if( m_cfg->m_Window.grid.style == 1 )
        m_rbLines->SetValue( true );
    else
        m_rbCrosses->SetValue( true );

    m_gridMinSpacing->SetValue( m_cfg->m_Window.grid.min_spacing );

    if( m_cfg->m_Window.cursor.fullscreen_cursor )
        m_rbFullWindowCrosshairs->SetValue( true );
    else
        m_rbSmallCrosshairs->SetValue( true );

    m_forceCursorDisplay->SetValue( m_cfg->m_Window.cursor.always_show_cursor );

    return true;
}


bool GAL_OPTIONS_PANEL::TransferDataFromWindow()
{
    m_cfg->m_Window.grid.snap = m_gridSnapOptions->GetSelection();

    if( m_rbDots->GetValue() )
        m_cfg->m_Window.grid.style = 0;
    else if( m_rbLines->GetValue() )
        m_cfg->m_Window.grid.style = 1;
    else
        m_cfg->m_Window.grid.style = 2;

    if( m_gridLineWidth->GetSelection() >= 0 )
        m_cfg->m_Window.grid.line_width = m_gridThicknessList[ m_gridLineWidth->GetSelection() ];

    m_cfg->m_Window.grid.min_spacing = m_gridMinSpacing->GetValue();

    m_cfg->m_Window.cursor.fullscreen_cursor = m_rbFullWindowCrosshairs->GetValue();
    m_cfg->m_Window.cursor.always_show_cursor = m_forceCursorDisplay->GetValue();

#ifndef __WXMAC__
    m_cfg->m_Graphics.canvas_type = m_rbAccelerated->GetValue() ?
                                                    EDA_DRAW_PANEL_GAL::GAL_TYPE_OPENGL :
                                                    EDA_DRAW_PANEL_GAL::GAL_TYPE_CAIRO;
#endif

    return true;
}


bool GAL_OPTIONS_PANEL::ResetPanel( APP_SETTINGS_BASE* aAppSettings )
{
    APP_SETTINGS_BASE* saved = m_cfg;

    m_cfg = aAppSettings;
    TransferDataToWindow();
    m_cfg = saved;

    return true;
}


