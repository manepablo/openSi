/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2018-2023 KiCad Developers, see AUTHORS.txt for contributors.
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

#include <dialogs/panel_common_settings.h>

#include <advanced_config.h>
#include <bitmaps.h>
#include <dialog_shim.h>
#include <dpi_scaling_common.h>
#include <kiface_base.h>
#include <kiplatform/ui.h>
#include <pgm_base.h>
#include <id.h>
#include <settings/common_settings.h>
#include <settings/settings_manager.h>
#include <widgets/stepped_slider.h>
#include <widgets/std_bitmap_button.h>
#include <wx/filedlg.h>

/*
 * What follows is a whole lot of ugly to handle various platform GUI deficiences with respect
 * to light/dark mode, DPI scaling, and other foibles.
 *
 * Ugly as it all is, it does improve our usability on various platforms.
 */

PANEL_COMMON_SETTINGS::PANEL_COMMON_SETTINGS( wxWindow* aParent )
        : PANEL_COMMON_SETTINGS_BASE( aParent )
{
    /*
     * Cairo canvas doesn't work on Mac, so no need for fallback anti-aliasing options
     */
#ifdef __WXMAC__
    m_antialiasingFallback->Show( false );
    m_antialiasingFallbackLabel->Show( false );
#endif

    m_textEditorBtn->SetBitmap( KiBitmapBundle( BITMAPS::small_folder ) );
    m_pdfViewerBtn->SetBitmap( KiBitmapBundle( BITMAPS::small_folder ) );

    /*
     * Automatic dark mode detection works fine on Mac, so no need for the explicit options.
     */
#ifdef __WXMAC__
    m_stIconTheme->Show( false );
    m_rbIconThemeLight->Show( false );
    m_rbIconThemeDark->Show( false );
    m_rbIconThemeAuto->Show( false );
#endif

   	/*
   	 * Automatic canvas scaling works fine on all supported platforms, so manual scaling is disabled
   	 */
    if( ADVANCED_CFG::GetCfg().m_AllowManualCanvasScale )
    {
        static constexpr int    dpi_scaling_precision = 1;
        static constexpr double dpi_scaling_increment = 0.5;

        m_canvasScaleCtrl->SetRange( DPI_SCALING::GetMinScaleFactor(),
                                     DPI_SCALING::GetMaxScaleFactor() );
        m_canvasScaleCtrl->SetDigits( dpi_scaling_precision );
        m_canvasScaleCtrl->SetIncrement( dpi_scaling_increment );
        m_canvasScaleCtrl->SetValue( DPI_SCALING::GetDefaultScaleFactor() );

        m_canvasScaleCtrl->SetToolTip(
                _( "Set the scale for the canvas."
                   "\n\n"
                   "On high-DPI displays on some platforms, KiCad cannot determine the "
                   "scaling factor. In this case you may need to set this to a value to "
                   "match your system's DPI scaling. 2.0 is a common value. "
                   "\n\n"
                   "If this does not match the system DPI scaling, the canvas will "
                   "not match the window size and cursor position." ) );

        m_canvasScaleAuto->SetToolTip(
                _( "Use an automatic value for the canvas scale."
                   "\n\n"
                   "On some platforms, the automatic value is incorrect and should be "
                   "set manually." ) );
    }
    else
    {
        m_staticTextCanvasScale->Show( false );
        m_canvasScaleCtrl->Show( false );
        m_canvasScaleCtrl = nullptr;
        m_canvasScaleAuto->Show( false );
    }

    // Hide the option of icons in menus for platforms that do not support them
    m_checkBoxIconsInMenus->Show( KIPLATFORM::UI::AllowIconsInMenus() );

    m_scaleFonts->Show( false );
    m_fontScalingHelp->Show( false );

    if( m_canvasScaleCtrl )
    {
        m_canvasScaleCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED,
                                    wxCommandEventHandler( PANEL_COMMON_SETTINGS::OnCanvasScaleChange ),
                                    nullptr, this );
    }

    wxSize minSize = m_highContrastCtrl->GetMinSize();
    int    minWidth = m_highContrastCtrl->GetTextExtent( wxT( "XXX.XXX" ) ).GetWidth();

    m_highContrastCtrl->SetMinSize( wxSize( minWidth, minSize.GetHeight() ) );
}


