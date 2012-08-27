#ifndef __udfMainFrameBase__
#define __udfMainFrameBase__

/**
@file
Subclass of MainFrameBase, which is generated by wxFormBuilder.
*/

#include "udf.h"

/** Implementing MainFrameBase */
class udfMainFrameBase : public MainFrameBase
{
protected:
	// Handlers for MainFrameBase events.
	void OnCloseFrame( wxCloseEvent& event );
	void OnExitClick( wxCommandEvent& event );
	void OnMenuCategoryManage( wxCommandEvent& event );
	void OnMenuClubManage( wxCommandEvent& event );
	void OnMenuJudgeManage( wxCommandEvent& event );
	void OnAddChampionsip( wxCommandEvent& event );
	void OnRemoveChampionship( wxCommandEvent& event );
	void OnCategoryMngr( wxCommandEvent& event );
	void OnStartNumberAssign( wxCommandEvent& event );
	void OnJudgeMngr( wxCommandEvent& event );
	void OnSendInvitation( wxCommandEvent& event );
	void OnResults( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	void OnAboutDlg( wxCommandEvent& event );
	
	void OnDanceTypesCodeMgr( wxCommandEvent& event );
	void OnLigueCodeMgr( wxCommandEvent& event );
	void OnAgeCodesMgr( wxCommandEvent& event );

private:
	unsigned long m_nCSid;

public:
	/** Constructor */
	udfMainFrameBase( wxWindow* parent );
	
public:
	int ShowDanceTypesMngrDlg();
	int ShowLiguesMngrDlg();
	int ShowAgeCatsMngrDlg();
};

#endif // __udfMainFrameBase__
