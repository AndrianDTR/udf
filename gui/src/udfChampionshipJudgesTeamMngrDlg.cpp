#include "udfChampionshipJudgesTeamMngrDlg.h"

udfChampionshipJudgesTeamMngrDlg::udfChampionshipJudgesTeamMngrDlg( wxWindow* parent, unsigned int nId )
: ChampionshipJudgesTeamMngrDlg( parent )
, m_pCon(NULL)
, m_nCSId(nId)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshAllList();
	RefreshSelectedList();
}

void udfChampionshipJudgesTeamMngrDlg::OnAddAll( wxCommandEvent& event )
{
	m_ChampionshipsJudges.clear();
	
	CChampionshipJudgesTeamTable::tDATA data = {0};
	data.championshipId = m_nCSId;
	
	int nId = 0;
	CJudgesTable::tTableIt it = m_Judges.begin();
	while(it != m_Judges.end())
	{
		CJudgesTable::tDATA& jData = it->second;
		int nPos = m_listSelected->GetCount();
		data.id = -nPos;
		data.judgeId = it->first;
		
		CChampionshipJudgesTeamTable::tTableIt itemIt = 
			m_ChampionshipsJudges.insert(std::make_pair(data.id, data)).first;
		m_listSelected->Insert(jData.name, nPos, (void*)&itemIt->first);

		it++;
	}
}

void udfChampionshipJudgesTeamMngrDlg::OnAdd( wxCommandEvent& event )
{
	wxArrayInt	nSelections;
	m_listAll->GetSelections(nSelections);
	CChampionshipJudgesTeamTable::tDATA data = {0};
	data.championshipId = m_nCSId;
	unsigned int i = 0;
	for(i = 0; i < nSelections.GetCount() ; ++i)
	{
		int nId = *(int*)m_listAll->GetClientData(nSelections[i]);
		CJudgesTable::tTableIt it = m_Judges.find(nId);
		if(it != m_Judges.end())
		{
			CJudgesTable::tDATA& jData = it->second;
			if(-1 == m_listSelected->FindString(jData.name))
			{
				int nPos = m_listSelected->GetCount();
				data.id = -nPos;
				data.judgeId = it->first;
				
				CChampionshipJudgesTeamTable::tTableIt itemIt = 
					m_ChampionshipsJudges.insert(std::make_pair(data.id, data)).first;
				m_listSelected->Insert(jData.name, nPos, (void*)&itemIt->first);
			}
		}
	}
}

void udfChampionshipJudgesTeamMngrDlg::OnRemove( wxCommandEvent& event )
{
	wxArrayInt	nSelections;
	m_listSelected->GetSelections(nSelections);
	int i = 0;
	for(i = nSelections.GetCount()-1; i >= 0 ; --i)
	{
		int nId = *(int*)m_listSelected->GetClientData(nSelections[i]);
		m_listSelected->Delete(nSelections[i]);
		m_ChampionshipsJudges.erase(nId);
	}
}

void udfChampionshipJudgesTeamMngrDlg::OnRemoveAll( wxCommandEvent& event )
{
	m_ChampionshipsJudges.clear();
	m_listSelected->Clear();
}

void udfChampionshipJudgesTeamMngrDlg::OnSave( wxCommandEvent& event )
{
	CChampionshipJudgesTeamTable table(m_pCon);
	CChampionshipJudgesTeamTable::tTableMap stored;
	CChampionshipJudgesTeamTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	table.Find(stored, filter);
		
	CChampionshipJudgesTeamTable::tTableIt listIt = stored.begin();
	while(listIt != stored.end())
	{
		CChampionshipJudgesTeamTable::tTableIt rLstIt = m_ChampionshipsJudges.find(listIt->first);
		if(rLstIt == m_ChampionshipsJudges.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_ChampionshipsJudges.end() && rLstIt->first == listIt->first)
		{
			CChampionshipJudgesTeamTable::tDATA& data = listIt->second;
			CChampionshipJudgesTeamTable::tDATA& cData = rLstIt->second;
			if( data.judgeId != cData.judgeId)
			{
				data.judgeId = cData.judgeId;
				table.UpdateRow(listIt->first, data);
			}
			m_ChampionshipsJudges.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_ChampionshipsJudges.size() > 0)
	{
		CChampionshipJudgesTeamTable::tTableIt rLstIt = m_ChampionshipsJudges.begin();
		while(rLstIt != m_ChampionshipsJudges.end())
		{
			CChampionshipJudgesTeamTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}
	
	EndModal(wxID_OK);
}

void udfChampionshipJudgesTeamMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}


void udfChampionshipJudgesTeamMngrDlg::RefreshAllList()
{
	m_Judges.clear();
	m_listAll->Clear();
	CJudgesTable(m_pCon).GetTable(m_Judges);
	
	CJudgesTable::tTableIt it = m_Judges.begin();
	while(it != m_Judges.end())
	{
		CJudgesTable::tDATA& data = it->second;
		int nPos = m_listAll->GetCount();
		m_listAll->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
}

void udfChampionshipJudgesTeamMngrDlg::RefreshSelectedList()
{
	m_ChampionshipsJudges.clear();
	CChampionshipJudgesTeamTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	CChampionshipJudgesTeamTable(m_pCon).Find(m_ChampionshipsJudges, filter);
	
	m_listSelected->Clear();
	
	CChampionshipJudgesTeamTable::tTableIt it = m_ChampionshipsJudges.begin();
	while(it != m_ChampionshipsJudges.end())
	{
		CChampionshipJudgesTeamTable::tDATA& data = it->second;
		int nPos = m_listSelected->GetCount();
		
		CJudgesTable::tTableIt cIt = m_Judges.find(data.judgeId);
		if(cIt != m_Judges.end())
		{
			CJudgesTable::tDATA& cData = cIt->second;
			m_listSelected->Insert(cData.name, nPos, (void*)&it->first);
		}
		
		it++;
	}
}

