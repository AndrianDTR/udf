#ifndef __udfDancersTeamMngr__
#define __udfDancersTeamMngr__

/**
@file
Subclass of DancersTeamMngr, which is generated by wxFormBuilder.
*/

#include "udf.h"

#include "tchampionshipteam.h"
#include "tchampionshipcategories.h"
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
	
protected:
	// Handlers for DancersTeamMngr events.
	void OnAddDancerTeam( wxCommandEvent& event );
	void OnRemoveTancerTeam( wxCommandEvent& event );
	void OnAddDancerTeamCategory( wxCommandEvent& event );
	void OnRemoveDancerTeamCategory( wxCommandEvent& event );
	void OnAddDancerTeamDancer( wxCommandEvent& event );
	void OnRemoveDancerTeamDancer( wxCommandEvent& event );
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
	void	RefreshTeamCategories();
	int		GetSelectedClub();
	bool	ValidateData();
	bool	GetSelectedItemData(CDancersTable::tDATA*& pData);
};

#endif // __udfDancersTeamMngr__
