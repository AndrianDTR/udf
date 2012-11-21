#include "udfChampionshipCategoriesMngrDlg.h"

#include "udfCategoriesMngrDlg.h"

#include "string_def.h"

#include "tree_unchecked.xpm"
#include "tree_checked.xpm"
#include "tree_3state.xpm"

udfChampionshipCategoriesMngrDlg::udfChampionshipCategoriesMngrDlg( wxWindow* parent, unsigned int nId )
: ChampionshipCategoriesMngrDlg( parent )
, m_pCon(NULL)
, m_nCSId(nId)
, m_states(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();

	wxIcon icons[3];
	icons[TIS_UNCHECKED] = wxIcon(tree_unchecked_xpm);
	icons[TIS_3STATE] = wxIcon(tree_3state_xpm);
	icons[TIS_CHECKED] = wxIcon(tree_checked_xpm);

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
	CChampionshipCategoriesTable table(m_pCon);
	CChampionshipCategoriesTable::tTableMap stored;
	CChampionshipCategoriesTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	table.Find(stored, filter);
	
	wxTreeItemIdValue	cookie;
	wxTreeItemId group = m_treeCategories->GetFirstChild(m_root, cookie);
	while(group.IsOk())
	{
		wxTreeItemIdValue	cookie2;
		wxTreeItemId cat = m_treeCategories->GetFirstChild(group, cookie2);
		while(cat.IsOk())
		{
			if(TIS_CHECKED == m_treeCategories->GetItemState(cat))
			{
				bool found = false;
				udfCatTreeItemData* pData = (udfCatTreeItemData*)m_treeCategories->GetItemData(cat);
				
				CChampionshipCategoriesTable::tTableIt it = stored.begin();
				while(it != stored.end())
				{
					CChampionshipCategoriesTable::tDATA& catData = it->second;
					if(catData.catId == pData->GetId())
					{
						found = true;
						stored.erase(it);
						break;
					}
					it++;
				}
				
				if(!found)
				{
					CChampionshipCategoriesTable::tDATA catData = {0};
					catData.championshipId = m_nCSId;
					catData.catId = pData->GetId();
					table.AddRow(catData);
				}
			}
			cat = m_treeCategories->GetNextChild(group, cookie2);
		}
		
		group = m_treeCategories->GetNextChild(m_root, cookie);
	}
	
	CChampionshipCategoriesTable::tTableIt it = stored.begin();
	while(it != stored.end())
	{
		table.DelRow(it->first);
		it++;
	}

	EndModal(wxID_OK);
}

void udfChampionshipCategoriesMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

wxTreeItemId udfChampionshipCategoriesMngrDlg::SetParentState(wxTreeItemId item)
{
	wxTreeItemId res;
	do
	{
		if(!item.IsOk())
			break;

		wxTreeItemId parent = m_treeCategories->GetItemParent(item);
		if(parent.IsOk() && parent != m_root)
		{
			wxTreeItemIdValue cookie;
			wxTreeItemId chldItem = m_treeCategories->GetFirstChild(parent, cookie);
			int state = TIS_CHECKED;
			do
			{
				if(TIS_UNCHECKED == m_treeCategories->GetItemState(chldItem))
				{
					state = TIS_3STATE;
					break;
				}
				chldItem = m_treeCategories->GetNextChild(parent, cookie);
			}while(chldItem.IsOk());
			m_treeCategories->SetItemState(parent, state);
			res = parent;
		}
	}while(0);
	return res;
}

void udfChampionshipCategoriesMngrDlg::OnStateToggle( wxTreeEvent& event )
{
	do
	{
		wxTreeItemId item = m_treeCategories->GetFocusedItem();

		if( !item.IsOk() )
			break;

		int state = m_treeCategories->GetItemState(item);

		if(TIS_UNCHECKED == state)
			m_treeCategories->SetItemState(item, TIS_CHECKED);
		else
			m_treeCategories->SetItemState(item, TIS_UNCHECKED);

		state = m_treeCategories->GetItemState(item);

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

		SetParentState(item);
    }while(0);
}

void udfChampionshipCategoriesMngrDlg::Refresh()
{
	UI2IdMap	id2tid;

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
		m_treeCategories->SetItemState(block, TIS_UNCHECKED);

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
			m_treeCategories->SetItemState(catId, TIS_UNCHECKED);
			id2tid[it->first] = catId;

			it++;
		}

		listIt++;
	}

	CChampionshipCategoriesTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;

	CChampionshipCategoriesTable::tTableMap csCats;
	CChampionshipCategoriesTable(m_pCon).Find(csCats, filter);
	CChampionshipCategoriesTable::tTableIt catIt = csCats.begin();
	while(catIt != csCats.end())
	{
		CChampionshipCategoriesTable::tDATA& data = catIt->second;
		wxTreeItemId catId = id2tid[data.catId];
		if(catId.IsOk())
		{
			m_treeCategories->SetItemState(catId, TIS_CHECKED);
			wxTreeItemId parent = SetParentState(catId);
			m_treeCategories->Expand(parent);
		}
		catIt++;
	}
}
