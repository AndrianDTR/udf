#include "udfCategoriesMngrDlg.h"

udfCategoriesMngrDlg::udfCategoriesMngrDlg( wxWindow* parent )
:
CategoriesMngrDlg( parent )
{

}

void udfCategoriesMngrDlg::OnAdd( wxCommandEvent& event )
{
	// TODO: Implement OnAdd
}

void udfCategoriesMngrDlg::OnRemove( wxCommandEvent& event )
{
	// TODO: Implement OnRemove
}

void udfCategoriesMngrDlg::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfCategoriesMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
