#include "udfMainFrameBase.h"
#include "udfChampionshipCategoriesMngrDlg.h"
#include "udfClubsMngrDlg.h"
#include "udfCategoriesMngrDlg.h"
#include "udfJudgesMngr.h"
#include "udfChampionshipJudgesTeamMngrDlg.h"
#include "udfStartNumberAssignDlg.h"

#include "tliga.h"
#include "tdancetypes.h"
#include "tagecategory.h"

#include "udfCodeDialog.h"
#include "udfCitiesMngr.h"
#include "udfCountriesMngr.h"

#include "version.h"
#include "wx/aboutdlg.h"
#include "wx/msgdlg.h"

#include "common.h"

udfMainFrameBase::udfMainFrameBase( wxWindow* parent )
: MainFrameBase( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshData();
}

void udfMainFrameBase::RefreshData()
{
	CChampionshipTable table(m_pCon);
	table.GetTable(m_Championships);
	
	m_listChamlionship->Clear();
	
	CChampionshipTable::tTableIt it = m_Championships.begin();
	while(it != m_Championships.end())
	{
		CChampionshipTable::tDATA& data = it->second;
		int nPos = m_listChamlionship->GetCount();
		m_listChamlionship->Insert(data.name, nPos, (void*)&it->first);
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

void udfMainFrameBase::OnAddChampionsip( wxCommandEvent& event )
{
	CChampionshipTable::tDATA data = {0};
	data.id = -m_listChamlionship->GetCount();
	
	data.type = *(int*)m_comboType->GetClientData(m_comboType->GetSelection());
	data.city = *(int*)m_comboCity->GetClientData(m_comboCity->GetSelection());
	
	data.name = m_textName->GetValue();
	data.additionalInfo = m_textAdditionalInfo->GetValue();
	data.address = m_textAddress->GetValue();
	data.date = m_dateDate->GetValue().Format(_(""));
	data.regOpenDate = m_dateRegOpen->GetValue().Format(_(""));
	data.regCloseDate = m_dateRegClose->GetValue().Format(_(""));
	
	m_Championships.insert(std::make_pair(data.id, data));
}

void udfMainFrameBase::OnRemoveChampionship( wxCommandEvent& event )
{

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

void udfMainFrameBase::OnSave( wxCommandEvent& event )
{
	// TODO: Implement OnSave
}

void udfMainFrameBase::OnDiscard( wxCommandEvent& event )
{
	// TODO: Implement OnDiscard
}

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
	dlg.SetTitle(wxT("Age category code manager"));
	dlg.SetListName(_("Age categories list"));
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
	dlg.SetTitle(wxT("Dance types code manager"));
	dlg.SetListName(_("Dance types list"));
	
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
	dlg.SetTitle(wxT("Ligues code manager"));
	dlg.SetListName(_("Ligues list"));
	
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

void udfMainFrameBase::OnChampionshipSelect(wxCommandEvent& event)
{
}

void udfMainFrameBase::OnSearch(wxCommandEvent& event)
{
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
		
		if(wxNO == wxMessageBox(_("Selected 'City' not present in database. Insert it?")
			, _("Incorrect value")
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		CountriesMngr	dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;
		
		RefreshCities();
		m_comboCity->SetValue(value);
		DEBUG_PRINTF("Country %d", res);
	}
	
	return res;
}

int udfMainFrameBase::GetSelectedCountry()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboCountry->GetValue();
		res = m_comboCountry->FindString(value);
		if(-1 != res)
			break;
		
		if(wxNO == wxMessageBox(_("Selected 'Country' not present in database. Insert it?")
			, _("Incorrect value")
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		CitiesMngr	dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;
		
		RefreshCountries();
		m_comboCountry->SetValue(value);
		DEBUG_PRINTF("Country %d", res);
	}
	
	return res;
}

void udfMainFrameBase::OnCountryChanged(wxCommandEvent& event)
{
}

void udfMainFrameBase::RefreshCities()
{
}

void udfMainFrameBase::RefreshCountries()
{
}

void udfMainFrameBase::OnCitiesMngr(wxCommandEvent& event)
{
	//udfCitiesMngr	dlg(this);
	//dlg.ShowModal();
}

void udfMainFrameBase::OnCountriesMngr(wxCommandEvent& event)
{
	udfCountriesMngr	dlg(this);
	dlg.ShowModal();
}
