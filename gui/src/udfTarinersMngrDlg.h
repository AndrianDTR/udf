#ifndef __udfTarinersMngrDlg__
#define __udfTarinersMngrDlg__

/**
@file
Subclass of TarinersMngrDlg, which is generated by wxFormBuilder.
*/

#include "udf.h"

#include "ttreiners.h"
#include "tclubs.h"

#include "cdbmanager.h"

/** Implementing TarinersMngrDlg */
class udfTarinersMngrDlg : public TarinersMngrDlg
{
private:
	unsigned int					m_nClubId;
	CDbConnection*					m_pCon;
	CClubsTable::tTableMap			m_Clubs;
	CTrainersTable::tTableMap		m_Trainers;
	
protected:
	// Handlers for TarinersMngrDlg events.
	void OnAddTrainer( wxCommandEvent& event );
	void OnRemoveTrainer( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	void OnSearch( wxCommandEvent& event );
	void OnSelectTrainer( wxCommandEvent& event );
	void OnUpdate( wxCommandEvent& event );
	
public:
	/** Constructor */
	udfTarinersMngrDlg( wxWindow* parent, unsigned int nClubId );
	
private:
	int 		GetSelectedClub();
	void		RefreshList();
	void		RefreshClubs();
	bool		ValidateData();
	bool 		GetClubNameById(unsigned int id, wxString& name);
	bool		GetSelectedItemData(CTrainersTable::tDATA*& pData);
	
};

#endif // __udfTarinersMngrDlg__
