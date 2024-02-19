/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2014-2023 KiCad Developers, see AUTHORS.txt for contributors.
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

#include <mutex>
#include <wx/ffile.h>

#include <symbol_library.h>
#include <confirm.h>
#include <dialogs/dialog_schematic_setup.h>
#include <kiway.h>
#include <symbol_edit_frame.h>
#include <dialogs/panel_gal_display_options.h>
#include <pgm_base.h>
#include <project/project_file.h>
#include <project/net_settings.h>
#include <sch_edit_frame.h>
#include <sch_painter.h>
#include <schematic.h>
#include <widgets/hierarchy_pane.h>
#include <widgets/sch_search_pane.h>
#include <widgets/properties_panel.h>
#include <settings/app_settings.h>
#include <settings/settings_manager.h>
#include <wildcards_and_files_ext.h>
#include <drawing_sheet/ds_data_model.h>
#include <zoom_defines.h>
#include <sim/spice_settings.h>


/// Helper for all the old plotting/printing code while it still exists
COLOR4D GetLayerColor( SCH_LAYER_ID aLayer )
{
    return Pgm().GetSettingsManager().GetColorSettings()->GetColor( aLayer );
}


bool SCH_EDIT_FRAME::LoadProjectSettings()
{
    SCHEMATIC_SETTINGS& settings = Schematic().Settings();
    settings.m_JunctionSize = GetSchematicJunctionSize();

    GetRenderSettings()->SetDefaultPenWidth( settings.m_DefaultLineWidth );
    GetRenderSettings()->m_LabelSizeRatio  = settings.m_LabelSizeRatio;
    GetRenderSettings()->m_TextOffsetRatio = settings.m_TextOffsetRatio;
    GetRenderSettings()->m_PinSymbolSize   = settings.m_PinSymbolSize;

    GetRenderSettings()->SetDashLengthRatio( settings.m_DashedLineDashRatio );
    GetRenderSettings()->SetGapLengthRatio( settings.m_DashedLineGapRatio );

    BASE_SCREEN::m_DrawingSheetFileName = settings.m_SchDrawingSheetFileName;

    // Load the drawing sheet from the filename stored in BASE_SCREEN::m_DrawingSheetFileName.
    // If empty, or not existing, the default drawing sheet is loaded.
    wxString filename = DS_DATA_MODEL::ResolvePath( BASE_SCREEN::m_DrawingSheetFileName,
                                                    Prj().GetProjectPath() );

    if( !DS_DATA_MODEL::GetTheInstance().LoadDrawingSheet( filename ) )
        ShowInfoBarError( _( "Error loading drawing sheet." ), true );

    return true;
}


void SCH_EDIT_FRAME::ShowSchematicSetupDialog( const wxString& aInitialPage )
{
    SCH_SCREENS screens( Schematic().Root() );
    std::vector<std::shared_ptr<BUS_ALIAS>> oldAliases;

    for( SCH_SCREEN* screen = screens.GetFirst(); screen != nullptr; screen = screens.GetNext() )
    {
        for( const std::shared_ptr<BUS_ALIAS>& alias : screen->GetBusAliases() )
            oldAliases.push_back( alias );
    }

    DIALOG_SCHEMATIC_SETUP dlg( this );

    if( !aInitialPage.IsEmpty() )
        dlg.SetInitialPage( aInitialPage, wxEmptyString );

    if( dlg.ShowQuasiModal() == wxID_OK )
    {
        // Mark document as modified so that project settings can be saved as part of doc save
        OnModify();

        Kiway().CommonSettingsChanged( false, true );

        Prj().IncrementTextVarsTicker();
        Prj().IncrementNetclassesTicker();

        GetRenderSettings()->SetDefaultPenWidth( Schematic().Settings().m_DefaultLineWidth );
        GetRenderSettings()->m_LabelSizeRatio  = Schematic().Settings().m_LabelSizeRatio;
        GetRenderSettings()->m_TextOffsetRatio = Schematic().Settings().m_TextOffsetRatio;
        GetRenderSettings()->m_PinSymbolSize   = Schematic().Settings().m_PinSymbolSize;

        GetRenderSettings()->SetDashLengthRatio( Schematic().Settings().m_DashedLineDashRatio );
        GetRenderSettings()->SetGapLengthRatio( Schematic().Settings().m_DashedLineGapRatio );

        GetCanvas()->GetView()->MarkDirty();
        GetCanvas()->GetView()->UpdateAllItems( KIGFX::REPAINT );

        std::vector<std::shared_ptr<BUS_ALIAS>> newAliases;

        for( SCH_SCREEN* screen = screens.GetFirst(); screen != nullptr; screen = screens.GetNext() )
        {
            for( const std::shared_ptr<BUS_ALIAS>& alias : screen->GetBusAliases() )
                newAliases.push_back( alias );
        }

        if( oldAliases != newAliases )
            RecalculateConnections( nullptr, GLOBAL_CLEANUP );

        RefreshOperatingPointDisplay();
        GetCanvas()->Refresh();
    }
}


