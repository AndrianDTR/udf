#include "udfStaff.h"

udfStaff::udfStaff( wxWindow* parent )
: Staff( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();

}

void udfStaff::OnSelectWorker( wxCommandEvent& event )
{

}

void udfStaff::OnAdd( wxCommandEvent& event )
{
// TODO: Implement OnAdd
}

void udfStaff::OnUpdate( wxCommandEvent& event )
{
// TODO: Implement OnUpdate
}

void udfStaff::OnRemove( wxCommandEvent& event )
{
// TODO: Implement OnRemove
}

void udfStaff::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfStaff::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
