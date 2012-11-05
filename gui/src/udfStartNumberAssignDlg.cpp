#include "udfStartNumberAssignDlg.h"

#include "udfexceptions.h"
#include "string_def.h"

udfStartNumberAssignDlg::udfStartNumberAssignDlg( wxWindow* parent, unsigned int nCsId  )
: StartNumberAssignDlg( parent )
, m_pCon(NULL)
, m_nCsId(nCsId)
{
	m_pCon = CDbManager::Instance()->GetConnection();

	RefreshList();

	srand(time(NULL));

	m_textSearch->SetFocus();
}

void udfStartNumberAssignDlg::RefreshList()
{
	CChampionshipTeamsTable::tDATA 	filter = {0};
	filter.championshipId = m_nCsId;

	CChampionshipTeamsTable(m_pCon).Find(m_CsTeams, filter);

	m_listTeams->Clear();

	CChampionshipTeamsTable::tTableIt it = m_CsTeams.begin();
	while(it != m_CsTeams.end())
	{
		CChampionshipTeamsTable::tDATA& data = it->second;
		int nPos = m_listTeams->GetCount();
		m_listTeams->Insert(data.name, nPos, (void*)&it->first);

		it++;
	}
}

void udfStartNumberAssignDlg::OnSearch( wxCommandEvent& event )
{
	wxString search = m_textSearch->GetValue().Upper();
	CChampionshipTeamsTable::tTableIt item;

	m_listTeams->Clear();
	for(item = m_CsTeams.begin(); item != m_CsTeams.end(); item++)
	{
		CChampionshipTeamsTable::tDATA& data = item->second;

		if(wxString(data.name).Upper().Contains(search))
		{
			int pos = m_listTeams->GetCount();
			m_listTeams->Insert(data.name, pos, (void*)&item->first);
		}
	}

	if(0 < m_listTeams->GetCount())
	{
		m_listTeams->SetSelection(0);
		m_bpAssign->Enable();
	}
	else
		m_bpAssign->Disable();
}

void udfStartNumberAssignDlg::OnSelectTeam( wxCommandEvent& event )
{

}

void udfStartNumberAssignDlg::OnAssign( wxCommandEvent& event )
{
	do{
		unsigned long startNum = 1;
	/*	if(!m_textNumber->GetValue().ToULong(&startNum))
			break;

		int nPos = m_listTeams->GetSelection();

		if(-1 == nPos)
			break;

		int nId = *(int*)m_listTeams->GetClientData(nPos);
		CChampionshipTeamsTable::tDATA data = {0};

		if (0 == data.startNumber)
		{
			data.startNumber = startNum;
			m_pTable->UpdateRow(nId, data);
			m_textNumber->SetValue(wxString::Format(STR_FORMAT_START_NUMBER, startNum));
		}
		else
		{
			m_textNumber->SetValue(wxString::Format(STR_FORMAT_START_NUMBER, (unsigned long)data.startNumber));
		}

		m_textSearch->SetValue("");
		m_textSearch->SetFocus();
		 * */
	}while(0);
}

void udfStartNumberAssignDlg::OnSave( wxCommandEvent& event )
{
	CChampionshipTeamsTable::tTableIt it = m_CsTeams.begin();
	while(it != m_CsTeams.end())
	{
		CChampionshipTeamsTable::tDATA	newData = {0};
		CChampionshipTeamsTable::tDATA& data = it->second;

		newData.startNumber = data.startNumber;

		CChampionshipTeamsTable(m_pCon).UpdateRow(data.id, newData);

		it++;
	}
	EndModal(wxID_OK);
}

void udfStartNumberAssignDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfStartNumberAssignDlg::OnAllAssignIncrease(wxCommandEvent& event)
{
	unsigned int nStartNum = 1;
	CChampionshipTeamsTable::tTableIt it = m_CsTeams.begin();
	while(it != m_CsTeams.end())
	{
		CChampionshipTeamsTable::tDATA& data = it->second;
		data.startNumber = nStartNum;

		m_StNumMap[nStartNum] = data.id;

		nStartNum++;
		it++;
	}
}

void udfStartNumberAssignDlg::OnAllAssignRandom(wxCommandEvent& event)
{
	unsigned int nStartNum = 1;
	CChampionshipTeamsTable::tTableIt it = m_CsTeams.begin();
	while(it != m_CsTeams.end())
	{
		CChampionshipTeamsTable::tDATA& data = it->second;

		do
		{
			nStartNum = rand()%9999;
		}while(m_StNumMap.end() != m_StNumMap.find(nStartNum));

		data.startNumber = nStartNum;

		it++;
	}
}

void udfStartNumberAssignDlg::OnFindNext(wxCommandEvent& event)
{
	unsigned int nStartNum = m_StNumMap.rbegin()->second;

	m_textNumber->SetValue(wxString::Format(STR_FORMAT_START_NUMBER, nStartNum));
}

void udfStartNumberAssignDlg::OnFindRandom(wxCommandEvent& event)
{
	unsigned int nStartNum = 1;
	do
	{
		nStartNum = rand()%9999;
	}while(m_StNumMap.end() != m_StNumMap.find(nStartNum));

	m_textNumber->SetValue(wxString::Format(STR_FORMAT_START_NUMBER, nStartNum));
}

