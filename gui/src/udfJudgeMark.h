#ifndef __udfJudgeMark__
#define __udfJudgeMark__

/**
@file
Subclass of JudgeMark, which is generated by wxFormBuilder.
*/

#include "udf.h"

#include "tchampionshipjudgesmark.h"
#include "tchampionshipjudgesteam.h"
#include "tchampionshipteam.h"
#include "cdbmanager.h"

/** Implementing JudgeMark */
class udfJudgeMark : public JudgeMark
{
private:
	unsigned int							m_nCsId;
	unsigned int							m_nCsTourId;
	CDbConnection*							m_pCon;
	CChampionshipJudgesMarkTable::tTableMap	m_Marks;
	CChampionshipTeamsTable::tTableMap		m_Teams;
	CChampionshipTeamsTable::tTableMap		m_TeamsAll;
	CChampionshipJudgesTeamTable::tTableMap	m_Judges;
	
protected:
	// Handlers for JudgeMark events.
	void OnSelectJudge( wxCommandEvent& event );
	void OnSelectTeam( wxCommandEvent& event );
	void OnShowAll( wxCommandEvent& event );
	void OnSearch( wxCommandEvent& event );
	void OnPlus( wxCommandEvent& event );
	void OnMinus( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	
public:
	/** Constructor */
	udfJudgeMark( wxWindow* parent, unsigned int nCsId, unsigned int nCsTourId, bool bEditable = false );
	
protected:
	void 	RefreshTeams();
	void 	RefreshJudges();
	void 	RefreshMarks();
};

#endif // __udfJudgeMark__
