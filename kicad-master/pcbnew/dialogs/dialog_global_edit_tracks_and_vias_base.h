///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
class PCB_LAYER_BOX_SELECTOR;

#include "dialog_shim.h"
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <widgets/net_selector.h>
#include <wx/choice.h>
#include <wx/bmpcbox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_SPECIFIED_NET_TO_SPECIFIED_VALUES 1000
#define ID_SPECIFIED_NET_TO_NETCLASS_VALUES 1001

///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_GLOBAL_EDIT_TRACKS_AND_VIAS_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_GLOBAL_EDIT_TRACKS_AND_VIAS_BASE : public DIALOG_SHIM
{
	private:

	protected:
		wxCheckBox* m_tracks;
		wxCheckBox* m_vias;
		wxCheckBox* m_netFilterOpt;
		NET_SELECTOR* m_netFilter;
		wxCheckBox* m_netclassFilterOpt;
		wxChoice* m_netclassFilter;
		wxCheckBox* m_layerFilterOpt;
		PCB_LAYER_BOX_SELECTOR* m_layerFilter;
		wxCheckBox* m_filterByTrackWidth;
		wxTextCtrl* m_trackWidthFilterCtrl;
		wxStaticText* m_trackWidthFilterUnits;
		wxCheckBox* m_filterByViaSize;
		wxTextCtrl* m_viaSizeFilterCtrl;
		wxStaticText* m_viaSizeFilterUnits;
		wxCheckBox* m_selectedItemsFilter;
		wxRadioButton* m_setToSpecifiedValues;
		wxStaticText* m_trackWidthLabel;
		wxStaticText* m_viaSizeLabel;
		wxStaticText* m_layerLabel;
		wxChoice* m_trackWidthCtrl;
		wxChoice* m_viaSizesCtrl;
		PCB_LAYER_BOX_SELECTOR* m_layerCtrl;
		wxRadioButton* m_setToDesignRuleValues;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;

		// Virtual event handlers, override them in your derived class
		virtual void OnNetclassFilterSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLayerFilterSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTrackWidthText( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViaSizeText( wxCommandEvent& event ) { event.Skip(); }
		virtual void onActionButtonChange( wxCommandEvent& event ) { event.Skip(); }


	public:

		DIALOG_GLOBAL_EDIT_TRACKS_AND_VIAS_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Set Track and Via Properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~DIALOG_GLOBAL_EDIT_TRACKS_AND_VIAS_BASE();

};

