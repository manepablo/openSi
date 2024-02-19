/*
 * This program source code file is part of KICAD, a free EDA CAD application.
 *
 * Copyright (C) 2020-2024 KiCad Developers, see AUTHORS.txt for contributors.
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

#include <panel_text_variables.h>

#include <bitmaps.h>
#include <confirm.h>
#include <validators.h>
#include <project.h>
#include <grid_tricks.h>
#include <widgets/std_bitmap_button.h>

#include <algorithm>

enum TEXT_VAR_GRID_COLUMNS
{
    TV_NAME_COL = 0,
    TV_VALUE_COL
};


PANEL_TEXT_VARIABLES::PANEL_TEXT_VARIABLES( wxWindow* aParent, PROJECT* aProject ) :
    PANEL_TEXT_VARIABLES_BASE( aParent ),
    m_project( aProject ),
    m_lastCheckedTicker( 0 ),
    m_errorRow( -1 ), m_errorCol( -1 ),
    m_gridWidthsDirty( true )
{
    m_btnAddTextVar->SetBitmap( KiBitmapBundle( BITMAPS::small_plus ) );
    m_btnDeleteTextVar->SetBitmap( KiBitmapBundle( BITMAPS::small_trash ) );

    m_TextVars->ClearRows();
    m_TextVars->SetUseNativeColLabels();

    // prohibit these characters in the alias names: []{}()%~<>"='`;:.,&?/\|$
    m_nameValidator.SetStyle( wxFILTER_EXCLUDE_CHAR_LIST );
    m_nameValidator.SetCharExcludes( wxT( "{}[]()%~<>\"='`;:.,&?/\\|$" ) );

    m_TextVars->PushEventHandler( new GRID_TRICKS( m_TextVars, [this]( wxCommandEvent& aEvent )
                                                               {
                                                                   OnAddTextVar( aEvent );
                                                               } ) );
    m_TextVars->SetSelectionMode( wxGrid::wxGridSelectionModes::wxGridSelectRows );

    // wxFormBuilder doesn't include this event...
    m_TextVars->Connect( wxEVT_GRID_CELL_CHANGING,
                         wxGridEventHandler( PANEL_TEXT_VARIABLES::OnGridCellChanging ),
                         nullptr, this );

    Bind( wxEVT_IDLE,
          [this]( wxIdleEvent& aEvent )
          {
              // Careful of consuming CPU in an idle event handler.  Check the ticker first to
              // see if there's even a possibility of the text variables having changed.
              if( m_project->GetTextVarsTicker() > m_lastCheckedTicker )
              {
                  wxWindow* dialog = wxGetTopLevelParent( this );
                  wxWindow* topLevelFocus = wxGetTopLevelParent( wxWindow::FindFocus() );

                  if( topLevelFocus == dialog && m_lastLoaded != m_project->GetTextVars() )
                      checkReload();
              }
          } );
}


PANEL_TEXT_VARIABLES::~PANEL_TEXT_VARIABLES()
{
    // Delete the GRID_TRICKS.
    m_TextVars->PopEventHandler( true );

    m_TextVars->Disconnect( wxEVT_GRID_CELL_CHANGING,
                            wxGridEventHandler( PANEL_TEXT_VARIABLES::OnGridCellChanging ),
                            nullptr, this );
}


void PANEL_TEXT_VARIABLES::checkReload()
{
    // MUST update the ticker before calling IsOK (or we'll end up re-entering through the idle
    // event until we crash the stack).
    m_lastCheckedTicker = m_project->GetTextVarsTicker();

    if( IsOK( m_parent, _( "The text variables have been changed outside the Setup dialog.\n"
                           "Do you wish to reload them?" ) ) )
    {
        m_TextVars->ClearRows();

        m_lastLoaded = m_project->GetTextVars();

        for( const auto& var : m_lastLoaded )
            AppendTextVar( var.first, var.second );
    }
}


bool PANEL_TEXT_VARIABLES::TransferDataToWindow()
{
    m_lastLoaded = m_project->GetTextVars();
    m_lastCheckedTicker = m_project->GetTextVarsTicker();

    for( const auto& var : m_lastLoaded )
        AppendTextVar( var.first, var.second );

    return true;
}


void PANEL_TEXT_VARIABLES::AppendTextVar( const wxString& aName, const wxString& aValue )
{
    int i = m_TextVars->GetNumberRows();

    m_TextVars->AppendRows( 1 );

    m_TextVars->SetCellValue( i, TV_NAME_COL, aName );

    wxGridCellAttr* nameCellAttr = m_TextVars->GetOrCreateCellAttr( i, TV_NAME_COL );
    wxGridCellTextEditor* nameTextEditor = new GRID_CELL_TEXT_EDITOR();
    nameTextEditor->SetValidator( m_nameValidator );
    nameCellAttr->SetEditor( nameTextEditor );
    nameCellAttr->DecRef();

    m_TextVars->SetCellValue( i, TV_VALUE_COL, aValue );
}


bool PANEL_TEXT_VARIABLES::TransferDataFromWindow()
{
    if( !m_TextVars->CommitPendingChanges() )
        return false;

    for( int row = 0; row < m_TextVars->GetNumberRows(); ++row )
    {
        if( m_TextVars->GetCellValue( row, TV_NAME_COL ).IsEmpty() )
        {
            m_errorRow = row;
            m_errorCol = TV_NAME_COL;
            m_errorMsg = _( "Variable name cannot be empty." );
            return false;
        }
    }

    std::map<wxString, wxString>& variables = m_project->GetTextVars();

    variables.clear();

    for( int row = 0; row < m_TextVars->GetNumberRows(); ++row )
    {
        wxString name = m_TextVars->GetCellValue( row, TV_NAME_COL );
        wxString value = m_TextVars->GetCellValue( row, TV_VALUE_COL );
        variables[ name ] = value;
    }

    return true;
}


void PANEL_TEXT_VARIABLES::OnGridCellChanging( wxGridEvent& event )
{
    int      row = event.GetRow();
    int      col = event.GetCol();
    wxString text = event.GetString();

    if( text.IsEmpty() && col == TV_NAME_COL )
    {
        m_errorMsg = _( "Variable name cannot be empty." );
        m_errorRow = row;
        m_errorCol = col;

        event.Veto();
    }
}


void PANEL_TEXT_VARIABLES::OnAddTextVar( wxCommandEvent& event )
{
    if( !m_TextVars->CommitPendingChanges() )
        return;

    AppendTextVar( wxEmptyString, wxEmptyString );

    m_TextVars->MakeCellVisible( m_TextVars->GetNumberRows() - 1, TV_NAME_COL );
    m_TextVars->SetGridCursor( m_TextVars->GetNumberRows() - 1, TV_NAME_COL );

    m_TextVars->EnableCellEditControl( true );
    m_TextVars->ShowCellEditControl();
}


void PANEL_TEXT_VARIABLES::OnRemoveTextVar( wxCommandEvent& event )
{
    int curRow = m_TextVars->GetGridCursorRow();

    if( curRow < 0 || m_TextVars->GetNumberRows() <= curRow )
        return;

    m_TextVars->CommitPendingChanges( true /* silent mode; we don't care if it's valid */ );
    m_TextVars->DeleteRows( curRow, 1 );

    m_TextVars->MakeCellVisible( std::max( 0, curRow-1 ), m_TextVars->GetGridCursorCol() );
    m_TextVars->SetGridCursor( std::max( 0, curRow-1 ), m_TextVars->GetGridCursorCol() );
}


