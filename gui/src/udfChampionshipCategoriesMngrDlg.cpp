#include "udfChampionshipCategoriesMngrDlg.h"

#include "udfCategoriesMngrDlg.h"

#include "string_def.h"

#include "tree_unchecked.xpm"
#include "tree_checked.xpm"

udfChampionshipCategoriesMngrDlg::udfChampionshipCategoriesMngrDlg( wxWindow* parent, unsigned int nId )
: ChampionshipCategoriesMngrDlg( parent )
, m_pCon(NULL)
, m_nCSId(nId)
, m_states(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();

	wxIcon icons[2];
	icons[0] = wxIcon(tree_unchecked_xpm);
	icons[1] = wxIcon(tree_checked_xpm);

	int width  = icons[0].GetWidth(),
		height = icons[0].GetHeight();

	// Make an state image list containing small icons
	m_states = new wxImageList(width, height, true);

	for ( size_t i = 0; i < WXSIZEOF(icons); i++ )
		m_states->Add(icons[i]);

    m_treeCategories->AssignStateImageList(m_states);

	Refresh();
}

udfChampionshipCategoriesMngrDlg::~udfChampionshipCategoriesMngrDlg()
{
}

void udfChampionshipCategoriesMngrDlg::OnSave( wxCommandEvent& event )
{
	/*
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
	*/
	EndModal(wxID_OK);
}

void udfChampionshipCategoriesMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfChampionshipCategoriesMngrDlg::OnStateToggle( wxTreeEvent& event )
{
	do
	{
		wxTreeItemId item = m_treeCategories->GetFocusedItem();

		if( !item.IsOk() )
			break;

		m_treeCategories->SetItemState(item, wxTREE_ITEMSTATE_NEXT);

		int state = m_treeCategories->GetItemState(item);
		if (m_treeCategories->ItemHasChildren(item))
		{
			wxTreeItemIdValue cookie;
			wxTreeItemId chldItem = m_treeCategories->GetFirstChild(item, cookie);
        	do
			{
				m_treeCategories->SetItemState(chldItem, state);
				chldItem = m_treeCategories->GetNextChild(item, cookie);
			}while(chldItem.IsOk());
		}

    }while(0);
}

void udfChampionshipCategoriesMngrDlg::OnSelectItem( wxTreeEvent& event )
{

}

void udfChampionshipCategoriesMngrDlg::Refresh()
{
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
		m_treeCategories->SetItemState(block, 0);

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
			wxTreeItemId catId = m_treeCategories->AppendItem(
				block, catName, -1, -1, new udfCatTreeItemData(it->first, CTIT_CAT));
			m_treeCategories->SetItemState(catId, 0);

			it++;
		}

		listIt++;
	}

	// Move throyugh registered categories and set state to 1
	//m_treeCategories->SetItemState(catId, 0);

}
