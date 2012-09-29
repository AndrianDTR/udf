#include "udfMainFrameBase.h"
#include "udfChampionshipCategoriesMngrDlg.h"
#include "udfClubsMngrDlg.h"
#include "udfCategoriesMngrDlg.h"
#include "udfJudgesMngr.h"
#include "udfChampionshipJudgesTeamMngrDlg.h"
#include "udfStartNumberAssignDlg.h"
#include "udfChampionshipTypeMngr.h"
#include "udfDancersTeamMngr.h"

#include "tliga.h"
#include "tdancetypes.h"
#include "tagecategory.h"

#include "udfCodeDialog.h"
#include "udfCitiesMngr.h"
#include "udfCountriesMngr.h"
#include "udfCsTours.h"

#include "version.h"
#include "wx/aboutdlg.h"
#include "wx/msgdlg.h"

#include "udfexceptions.h"
#include "common.h"
#include "string_def.h"

#include "button_raiting.xpm"

udfMainFrameBase::udfMainFrameBase( wxWindow* parent )
: MainFrameBase( parent )
, m_pCon(NULL)
{
	SetIcon(wxICON(button_raiting));
	
	m_pCon = CDbManager::Instance()->GetConnection();
	
	m_root = m_treeCs->AddRoot(_("Root"));
	
	RefreshList();
	RefreshCities();
	RefreshTypes();
}

void udfMainFrameBase::OnCloseFrame( wxCloseEvent& event )
{
	// TODO: Implement OnCloseFrame
}

void udfMainFrameBase::OnExitClick( wxCommandEvent& event )
{
	// TODO: Implement OnExitClick
}


wxTreeItemId udfMainFrameBase::GetSelectedCs()
{
	wxTreeItemId res;
	do
	{
		wxTreeItemId item = m_treeCs->GetSelection();
		if(!item.IsOk())
			break;
		
		if(m_root != m_treeCs->GetItemParent(item) )
		{
			item = m_treeCs->GetItemParent(item);
		}
		res = item;
	}while(0);
	
	return res;
}

void udfMainFrameBase::RefreshList()
{
	CChampionshipTable table(m_pCon);
	table.GetTable(m_Championships);
	
	m_treeCs->DeleteChildren(m_root);
		
	CChampionshipTable::tTableIt it = m_Championships.begin();
	while(it != m_Championships.end())
	{
		CChampionshipTable::tDATA& data = it->second;
		
		wxTreeItemId csItem = m_treeCs->AppendItem(m_root, data.name, -1, -1, new udfTreeItemData(it->first));
		/** Append tours **/
		CChampionshipToursTable::tTableMap tours;
		CChampionshipToursTable::tDATA filter = {0};
		filter.championshipId = it->first;
		
		CChampionshipToursTable(m_pCon).Find(tours, filter);
		
		CChampionshipToursTable::tTableIt itTour = tours.begin();
		while(itTour != tours.end())
		{
			CChampionshipToursTable::tDATA& data = itTour->second;
			wxString tourName = wxString::Format(_("%s(%d)"), data.name, data.limit);
			m_treeCs->AppendItem(csItem, tourName, -1, -1, new udfTreeItemData(itTour->first));
			
			itTour++;
		}
			
		it++;
	}
}

void udfMainFrameBase::RefreshTypes()
{
	CChampionshipTypeTable table(m_pCon);
	table.GetTable(m_ChampionshipTypes);
	
	m_comboType->Clear();
	
	CChampionshipTypeTable::tTableIt it = m_ChampionshipTypes.begin();
	while(it != m_ChampionshipTypes.end())
	{
		CChampionshipTypeTable::tDATA& data = it->second;
		int nPos = m_comboType->GetCount();
		m_comboType->Insert(data.name, nPos, (void*)&it->first);
		it++;
	}
	m_comboType->AutoComplete(m_comboType->GetStrings());
}

void udfMainFrameBase::RefreshCountries()
{
	CCountriesTable table(m_pCon);
	table.GetTable(m_Countries);
}

void udfMainFrameBase::RefreshCities()
{
	RefreshCountries();
	
	CCitiesTable table(m_pCon);
	table.GetTable(m_Cities);
	
	m_comboCity->Clear();
	
	CCitiesTable::tTableIt it = m_Cities.begin();
	while(it != m_Cities.end())
	{
		CCitiesTable::tDATA& data = it->second;
		int nPos = m_comboCity->GetCount();
		
		CCountriesTable::tTableIt cIt = m_Countries.find(data.countryId);
		if(cIt != m_Countries.end())
		{
			CCountriesTable::tDATA& cData = cIt->second;
			wxString city = wxString::Format(STR_FORMAT_CITY_NAME, data.Name, cData.name);
			m_comboCity->Insert(city, nPos, (void*)&it->first);
		}
		it++;
	}
	m_comboCity->AutoComplete(m_comboCity->GetStrings());
}

