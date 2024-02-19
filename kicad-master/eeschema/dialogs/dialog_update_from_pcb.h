/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2019 Alexander Shuklin <Jasuramme@gmail.com>
 * Copyright (C) 1992-2021 KiCad Developers, see AUTHORS.txt for contributors.
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

#ifndef _DIALOG_UPDATE_FROM_PCB_H_
#define _DIALOG_UPDATE_FROM_PCB_H_

#include <backannotate.h>
#include <dialog_update_from_pcb_base.h>

class SCH_EDIT_FRAME;
class SCH_EDITOR_CONTROL;

class DIALOG_UPDATE_FROM_PCB : public DIALOG_UPDATE_FROM_PCB_BASE
{
public:
    DIALOG_UPDATE_FROM_PCB( SCH_EDIT_FRAME* aParent );
    ~DIALOG_UPDATE_FROM_PCB();

private:
    void updateData();

    bool TransferDataToWindow() override;
    void OnOptionChanged( wxCommandEvent& event ) override;
    void OnUpdateClick( wxCommandEvent& event ) override;

    /**
     * Container for the dialog last saved state.
     */
    struct DIALOG_UPDATE_FROM_PCB_SAVED_STATE
    {
        // Flags to remember last checkboxes state.
        bool MatchByReference;
        bool UpdateReferences;
        bool UpdateFootprints;
        bool UpdateValues;
        bool UpdateNetNames;
        bool UpdateAttributes;
        bool UpdateOtherFields;
    };

    static DIALOG_UPDATE_FROM_PCB_SAVED_STATE s_savedDialogState;

    SCH_EDIT_FRAME*     m_frame;
    SCH_EDITOR_CONTROL* m_editorControl;
};

#endif
