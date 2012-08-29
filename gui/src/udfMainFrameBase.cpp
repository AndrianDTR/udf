#include "udfMainFrameBase.h"
#include "udfChampionshipCategoriesMngrDlg.h"
#include "udfClubsMngrDlg.h"
#include "udfCategoriesMngrDlg.h"
#include "udfJudgesMngr.h"
#include "udfChampionshipJudgesTeamMngrDlg.h"
#include "udfStartNumberAssignDlg.h"
#include "udfChampionshipTypeMngr.h"

#include "tliga.h"
#include "tdancetypes.h"
#include "tagecategory.h"

#include "udfCodeDialog.h"
#include "udfCitiesMngr.h"
#include "udfCountriesMngr.h"

#include "version.h"
#include "wx/aboutdlg.h"
#include "wx/msgdlg.h"

#include "udfexceptions.h"
#include "common.h"
#include "string_def.h"

udfMainFrameBase::udfMainFrameBase( wxWindow* parent )
: MainFrameBase( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
	RefreshCities();
	RefreshTypes();
}

void udfMainFrameBase::RefreshList()
{
	CChampionshipTable table(m_pCon);
	table.GetTable(m_Championships);
	
	m_listChampionship->Clear();
	
	CChampionshipTable::tTableIt it = m_Championships.begin();
	while(it != m_Championships.end())
	{
		CChampionshipTable::tDATA& data = it->second;
		int nPos = m_listChampionship->GetCount();
		m_listChampionship->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
}

void udfMainFrameBase::OnCloseFrame( wxCloseEvent& event )
{
	// TODO: Implement OnCloseFrame
}

void udfMainFrameBase::OnExitClick( wxCommandEvent& event )
{
	// TODO: Implement OnExitClick
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
		//Add date validation here
		
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

void udfMainFrameBase::RefreshCountries()
{
	CCountriesTable table(m_pCon);
	table.GetTable(m_Countries);
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
		
		CChampionshipTable table(m_pCon);
		TEST_BREAK(UDF_OK, table.AddRow(data), STR_ERR_ADD_CHAMPIONSHIP_FAILED);
			
		CChampionshipTable::tTableIt it = m_Championships.insert(std::make_pair(data.id, data)).first;
		int nPos = m_listChampionship->GetCount();
		m_listChampionship->Insert(data.name, nPos, (void*)&it->first);
	}while(0);
}

void udfMainFrameBase::OnRemoveChampionship( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listChampionship->GetSelection();
		if(nItem == -1)
			break;
		int nId = *(int*)m_listChampionship->GetClientData(nItem);
		CChampionshipTable table(m_pCon);
		
		TEST_BREAK(UDF_OK, table.DelRow(nId), STR_ERR_DEL_CHAMPIONSHIP_FAILED);
		
		m_Championships.erase(nId);
		m_listChampionship->Delete(nItem);
	}while(0);
}

void udfMainFrameBase::OnSave( wxCommandEvent& event )
{
	do
	{
		if(! ValidateValues())
			break;
		
		int nItem = m_listChampionship->GetSelection();
		if(nItem == -1)
			break;
		int nId = *(int*)m_listChampionship->GetClientData(nItem);
		
		CChampionshipTable::tTableIt it = m_Championships.find(nId);
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
		
		CChampionshipTable table(m_pCon);
		TEST_BREAK(UDF_OK, table.UpdateRow(nId, data), STR_ERR_UPD_CHAMPIONSHIP_FAILED);
		m_listChampionship->SetString(nItem, data.name);
	}while(0);
}

void udfMainFrameBase::OnDiscard( wxCommandEvent& event )
{
	int nItem = m_listChampionship->GetSelection();
	m_listChampionship->SetSelection(nItem);
	OnSelectChampionship(event);
}

void udfMainFrameBase::OnSelectChampionship(wxCommandEvent& event)
{
	do
	{
		int nItem = m_listChampionship->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listChampionship->GetClientData(nItem);
		
		CChampionshipTable::tTableIt it = m_Championships.find(nId);
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
		
		wxDateTime dt = wxDateTime::Now();
		dt.Set(data.date);
		m_dateDate->SetValue(dt);
		
		wxDateTime odt = wxDateTime::Now();
		odt.Set(data.regOpenDate);
		m_dateRegOpen->SetValue(odt);
		
		wxDateTime cdt = wxDateTime::Now();
		cdt.Set(data.regCloseDate);
		m_dateRegClose->SetValue(cdt);
	}while(0);
}

void udfMainFrameBase::OnSearch(wxCommandEvent& event)
{
	wxString search = m_textSearch->GetValue().Upper();
	CChampionshipTable::tTableIt item;
	
	m_listChampionship->Clear();
	for(item = m_Championships.begin(); item != m_Championships.end(); item++)
	{
		CChampionshipTable::tDATA& data = item->second;
		wxString name(data.name);
		
		if(name.Upper().Contains(search))
		{
			int pos = m_listChampionship->GetCount();
			m_listChampionship->Insert(data.name, pos, (void*)&item->first);
		}
	}
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
			}
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
			//insert data here
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
	udfChampionshipCategoriesMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnStartNumberAssign( wxCommandEvent& event )
{
	udfStartNumberAssignDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnJudgeMngr( wxCommandEvent& event )
{
	udfChampionshipJudgesTeamMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfMainFrameBase::OnSendInvitation( wxCommandEvent& event )
{
	// TODO: Implement OnSendInvitation
}

void udfMainFrameBase::OnResults( wxCommandEvent& event )
{
	// TODO: Implement OnResults
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
