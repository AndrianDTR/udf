#include "udfMainFrameBase.h"
#include "udfChampionshipCategoriesMngrDlg.h"
#include "udfClubsMngrDlg.h"
#include "udfCategoriesMngrDlg.h"
#include "udfJudgesMngr.h"
#include "udfChampionshipJudgesTeamMngrDlg.h"
#include "udfStartNumberAssignDlg.h"
#include "udfChampionshipTypeMngr.h"
#include "udfDancersTeamMngr.h"
#include "udfCodeDialog.h"
#include "udfCitiesMngr.h"
#include "udfCountriesMngr.h"
#include "udfCsTours.h"
#include "udfJudgeMark.h"
#include "udfCsTourReport.h"

#include "udfCsInfo.h"
#include "udfBlockInfo.h"
#include "udfCategoryInfo.h"
#include "udfTourInfo.h"

#include "db.h"

#include "wx/aboutdlg.h"
#include "wx/msgdlg.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

#include "button_raiting.xpm"

udfMainFrameBase::udfMainFrameBase( wxWindow* parent )
: MainFrameBase( parent )
, m_pCon(NULL)
{
	SetIcon(wxICON(button_raiting));

	m_pCon = CDbManager::Instance()->GetConnection();

	m_root = m_treeCs->AddRoot(_("Root"));

	m_pageCsInfo = new udfCsInfo(m_notebook);
	m_pageCsInfo->SetMainWindow(this);
	m_notebook->AddPage(m_pageCsInfo, _("Championship info"));
	m_pageCsInfo->Hide();

	m_pageBlockInfo = new udfBlockInfo(m_notebook);
	m_pageBlockInfo->SetMainWindow(this);
	m_notebook->AddPage(m_pageBlockInfo, _("Block info"));
	m_pageBlockInfo->Hide();

	m_pageCatInfo = new udfCategoryInfo(m_notebook);
	m_pageCatInfo->SetMainWindow(this);
	m_notebook->AddPage(m_pageCatInfo, _("Category info"));
	m_pageCatInfo->Hide();

	m_pageTourInfo = new udfTourInfo(m_notebook);
	m_pageTourInfo->SetMainWindow(this);
	m_notebook->AddPage(m_pageTourInfo, _("Tour info"));
	m_pageTourInfo->Hide();

	RefreshList();
}

void udfMainFrameBase::OnCloseFrame( wxCloseEvent& event )
{
	Destroy();
}

void udfMainFrameBase::OnExitClick( wxCommandEvent& event )
{
	Destroy();
}

wxTreeItemId udfMainFrameBase::GetItemByType(eITEM_TYPE type)
{
	wxTreeItemId res;
	do
	{
		wxTreeItemId item = m_treeCs->GetSelection();
		if(!item.IsOk())
			break;

		udfTreeItemData* pData = (udfTreeItemData*)m_treeCs->GetItemData(item);
		while(item != m_root && pData && pData->GetType() != type)
		{
			item = m_treeCs->GetItemParent(item);
			pData = (udfTreeItemData*)m_treeCs->GetItemData(item);
		}
		if(item != m_root)
			res = item;
	}while(0);

	return res;
}

wxTreeItemId udfMainFrameBase::GetSelectedCs()
{
	return GetItemByType(IT_CS);
}

wxTreeItemId udfMainFrameBase::GetSelectedCsBlock()
{
	return GetItemByType(IT_BLOCK);
}

wxTreeItemId udfMainFrameBase::GetSelectedBlockCategory()
{
	return GetItemByType(IT_CAT);
}

wxTreeItemId udfMainFrameBase::GetSelectedCatTour()
{
	return GetItemByType(IT_TOUR);
}

