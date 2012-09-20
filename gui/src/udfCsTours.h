#ifndef __udfCsTours__
#define __udfCsTours__

/**
@file
Subclass of CsTours, which is generated by wxFormBuilder.
*/

#include "udf.h"

#include "tchampionshiptour.h"
#include "cdbmanager.h"

/** Implementing CsTours */
class udfCsTours : public CsTours
{
private:
	unsigned int						m_nCsId;
	CDbConnection*						m_pCon;
	CChampionshipToursTable::tTableMap	m_Tours;
	
protected:
	// Handlers for CsTours events.
	void OnSelectTour( wxCommandEvent& event );
	void OnAddTour( wxCommandEvent& event );
	void OnRemoveTour( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	void OnJudgesMark( wxCommandEvent& event );
	void OnReport( wxCommandEvent& event );
		
public:
	/** Constructor */
	udfCsTours( wxWindow* parent, unsigned int nCsId );
	
protected:
	void	RefreshList();
	bool 	IsFinalAdded();
	void	DisableEdit(bool bEdit = true);
};

#endif // __udfCsTours__
