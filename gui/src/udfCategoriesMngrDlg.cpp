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
	
	CLigaTable ligaTable(pCon);
	CDanceTypesTable danceTypesTable(pCon);
	CAgeCategoryTable ageCatTable(pCon);
	CCategoriesTable catTable(pCon);
	
	CCategoriesTable::tTableMap* categoriesList = NULL;
	catTable.GetTable(&categoriesList);
	
	
	for(CCategoriesTable::tTableIt it = categoriesList->begin(); it != categoriesList->end(); it++)
	{
		CCategoriesTable::tDATA data = it->second;
		
		CAgeCategoryTable::tDATA ageCat = {0};
		ageCatTable.GetRow(data.age_category, ageCat);
		
		CDanceTypesTable::tDATA danceType = {0};
		danceTypesTable.GetRow(data.dance, danceType);
		
		CLigaTable::tDATA liga = {0};
		ligaTable.GetRow(data.liga, liga);
		
		wxString name = wxString::Format("%d%d%02d", ageCat.code, liga.code, danceType.code);
		m_listCategories->Append(name);
	}
	
	if(categoriesList)
	{
		delete categoriesList;
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
}

