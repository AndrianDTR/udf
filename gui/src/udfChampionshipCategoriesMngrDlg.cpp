#include "udfChampionshipCategoriesMngrDlg.h"

#include <wx/aboutdlg.h>

udfChampionshipCategoriesMngrDlg::udfChampionshipCategoriesMngrDlg( wxWindow* parent )
:
ChampionshipCategoriesMngrDlg( parent )
{
	
}

void udfChampionshipCategoriesMngrDlg::OnAddAll( wxCommandEvent& event )
{
	// TODO: Implement OnAddAll
}

void udfChampionshipCategoriesMngrDlg::OnAdd( wxCommandEvent& event )
{
	// TODO: Implement OnAdd
}

void udfChampionshipCategoriesMngrDlg::OnRemove( wxCommandEvent& event )
{
	// TODO: Implement OnRemove
}

void udfChampionshipCategoriesMngrDlg::OnRemoveAll( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveAll
}

void udfChampionshipCategoriesMngrDlg::OnSave( wxCommandEvent& event )
{
	wxAboutDialogInfo info;
    info.SetName(_("My Program"));
    info.SetVersion(_("1.2.3 Beta"));
    info.SetDescription(_("This program does something great."));
    info.SetCopyright(_T("(C) 2007 Me <my@email.addre.ss>"));

    wxAboutBox(info);
	if ( Validate() && TransferDataFromWindow() )
	{
		if ( IsModal() )
			EndModal(wxID_SAVE); // Если диалог модальный
		else
		{
			SetReturnCode(wxID_SAVE);
			this->Show(false); // Если диалог не модальный
		}
	}
}

void udfChampionshipCategoriesMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