void udfMainFrameBase::RefreshList()
{
	/** Refresh championship list **/
	CChampionshipTable table(m_pCon);
	table.GetTable(m_Championships);

	m_treeCs->DeleteChildren(m_root);

	CChampionshipTable::tTableIt it = m_Championships.begin();
	while(it != m_Championships.end())
	{
		CChampionshipTable::tDATA& data = it->second;

		int nTeamsCount = 0;
		GetTeamsCountForChampionship(it->first, nTeamsCount);
		wxString csName = wxString::Format(_("%s (%d)"), data.name, nTeamsCount);
		wxTreeItemId csItem = m_treeCs->AppendItem(m_root, csName, -1, -1, new udfTreeItemData(it->first, IT_CS));

		RefreshCs(it->first, csItem);

		it++;
	}
}

void udfMainFrameBase::RefreshCs(unsigned int id, wxTreeItemId parent)
{
	/** Refresh championship blocks **/
	CCsBlocksTable::tTableMap blocks;
	CCsBlocksTable::tDATA filter = {0};
	filter.csId = id;

	CCsBlocksTable(m_pCon).Find(blocks, filter);

	CCsBlocksTable::tTableIt it = blocks.begin();
	while(it != blocks.end())
	{
		CCsBlocksTable::tDATA& data = it->second;
		time_t len;

		GetBlockLenById(it->first, len);
		wxString name = wxString::Format(STR_FORMAT_BLOCK_NAME, data.name, time2str(len));
		wxTreeItemId csBlock = m_treeCs->AppendItem(parent, name, -1, -1, new udfTreeItemData(it->first, IT_BLOCK));

		RefreshCsBlock(it->first, csBlock);

		it++;
	}
}

void udfMainFrameBase::RefreshCsBlock(unsigned int id, wxTreeItemId parent)
{
	/** Append block categories **/
	CCsBlockCategoriesTable::tTableMap categories;
	CCsBlockCategoriesTable::tDATA catFilter = {0};
	catFilter.blockId = id;

	CCsBlockCategoriesTable(m_pCon).Find(categories, catFilter);

	CCsBlockCategoriesTable::tTableIt it = categories.begin();
	while(it != categories.end())
	{
		CCsBlockCategoriesTable::tDATA& data = it->second;
		int regTeams = 0;

		GetRegisteredTeamsForCategory(data.csCatId, regTeams);
		wxString catName = wxString::Format(STR_FORMAT_CS_NAME, GetCsCategoryNameById(data.csCatId), regTeams);
		wxTreeItemId csCat = m_treeCs->AppendItem(parent, catName, -1, -1, new udfTreeItemData(it->first, IT_CAT));

		RefreshCategory(it->first, csCat);

		it++;
	}
}

void udfMainFrameBase::RefreshCategory(unsigned int id, wxTreeItemId parent)
{
	/** Refresh category tours **/
	CChampionshipToursTable::tTableMap tours;
	CChampionshipToursTable::tDATA filter = {0};
	filter.csCatId = id;

	CChampionshipToursTable(m_pCon).Find(tours, filter);

	CChampionshipToursTable::tTableIt itTour = tours.begin();
	while(itTour != tours.end())
	{
		CChampionshipToursTable::tDATA& data = itTour->second;
		wxString tourName = wxString::Format(STR_FORMAT_TOUR_NAME, GetTourTypeNameById(data.typeId), data.limit);
		m_treeCs->AppendItem(parent, tourName, -1, -1, new udfTreeItemData(itTour->first, IT_TOUR));

		itTour++;
	}
}

void udfMainFrameBase::OnDiscard( wxCommandEvent& event )
{
	do{
		wxTreeItemId itemId = GetSelectedCs();
		if(!itemId.IsOk())
			break;

		m_treeCs->SelectItem(itemId);
	}while(0);
}