PANEL_COMMON_SETTINGS::~PANEL_COMMON_SETTINGS()
{
    if( m_canvasScaleCtrl )
    {
        m_canvasScaleCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED,
                                       wxCommandEventHandler( PANEL_COMMON_SETTINGS::OnCanvasScaleChange ),
                                       nullptr, this );
    }
}


bool PANEL_COMMON_SETTINGS::TransferDataToWindow()
{
    COMMON_SETTINGS* commonSettings = Pgm().GetCommonSettings();

    applySettingsToPanel( *commonSettings );

    // TODO(JE) Move these into COMMON_SETTINGS probably
    m_textEditorPath->SetValue( Pgm().GetTextEditor( false ) );
    m_defaultPDFViewer->SetValue( Pgm().UseSystemPdfBrowser() );
    m_otherPDFViewer->SetValue( !Pgm().UseSystemPdfBrowser() );
    m_PDFViewerPath->SetValue( Pgm().GetPdfBrowserName() );
    setPdfViewerPathState();

    return true;
}


bool PANEL_COMMON_SETTINGS::TransferDataFromWindow()
{
    COMMON_SETTINGS* commonSettings = Pgm().GetCommonSettings();

    commonSettings->m_System.autosave_interval = m_SaveTime->GetValue() * 60;
    commonSettings->m_System.file_history_size = m_fileHistorySize->GetValue();
    commonSettings->m_System.clear_3d_cache_interval = m_Clear3DCacheFilesOlder->GetValue();

    commonSettings->m_Graphics.opengl_aa_mode = m_antialiasing->GetSelection();
    commonSettings->m_Graphics.cairo_aa_mode = m_antialiasingFallback->GetSelection();

    if( m_canvasScaleCtrl )
    {
        DPI_SCALING_COMMON dpi( commonSettings, this );
        dpi.SetDpiConfig( m_canvasScaleAuto->GetValue(), m_canvasScaleCtrl->GetValue() );
    }

    if( m_rbIconThemeLight->GetValue() )
        commonSettings->m_Appearance.icon_theme = ICON_THEME::LIGHT;
    else if( m_rbIconThemeDark->GetValue() )
        commonSettings->m_Appearance.icon_theme = ICON_THEME::DARK;
    else if( m_rbIconThemeAuto->GetValue() )
        commonSettings->m_Appearance.icon_theme = ICON_THEME::AUTO;

    if( m_rbIconSizeSmall->GetValue() )
        commonSettings->m_Appearance.toolbar_icon_size = 16;
    else if( m_rbIconSizeNormal->GetValue() )
        commonSettings->m_Appearance.toolbar_icon_size = 24;
    else if( m_rbIconSizeLarge->GetValue() )
        commonSettings->m_Appearance.toolbar_icon_size = 32;

    commonSettings->m_Appearance.use_icons_in_menus = m_checkBoxIconsInMenus->GetValue();
    commonSettings->m_Appearance.apply_icon_scale_to_fonts = m_scaleFonts->GetValue();

    commonSettings->m_Appearance.show_scrollbars = m_showScrollbars->GetValue();

    double dimmingPercent = 80;
    m_highContrastCtrl->GetValue().ToDouble( &dimmingPercent );
    commonSettings->m_Appearance.hicontrast_dimming_factor = dimmingPercent / 100.0f;

    commonSettings->m_Input.focus_follow_sch_pcb = m_focusFollowSchPcb->GetValue();
    commonSettings->m_Input.hotkey_feedback      = m_hotkeyFeedback->GetValue();
    commonSettings->m_Input.immediate_actions    = !m_NonImmediateActions->GetValue();
    commonSettings->m_Input.warp_mouse_on_move   = m_warpMouseOnMove->GetValue();

    commonSettings->m_Backup.enabled             = m_cbBackupEnabled->GetValue();
    commonSettings->m_Backup.backup_on_autosave  = m_cbBackupAutosave->GetValue();
    commonSettings->m_Backup.limit_total_files   = m_backupLimitTotalFiles->GetValue();
    commonSettings->m_Backup.limit_daily_files   = m_backupLimitDailyFiles->GetValue();
    commonSettings->m_Backup.min_interval        = m_backupMinInterval->GetValue() * 60;
    commonSettings->m_Backup.limit_total_size    = m_backupLimitTotalSize->GetValue() * 1024 * 1024;

    commonSettings->m_Session.remember_open_files = m_cbRememberOpenFiles->GetValue();

    Pgm().SetTextEditor( m_textEditorPath->GetValue());

    Pgm().SetPdfBrowserName( m_PDFViewerPath->GetValue() );
    Pgm().ForceSystemPdfBrowser( m_defaultPDFViewer->GetValue() );
    Pgm().WritePdfBrowserInfos();

    Pgm().GetSettingsManager().Save( commonSettings );

    return true;
}


