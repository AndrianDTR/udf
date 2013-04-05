#ifndef __udfClubsMngrDlg__
#define __udfClubsMngrDlg__

/**
@file
Subclass of ClubsMngrDlg, which is generated by wxFormBuilder.
*/

#include "udf.h"

#include "tcountries.h"
#include "tcities.h"
#include "tclubs.h"
#include "cdbmanager.h"

/** Implementing ClubsMngrDlg */
class udfClubsMngrDlg : public ClubsMngrDlg
{
private:
	CDbConnection*						m_pCon;
	CClubsTable::tTableMap				m_Clubs;
	CCountriesTable::tTableMap			m_Countries;
	CCitiesTable::tTableMap				m_Cities;
	
protected:
	// Handlers for ClubsMngrDlg events.
	void OnAddClub( wxCommandEvent& event );
	void OnRemoveClub( wxCommandEvent& event );
	void OnAccountInfo( wxCommandEvent& event );
	void OnDirectorInfo( wxCommandEvent& event );
	void OnTrainersMngr( wxCommandEvent& event );
	void OnDancersMngr( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	void OnSelectClub( wxCommandEvent& event );
	void OnSearch( wxCommandEvent& event );
	void OnUpdate( wxCommandEvent& event );
	void OnPayment( wxCommandEvent& event );
	
public:
	/** Constructor */
	udfClubsMngrDlg( wxWindow* parent );
	
private:
	void	RefreshList();
	void	RefreshCities();
	void	RefreshCountries();
	int		GetSelectedCity();
	bool	ValidateData();
	bool	GetSelectedItemData(CClubsTable::tDATA*& pData);

};

#endif // __udfClubsMngrDlg__