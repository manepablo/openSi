/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2023 CERN
 * Copyright (C) 2023 KiCad Developers, see AUTHORS.txt for contributors.
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

#ifndef FOOTPRINT_CHOOSER_FRAME_H
#define FOOTPRINT_CHOOSER_FRAME_H


#include <wx/gdicmn.h>
#include <pcb_base_frame.h>
#include <pcbnew_settings.h>
#include <netlist_reader/pcb_netlist.h>
#include <lib_tree_model.h>

class PANEL_FOOTPRINT_CHOOSER;
class wxCheckBox;

namespace PCB { struct IFACE; }


class FOOTPRINT_CHOOSER_FRAME : public PCB_BASE_FRAME
{
public:
    ~FOOTPRINT_CHOOSER_FRAME();

    ///< @copydoc PCB_BASE_FRAME::GetModel()
    BOARD_ITEM_CONTAINER* GetModel() const override { return nullptr; }

    /**
     * @param aFootprint an optional FPID string to initialize the viewer with and to
     *                   return a selected footprint through.
     */
    bool ShowModal( wxString* aFootprint, wxWindow* aParent ) override;

    void KiwayMailIn( KIWAY_EXPRESS& mail ) override;

    /**
     * Force the position of the dialog to a new position.  This mimics the DIALOG_SHIM
     * implementation.
     * @param aNewPosition is the new forced position
     */
    void SetPosition( const wxPoint& aNewPosition );

    bool Show( bool show ) override;

protected:
    FOOTPRINT_CHOOSER_FRAME( KIWAY* aKiway, wxWindow* aParent );

private:
    bool filterFootprint( LIB_TREE_NODE& aNode );

    void OnPaint( wxPaintEvent& aEvent );
    void OnOK( wxCommandEvent& aEvent );

    void doCloseWindow() override;
    void closeFootprintChooser( wxCommandEvent& aEvent );

    WINDOW_SETTINGS* GetWindowSettings( APP_SETTINGS_BASE* aCfg ) override;
    COLOR_SETTINGS* GetColorSettings( bool aForceRefresh ) const override;

    DECLARE_EVENT_TABLE()

    friend struct PCB::IFACE;       // constructor called from here only

private:
    PANEL_FOOTPRINT_CHOOSER* m_chooserPanel;
    wxCheckBox*              m_filterByPinCount;
    wxCheckBox*              m_filterByFPFilters;

    int                                             m_pinCount;
    std::vector<std::unique_ptr<EDA_PATTERN_MATCH>> m_fpFilters;

    // On MacOS (at least) SetFocus() calls made in the constructor will fail because a
    // window that isn't yet visible will return false to AcceptsFocus().  So we must delay
    // the initial-focus SetFocus() call to the first paint event.
    bool                     m_firstPaintEvent;
};

#endif  // FOOTPRINT_CHOOSER_FRAME_H
