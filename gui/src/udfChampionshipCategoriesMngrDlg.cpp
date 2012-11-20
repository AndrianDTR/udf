#include "udfChampionshipCategoriesMngrDlg.h"

#include "udfCategoriesMngrDlg.h"

#include "string_def.h"

udfChampionshipCategoriesMngrDlg::udfChampionshipCategoriesMngrDlg( wxWindow* parent, unsigned int nId )
: ChampionshipCategoriesMngrDlg( parent )
, m_pCon(NULL)
, m_nCSId(nId)
{
	m_pCon = CDbManager::Instance()->GetConnection();

	Refresh();
}

void udfChampionshipCategoriesMngrDlg::OnSave( wxCommandEvent& event )
{
	CChampionshipCategoriesTable table(m_pCon);
	CChampionshipCategoriesTable::tTableMap stored;
	CChampionshipCategoriesTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	table.Find(stored, filter);

	CChampionshipCategoriesTable::tTableIt listIt = stored.begin();
	while(listIt != stored.end())
	{
		CChampionshipCategoriesTable::tTableIt rLstIt = m_ChampionshipsCategories.find(listIt->first);
		if(rLstIt == m_ChampionshipsCategories.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_ChampionshipsCategories.end() && rLstIt->first == listIt->first)
		{
			CChampionshipCategoriesTable::tDATA& data = listIt->second;
			CChampionshipCategoriesTable::tDATA& cData = rLstIt->second;
			if( data.catId != cData.catId)
			{
				data.catId = cData.catId;
				table.UpdateRow(listIt->first, data);
			}
			m_ChampionshipsCategories.erase(rLstIt);
		}
		listIt++;
	}

	if(m_ChampionshipsCategories.size() > 0)
	{
		CChampionshipCategoriesTable::tTableIt rLstIt = m_ChampionshipsCategories.begin();
		while(rLstIt != m_ChampionshipsCategories.end())
		{
			CChampionshipCategoriesTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}

	EndModal(wxID_OK);
}

void udfChampionshipCategoriesMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfChampionshipCategoriesMngrDlg::Refresh()
{
	//m_treeCategories->SetItemState()
	m_treeCategories->DeleteAllItems();
	m_root = m_treeCategories->AddRoot("");
	
	CAgeCategoryTable::tTableMap blocks;
	CAgeCategoryTable(m_pCon).GetTable(blocks);
	CAgeCategoryTable::tTableIt listIt = blocks.begin();
	while(listIt != blocks.end())
	{
		CAgeCategoryTable::tDATA data = listIt->second;
		wxTreeItemId block = m_treeCategories->AppendItem(
			m_root, data.name, -1, -1, new udfCatTreeItemData(listIt->first, CTIT_BLOCK));
	
		CCategoriesTable::tTableMap cats;
		CCategoriesTable::tDATA filter = {0};
		filter.age_category = listIt->first;
		
		CCategoriesTable(m_pCon).Find(cats, filter);
		CCategoriesTable::tTableIt it = cats.begin();
		while(it != cats.end())
		{
			CCategoriesTable::tDATA& catData = it->second;
			wxString catName = STR_FORMAT(STR_FORMAT_CATEGORY_LIST_ITEM
						, catData.shortName
						, catData.name);
			m_treeCategories->AppendItem(
				block, catName, -1, -1, new udfCatTreeItemData(it->first, CTIT_CAT));

			it++;
		}
		
		listIt++;
	}
}
