#include "udfCsTours.h"

#include "udfJudgeMark.h"

#include "udfuiutils.h"
#include "udfexceptions.h"
#include "string_def.h"

#include "common.h"

#include "tchampionshipjudgesmark.h"
#include "udfCsTourReport.h"

udfCsTours::udfCsTours( wxWindow* parent, unsigned int nCsId )
: CsTours( parent )
, m_pCon(NULL)
, m_nCsId(nCsId)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
}

void udfCsTours::RefreshList()
{
	m_Tours.clear();
	m_listTours->Clear();
	
	CChampionshipToursTable::tDATA filter = {0};
	filter.championshipId = m_nCsId;
	
	CChampionshipToursTable(m_pCon).Find(m_Tours, filter);
	
	CChampionshipToursTable::tTableIt it = m_Tours.begin();
	while(it != m_Tours.end())
	{
		CChampionshipToursTable::tDATA& data = it->second;
		int nPos = m_listTours->GetCount();
		m_listTours->Insert(data.name, nPos, (void*)&it->first);
		it++;
	}
}

void udfCsTours::OnSelectTour( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listTours->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listTours->GetClientData(nItem);
		
		CChampionshipToursTable::tTableIt it = m_Tours.find(nId);
		if(it == m_Tours.end())
			break;
		
		CChampionshipToursTable::tDATA& data = it->second;
		m_textName->SetValue(data.name);
		m_textLimit->SetValue(wxString::Format(_("%d"),data.limit));
		m_checkFinal->SetValue(data.final == udfYES);
		
		DisableEdit(nItem == (m_listTours->GetCount() - 1));
	}while(0);
}

void udfCsTours::OnAddTour( wxCommandEvent& event )
{
	do
	{
		if(IsFinalAdded())
			break;
		
		int nPos = m_listTours->GetCount();
		
		CChampionshipToursTable::tDATA data = {0};
		
		data.id = -nPos;
		data.championshipId = m_nCsId;
		data.name = m_textName->GetValue();
		m_textLimit->GetValue().ToLong((long*)&data.limit);
		data.final = m_checkFinal->GetValue() ? udfYES : udfNO;
		
		if(UDF_OK != CChampionshipToursTable(m_pCon).AddRow(data))
		{
			ShowWarning(STR_ERR_ADD_CHAMPIONSHIP_TOUR_FAILED);
			break;
		}
		
		CChampionshipToursTable::tTableIt it = m_Tours.insert(std::make_pair(data.id, data)).first;
		m_listTours->Insert(data.name, nPos, (void*)&it->first);
	}while(0);
}

void udfCsTours::OnRemoveTour( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listTours->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listTours->GetClientData(nItem);
		
		if(UDF_OK != CChampionshipToursTable(m_pCon).DelRow(nId))
		{
			ShowWarning(STR_ERR_DEL_CHAMPIONSHIP_TOUR_FAILED);
			break;
		}
			
		m_Tours.erase(nId);
		m_listTours->Delete(nItem);
	}while(0);
}

void udfCsTours::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfCsTours::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfCsTours::DisableEdit(bool bEdit)
{
	m_checkFinal->Enable(bEdit);
	m_textLimit->Enable(bEdit);
	m_textName->Enable(bEdit);
}

void udfCsTours::OnJudgesMark(wxCommandEvent& event)
{
	do
	{
		int nItem = m_listTours->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listTours->GetClientData(nItem);
		
		udfJudgeMark dlg(this, m_nCsId, nId, nItem == (m_listTours->GetCount() - 1));
		dlg.ShowModal();
	}while(0);
}

bool udfCsTours::IsFinalAdded()
{
	CChampionshipToursTable::tTableMap recs;
	CChampionshipToursTable::tDATA filter = {0};
	filter.championshipId = m_nCsId;
	filter.final = udfYES;
	
	CChampionshipToursTable(m_pCon).Find(recs, filter);
	
	return (recs.size() > 0);
}

void udfCsTours::OnReport(wxCommandEvent& event)
{
	do
	{
		unsigned long 	limit = 0;
		tJudges			judgeMap;
		tDancerMarks	dancerMarks;
		
		CChampionshipJudgesTeamTable::tTableMap judges;
		CChampionshipJudgesTeamTable::tTableIt	jIt;
		CChampionshipJudgesTeamTable::tDATA		jFilter = {0};
				
		CChampionshipJudgesMarkTable::tTableMap marks;
		CChampionshipJudgesMarkTable::tTableIt	mIt;
		CChampionshipJudgesMarkTable::tDATA		mFilter = {0};
		
		int nItem = m_listTours->GetSelection();
		if(nItem == -1)
			break;
		
		if(!m_textLimit->GetValue().ToULong(&limit))
			break;
		
		jFilter.championshipId = m_nCsId;
		CChampionshipJudgesTeamTable(m_pCon).Find(judges, jFilter);
		
		jIt = judges.begin();
		while(jIt != judges.end())
		{
			CChampionshipJudgesTeamTable::tDATA& data = jIt->second;
			judgeMap[jIt->first] = GetJudgeNameById(data.judgeId);
			
			jIt++;
		}
		
		mFilter.championshipId = m_nCsId;
		mFilter.tourId = *(int*)m_listTours->GetClientData(nItem);
		CChampionshipJudgesMarkTable(m_pCon).Find(marks, mFilter);
		
		mIt = marks.begin();
		while(mIt != marks.end())
		{
			CChampionshipJudgesMarkTable::tDATA& data = mIt->second;
			tMarks	marksMap;
			
			tDancerMarksIt di = dancerMarks.find(data.teamId);
			if(di != dancerMarks.end())
			{
				marksMap = di->second;
			}
			marksMap[data.judgeId] = data.nMark;
			dancerMarks[data.teamId] = marksMap;
			
			mIt++;
		}
		
		udfCsTourReport dlg(this, mFilter.tourId, limit, judgeMap, dancerMarks);
		dlg.ShowModal();
		
	}while(0);
}