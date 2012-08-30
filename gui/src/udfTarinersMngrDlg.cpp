#include "udfTarinersMngrDlg.h"

udfTarinersMngrDlg::udfTarinersMngrDlg( wxWindow* parent )
:
TarinersMngrDlg( parent )
{

}

void udfTarinersMngrDlg::OnAddTrainer( wxCommandEvent& event )
{
	// TODO: Implement OnAddTrainer
}

void udfTarinersMngrDlg::OnRemoveTrainer( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveTrainer
}

void udfTarinersMngrDlg::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfTarinersMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
