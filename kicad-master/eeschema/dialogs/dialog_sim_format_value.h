/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2023 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * https://www.gnu.org/licenses/gpl-3.0.html
 * or you may search the http://www.gnu.org website for the version 3 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef DIALOG_SIM_FORMAT_VALUE_H
#define DIALOG_SIM_FORMAT_VALUE_H

#include <dialog_sim_format_value_base.h>

struct SPICE_VALUE_FORMAT;

class DIALOG_SIM_FORMAT_VALUE : public DIALOG_SIM_FORMAT_VALUE_BASE
{
public:
    DIALOG_SIM_FORMAT_VALUE( wxWindow* aParent, SPICE_VALUE_FORMAT* aFormat );

private:
    bool TransferDataFromWindow() override;

private:
    SPICE_VALUE_FORMAT* m_format;
    wxString            m_units;
};

#endif /* DIALOG_SIM_FORMAT_VALUE_H */
