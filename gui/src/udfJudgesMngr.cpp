#include "udfJudgesMngr.h"

udfJudgesMngr::udfJudgesMngr( wxWindow* parent )
:
JudgesMngr( parent )
{

}

void udfJudgesMngr::OnSearch( wxCommandEvent& event )
{
	// TODO: Implement OnSearch
}

void udfJudgesMngr::OnSelectJudge( wxCommandEvent& event )
{
	// TODO: Implement OnSelectJudge
}

void udfJudgesMngr::OnAddJudge( wxCommandEvent& event )
{
	// TODO: Implement OnAddJudge
}

void udfJudgesMngr::OnRemoveJudge( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveJudge
}

void udfJudgesMngr::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfJudgesMngr::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
