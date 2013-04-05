#include "udfUserRolesMgr.h"

udfUserRolesMgr::udfUserRolesMgr( wxWindow* parent )
: UserRolesMgr( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();

}

void udfUserRolesMgr::OnAdd( wxCommandEvent& event )
{
// TODO: Implement OnAdd
}

void udfUserRolesMgr::OnUpdate( wxCommandEvent& event )
{
// TODO: Implement OnUpdate
}

void udfUserRolesMgr::OnRemove( wxCommandEvent& event )
{
// TODO: Implement OnRemove
}

void udfUserRolesMgr::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfUserRolesMgr::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfUserRolesMgr::OnSelectRole( wxListEvent& event )
{
// TODO: Implement OnSelectRole
}