int udfMainFrameBase::GetSelectedType()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboType->GetValue();
		res = m_comboType->FindString(value);
		if(-1 != res)
			break;
		if(wxNO == wxMessageBox(
			  wxString::Format(STR_NOT_IN_DB_INSERT, STR_CHAMPIONSHIP_TYPE)
			, STR_INCORRECT_VALUE
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		udfChampionshipTypeMngr dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;
		
		RefreshTypes();
		m_comboType->SetValue(value);
	}
	
	return res;
}

bool udfMainFrameBase::ValidateValues()
{
	bool res = false;
	do
	{
		if(-1 == GetSelectedType())
			break;
		
		if(-1 == GetSelectedCity())
			break;
		
		wxDateTime date = m_dateDate->GetValue();
		wxDateTime open = m_dateRegOpen->GetValue();
		wxDateTime close = m_dateRegClose->GetValue();
		
		if(date < wxDateTime::Now())
		{
			ShowWarning(STR_WARN_NOW_GREATTHEN_ChDATE);
			break;
		}
		if(close >= date)
		{
			ShowWarning(STR_WARN_REGCLOSE_GREATTHEN_ChDATE);
			break;
		}
		if(open >= close)
		{
			ShowWarning(STR_WARN_REGOPEN_GREATTHEN_REGCLOSE);
			break;
		}
		
		res = true;
	}while(0);
	
	return res;
}

int udfMainFrameBase::GetSelectedCity()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboCity->GetValue();
		res = m_comboCity->FindString(value);
		if(-1 != res)
			break;
		if(wxNO == wxMessageBox(
			  wxString::Format(STR_NOT_IN_DB_INSERT, STR_CITY)
			, STR_INCORRECT_VALUE
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		udfCitiesMngr dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;
		
		RefreshCountries();
		m_comboCity->SetValue(value);
	}
	
	return res;
}

void udfMainFrameBase::OnAddChampionsip( wxCommandEvent& event )
{
	do
	{
		if(! ValidateValues())
			break;
		
		CChampionshipTable::tDATA data = {0};
		data.type = *(int*)m_comboType->GetClientData(GetSelectedType());
		data.city = *(int*)m_comboCity->GetClientData(GetSelectedCity());
		
		data.name = m_textChName->GetValue();
		data.additionalInfo = m_textAdditionalInfo->GetValue();
		data.address = m_textAddress->GetValue();
		data.date = m_dateDate->GetValue().GetTicks();
		data.regOpenDate = m_dateRegOpen->GetValue().GetTicks();
		data.regCloseDate = m_dateRegClose->GetValue().GetTicks();
		
		if(UDF_OK != CChampionshipTable(m_pCon).AddRow(data))
		{
			ShowError(STR_ERR_ADD_CHAMPIONSHIP_FAILED);
			break;
		}
			
		CChampionshipTable::tTableIt it = m_Championships.insert(std::make_pair(data.id, data)).first;
				
		m_treeCs->AppendItem(m_root, data.name, -1, -1, new udfTreeItemData(it->first));
		
	}while(0);
}

void udfMainFrameBase::OnRemoveChampionship( wxCommandEvent& event )
{
	do
	{
		wxTreeItemId item = GetSelectedCs();
		udfTreeItemData* csItem = (udfTreeItemData*)m_treeCs->GetItemData(item);
		
		if(UDF_OK != CChampionshipTable(m_pCon).DelRow(csItem->GetId()))
		{
			ShowError(STR_ERR_DEL_CHAMPIONSHIP_FAILED);
			break;
		}
		
		m_Championships.erase(csItem->GetId());
		m_treeCs->Delete(item);
	}while(0);
}