void PANEL_COMMON_SETTINGS::ResetPanel()
{
    COMMON_SETTINGS defaultSettings;

    defaultSettings.ResetToDefaults();

    applySettingsToPanel( defaultSettings );

    // TODO(JE) Move these into COMMON_SETTINGS probably
    m_textEditorPath->SetValue( defaultSettings.m_System.text_editor );
    m_defaultPDFViewer->SetValue( defaultSettings.m_System.use_system_pdf_viewer );
    m_otherPDFViewer->SetValue( !defaultSettings.m_System.use_system_pdf_viewer );
    m_PDFViewerPath->SetValue( defaultSettings.m_System.pdf_viewer_name );
    setPdfViewerPathState();
}


void PANEL_COMMON_SETTINGS::applySettingsToPanel( COMMON_SETTINGS& aSettings )
{
    int timevalue = aSettings.m_System.autosave_interval;
    wxString msg;

    msg << timevalue / 60;
    m_SaveTime->SetValue( msg );

    m_fileHistorySize->SetValue( aSettings.m_System.file_history_size );

    m_antialiasing->SetSelection( aSettings.m_Graphics.opengl_aa_mode );
    m_antialiasingFallback->SetSelection( aSettings.m_Graphics.cairo_aa_mode );

    m_Clear3DCacheFilesOlder->SetValue( aSettings.m_System.clear_3d_cache_interval );

    if( m_canvasScaleCtrl )
    {
        const DPI_SCALING_COMMON dpi( &aSettings, this );
        m_canvasScaleCtrl->SetValue( dpi.GetScaleFactor() );
        m_canvasScaleAuto->SetValue( dpi.GetCanvasIsAutoScaled() );
    }

    switch( aSettings.m_Appearance.icon_theme )
    {
    case ICON_THEME::LIGHT: m_rbIconThemeLight->SetValue( true );   break;
    case ICON_THEME::DARK:  m_rbIconThemeDark->SetValue( true );    break;
    case ICON_THEME::AUTO:  m_rbIconThemeAuto->SetValue( true );    break;
    }

    switch( aSettings.m_Appearance.toolbar_icon_size )
    {
    case 16: m_rbIconSizeSmall->SetValue( true );   break;
    case 24: m_rbIconSizeNormal->SetValue( true );  break;
    case 32: m_rbIconSizeLarge->SetValue( true );   break;
    }

    m_checkBoxIconsInMenus->SetValue( aSettings.m_Appearance.use_icons_in_menus );
    m_scaleFonts->SetValue( aSettings.m_Appearance.apply_icon_scale_to_fonts );

    double dimmingPercent = aSettings.m_Appearance.hicontrast_dimming_factor * 100.0f;
    m_highContrastCtrl->SetValue( wxString::Format( "%.0f", dimmingPercent ) );

    m_focusFollowSchPcb->SetValue( aSettings.m_Input.focus_follow_sch_pcb );
    m_hotkeyFeedback->SetValue( aSettings.m_Input.hotkey_feedback );
    m_warpMouseOnMove->SetValue( aSettings.m_Input.warp_mouse_on_move );
    m_NonImmediateActions->SetValue( !aSettings.m_Input.immediate_actions );

    m_cbRememberOpenFiles->SetValue( aSettings.m_Session.remember_open_files );

    m_cbBackupEnabled->SetValue( aSettings.m_Backup.enabled );
    m_cbBackupAutosave->SetValue( aSettings.m_Backup.backup_on_autosave );
    m_backupLimitTotalFiles->SetValue( aSettings.m_Backup.limit_total_files );
    m_backupLimitDailyFiles->SetValue( aSettings.m_Backup.limit_daily_files );
    m_backupMinInterval->SetValue( aSettings.m_Backup.min_interval / 60 );
    m_backupLimitTotalSize->SetValue( aSettings.m_Backup.limit_total_size / ( 1024 * 1024 ) );

    m_showScrollbars->SetValue( aSettings.m_Appearance.show_scrollbars );
}


