#include "udfCsTourReport.h"

#include "udfuiutils.h"
#include "string_def.h"

udfCsTourReport::udfCsTourReport(wxWindow* parent
	, unsigned long nTourId
	, int limit
	, const tJudges& judgesMap
	, const tDancerMarks& dancerMarks)
: CsTourReport(parent)
, m_judgesMap(judgesMap)
, m_dancerMarks(dancerMarks)
, m_nLimit(limit)
, m_nTourId(nTourId)
{
	CreateHeaders();
	FillList();
}

void udfCsTourReport::CreateHeaders()
{
	int index = 0;
	int width = 850 - m_judgesMap.size()*20;
	m_listTeams->InsertColumn(index++, _("#"), wxLIST_FORMAT_LEFT, 50);
	m_listTeams->InsertColumn(index++, _("Team"), wxLIST_FORMAT_LEFT, width);
	
	wxString judgeDescr;
	
	tJudgesItC it = m_judgesMap.begin();
	char	n = 'A';
	while(it != m_judgesMap.end())
	{
		judgeDescr += wxString::Format(_("%c - %s; "), n, it->second);
		m_listTeams->InsertColumn(index++, wxString::Format(_("%c"), n), wxLIST_FORMAT_LEFT, 20);
		n++;
		it++;
	}
	
	m_listTeams->InsertColumn(index++, _("Sum"), wxLIST_FORMAT_LEFT, 50);
	
	m_staticJudgeDescr->SetLabel(judgeDescr);
}

void udfCsTourReport::FillList()
{
	m_listTeams->Hide();
	
	tDancerMarksItC	marksIt = m_dancerMarks.begin();
	while(marksIt != m_dancerMarks.end())
	{
		
		const tMarks& marks = marksIt->second;
		int nId = m_listTeams->GetItemCount();
		
		long item = m_listTeams->InsertItem(nId, wxString::Format(STR_FORMAT_START_NUMBER, marksIt->first));
		//m_listTeams->SetItem(item, 1, GetTeamNameById(marksIt->first));
		
		marksIt++;
	}
	
	m_listTeams->Show();
	
	int nColumn = 0;
	int nColumnsCount = m_listTeams->GetColumnCount();
	for(nColumn = 0; nColumn < nColumnsCount; ++nColumn)
	{
		m_listTeams->SetColumnWidth( nColumn, wxLIST_AUTOSIZE );
	}
}

void udfCsTourReport::OnReport( wxCommandEvent& event )
{
	// TODO: Implement OnReport
}

void udfCsTourReport::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfCsTourReport::OnTeamSelect( wxListEvent& event )
{
	// TODO: Implement OnTeamSelect
}

