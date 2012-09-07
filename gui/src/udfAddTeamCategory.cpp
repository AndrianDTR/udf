#include "udfAddTeamCategory.h"

udfAddTeamCategory::udfAddTeamCategory( wxWindow* parent, wxString name )
: AddTeamCategory( parent )
{
	m_staticCategory->SetLabel(name);
}

void udfAddTeamCategory::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfAddTeamCategory::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