void udfMainFrameBase::OnCsSelect(wxTreeEvent& event)
{
	do
	{
		wxTreeItemId item = m_treeCs->GetSelection();
		if(!item.IsOk())
			break;

		udfTreeItemData* pData = (udfTreeItemData*)m_treeCs->GetItemData(item);
		eITEM_TYPE type = pData->GetType();
		DEBUG_PRINTF("Item type: %d", type);
		switch(type)
		{
			case IT_CS:
				CsSelected();
				break;
			case IT_BLOCK:
				BlockSelected();
				break;
			case IT_CAT:
				CatSelected();
				break;
			case IT_TOUR:
				TourSelected();
				break;
		}

	}while(0);
}

void udfMainFrameBase::OnSearch(wxCommandEvent& event)
{
	wxString search = m_textSearch->GetValue().Upper();
	CChampionshipTable::tTableIt it;

	m_treeCs->DeleteChildren(m_root);

	for(it = m_Championships.begin(); it != m_Championships.end(); it++)
	{
		CChampionshipTable::tDATA& data = it->second;
		wxString name(data.name);

		if(name.Upper().Contains(search))
		{
			wxTreeItemId csItem = m_treeCs->AppendItem(m_root, data.name, -1, -1, new udfTreeItemData(it->first, IT_CS));

			RefreshCs(it->first, csItem);
		}
	}
}

wxDateTime udfMainFrameBase::GetChDateById(unsigned int nId)
{
	wxDateTime dt;
	do
	{
		CChampionshipTable::tTableIt it = m_Championships.find(nId);
		if(it == m_Championships.end())
			break;
		CChampionshipTable::tDATA& data = it->second;
		dt = wxDateTime(data.date);
	}while(0);

	return dt;
}

/****************************************************************
 * Dialogs
 ****************************************************************/
 void udfMainFrameBase::OnAboutDlg(wxCommandEvent& event)
{
	wxAboutDialogInfo info;

	info.SetName(wxT("Championship calculator."));

	info.SetVersion(
		wxString::Format("%d.%d.%d", UDF_VERSION_MAJOR, UDF_VERSION_MINOR, UDF_VERSION_PATCH)
		);

	info.SetDescription(wxT("Calculate and print dance championship result."));

	info.SetWebSite("andrian.yablonsky@gmail.com");

	info.SetCopyright(wxT("(C) 2012 Andrian Yablonsky."));

	wxAboutBox(info, this);
}

void udfMainFrameBase::OnAgeCodesMgr(wxCommandEvent& event)
{
	ShowAgeCatsMngrDlg();
}

void udfMainFrameBase::OnDanceTypesCodeMgr(wxCommandEvent& event)
{
	ShowDanceTypesMngrDlg();
}

void udfMainFrameBase::OnLigueCodeMgr(wxCommandEvent& event)
{
	ShowLiguesMngrDlg();
}

int udfMainFrameBase::ShowAgeCatsMngrDlg()
{
	int res = wxID_CANCEL;

	udfCodeDialog dlg(this);
	dlg.SetTitle(STR_AGE_CATEGORY_CODE_MNGR);
	dlg.SetListName(STR_AGE_CATEGORY_CODE_LIST);
	CDbConnection* pCon = CDbManager::Instance()->GetConnection();
	CAgeCategoryTable::tTableMap list;
	CAgeCategoryTable	table(pCon);
	table.GetTable(list);
	CAgeCategoryTable::tTableIt listIt = list.begin();
	while(listIt != list.end())
	{
		CAgeCategoryTable::tDATA data = listIt->second;
		dlg.AddListItem(data.id, data.name, data.code);
		listIt++;
	}
	dlg.RefreshList();
	res = dlg.ShowModal();
	if(res == wxID_OK)
	{
		udfCodeDialog::tListMap rList = dlg.GetResultList();

		listIt = list.begin();
		while(listIt != list.end())
		{
			udfCodeDialog::tListIt rLstIt = rList.find(listIt->first);
			if(rLstIt == rList.end())
			{
				table.DelRow(listIt->first);
			}
			else if(rLstIt != rList.end() && rLstIt->first == listIt->first)
			{
				CAgeCategoryTable::tDATA data = listIt->second;
				udfCodeDialog::tDATA cData = rLstIt->second;
				if(data.code != cData.code || data.name != cData.name)
				{
					data.code = cData.code;
					data.name = cData.name;
					table.UpdateRow(listIt->first, data);
				}
				rList.erase(rLstIt);
			}
			listIt++;
		}

		if(rList.size() > 0)
		{
			//insert data here
			udfCodeDialog::tListIt rLstIt = rList.begin();
			while(rLstIt != rList.end())
			{
				CAgeCategoryTable::tDATA data;
				udfCodeDialog::tDATA cData = rLstIt->second;
				data.code = cData.code;
				data.name = cData.name;
				table.AddRow(data);
				rLstIt++;
			}
		}
	}
	return res;
}

