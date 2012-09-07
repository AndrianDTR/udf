#include "udfDancersTeamMngr.h"

udfDancersTeamMngr::udfDancersTeamMngr( wxWindow* parent, unsigned int nId )
: DancersTeamMngr( parent )
, m_pCon(NULL)
, m_nCSId(nId)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
}

void udfDancersTeamMngr::OnAddDancerTeam( wxCommandEvent& event )
{
	// TODO: Implement OnAddDancerTeam
}

void udfDancersTeamMngr::OnRemoveTancerTeam( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveTancerTeam
}

void udfDancersTeamMngr::OnAddDancerTeamCategory( wxCommandEvent& event )
{
	// TODO: Implement OnAddDancerTeamCategory
}

void udfDancersTeamMngr::OnRemoveDancerTeamCategory( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveDancerTeamCategory
}

void udfDancersTeamMngr::OnAddDancerTeamDancer( wxCommandEvent& event )
{
	// TODO: Implement OnAddDancerTeamDancer
}

void udfDancersTeamMngr::OnRemoveDancerTeamDancer( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveDancerTeamDancer
}

void udfDancersTeamMngr::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfDancersTeamMngr::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
