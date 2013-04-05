#ifndef __udfJudgesMngr__
#define __udfJudgesMngr__

/**
@file
Subclass of JudgesMngr, which is generated by wxFormBuilder.
*/

#include "udf.h"

#include "db.h"
#include "cdbmanager.h"
/** Implementing JudgesMngr */
class udfJudgesMngr : public JudgesMngr
{
private:
	CDbConnection*						m_pCon;
	CJudgesTable::tTableMap				m_Judges;
	CCountriesTable::tTableMap			m_Countries;
	CCitiesTable::tTableMap				m_Cities;
	
protected:
	// Handlers for JudgesMngr events.
	void OnSearch( wxCommandEvent& event );
	void OnSelectJudge( wxCommandEvent& event );
	void OnAddJudge( wxCommandEvent& event );
	void OnRemoveJudge( wxCommandEvent& event );
	void OnUpdate( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	void OnPayment( wxCommandEvent& event );
	void OnCategories( wxCommandEvent& event );
	
public:
	/** Constructor */
	udfJudgesMngr( wxWindow* parent );

protected:
	void	RefreshCities();
	void	RefreshList();
	void	RefreshCountries();
	int		GetSelectedCity();
	bool	ValidateData();
	bool	GetSelectedItemData(CJudgesTable::tDATA*& pData);
};

#endif // __udfJudgesMngr__