int SCH_EDIT_FRAME::GetSchematicJunctionSize()
{
    std::vector<double>& sizeMultipliers = eeconfig()->m_Drawing.junction_size_mult_list;

    const std::shared_ptr<NET_SETTINGS>& netSettings = Prj().GetProjectFile().NetSettings();
    int sizeChoice = Schematic().Settings().m_JunctionSizeChoice;
    int dotSize = netSettings->m_DefaultNetClass->GetWireWidth() * sizeMultipliers[ sizeChoice ];

    return std::max( dotSize, 1 );
}


void SCH_EDIT_FRAME::saveProjectSettings()
{
    wxFileName fn = Schematic().RootScreen()->GetFileName();  //ConfigFileName

    fn.SetExt( FILEEXT::ProjectFileExtension );

    if( !fn.HasName() || !IsWritable( fn, false ) )
        return;

    Schematic().RecordERCExclusions();

    if( Kiway().Player( FRAME_SIMULATOR, false ) )
        Prj().GetProjectFile().m_SchematicSettings->m_NgspiceSettings->SaveToFile();

    // Save the page layout file if doesn't exist yet (e.g. if we opened a non-kicad schematic)

    // TODO: We need to remove dependence on BASE_SCREEN
    Prj().GetProjectFile().m_SchematicSettings->m_SchDrawingSheetFileName
                                        = BASE_SCREEN::m_DrawingSheetFileName;

    if( !BASE_SCREEN::m_DrawingSheetFileName.IsEmpty() )
    {
        wxFileName layoutfn( DS_DATA_MODEL::ResolvePath( BASE_SCREEN::m_DrawingSheetFileName,
                                                         Prj().GetProjectPath() ) );

        bool success = true;

        if( !layoutfn.IsAbsolute() )
            success = layoutfn.MakeAbsolute( Prj().GetProjectPath() );

        if( success && layoutfn.IsOk() && !layoutfn.FileExists() )
        {
            if( layoutfn.DirExists() && layoutfn.IsDirWritable() )
                DS_DATA_MODEL::GetTheInstance().Save( layoutfn.GetFullPath() );
        }
    }

    GetSettingsManager()->SaveProject( fn.GetFullPath() );
}


void SCH_EDIT_FRAME::SaveProjectLocalSettings()
{
    if( m_schematic )
        m_schematic->RecordERCExclusions();
}


void SCH_EDIT_FRAME::LoadSettings( APP_SETTINGS_BASE* aCfg )
{
    // For now, axes are forced off in Eeschema even if turned on in config
    EESCHEMA_SETTINGS* cfg = eeconfig();
    cfg->m_Window.grid.axes_enabled = false;

    SCH_BASE_FRAME::LoadSettings( cfg );

    SCH_SEARCH_DATA* searchData = dynamic_cast<SCH_SEARCH_DATA*>( m_findReplaceData.get() );

    if( searchData )
    {
        searchData->replaceReferences = cfg->m_FindReplaceExtra.replace_references;
        searchData->searchAllFields = cfg->m_FindReplaceExtra.search_all_fields;
        searchData->searchAllPins = cfg->m_FindReplaceExtra.search_all_pins;
        searchData->searchCurrentSheetOnly = cfg->m_FindReplaceExtra.search_current_sheet_only;
        searchData->searchSelectedOnly = cfg->m_FindReplaceExtra.search_selected_only;
    }

    m_show_search = cfg->m_AuiPanels.show_search;

    GetRenderSettings()->m_ShowPinsElectricalType = false;
    GetRenderSettings()->m_ShowPinNumbers = false;
    GetRenderSettings()->SetDefaultFont( cfg->m_Appearance.default_font );
}


