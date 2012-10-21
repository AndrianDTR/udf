#ifndef __udfChampionshipCategoriesMngrDlg__
#define __udfChampionshipCategoriesMngrDlg__

/**
@file
Subclass of ChampionshipCategoriesMngrDlg, which is generated by wxFormBuilder.
*/

#include "udf.h"

#include "db.h"
#include "cdbmanager.h"

/** Implementing ChampionshipCategoriesMngrDlg */
class udfChampionshipCategoriesMngrDlg : public ChampionshipCategoriesMngrDlg
{
private:
	unsigned int 								m_nCSId;
	CDbConnection*								m_pCon;
	CChampionshipCategoriesTable::tTableMap		m_ChampionshipsCategories;
	CCategoriesTable::tTableMap					m_Categories;

protected:
	// Handlers for ChampionshipCategoriesMngrDlg events.
	void OnAddAll( wxCommandEvent& event );
	void OnAdd( wxCommandEvent& event );
	void OnRemove( wxCommandEvent& event );
	void OnRemoveAll( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );

public:
	/** Constructor */
	udfChampionshipCategoriesMngrDlg( wxWindow* parent, unsigned int nId );

protected:
	void 	RefreshAllList();
	void 	RefreshSelectedList();
};

#endif // __udfChampionshipCategoriesMngrDlg__
