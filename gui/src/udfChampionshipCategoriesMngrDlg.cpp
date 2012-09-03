#include "udfChampionshipCategoriesMngrDlg.h"

#include "udfCategoriesMngrDlg.h"

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
	// TODO: Implement OnAddAll
}

void udfChampionshipCategoriesMngrDlg::OnAdd( wxCommandEvent& event )
{
	// TODO: Implement OnAdd
}

void udfChampionshipCategoriesMngrDlg::OnRemove( wxCommandEvent& event )
{
	// TODO: Implement OnRemove
}

void udfChampionshipCategoriesMngrDlg::OnRemoveAll( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveAll
}

void udfChampionshipCategoriesMngrDlg::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfChampionshipCategoriesMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfChampionshipCategoriesMngrDlg::RefreshAllList()
{
	m_Categories.clear();
	CCategoriesTable(m_pCon).GetTable(m_Categories);
	
	CCategoriesTable::tTableIt it = m_Categories.begin();
	while(it != m_Categories.end())
	{
		CCategoriesTable::tDATA& data = it->second;
		int nPos = m_listAll->GetCount();
		m_listAll->Insert(data.shortName, nPos, (void*)&it->first);
		
		it++;
	}
}

void udfChampionshipCategoriesMngrDlg::RefreshSelectedList()
{
	m_ChampionshipsCategories.clear();
	CChampionshipCategotiesTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	CChampionshipCategotiesTable(m_pCon).Find(m_ChampionshipsCategories, filter);
	
	CChampionshipCategotiesTable::tTableIt it = m_ChampionshipsCategories.begin();
	while(it != m_ChampionshipsCategories.end())
	{
		CChampionshipCategotiesTable::tDATA& data = it->second;
		int nPos = m_listSelected->GetCount();
			
		CCategoriesTable::tDATA cData = {0};
		if(CCategoriesTable(m_pCon).GetRow(data.catId, cData))
		{
			m_listSelected->Insert(cData.shortName, nPos, (void*)&it->first);
		}
		
		it++;
	}
}
