#include "udfCsTourReport.h"

#include "common.h"

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
	wxArrayInt order;
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
		m_listTeams->InsertColumn(index++, wxString::Format(_("%c"), n), wxLIST_FORMAT_CENTER, 20);
		n++;
		it++;
	}
	
	m_listTeams->InsertColumn(index++, _("Sum"), wxLIST_FORMAT_LEFT, 50);
		
	m_staticJudgeDescr->SetLabel(judgeDescr);
}

void udfCsTourReport::FillList()
{
	m_listTeams->Hide();
	
	tDancerMarksItC it = m_dancerMarks.begin();
	long	ndx = 0;
	while(it != m_dancerMarks.end())
	{
		int nCol = 1;
		wxListItem info;
		info.SetId(ndx);
		info.SetText(wxString::Format(STR_FORMAT_START_NUMBER, it->first));
		m_listTeams->InsertItem(info);
		
		info.SetColumn(nCol++);
		info.SetText(GetTeamNameById(it->first));
		m_listTeams->SetItem(info);
		
		// Marks
		const tMarks&	marks = it->second;
		tMarksItC mIt = marks.begin();
		int sum = 0;
		while(mIt != marks.end())
		{
			info.SetColumn(nCol++);
			sum += mIt->second;
			info.SetText(wxString::Format(_("%c"), mIt->second == 0 ? '-':'+'));
			m_listTeams->SetItem(info);
			
			mIt++;
		}
		
		info.SetColumn(nCol++);
		info.SetText(wxString::Format(_("%d"), sum));
		m_listTeams->SetItem(info);
	
		// Marks end
		
		ndx++;
		it++;
	}
	
	m_listTeams->Show();
	
	int nColumn = 0;
	int nColumnsCount = m_listTeams->GetColumnCount();
	for(nColumn = 0; nColumn < nColumnsCount; ++nColumn)
	{
		m_listTeams->SetColumnWidth( nColumn, wxLIST_AUTOSIZE);
	}
		
}

void udfCsTourReport::FormatReportTableHeader()
{
	m_report.Add(STR_HTML_REPORT_TABLE_HEADER);
	//Add report title
	//m_report.Add(STR_REPPORT_HTML_TITLE);
	m_report.Add(STR_HTML_REPORT_TABLE_FOOTER);
	
	m_report.Add(STR_HTML_REPORT_TABLE_HEADER);
	wxArrayString row;
	// Start number
	row.Add(wxString::Format(STR_FORMAT_HTML_REPORT_COL, STR_REPORT_START_NUMBER));
	// Team name
	row.Add(wxString::Format(STR_FORMAT_HTML_REPORT_COL, STR_REPORT_TEAM));
	
	tJudgesItC it = m_judgesMap.begin();
	while(it != m_judgesMap.end())
	{
		row.Add(wxString::Format(STR_FORMAT_HTML_REPORT_COL, it->second));
		it++;
	}
	
	// Sum
	row.Add(wxString::Format(STR_FORMAT_HTML_REPORT_COL, STR_REPORT_SUM));
	wxString szRow;
	int col = 0;
	for(; col < row.GetCount(); ++col)
	{
		szRow += row[col]; 
	}
	m_report.Add(wxString::Format(STR_FORMAT_HTML_REPORT_ROW, szRow));
}

void udfCsTourReport::FormatReportTableBody()
{
	m_report.Add(STR_HTML_REPORT_TABLE_FOOTER);
}

void udfCsTourReport::OnReport( wxCommandEvent& event )
{
	m_report.Clear();
	m_report.Add(STR_HTML_REPORT_HEADER);
	
	FormatReportTableHeader();
	FormatReportTableBody();
	
	m_report.Add(STR_HTML_REPORT_FOOTER);
	
	wxString text;
	int col = 0;
	for(; col < m_report.GetCount(); ++col)
	{
		text += m_report[col]; 
	}
}

void udfCsTourReport::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfCsTourReport::OnTeamSelect( wxListEvent& event )
{
	// TODO: Implement OnTeamSelect
}

void udfCsTourReport::OnBeginDrag(wxListEvent& event)
{
}

