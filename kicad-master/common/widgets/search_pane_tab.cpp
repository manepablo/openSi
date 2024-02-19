/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2022-2023 KiCad Developers, see AUTHORS.txt for contributors.
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

#include <widgets/search_pane_tab.h>
#include <widgets/search_pane.h>
#include <kiway.h>
#include <vector>
#include <string_utils.h>
#include <wx/clipbrd.h>

SEARCH_PANE_LISTVIEW::SEARCH_PANE_LISTVIEW( SEARCH_HANDLER* handler, wxWindow* parent,
                                            wxWindowID winid, const wxPoint& pos,
                                            const wxSize& size ) :
        wxListView( parent, winid, pos, size, wxLC_REPORT | wxLC_VIRTUAL ),
        m_handler( handler ),
        m_sortCol( -1 ),
        m_sortAscending( true ),
        m_selectionDirty( false )
{
    SetItemCount( 0 );

    RefreshColumnNames();

    Bind( wxEVT_LIST_ITEM_SELECTED, &SEARCH_PANE_LISTVIEW::OnItemSelected, this );
    Bind( wxEVT_LIST_ITEM_ACTIVATED, &SEARCH_PANE_LISTVIEW::OnItemActivated, this );
    Bind( wxEVT_LIST_ITEM_FOCUSED, &SEARCH_PANE_LISTVIEW::OnItemSelected, this );
    Bind( wxEVT_LIST_ITEM_DESELECTED, &SEARCH_PANE_LISTVIEW::OnItemDeselected, this );
    Bind( wxEVT_LIST_COL_CLICK, &SEARCH_PANE_LISTVIEW::OnColClicked, this );
    Bind( wxEVT_UPDATE_UI, &SEARCH_PANE_LISTVIEW::OnUpdateUI, this );
    Bind( wxEVT_CHAR, &SEARCH_PANE_LISTVIEW::OnChar, this );
}


SEARCH_PANE_LISTVIEW::~SEARCH_PANE_LISTVIEW()
{
    Unbind( wxEVT_LIST_ITEM_SELECTED, &SEARCH_PANE_LISTVIEW::OnItemSelected, this );
    Unbind( wxEVT_LIST_ITEM_ACTIVATED, &SEARCH_PANE_LISTVIEW::OnItemActivated, this );
    Unbind( wxEVT_LIST_ITEM_FOCUSED, &SEARCH_PANE_LISTVIEW::OnItemSelected, this );
    Unbind( wxEVT_LIST_ITEM_DESELECTED, &SEARCH_PANE_LISTVIEW::OnItemDeselected, this );
    Unbind( wxEVT_LIST_COL_CLICK, &SEARCH_PANE_LISTVIEW::OnColClicked, this );
    Unbind( wxEVT_UPDATE_UI, &SEARCH_PANE_LISTVIEW::OnUpdateUI, this );
    Unbind( wxEVT_CHAR, &SEARCH_PANE_LISTVIEW::OnChar, this );
}


void SEARCH_PANE_LISTVIEW::GetSelectRowsList( std::vector<long>& aSelectedList )
{
    long idx = GetFirstSelected();

    if( idx < 0 )   // Nothing selected
        return;

    aSelectedList.emplace_back( idx );

    idx = GetNextSelected( idx );

    while( idx >= 0 )
    {
        aSelectedList.emplace_back( idx );
        idx = GetNextSelected( idx );
    }
}


void SEARCH_PANE_LISTVIEW::OnItemActivated( wxListEvent& aEvent )
{
    CallAfter(
            [&]()
            {
                m_handler->ActivateItem( aEvent.GetIndex() );
            } );

    m_selectionDirty = true;
    aEvent.Skip();
}


void SEARCH_PANE_LISTVIEW::OnItemSelected( wxListEvent& aEvent )
{
    m_selectionDirty = true;
    aEvent.Skip();
}


void SEARCH_PANE_LISTVIEW::OnItemDeselected( wxListEvent& aEvent )
{
    m_selectionDirty = true;
    aEvent.Skip();
}


