#include "udfCsTourReport.h"

#include "udfReportPreview.h"

#include "udfcommon.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

#include "wx/dnd.h"

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
	m_listTeams->InsertColumn(index++, STR_START_NUMBER, wxLIST_FORMAT_LEFT, 50);
	m_listTeams->InsertColumn(index++, STR_TEAM, wxLIST_FORMAT_LEFT, width);

	wxString judgeDescr;

	tJudgesItC it = m_judgesMap.begin();
	char	n = 'A';
	while(it != m_judgesMap.end())
	{
		judgeDescr += STR_FORMAT(STR_FORMAT_REPORT_JUDGE_SHORTCUT, n, it->second);
		m_listTeams->InsertColumn(index++, STR_FORMAT(_("%c"), n), wxLIST_FORMAT_CENTER, 20);
		n++;
		it++;
	}

	m_listTeams->InsertColumn(index++, STR_REPORT_SUM, wxLIST_FORMAT_LEFT, 50);

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
		info.SetText(STR_FORMAT(STR_FORMAT_START_NUMBER, it->first));
		if(ndx < m_nLimit - 10)
			info.SetBackgroundColour(wxColour( 190, 255, 190 ));
		else if(ndx >= m_nLimit - 10 && ndx < m_nLimit)
			info.SetBackgroundColour(wxColour( 190, 190, 255 ));
		else if(ndx >= m_nLimit && ndx < m_nLimit + 10)
			info.SetBackgroundColour(wxColour( 255, 255, 190 ));
		else
			info.SetBackgroundColour(wxColour( 255, 190, 190 ));

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
			info.SetText(STR_FORMAT(_("%c"), mIt->second == 0 ? '-':'+'));
			m_listTeams->SetItem(info);

			mIt++;
		}

		info.SetColumn(nCol++);
		info.SetText(STR_FORMAT(_("%d"), sum));
		m_listTeams->SetItem(info);

		// Marks end

		ndx++;
		it++;
	}

	m_listTeams->Show();

	// Resize columns to fit content
	int nColumn = 0;
	int nColumnsCount = m_listTeams->GetColumnCount();
	for(nColumn = 0; nColumn < nColumnsCount; ++nColumn)
	{
		m_listTeams->SetColumnWidth( nColumn, wxLIST_AUTOSIZE);
	}
}

void udfCsTourReport::FormatReportTitle()
{
	m_report.Add(STR_HTML_TABLE_BEGIN);
	//Add report title
	//m_report.Add(STR_REPPORT_HTML_TITLE);
	m_report.Add(STR_HTML_TABLE_END);
}

void udfCsTourReport::FormatReportTableHeader()
{
	wxString szRow;
	wxArrayString row;

	// Start number
	row.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_HDR, STR_START_NUMBER));
	// Team name
	row.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_HDR, STR_TEAM));

	tJudgesItC it = m_judgesMap.begin();
	while(it != m_judgesMap.end())
	{
		wxString judge = it->second;
		judge.Replace(" ", STR_HTML_REPORT_BR);
		row.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_HDR, judge));
		it++;
	}

	// Sum
	row.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_HDR, STR_REPORT_SUM));

	int col = 0;
	for(; col < row.GetCount(); ++col)
	{
		szRow += row[col];
	}
	m_report.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_ROW, szRow));
}

void udfCsTourReport::FormatReportTableBody()
{
	tDancerMarksItC it = m_dancerMarks.begin();
	while(it != m_dancerMarks.end())
	{
		wxString szRow;
		wxArrayString row;

		row.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_COL, STR_FORMAT(STR_FORMAT_START_NUMBER, it->first)));
		row.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_COL, GetTeamNameById(it->first)));

		// Marks
		const tMarks&	marks = it->second;
		tMarksItC mIt = marks.begin();
		int sum = 0;
		while(mIt != marks.end())
		{
			row.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_COL, STR_FORMAT(_("%c"), mIt->second == 0 ? '-':'+')));
			sum += mIt->second;
			mIt++;
		}

		row.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_COL, STR_FORMAT(_("%d"), sum)));

		int col = 0;
		for(; col < row.GetCount(); ++col)
		{
			szRow += row[col];
		}
		m_report.Add(STR_FORMAT(STR_FORMAT_HTML_TABLE_ROW, szRow));

		it++;
	}
}

void udfCsTourReport::OnReport( wxCommandEvent& event )
{
	m_report.Clear();
	m_report.Add(STR_HTML_BEGIN);

	FormatReportTitle();

	m_report.Add(STR_HTML_TABLE_BEGIN);
	FormatReportTableHeader();
	FormatReportTableBody();
	m_report.Add(STR_HTML_TABLE_END);

	m_report.Add(STR_HTML_END);

	char *fileName = "./report.html";
	FILE *file;
	file = fopen(fileName, "w+");
	int col = 0;
	for(; col < m_report.GetCount(); ++col)
	{
		const char* szData = m_report[col].mb_str(wxConvUTF8);
		fprintf(file,"%s", szData);
	}
	fclose(file);

	system(STR_FORMAT(STR_FORMAT_REPORT_PREVIEW_CMD, fileName).c_str());
}

void udfCsTourReport::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfCsTourReport::OnTeamSelect( wxListEvent& event )
{
	// TODO: Implement OnTeamSelect
}

void udfCsTourReport::OnStartDrag(wxListEvent& event)
{
	do
	{
		wxListItem info;
		info.SetId(event.GetIndex());
		m_listTeams->GetItem(info);

		wxTextDataObject tdo(info.GetText());
		wxDropSource tds(tdo, m_listTeams);
		tds.DoDragDrop(wxDrag_CopyOnly);
	}while(0);
}

void udfCsTourReport::OnDown(wxListEvent& event)
{
}

void udfCsTourReport::OnDown10(wxListEvent& event)
{
}

void udfCsTourReport::OnUp(wxListEvent& event)
{
}

void udfCsTourReport::OnUp10(wxListEvent& event)
{
}