int udfMainFrameBase::ShowDanceTypesMngrDlg()
{
	int res = wxID_CANCEL;
	udfCodeDialog dlg(this);
	dlg.SetTitle(STR_DANCE_TYPES_CODE_MNGR);
	dlg.SetListName(STR_DANCE_TYPES_CODE_LIST);

	CDbConnection* pCon = CDbManager::Instance()->GetConnection();
	CDanceTypesTable::tTableMap list;
	CDanceTypesTable	table(pCon);
	table.GetTable(list);
	CDanceTypesTable::tTableIt listIt = list.begin();
	while(listIt != list.end())
	{
		CDanceTypesTable::tDATA data = listIt->second;
		dlg.AddListItem(data.id, data.name, data.code);
		listIt++;
	}
	dlg.RefreshList();
	res = dlg.ShowModal();
	if(res == wxID_OK)
	{
		udfCodeDialog::tListMap rList = dlg.GetResultList();

		listIt = list.begin();
		while(listIt != list.end())
		{
			udfCodeDialog::tListIt rLstIt = rList.find(listIt->first);
			if(rLstIt == rList.end())
			{
				table.DelRow(listIt->first);
			}
			else if(rLstIt != rList.end() && rLstIt->first == listIt->first)
			{
				CDanceTypesTable::tDATA data = listIt->second;
				udfCodeDialog::tDATA& cData = rLstIt->second;
				if(data.code != cData.code || data.name != cData.name)
				{
					data.code = cData.code;
					data.name = cData.name;
					table.UpdateRow(listIt->first, data);
				}
				rList.erase(rLstIt);
			}class MyTreeItemData : public wxTreeItemData
{
public:
    MyTreeItemData(const wxString& desc) : m_desc(desc) { }

    void ShowInfo(wxTreeCtrl *tree);
    const wxChar *GetDesc() const { return m_desc.c_str(); }

private:
    wxString m_desc;
};
			listIt++;
		}

		if(rList.size() > 0)
		{
			//insert data here
			udfCodeDialog::tListIt rLstIt = rList.begin();
			while(rLstIt != rList.end())
			{
				CDanceTypesTable::tDATA data;
				udfCodeDialog::tDATA cData = rLstIt->second;
				data.code = cData.code;
				data.name = cData.name;
				table.AddRow(data);
				rLstIt++;
			}
		}
	}
	return res;
}