void SEARCH_PANE_LISTVIEW::OnUpdateUI( wxUpdateUIEvent& aEvent )
{
    if( m_selectionDirty )
    {
        m_selectionDirty = false;

        std::vector<long> list;
        GetSelectRowsList( list );
        m_handler->SelectItems( list );
    }
}


void SEARCH_PANE_LISTVIEW::OnColClicked( wxListEvent& aEvent )
{
    if( aEvent.GetColumn() == m_sortCol )
    {
        m_sortAscending = !m_sortAscending;
    }
    else
    {
        m_sortAscending = true;
        m_sortCol = aEvent.GetColumn();
    }

    ShowSortIndicator( m_sortCol, m_sortAscending );

    Sort();
    Refresh();
}


void SEARCH_PANE_LISTVIEW::OnChar( wxKeyEvent& aEvent )
{
    if( aEvent.GetKeyCode() == WXK_CONTROL_A )
    {
        // Select All
        for( int row = 0; row < GetItemCount(); row++ )
            SetItemState( row, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED );
    }
    else if( aEvent.GetKeyCode() == WXK_CONTROL_C )
    {
        // Copy to clipboard the selected rows
        if( wxTheClipboard->Open() )
        {
            wxString txt;
            for( int row = 0; row < GetItemCount(); row++ )
            {
                if( GetItemState( row, wxLIST_STATE_SELECTED ) == wxLIST_STATE_SELECTED )
                {
                    for( int col = 0; col < GetColumnCount(); col++ )
                    {
                        if( GetColumnWidth( col ) > 0 )
                        {
                            txt += GetItemText( row, col );
                            if( row <= GetItemCount() - 1 )
                                txt += wxT( "\t" );
                        }
                    }
                    txt += wxT( "\n" );
                }
            }

            wxTheClipboard->SetData( new wxTextDataObject( txt ) );
            wxTheClipboard->Close();
        }
    }
}


void SEARCH_PANE_LISTVIEW::Sort()
{
    m_handler->Sort( m_sortCol, m_sortAscending );
}


void SEARCH_PANE_LISTVIEW::RefreshColumnNames()
{
    Freeze();
    DeleteAllColumns();

    std::vector<std::tuple<wxString, int, wxListColumnFormat>> columns = m_handler->GetColumns();

    for( auto& [ columnName, colProportion, colAlign ] : columns )
        AppendColumn( wxGetTranslation( columnName ), colAlign );

    int widthUnit = GetClientSize().GetWidth() / 10;

    for( int ii = 0; ii < (int) columns.size(); ++ii )
        SetColumnWidth( ii, widthUnit * std::get<1>( columns[ ii ] ) );

    Thaw();
}


wxString SEARCH_PANE_LISTVIEW::OnGetItemText( long item, long column ) const
{
    return m_handler->GetResultCell( (int) item, (int) column );
}


SEARCH_PANE_TAB::SEARCH_PANE_TAB( SEARCH_HANDLER* handler, wxWindow* parent, wxWindowID aId,
                                  const wxPoint& aLocation, const wxSize& aSize ) :
        wxPanel( parent, aId, aLocation, aSize ),
        m_handler( handler )
{
    wxBoxSizer* sizer = new wxBoxSizer( wxVERTICAL );

    m_listView = new SEARCH_PANE_LISTVIEW( handler, this );
    sizer->Add( m_listView, 5, wxRIGHT | wxBOTTOM | wxEXPAND, 1 );

    SetSizer( sizer );

    Layout();
    sizer->Fit( this );
}


void SEARCH_PANE_TAB::Search( wxString& query )
{
    int results = m_handler->Search( query );
    m_listView->SetItemCount( results );
    m_listView->Sort();
    m_listView->Refresh();
}


void SEARCH_PANE_TAB::Clear()
{
    m_listView->SetItemCount( 0 );
    m_listView->Refresh();
}


void SEARCH_PANE_TAB::RefreshColumnNames()
{
    m_listView->RefreshColumnNames();
}
