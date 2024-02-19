/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2020 Wayne Stambaugh <stambaughw@gmail.com>
 * Copyright (C) 2020-2021 KiCad Developers, see AUTHORS.txt for contributors.
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

#ifndef __dialog_junction_props__
#define __dialog_junction_props__

#include <gal/color4d.h>
#include <widgets/unit_binder.h>
#include <dialog_junction_props_base.h>


class SCH_EDIT_FRAME;
class SCH_JUNCTION;


class DIALOG_JUNCTION_PROPS : public DIALOG_JUNCTION_PROPS_BASE
{
public:
    DIALOG_JUNCTION_PROPS( SCH_EDIT_FRAME* aParent, std::deque<SCH_JUNCTION*>& aJunctions );

    bool TransferDataToWindow() override;
    bool TransferDataFromWindow() override;

private:
    void resetDefaults( wxCommandEvent& event ) override;

    SCH_EDIT_FRAME*           m_frame;
    std::deque<SCH_JUNCTION*> m_junctions;

    UNIT_BINDER               m_diameter;
};

#endif // __dialog_junction_props__
