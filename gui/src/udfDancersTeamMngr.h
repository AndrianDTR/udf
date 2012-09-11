#ifndef __udfDancersTeamMngr__
#define __udfDancersTeamMngr__

/**
@file
Subclass of DancersTeamMngr, which is generated by wxFormBuilder.
*/

#include "udf.h"

#include "tchampionshipteam.h"
#include "tchampionshipcategories.h"
#include "tchampionshipteamcategories.h"
#include "tchampionshipteamdancers.h"
#include "tdancers.h"
#include "tclubs.h"
#include "cdbmanager.h"

/** Implementing DancersTeamMngr */
class udfDancersTeamMngr : public DancersTeamMngr
{
private:
	unsigned int 								m_nCSId;
	CDbConnection*								m_pCon;
	CChampionshipTeamsTable::tTableMap			m_CsTeams;
	CChampionshipCategoriesTable::tTableMap		m_CsCategories;
	CClubsTable::tTableMap						m_Clubs;
	CDancersTable::tTableMap					m_Dancers;
	CChampionshipTeamCategoriesTable::tTableMap m_CsTmCats;
	CChampionshipTeamDancersTable::tTableMap 	m_CsTmDancers;
	
protected:
	// Handlers for DancersTeamMngr events.
	void OnAddDancerTeam( wxCommandEvent& event );
	void OnRemoveTancerTeam( wxCommandEvent& event );
	void OnAddDancerTeamCategory( wxCommandEvent& event );
	void OnRemoveDancerTeamCategory( wxCommandEvent& event );
	void OnAddDancer2Team( wxCommandEvent& event );
	void OnRemoveDancerFromTeam( wxCommandEvent& event );
	void OnSelectTeam( wxCommandEvent& event );
	void OnSearch( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	void OnClubChanged( wxCommandEvent& event );
	void OnSelectClub( wxCommandEvent& event );
	
public:
	/** Constructor */
	udfDancersTeamMngr( wxWindow* parent, unsigned int nId );

private:
	void	RefreshList();
	void	RefreshClubs();
	void	RefreshCategories();
	void	RefreshDancers(int clubId);
	void	RefreshTeamCategories(int teamId);
	void	RefreshTeamDancers(int teamId, int clubId);
	int		GetSelectedClub();
	int		GetSelectedCategory();
	int		GetSelectedDancer();
	bool	ValidateData();
	bool	GetSelectedItemData(CDancersTable::tDATA*& pData);
	void 	EnableEditTeam(bool bEdit = true);
	
	void	AddTeamData(int nTeamId, int nInsertedTeamId);
	void	UpdateTeamData(int nTeamId);
	void	RemoveTeamData(int nTeamId);
};

#endif // __udfDancersTeamMngr__
