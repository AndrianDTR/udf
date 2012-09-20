#include "udfCsTourReport.h"

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