void PANEL_COMMON_SETTINGS::OnCanvasScaleChange( wxCommandEvent& aEvent )
{
    m_canvasScaleAuto->SetValue( false );
}


void PANEL_COMMON_SETTINGS::OnCanvasScaleAuto( wxCommandEvent& aEvent )
{
    const bool automatic = m_canvasScaleAuto->GetValue();

    if( automatic && m_canvasScaleCtrl )
    {
        // set the scale to the auto value, without consulting the config
        DPI_SCALING_COMMON dpi( nullptr, this );

        // update the field (no events sent)
        m_canvasScaleCtrl->SetValue( dpi.GetScaleFactor() );
    }
}


void PANEL_COMMON_SETTINGS::OnTextEditorClick( wxCommandEvent& event )
{
    // Ask the user to select a new editor, but suggest the current one as the default.
    wxString editorname = Pgm().AskUserForPreferredEditor( m_textEditorPath->GetValue() );

    // If we have a new editor name request it to be copied to m_text_editor and saved
    // to the preferences file. If the user cancelled the dialog then the previous
    // value will be retained.
    if( !editorname.IsEmpty() )
        m_textEditorPath->SetValue( editorname );
}


void PANEL_COMMON_SETTINGS::OnPDFViewerClick( wxCommandEvent& event )
{
    wxString mask( wxT( "*" ) );

#ifdef __WINDOWS__
    mask += wxT( ".exe" );
#endif

    wxString wildcard = _( "Executable files (" ) + mask + wxT( ")|" ) + mask;

    Pgm().ReadPdfBrowserInfos();
    wxFileName fn = Pgm().GetPdfBrowserName();

    wxWindow* topLevelParent = wxGetTopLevelParent( this );

    wxFileDialog dlg( topLevelParent, _( "Select Preferred PDF Viewer" ), fn.GetPath(),
                      fn.GetFullPath(), wildcard, wxFD_OPEN | wxFD_FILE_MUST_EXIST );

    if( dlg.ShowModal() == wxID_CANCEL )
        return;

    m_otherPDFViewer->SetValue( true );
    m_PDFViewerPath->SetValue( dlg.GetPath() );
}


void PANEL_COMMON_SETTINGS::OnRadioButtonPdfViewer( wxCommandEvent& event )
{
    setPdfViewerPathState();
}


void PANEL_COMMON_SETTINGS::setPdfViewerPathState()
{
    m_PDFViewerPath->Enable( m_otherPDFViewer->GetValue() );
    m_pdfViewerBtn->Enable( m_otherPDFViewer->GetValue() );
}