int udfMainFrameBase::ShowLiguesMngrDlg()
{
	int res = wxID_CANCEL;

	udfCodeDialog dlg(this);
	dlg.SetTitle(STR_LIGUES_CODE_MNGR);
	dlg.SetListName(STR_LIGUES_CODE_LIST);

	CDbConnection* pCon = CDbManager::Instance()->GetConnection();
	CLigaTable::tTableMap list;
	CLigaTable	table(pCon);
	table.GetTable(list);
	CLigaTable::tTableIt listIt = list.begin();
	while(listIt != list.end())
	{
		CLigaTable::tDATA data = listIt->second;
		dlg.AddListItem(data.id, data.name, data.code);
		listIt++;
	}
	dlg.RefreshList();
	res = dlg.ShowModal();
	if(res == wxID_OK)
	{
		udfCodeDialog::tListMap rList = dlg.GetResultList();

		listIt = list.begin();
		while(listIt != list.end())
		{
			udfCodeDialog::tListIt rLstIt = rList.find(listIt->first);
			if(rLstIt == rList.end())
			{
				table.DelRow(listIt->first);
			}
			else if(rLstIt != rList.end() && rLstIt->first == listIt->first)
			{
				CLigaTable::tDATA data = listIt->second;
				udfCodeDialog::tDATA cData = rLstIt->second;

				if(data.code != cData.code || data.name != cData.name)
				{
					data.code = cData.code;
					data.name = cData.name;
					table.UpdateRow(listIt->first, data);
				}

				rList.erase(rLstIt);
			}
			listIt++;
		}

		if(rList.size() > 0)
		{
			udfCodeDialog::tListIt rLstIt = rList.begin();
			while(rLstIt != rList.end())
			{
				CLigaTable::tDATA data;
				udfCodeDialog::tDATA cData = rLstIt->second;
				data.code = cData.code;
				data.name = cData.name;
				table.AddRow(data);
				rLstIt++;
			}
		}
	}

	return res;
}

void udfMainFrameBase::OnCategoryMngr( wxCommandEvent& event )
{
	do{
		wxTreeItemId csId = GetSelectedCs();
		if(!csId.IsOk())
			break;

		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(csId);

		if(wxID_OK == udfChampionshipCategoriesMngrDlg(this, csItem->GetId()).ShowModal())
		{
			m_treeCs->DeleteChildren(csId);
			RefreshCs(csItem->GetId(), csId);
		}

	}while(0);
}

void udfMainFrameBase::OnDancersTeams(wxCommandEvent& event)
{
	do{
		wxTreeItemId csId = GetSelectedCs();
		if(!csId.IsOk())
			break;

		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(csId);

		if(wxID_OK == udfDancersTeamMngr(this, csItem->GetId()).ShowModal())
		{
			RefreshList();
		}
	}while(0);
}

void udfMainFrameBase::OnStartNumberAssign( wxCommandEvent& event )
{
	do{
		wxTreeItemId itemId = GetSelectedCs();
		if(!itemId.IsOk())
			break;

		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(itemId);

		udfStartNumberAssignDlg(this, csItem->GetId()).ShowModal();
	}while(0);
}

void udfMainFrameBase::OnJudgeMngr( wxCommandEvent& event )
{
	do{
		wxTreeItemId itemId = GetSelectedCs();
		if(!itemId.IsOk())
			break;

		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(itemId);

		udfChampionshipJudgesTeamMngrDlg(this, csItem->GetId()).ShowModal();
	}while(0);
}

void udfMainFrameBase::OnSendInvitation( wxCommandEvent& event )
{
	// TODO: Implement OnSendInvitation
}

void udfMainFrameBase::OnCitiesMngr(wxCommandEvent& event)
{
	udfCitiesMngr	dlg(this);
	dlg.ShowModal();
	m_pageCsInfo->RefreshCities();
}

void udfMainFrameBase::OnCountriesMngr(wxCommandEvent& event)
{
	udfCountriesMngr	dlg(this);
	dlg.ShowModal();
	m_pageCsInfo->RefreshCities();
}