void PANEL_TEXT_VARIABLES::OnGridCellChange( wxGridEvent& aEvent )
{
    m_gridWidthsDirty = true;

    aEvent.Skip();
}


void PANEL_TEXT_VARIABLES::OnUpdateUI( wxUpdateUIEvent& event )
{
    if( m_gridWidthsDirty )
    {
        int width = m_TextVars->GetClientRect().GetWidth();

        m_TextVars->AutoSizeColumn( TV_NAME_COL );
        m_TextVars->SetColSize( TV_NAME_COL,
                                std::max( 72, m_TextVars->GetColSize( TV_NAME_COL ) ) );

        m_TextVars->SetColSize( TV_VALUE_COL,
                                std::max( 120, width - m_TextVars->GetColSize( TV_NAME_COL ) ) );
        m_gridWidthsDirty = false;
    }

    // Handle a grid error.  This is delayed to OnUpdateUI so that we can change focus
    // even when the original validation was triggered from a killFocus event (and for
    // dialog with notebooks, so that the corresponding notebook page can be shown in
    // the background when triggered from an OK).
    if( !m_errorMsg.IsEmpty() )
    {
        // We will re-enter this routine when the error dialog is displayed, so make
        // sure we don't keep putting up more dialogs.
        wxString errorMsg = m_errorMsg;
        m_errorMsg = wxEmptyString;

        wxWindow* topLevelParent = wxGetTopLevelParent( this );

        DisplayErrorMessage( topLevelParent, errorMsg );

        m_TextVars->SetFocus();
        m_TextVars->MakeCellVisible( m_errorRow, m_errorCol );
        m_TextVars->SetGridCursor( m_errorRow, m_errorCol );

        m_TextVars->EnableCellEditControl( true );
        m_TextVars->ShowCellEditControl();
    }
}


void PANEL_TEXT_VARIABLES::OnGridSize( wxSizeEvent& event )
{
    m_gridWidthsDirty = true;

    event.Skip();
}

