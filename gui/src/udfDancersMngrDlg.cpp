#include "udfDancersMngrDlg.h"

udfDancersMngrDlg::udfDancersMngrDlg( wxWindow* parent )
:
DancersMngrDlg( parent )
{

}

void udfDancersMngrDlg::OnAddDancer( wxCommandEvent& event )
{
	// TODO: Implement OnAddDancer
}

void udfDancersMngrDlg::OnRemoveDancer( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveDancer
}

void udfDancersMngrDlg::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfDancersMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
