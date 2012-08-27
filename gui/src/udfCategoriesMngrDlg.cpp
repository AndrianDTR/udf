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
	
	for(CDanceTypesTable::tTableIt it = listDanceTypes.begin(); it != listDanceTypes.end(); it++)
	{
		CDanceTypesTable::tDATA data = it->second;
		
		int nPos = m_comboDance->GetCount();
		m_comboDance->Insert(data.name, nPos, &data);
	}
	m_comboDance->AutoComplete(m_comboDance->GetStrings());
	
	for(CLigaTable::tTableIt it = listLiga.begin(); it != listLiga.end(); it++)
	{
		CLigaTable::tDATA data = it->second;
		
		int nPos = m_comboLiga->GetCount();
		m_comboLiga->Insert(data.name, nPos, &data);
	}
	m_comboLiga->AutoComplete(m_comboLiga->GetStrings());
	
	for(CAgeCategoryTable::tTableIt it = listAgeCat.begin(); it != listAgeCat.end(); it++)
	{
		CAgeCategoryTable::tDATA data = it->second;
		
		int nPos = m_comboAge->GetCount();
		m_comboAge->Insert(data.name, nPos, &data);
	}
	m_comboAge->AutoComplete(m_comboAge->GetStrings());
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

