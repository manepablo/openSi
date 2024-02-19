/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2012 Miguel Angel Ajo Pelayo, miguelangel@nbee.es
 * Copyright (C) 2018 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 2004-2021 KiCad Developers, see AUTHORS.txt for contributors.
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

/**
 * @file footprint_wizard_frame.h
 */

#ifndef FOOTPRINT_WIZARD_FRAME_H_
#define FOOTPRINT_WIZARD_FRAME_H_

#include <wx/gdicmn.h>
#include <footprint_wizard.h>
#include <pcb_base_edit_frame.h>

class wxSashLayoutWindow;
class wxSashEvent;
class wxListBox;
class WX_GRID;
class wxGridEvent;
class FOOTPRINT_EDIT_FRAME;


enum WizardParameterColumnNames
{
    WIZ_COL_NAME = 0,
    WIZ_COL_VALUE,
    WIZ_COL_UNITS
};

class FOOTPRINT_WIZARD_FRAME : public PCB_BASE_EDIT_FRAME
{
public:
    FOOTPRINT_WIZARD_FRAME( KIWAY* aKiway, wxWindow* parent, FRAME_T aFrameType );

    ~FOOTPRINT_WIZARD_FRAME();

    ///< @copydoc PCB_BASE_FRAME::GetModel()
    BOARD_ITEM_CONTAINER* GetModel() const override;

    FOOTPRINT* GetBuiltFootprint();

    /**
     * Reload the Python plugins if they are newer than
     * the already loaded, and load new plugins if any
     */
    void PythonPluginsReload();

    COLOR_SETTINGS* GetColorSettings( bool aForceRefresh = false ) const override;

private:

    void                OnSize( wxSizeEvent& event ) override;
    void                OnGridSize( wxSizeEvent& aSizeEvent );

    /**
     * Redraw the message panel.
     *
     * Display the current footprint info, or clear the message panel if nothing is loaded.
     */
    void UpdateMsgPanel() override;

    /**
     * Rebuild the GAL view (reint tool manager, colors and drawings) must be run after any
     * footprint change.
     */
    void updateView();

    /**
     * Will let the caller exit from the wait loop, and get the built footprint.
     *
     */
    void ExportSelectedFootprint( wxCommandEvent& aEvent );

    /**
     * Resize the child windows when dragging a sash window border.
     */
    void OnSashDrag( wxSashEvent& event );

    /**
     * Create or recreate the list of parameter pages for the current wizard.
     *
     * This list is sorted
     */
    void ReCreatePageList();

    /**
     * Create the list of parameters for the current page.
     */
    void ReCreateParameterList();

    /**
     * Expand the 'Value' column to fill available.
     */
    void ResizeParamColumns();

    /**
     * Prepare the grid where parameters are displayed.
     */
    void initParameterGrid();

    /**
     * Show the list of footprint wizards available into the system.
     */
    void SelectFootprintWizard();

    /**
     * Regenerate the current footprint.
     */
    void RegenerateFootprint();

    /**
     * Display the message generated by the python build footprint script.
     */
    void DisplayBuildMessage( wxString& aMessage );

    /**
     * Reloads the wizard by name.
     */
    FOOTPRINT_WIZARD* GetMyWizard();

    void Process_Special_Functions( wxCommandEvent& event );

    /**
     * Show all the details about the current wizard.
     */
    void DisplayWizardInfos();

    void doCloseWindow() override;
    void ReCreateHToolbar() override;
    void ReCreateVToolbar() override;
    void ClickOnPageList( wxCommandEvent& event );

    void LoadSettings( APP_SETTINGS_BASE* aCfg ) override;
    void SaveSettings( APP_SETTINGS_BASE* aCfg ) override;

    WINDOW_SETTINGS* GetWindowSettings( APP_SETTINGS_BASE* aCfg ) override;

    /**
     * Called when the frame frame is activate to reload the libraries and component lists
     * that can be changed by the schematic editor or the library editor.
     */
    void OnActivate( wxActivateEvent& event );

    void SelectCurrentWizard( wxCommandEvent& event );

    void DefaultParameters( wxCommandEvent& event );

    /**
     * Update the footprint python parameters values from the values in grid.
     */
    void ParametersUpdated( wxGridEvent& event );

    /// @copydoc PCB_BASE_FRAME::Update3DView
    void Update3DView( bool aMarkDirty, bool aRefresh, const wxString* aTitle = nullptr ) override;

    DECLARE_EVENT_TABLE()

protected:
    wxString        m_wizardName;           ///< name of the current wizard
    wxString        m_wizardDescription;    ///< description of the wizard
    wxString        m_wizardStatus;         ///< current wizard status

private:
    wxPanel*        m_parametersPanel;      ///< Panel for the page list and parameter grid
    wxListBox*      m_pageList;             ///< The list of pages
    WX_GRID*        m_parameterGrid;        ///< The list of parameters
    int             m_parameterGridPage;    ///< the page currently displayed by m_parameterGrid
                                            ///< it is most of time the m_pageList selection, but
                                            ///< can differ during transitions between pages.
    wxTextCtrl*     m_buildMessageBox;

    wxString        m_auiPerspective;       ///< Encoded string describing the AUI layout

    bool            m_wizardListShown;      ///< A show-once flag for the wizard list
};



#endif    // FOOTPRINT_WIZARD_FRM_H_
