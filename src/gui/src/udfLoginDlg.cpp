#include "udfLoginDlg.h"
#include "restricted.xpm"

udfLoginDlg::udfLoginDlg( wxWindow* parent )
: LoginDlg( parent )
{
	wxBitmap bg(restricted_xpm);
	//m_panelMain->SetBackground(bg);
}

void udfLoginDlg::OnOk( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfLoginDlg::OnCancel( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