void SCH_EDIT_FRAME::SaveSettings( APP_SETTINGS_BASE* aCfg )
{
    EESCHEMA_SETTINGS* cfg = eeconfig();
    SCH_BASE_FRAME::SaveSettings( cfg );
    wxAuiPaneInfo& hierarchy_pane = m_auimgr.GetPane( SchematicHierarchyPaneName() );

    if( cfg )
    {
        cfg->m_System.units = static_cast<int>( GetUserUnits() );
        cfg->m_AuiPanels.show_schematic_hierarchy = hierarchy_pane.IsShown();
        cfg->m_AuiPanels.schematic_hierarchy_float = hierarchy_pane.IsFloating();

        // Other parameters (hierarchy_panel_float_width, hierarchy_panel_float_height,
        // and hierarchy_panel_docked_width should have been updated when resizing the
        // hierarchy panel

        SCH_SEARCH_DATA* searchData = dynamic_cast<SCH_SEARCH_DATA*>( m_findReplaceData.get() );

        if( searchData )
        {
            cfg->m_FindReplaceExtra.replace_references = searchData->replaceReferences;
            cfg->m_FindReplaceExtra.search_all_fields = searchData->searchAllFields;
            cfg->m_FindReplaceExtra.search_all_pins = searchData->searchAllPins;
            cfg->m_FindReplaceExtra.search_current_sheet_only =
                    searchData->searchCurrentSheetOnly;
            cfg->m_FindReplaceExtra.search_selected_only = searchData->searchSelectedOnly;
        }

        wxAuiPaneInfo& searchPaneInfo = m_auimgr.GetPane( SearchPaneName() );
        m_show_search = searchPaneInfo.IsShown();
        cfg->m_AuiPanels.show_search = m_show_search;
        cfg->m_AuiPanels.search_panel_height = m_searchPane->GetSize().y;
        cfg->m_AuiPanels.search_panel_width = m_searchPane->GetSize().x;
        cfg->m_AuiPanels.search_panel_dock_direction = searchPaneInfo.dock_direction;

        wxAuiPaneInfo& propertiesPane = m_auimgr.GetPane( PropertiesPaneName() );
        cfg->m_AuiPanels.show_properties = propertiesPane.IsShown();
        cfg->m_AuiPanels.properties_splitter = m_propertiesPanel->SplitterProportion();
        cfg->m_AuiPanels.properties_panel_width = m_propertiesPanel->GetSize().x;

        wxAuiPaneInfo& netNavigatorPane = m_auimgr.GetPane( NetNavigatorPaneName() );
        cfg->m_AuiPanels.show_net_nav_panel = netNavigatorPane.IsShown();
        cfg->m_AuiPanels.float_net_nav_panel = netNavigatorPane.IsFloating();

        if( netNavigatorPane.IsDocked() )
            cfg->m_AuiPanels.net_nav_panel_docked_size = m_netNavigator->GetSize();
        else
        {
            cfg->m_AuiPanels.net_nav_panel_float_pos = netNavigatorPane.floating_pos;
            cfg->m_AuiPanels.net_nav_panel_float_size = netNavigatorPane.floating_size;
        }
    }
}


void SCH_BASE_FRAME::LoadSettings( APP_SETTINGS_BASE* aCfg )
{
    wxCHECK_RET( aCfg, "Call to SCH_BASE_FRAME::LoadSettings with null settings" );

    EDA_DRAW_FRAME::LoadSettings( aCfg );

    if( aCfg->m_Window.grid.grids.empty() )
        aCfg->m_Window.grid.grids = aCfg->DefaultGridSizeList();

    // Move legacy user grids to grid list
    if( !aCfg->m_Window.grid.user_grid_x.empty() )
    {
        aCfg->m_Window.grid.grids.emplace_back( GRID{ "User Grid", aCfg->m_Window.grid.user_grid_x,
                                                      aCfg->m_Window.grid.user_grid_y } );
        aCfg->m_Window.grid.user_grid_x = wxEmptyString;
        aCfg->m_Window.grid.user_grid_y = wxEmptyString;
    }

    if( aCfg->m_Window.grid.last_size_idx > (int) aCfg->m_Window.grid.grids.size() )
        aCfg->m_Window.grid.last_size_idx = 1;

    if( aCfg->m_Window.grid.fast_grid_1 > (int) aCfg->m_Window.grid.grids.size() )
        aCfg->m_Window.grid.fast_grid_1 = 1;

    if( aCfg->m_Window.grid.fast_grid_2 > (int) aCfg->m_Window.grid.grids.size() )
        aCfg->m_Window.grid.fast_grid_2 = 2;

    if( aCfg->m_Window.zoom_factors.empty() )
    {
        aCfg->m_Window.zoom_factors = { ZOOM_LIST_EESCHEMA };
    }
}


void SCH_BASE_FRAME::SaveSettings( APP_SETTINGS_BASE* aCfg )
{
    wxCHECK_RET( aCfg, wxS( "Call to SCH_BASE_FRAME::SaveSettings with null settings" ) );

    EDA_DRAW_FRAME::SaveSettings( aCfg );
}
