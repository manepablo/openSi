/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2023 Mark Roszko <mark.roszko@gmail.com>
 * Copyright (C) 2023 KiCad Developers, see AUTHORS.txt for contributors.
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

#include <jobs/job_sym_export_svg.h>


JOB_SYM_EXPORT_SVG::JOB_SYM_EXPORT_SVG( bool aIsCli ) :
    JOB( "symsvg", aIsCli ),
    m_libraryPath(),
    m_symbol(),
    m_outputDirectory(),
    m_blackAndWhite( false ),
    m_includeHiddenPins( false ),
    m_includeHiddenFields( false )
{
}