void udfMainFrameBase::OnSave( wxCommandEvent& event )
{
	do
	{
		wxTreeItemId item = GetSelectedCs();
		udfTreeItemData* csItem = (udfTreeItemData*)m_treeCs->GetItemData(item);
		
		if(!ValidateValues())
			break;
		
		CChampionshipTable::tTableIt it = m_Championships.find(csItem->GetId());
		if(it == m_Championships.end())
			break;
		
		CChampionshipTable::tDATA& data = it->second;
		data.type = *(int*)m_comboType->GetClientData(GetSelectedType());
		data.city = *(int*)m_comboCity->GetClientData(GetSelectedCity());
		
		data.name = m_textChName->GetValue();
		data.additionalInfo = m_textAdditionalInfo->GetValue();
		data.address = m_textAddress->GetValue();
		data.date = m_dateDate->GetValue().GetTicks();
		data.regOpenDate = m_dateRegOpen->GetValue().GetTicks();
		data.regCloseDate = m_dateRegClose->GetValue().GetTicks();
		
		if(UDF_OK != CChampionshipTable(m_pCon).UpdateRow(csItem->GetId(), data))
		{
			ShowError(STR_ERR_UPD_CHAMPIONSHIP_FAILED);
			break;
		}
		m_treeCs->SetItemText(item, data.name);
	}while(0);
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
		wxTreeItemId itemId = GetSelectedCs();
		if(!itemId.IsOk())
			break;
			
		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(itemId);
		
		CChampionshipTable::tTableIt it = m_Championships.find(csItem->GetId());
		if(it == m_Championships.end())
			break;
		
		CChampionshipTable::tDATA& data = it->second;
		m_textChName->SetValue(data.name);
		m_textAddress->SetValue(data.address);
		m_textAdditionalInfo->SetValue(data.additionalInfo);
		
		CChampionshipTypeTable::tTableIt typeIt = m_ChampionshipTypes.find(data.type);
		if(typeIt == m_ChampionshipTypes.end())
			break;
		
		CChampionshipTypeTable::tDATA& typeData = typeIt->second;
		m_comboType->SetValue(typeData.name);
		
		CCitiesTable::tTableIt cityIt = m_Cities.find(data.city);
		if(cityIt == m_Cities.end())
			break;
		
		CCitiesTable::tDATA& cityData = cityIt->second;
		CCountriesTable::tTableIt countryIt = m_Countries.find(cityData.countryId);
		if(countryIt == m_Countries.end())
			break;
		
		CCountriesTable::tDATA& countryData = countryIt->second;
		wxString city = wxString::Format(STR_FORMAT_CITY_NAME, cityData.Name, countryData.name);
		m_comboCity->SetValue(city);
		
		m_dateDate->SetValue(wxDateTime(data.date));
		m_dateRegOpen->SetValue(wxDateTime(data.regOpenDate));
		m_dateRegClose->SetValue(wxDateTime(data.regCloseDate));
		
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
			wxTreeItemId csItem = m_treeCs->AppendItem(m_root, data.name, -1, -1, new udfTreeItemData(it->first));
			
			CChampionshipToursTable::tTableMap tours;
			CChampionshipToursTable::tDATA filter = {0};
			filter.championshipId = it->first;
			
			CChampionshipToursTable(m_pCon).Find(tours, filter);
			
			CChampionshipToursTable::tTableIt itTour = tours.begin();
			while(itTour != tours.end())
			{
				CChampionshipToursTable::tDATA& data = itTour->second;
				wxString tourName = wxString::Format(_("%s(%d)"), data.name, data.limit);
				m_treeCs->AppendItem(csItem, tourName, -1, -1, new udfTreeItemData(itTour->first));
				
				itTour++;
			}
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
		wxTreeItemId itemId = GetSelectedCs();
		if(!itemId.IsOk())
			break;
			
		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(itemId);
	
		udfChampionshipCategoriesMngrDlg(this, csItem->GetId()).ShowModal();
	}while(0);
}

void udfMainFrameBase::OnDancersTeams(wxCommandEvent& event)
{
	do{
		wxTreeItemId itemId = GetSelectedCs();
		if(!itemId.IsOk())
			break;
			
		udfTreeItemData *csItem = (udfTreeItemData *)m_treeCs->GetItemData(itemId);
	
		udfDancersTeamMngr(this, csItem->GetId()).ShowModal();
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

void udfMainFrameBase::OnToursManager( wxCommandEvent& event )
{
	/*do
	{
		int nItem = m_listChampionship->GetSelection();
		if(-1 != nItem )
		{
			int nId = *(int*)m_listChampionship->GetClientData(nItem);
			
			udfCsTours dlg(this, nId);
			dlg.ShowModal();
		}
	}while(0);
	 * */
}

void udfMainFrameBase::OnCitiesMngr(wxCommandEvent& event)
{
	wxString val = m_comboCity->GetValue();
	
	udfCitiesMngr	dlg(this);
	dlg.ShowModal();
	RefreshCities();
	
	m_comboCity->SetValue(val);
}

void udfMainFrameBase::OnCountriesMngr(wxCommandEvent& event)
{
	wxString val = m_comboCity->GetValue();
	
	udfCountriesMngr	dlg(this);
	dlg.ShowModal();
	RefreshCities();
	
	m_comboCity->SetValue(val);
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
	wxString val = m_comboType->GetValue();
	
	udfChampionshipTypeMngr dlg(this);
	dlg.ShowModal();
	RefreshTypes();
	
	m_comboType->SetValue(val);
}