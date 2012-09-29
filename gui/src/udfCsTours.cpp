#include "udfCsTours.h"

udfCsTours::udfCsTours( wxWindow* parent, wxString name, wxString limit, bool bFinal )
: CsTours( parent )
{
	m_textLimit->SetValue(limit);
	m_textName->SetValue(name);
	m_checkFinal->SetValue(bFinal);
}

void udfCsTours::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfCsTours::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
