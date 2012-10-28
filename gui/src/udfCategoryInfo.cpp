#include "udfCategoryInfo.h"
#include "udfMainFrameBase.h"

#include "db.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

udfCategoryInfo::udfCategoryInfo( wxWindow* parent )
: CategoryInfo( parent )
, m_pCon(NULL)
, m_pMainWindow(NULL)
, m_pTree(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	CreateHeaders();
}

udfCategoryInfo::~udfCategoryInfo()
{
}

bool udfCategoryInfo::Show(bool show)
{
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk() || !m_itemId.IsOk())
			break;
		
		m_listRegisteredTeams->DeleteAllItems();
		
		FillList();

	}while(0);

	return wxPanel::Show(show);
}

void udfCategoryInfo::CreateHeaders()
{
	m_listRegisteredTeams->AppendColumn(STR_START_NUMBER, wxLIST_FORMAT_LEFT, 100);
	m_listRegisteredTeams->AppendColumn(STR_TEAM);
	m_listRegisteredTeams->AppendColumn(STR_COMPOSITION);
}

void udfCategoryInfo::FillList()
{
	tUIList teams;
	udfTreeItemData* catId = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
		
	GetTeamsInCategory(catId->GetId(), teams);
	
	m_listRegisteredTeams->Hide();
	
	tUIListIt it = teams.begin();
	int ndx = 0;
	while(it != teams.end())
	{
		int nCol = 1;
		unsigned int teamId = *it;
		CChampionshipTeamsTable::tDATA teamInfo = {0};
		CChampionshipTeamsTable(m_pCon).GetRow(teamId, teamInfo);
		
		CChampionshipTeamCategoriesTable::tDATA catFilter = {0};
		CChampionshipTeamCategoriesTable::tTableMap catInfo;
		catFilter.teamId = teamId;
		catFilter.csCatId = catId->GetId();
		CChampionshipTeamCategoriesTable(m_pCon).Find(catInfo, catFilter);
		
		wxListItem info;
		info.SetId(ndx);
		info.SetText(wxString::Format(STR_FORMAT_START_NUMBER, teamInfo.startNumber));
		
		m_listRegisteredTeams->InsertItem(info);
		
		info.SetColumn(nCol++);
		info.SetText(teamInfo.name);
		m_listRegisteredTeams->SetItem(info);
		
		CChampionshipTeamCategoriesTable::tTableIt first = catInfo.begin();
		CChampionshipTeamCategoriesTable::tDATA& cat = first->second;
		
		info.SetColumn(nCol++);
		info.SetText(cat.compositionName);
		m_listRegisteredTeams->SetItem(info);
		
		ndx++;
		it++;
	}
	
	m_listRegisteredTeams->Show();
	
	// Resize columns to fit content
	int nColumn = 0;
	int nColumnsCount = m_listRegisteredTeams->GetColumnCount();
	for(nColumn = 1; nColumn < nColumnsCount; ++nColumn)
	{
		m_listRegisteredTeams->SetColumnWidth( nColumn, wxLIST_AUTOSIZE);
	}
}

void udfCategoryInfo::OnAddTour(wxCommandEvent& event)
{
	if(m_pMainWindow)
		m_pMainWindow->OnAddTour(event);
	event.Skip();
}

void udfCategoryInfo::OnStartNumberMngr(wxCommandEvent& event)
{
}

