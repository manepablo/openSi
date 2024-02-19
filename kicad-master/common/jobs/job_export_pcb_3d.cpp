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

#include <jobs/job_export_pcb_3d.h>


JOB_EXPORT_PCB_3D::JOB_EXPORT_PCB_3D( bool aIsCli ) :
    JOB( "3d", aIsCli ),
    m_overwrite( false ),
    m_useGridOrigin( false ),
    m_useDrillOrigin( false ),
    m_hasUserOrigin( false ),
    m_boardOnly( false ),
    m_includeUnspecified( false ),
    m_includeDNP( false ),
    m_substModels( false ),
    m_optimizeStep( false ),
    m_filename(),
    m_outputFile(),
    m_xOrigin( 0.0 ),
    m_yOrigin( 0.0 ),
    // max dist to chain 2 items (lines or curves) to build the board outlines
    m_BoardOutlinesChainingEpsilon( 0.01 ),     // 0.01 mm is a good value
    m_exportTracks( false ),     // Time consuming if true
    m_exportZones( false ),      // Time consuming if true
    m_format( JOB_EXPORT_PCB_3D::FORMAT::UNKNOWN ),
    m_vrmlUnits( JOB_EXPORT_PCB_3D::VRML_UNITS::METERS ),
    m_vrmlModelDir( wxEmptyString ),
    m_vrmlRelativePaths( false )
{
}