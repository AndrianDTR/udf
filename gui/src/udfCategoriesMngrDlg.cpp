#include "udfCategoriesMngrDlg.h"

#include "tliga.h"
#include "tagecategory.h"
#include "tdancetypes.h"
#include "tcategories.h"
#include "cdbmanager.h"

udfCategoriesMngrDlg::udfCategoriesMngrDlg( wxWindow* parent )
:
CategoriesMngrDlg( parent )
{
	CDbManager* pMan = CDbManager::Instance();
	CDbConnection* pCon = pMan->GetConnection();
	
	CCategoriesTable tableCat(pCon);
	CCategoriesTable::tTableMap listCat;
	tableCat.GetTable(listCat);
	
	CLigaTable tableLiga(pCon);
	CLigaTable::tTableMap listLiga;
	tableLiga.GetTable(listLiga);
	
	CDanceTypesTable tableDanceTypes(pCon);
	CDanceTypesTable::tTableMap listDanceTypes;
	tableDanceTypes.GetTable(listDanceTypes);
	
	CAgeCategoryTable tableAgeCat(pCon);
	CAgeCategoryTable::tTableMap listAgeCat;;
	tableAgeCat.GetTable(listAgeCat);
		
	for(CCategoriesTable::tTableIt it = listCat.begin(); it != listCat.end(); it++)
	{
		CCategoriesTable::tDATA data = it->second;
		
		int nCount = m_listCategories->GetCount();
		m_listCategories->Insert(data.shortName, nCount, &data);
	}
}

void udfCategoriesMngrDlg::OnAdd( wxCommandEvent& event )
{
	// TODO: Implement OnAdd
}

void udfCategoriesMngrDlg::OnRemove( wxCommandEvent& event )
{
	// TODO: Implement OnRemove
}

void udfCategoriesMngrDlg::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfCategoriesMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfCategoriesMngrDlg::OnCategorySelected(wxCommandEvent& event)
{
	int nItem = m_listCategories->GetSelection();
	if(nItem > -1)
	{
		
	}
}

