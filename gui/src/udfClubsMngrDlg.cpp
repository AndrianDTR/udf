#include "udfClubsMngrDlg.h"
#include "udfAccountInfo.h"
#include "udfDancersMngrDlg.h"
#include "udfTarinersMngrDlg.h"
#include "udfDirectorInfo.h"

udfClubsMngrDlg::udfClubsMngrDlg( wxWindow* parent )
:
ClubsMngrDlg( parent )
{

}

void udfClubsMngrDlg::OnAddClub( wxCommandEvent& event )
{
	
}

void udfClubsMngrDlg::OnRemoveClub( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveClub
}

void udfClubsMngrDlg::OnAccountInfo( wxCommandEvent& event )
{
	udfAccountInfo dlg(this);
	dlg.ShowModal();
}

void udfClubsMngrDlg::OnDirectorInfo( wxCommandEvent& event )
{
	udfDirectorInfo dlg(this);
	dlg.ShowModal();
}

void udfClubsMngrDlg::OnTrainersMngr( wxCommandEvent& event )
{
	udfTarinersMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfClubsMngrDlg::OnDancersMngr( wxCommandEvent& event )
{
	udfDancersMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfClubsMngrDlg::OnSave( wxCommandEvent& event )
{
	// TODO: Implement OnSave
}

void udfClubsMngrDlg::OnDiscard( wxCommandEvent& event )
{
	// TODO: Implement OnDiscard
}

