#include "udfChampionshipCategoriesMngrDlg.h"

#include "udfCategoriesMngrDlg.h"

#include "string_def.h"

udfChampionshipCategoriesMngrDlg::udfChampionshipCategoriesMngrDlg( wxWindow* parent, unsigned int nId )
: ChampionshipCategoriesMngrDlg( parent )
, m_pCon(NULL)
, m_nCSId(nId)
{
	m_pCon = CDbManager::Instance()->GetConnection();

	RefreshAllList();
	RefreshSelectedList();
}

void udfChampionshipCategoriesMngrDlg::OnAddAll( wxCommandEvent& event )
{
	m_ChampionshipsCategories.clear();
	m_listSelected->Clear();

	CChampionshipCategoriesTable::tDATA data = {0};
	data.championshipId = m_nCSId;

	CCategoriesTable::tTableIt it = m_Categories.begin();
	while(it != m_Categories.end())
	{
		CCategoriesTable::tDATA& cData = it->second;
		int nPos = m_listSelected->GetCount();
		data.id = -nPos;
		data.catId = it->first;

		CChampionshipCategoriesTable::tTableIt itemIt =
			m_ChampionshipsCategories.insert(std::make_pair(data.id, data)).first;
		wxString catName = STR_FORMAT(STR_FORMAT_CATEGORY_LIST_ITEM
			, cData.shortName
			, cData.name);
		m_listSelected->Insert(catName, nPos, (void*)&itemIt->first);

		it++;
	}
}

void udfChampionshipCategoriesMngrDlg::OnAdd( wxCommandEvent& event )
{
	wxArrayInt	nSelections;
	m_listAll->GetSelections(nSelections);
	CChampionshipCategoriesTable::tDATA data = {0};
	data.championshipId = m_nCSId;
	unsigned int i = 0;
	for(i = 0; i < nSelections.GetCount() ; ++i)
	{
		int nId = *(int*)m_listAll->GetClientData(nSelections[i]);
		CCategoriesTable::tTableIt it = m_Categories.find(nId);
		if(it != m_Categories.end())
		{
			CCategoriesTable::tDATA& cData = it->second;
			if(-1 == m_listSelected->FindString(cData.shortName))
			{
				int nPos = m_listSelected->GetCount();
				data.id = -nPos;
				data.catId = it->first;

				CChampionshipCategoriesTable::tTableIt itemIt =
					m_ChampionshipsCategories.insert(std::make_pair(data.id, data)).first;
				wxString catName = STR_FORMAT(STR_FORMAT_CATEGORY_LIST_ITEM
					, cData.shortName
					, cData.name);
				m_listSelected->Insert(catName, nPos, (void*)&itemIt->first);
			}
		}
	}
}

void udfChampionshipCategoriesMngrDlg::OnRemove( wxCommandEvent& event )
{
	wxArrayInt	nSelections;
	m_listSelected->GetSelections(nSelections);
	int i = 0;
	for(i = nSelections.GetCount()-1; i >= 0 ; --i)
	{
		int nId = *(int*)m_listSelected->GetClientData(nSelections[i]);
		m_listSelected->Delete(nSelections[i]);
		m_ChampionshipsCategories.erase(nId);
	}
}

void udfChampionshipCategoriesMngrDlg::OnRemoveAll( wxCommandEvent& event )
{
	m_ChampionshipsCategories.clear();
	m_listSelected->Clear();
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

void udfChampionshipCategoriesMngrDlg::RefreshAllList()
{
	m_Categories.clear();
	m_listAll->Clear();
	CCategoriesTable(m_pCon).GetTable(m_Categories);

	CCategoriesTable::tTableIt it = m_Categories.begin();
	while(it != m_Categories.end())
	{
		CCategoriesTable::tDATA& data = it->second;
		int nPos = m_listAll->GetCount();
		wxString catName = STR_FORMAT(STR_FORMAT_CATEGORY_LIST_ITEM
					, data.shortName
					, data.name);
		m_listAll->Insert(catName, nPos, (void*)&it->first);

		it++;
	}
}

void udfChampionshipCategoriesMngrDlg::RefreshSelectedList()
{
	m_ChampionshipsCategories.clear();
	m_listSelected->Clear();

	CChampionshipCategoriesTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	CChampionshipCategoriesTable(m_pCon).Find(m_ChampionshipsCategories, filter);

	CChampionshipCategoriesTable::tTableIt it = m_ChampionshipsCategories.begin();
	while(it != m_ChampionshipsCategories.end())
	{
		CChampionshipCategoriesTable::tDATA& data = it->second;
		int nPos = m_listSelected->GetCount();

		CCategoriesTable::tTableIt cIt = m_Categories.find(data.catId);
		if(cIt != m_Categories.end())
		{
			CCategoriesTable::tDATA& cData = cIt->second;
			wxString catName = STR_FORMAT(STR_FORMAT_CATEGORY_LIST_ITEM
				, cData.shortName
				, cData.name);
			m_listSelected->Insert(catName, nPos, (void*)&it->first);
		}

		it++;
	}
}