void udfMainFrameBase::OnMenuCategoryManage( wxCommandEvent& event )
{
	udfCategoriesMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnMenuClubManage( wxCommandEvent& event )
{
	udfClubsMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnMenuJudgeManage( wxCommandEvent& event )
{
	udfJudgesMngr dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnMenuChampionshipTypes(wxCommandEvent& event)
{
	udfChampionshipTypeMngr dlg(this);
	dlg.ShowModal();
	m_pageCsInfo->RefreshTypes();
}

void udfMainFrameBase::OnAddTour(wxCommandEvent& event)
{
	do{
		wxTreeItemId itemCsId = GetSelectedBlockCategory();
		if(!itemCsId.IsOk())
			break;

		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(itemCsId);

		udfCsTours dlg(this, -1, -1);

		if(wxID_OK != dlg.ShowModal())
			break;

		CChampionshipToursTable::tDATA data = {0};

		data.id = -(csItem->GetId() * m_treeCs->GetChildrenCount(itemCsId));
		data.csCatId = csItem->GetId();
		data.typeId = dlg.GetTypeId();
		data.limit = dlg.GetLimit();

		if(UDF_OK != CChampionshipToursTable(m_pCon).AddRow(data))
		{
			ShowWarning(STR_ERR_ADD_CHAMPIONSHIP_TOUR_FAILED);
			break;
		}

		m_treeCs->DeleteChildren(itemCsId);
		RefreshCategory(csItem->GetId(), itemCsId);
	}while(0);
}

void udfMainFrameBase::OnRemoveTour(wxCommandEvent& event)
{
	do
	{
		wxTreeItemId itemTourId = GetSelectedCatTour();
		if(!itemTourId.IsOk())
			break;

		udfTreeItemData *tourItem = (udfTreeItemData *)m_treeCs->GetItemData(itemTourId);

		if(UDF_OK != CChampionshipToursTable(m_pCon).DelRow(tourItem->GetId()))
		{
			ShowWarning(STR_ERR_DEL_CHAMPIONSHIP_TOUR_FAILED);
			break;
		}

		m_treeCs->Delete(itemTourId);
	}while(0);
}

void udfMainFrameBase::EditTourInfo()
{
	do
	{
		wxTreeItemId itemTourId = GetSelectedCatTour();
		if(!itemTourId.IsOk())
			break;

		udfTreeItemData *tourItem = (udfTreeItemData *)m_treeCs->GetItemData(itemTourId);
		if(tourItem->GetType() != IT_TOUR)
			break;

		CChampionshipToursTable::tDATA data = {0};
		CChampionshipToursTable(m_pCon).GetRow(tourItem->GetId(), data);

		udfCsTours dlg(this, data.typeId, data.limit);

		if(wxID_OK != dlg.ShowModal())
			break;

		data.typeId = dlg.GetTypeId();
		data.limit = dlg.GetLimit();

		if(UDF_OK != CChampionshipToursTable(m_pCon).UpdateRow(tourItem->GetId(), data))
		{
			ShowWarning(STR_ERR_UPD_CHAMPIONSHIP_TOUR_FAILED);
			break;
		}

		m_treeCs->DeleteChildren(itemTourId);
		RefreshCategory(tourItem->GetId(), itemTourId);

	}while(0);
}

void udfMainFrameBase::OnCsTourReport(wxCommandEvent& event)
{
	do{
		wxTreeItemId itemCsId = GetSelectedCs();
		if(!itemCsId.IsOk())
			break;

		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(itemCsId);

		wxTreeItemId itemTourId = GetSelectedCatTour();
		if(!itemTourId.IsOk())
			break;

		udfTreeItemData *tourItem = (udfTreeItemData *)m_treeCs->GetItemData(itemTourId);

		unsigned long 	limit = 0;
		tJudges			judgeMap;
		tDancerMarks	dancerMarks;

		CChampionshipJudgesTeamTable::tTableMap judges;
		CChampionshipJudgesTeamTable::tTableIt	jIt;
		CChampionshipJudgesTeamTable::tDATA		jFilter = {0};

		CChampionshipJudgesMarkTable::tTableMap marks;
		CChampionshipJudgesMarkTable::tTableIt	mIt;
		CChampionshipJudgesMarkTable::tDATA		mFilter = {0};

		limit = GetTourLimit(tourItem->GetId());

		jFilter.championshipId = csItem->GetId();
		CChampionshipJudgesTeamTable(m_pCon).Find(judges, jFilter);

		jIt = judges.begin();
		while(jIt != judges.end())
		{
			CChampionshipJudgesTeamTable::tDATA& data = jIt->second;
			judgeMap[jIt->first] = GetJudgeNameById(data.judgeId);

			jIt++;
		}

		mFilter.championshipId = csItem->GetId();
		mFilter.tourId = tourItem->GetId();
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

		udfCsTourReport(this, csItem->GetId(), limit, judgeMap, dancerMarks).ShowModal();
	}while(0);
}

void udfMainFrameBase::OnJudgesMark(wxCommandEvent& event)
{
	do{
		wxTreeItemId itemCsId = GetSelectedCs();
		if(!itemCsId.IsOk())
			break;

		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(itemCsId);

		wxTreeItemId itemTourId = GetSelectedCatTour();
		if(!itemTourId.IsOk())
			break;

		udfTreeItemData *tourItem = (udfTreeItemData *)m_treeCs->GetItemData(itemTourId);

		udfJudgeMark(this, csItem->GetId(), tourItem->GetId(), true).ShowModal();
	}while(0);
}

/************************************************************************/
void udfMainFrameBase::OnAddChampionsip(wxCommandEvent& event)
{
	do
	{
		DEBUG_PRINT("Add Cs");
		wxTreeItemId id = wxTreeItemId();
		m_pageCsInfo->SetCsTreeItem(m_treeCs, m_root, id);

		m_pageCsInfo->Show(true);
		m_pageBlockInfo->Show(false);
		m_pageCatInfo->Show(false);
		m_pageTourInfo->Show(false);
	}while(0);
}

void udfMainFrameBase::CsSelected()
{
	do
	{
		DEBUG_PRINT("Cs selected");
		wxTreeItemId csItem = GetSelectedCs();
		if(!csItem.IsOk())
			break;

		m_pageCsInfo->SetCsTreeItem(m_treeCs, m_root, csItem);

		m_pageCsInfo->Show(true);
		m_pageBlockInfo->Show(false);
		m_pageCatInfo->Show(false);
		m_pageTourInfo->Show(false);
	}while(0);
}

void udfMainFrameBase::OnAddBlock(wxCommandEvent& event)
{
	do{
		DEBUG_PRINT("Add block");
		wxTreeItemId id = wxTreeItemId();

		wxTreeItemId csItem = GetSelectedCs();
		if(!csItem.IsOk())
			break;

		m_pageBlockInfo->SetCsTreeItem(m_treeCs, m_root, csItem);

		m_pageCsInfo->Show(false);
		m_pageBlockInfo->Show(true);
		m_pageCatInfo->Show(false);
		m_pageTourInfo->Show(false);
	}while(0);
}

void udfMainFrameBase::BlockSelected()
{
	do
	{
		DEBUG_PRINT("Block selected");
		wxTreeItemId csItem = GetSelectedCs();
		if(!csItem.IsOk())
			break;

		wxTreeItemId blockItem = GetSelectedCsBlock();
		if(!blockItem.IsOk())
			break;

		m_pageCsInfo->SetCsTreeItem(m_treeCs, csItem, blockItem);

		m_pageCsInfo->Show(false);
		m_pageBlockInfo->Show(true);
		m_pageCatInfo->Show(false);
		m_pageTourInfo->Show(false);
	}while(0);
}

void udfMainFrameBase::CatSelected()
{
	do
	{
		m_pageCsInfo->Show(false);
		m_pageBlockInfo->Show(false);
		m_pageCatInfo->Show(true);
		m_pageTourInfo->Show(false);
	}while(0);
}

void udfMainFrameBase::TourSelected()
{
	do
	{
		m_pageCsInfo->Show(false);
		m_pageBlockInfo->Show(false);
		m_pageCatInfo->Show(false);
		m_pageTourInfo->Show(true);
	}while(0);
}
