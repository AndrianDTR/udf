#ifndef __udfDancersMngrDlg__
#define __udfDancersMngrDlg__

/**
@file
Subclass of DancersMngrDlg, which is generated by wxFormBuilder.
*/

#include "udf.h"

#include "tgender.h"
#include "tliga.h"
#include "ttreiners.h"
#include "tdancers.h"
#include "tclubs.h"

#include "cdbmanager.h"

/** Implementing DancersMngrDlg */
class udfDancersMngrDlg : public DancersMngrDlg
{
	unsigned int					m_nClubId;
	CDbConnection*					m_pCon;
	CClubsTable::tTableMap			m_Clubs;
	CTrainersTable::tTableMap		m_Trainers;
	CDancersTable::tTableMap		m_Dancers;
	CLigaTable::tTableMap 			m_Ligues;
	CGenderTable::tTableMap 		m_Gender;
protected:
	// Handlers for DancersMngrDlg events.
	void OnSearch( wxCommandEvent& event );
	void OnDancerSelect( wxCommandEvent& event );
	void OnAddDancer( wxCommandEvent& event );
	void OnRemoveDancer( wxCommandEvent& event );
	void OnUpdate( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	
public:
	/** Constructor */
	udfDancersMngrDlg( wxWindow* parent, unsigned int nClubId );
	
private:
	void	RefreshList();
	void	RefreshLigues();
	void	RefreshClubs();
	void	RefreshTrainers();
	void	RefreshGenders();
	int		GetSelectedClub();
	int		GetSelectedTrainer();
	int		GetSelectedLigue();
	int		GetSelectedGender();
	bool	ValidateData();
	bool	GetSelectedItemData(CDancersTable::tDATA*& pData);
};

#endif // __udfDancersMngrDlg__
