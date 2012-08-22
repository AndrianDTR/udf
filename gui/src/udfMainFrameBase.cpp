#include "udfMainFrameBase.h"
#include "udfChampionshipCategoriesMngrDlg.h"
#include "udfClubsMngrDlg.h"
#include "udfCategoriesMngrDlg.h"
#include "udfJudgesMngr.h"
#include "udfChampionshipJudgesTeamMngrDlg.h"
#include "udfStartNumberAssignDlg.h"

#include "version.h"
#include "wx/aboutdlg.h"

udfMainFrameBase::udfMainFrameBase( wxWindow* parent )
:
MainFrameBase( parent )
{

}

void udfMainFrameBase::OnCloseFrame( wxCloseEvent& event )
{
	// TODO: Implement OnCloseFrame
}

void udfMainFrameBase::OnExitClick( wxCommandEvent& event )
{
	// TODO: Implement OnExitClick
}

void udfMainFrameBase::OnMenuCategoryManage( wxCommandEvent& event )
{
	udfCategoriesMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnMenuClubManage( wxCommandEvent& event )
{
	udfClubsMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnMenuJudgeManage( wxCommandEvent& event )
{
	udfJudgesMngr dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnAddChampionsip( wxCommandEvent& event )
{
	m_nCSid = -1;
	m_textName->SetValue(_("New cnampionship name"));
	
}

void udfMainFrameBase::OnRemoveChampionship( wxCommandEvent& event )
{
	if(m_nCSid != -1)
	{
		// TODO: Implement Remove from DB
	}
}

void udfMainFrameBase::OnCategoryMngr( wxCommandEvent& event )
{
	udfChampionshipCategoriesMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnStartNumberAssign( wxCommandEvent& event )
{
	udfStartNumberAssignDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnJudgeMngr( wxCommandEvent& event )
{
	udfChampionshipJudgesTeamMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnSendInvitation( wxCommandEvent& event )
{
	// TODO: Implement OnSendInvitation
}

void udfMainFrameBase::OnResults( wxCommandEvent& event )
{
	// TODO: Implement OnResults
}

void udfMainFrameBase::OnSave( wxCommandEvent& event )
{
	// TODO: Implement OnSave
}

void udfMainFrameBase::OnDiscard( wxCommandEvent& event )
{
	// TODO: Implement OnDiscard
}

void udfMainFrameBase::OnAboutDlg(wxCommandEvent& event)
{
	wxAboutDialogInfo info;
	
	info.SetName(wxT("Championship calculator."));
	
	info.SetVersion(
		wxString::Format("%d.%d.%d", UDF_VERSION_MAJOR, UDF_VERSION_MINOR, UDF_VERSION_PATCH)
		);
	
	info.SetDescription(wxT("Calculate and print dance championship result."));
	
	info.SetWebSite("andrian.yablonsky@gmail.com");
	
	info.SetCopyright(wxT("(C) 2012 Andrian Yablonsky."));
	
	wxAboutBox(info, this);
}

