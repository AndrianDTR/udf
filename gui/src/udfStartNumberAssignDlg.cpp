#include "udfStartNumberAssignDlg.h"

#include "udfexceptions.h"
#include "string_def.h"

udfStartNumberAssignDlg::udfStartNumberAssignDlg( wxWindow* parent, unsigned int nCsId  )
: StartNumberAssignDlg( parent )
, m_pCon(NULL)
, m_nCsId(nCsId)
, m_nLastAssign(1)
, m_pTable(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	m_pTable = new CChampionshipTeamsTable(m_pCon);
		
	RefreshList();
	
	m_Filter.clubId = 0;
	m_Filter.startNumber = 0;
	m_Filter.name = "";
	m_Filter.championshipId = nCsId;
	
	srand(time(NULL));
	
	m_textNumber->SetValue(wxString::Format(STR_FORMAT_START_NUMBER, m_nLastAssign));
	m_textSearch->SetFocus();
}

void udfStartNumberAssignDlg::RefreshList()
{
	CChampionshipTeamsTable::tDATA filter = {0};
	filter.championshipId = m_nCsId;
	m_pTable->Find(m_CsTeams, filter);
	
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

void udfStartNumberAssignDlg::OnRandomFind( wxCommandEvent& event )
{
	unsigned int startNum = m_nLastAssign;
	CChampionshipTeamsTable::tTableMap data;
	
	do
	{
		startNum = rand()%99999;
		
		m_Filter.startNumber = startNum;
		
		m_pTable->Find(data, m_Filter);
		
		if(data.size() == 0)
			break;
	}while(1);
	
	m_textNumber->SetValue(wxString::Format(STR_FORMAT_START_NUMBER, startNum));
}

void udfStartNumberAssignDlg::OnNextFind( wxCommandEvent& event )
{
	unsigned int startNum = m_nLastAssign;
	CChampionshipTeamsTable::tTableMap data;
	
	do
	{
		m_Filter.startNumber = ++startNum;
		
		m_pTable->Find(data, m_Filter);
		
		if(data.size() == 0)
			break;
	}while(1);
	
	m_textNumber->SetValue(wxString::Format(STR_FORMAT_START_NUMBER, startNum));
}

void udfStartNumberAssignDlg::OnAssign( wxCommandEvent& event )
{
	do{
		unsigned long startNum = m_nLastAssign;
		if(!m_textNumber->GetValue().ToULong(&startNum))
			break;

		int nPos = m_listTeams->GetSelection();
			
		if(-1 == nPos)
			break;

		int nId = *(int*)m_listTeams->GetClientData(nPos);
		CChampionshipTeamsTable::tDATA data = {0};
		m_pTable->GetRow(nId, data);
		
		if (0 == data.startNumber)
		{
			data.startNumber = startNum;
		
			m_pTable->UpdateRow(nId, data);
			m_nLastAssign = startNum;
		}

		m_textSearch->SetValue("");
		OnNextFind(event);
		m_textSearch->SetFocus();
	}while(0);
}

void udfStartNumberAssignDlg::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfStartNumberAssignDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
