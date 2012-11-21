#include "udfCsInfo.h"
#include "udfMainFrameBase.h"
#include "udfChampionshipTypeMngr.h"
#include "udfCitiesMngr.h"
#include "udfDancersTeamMngr.h"

#include "db.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

udfCsInfo::udfCsInfo( wxWindow* parent)
: CsInfo( parent )
, m_pCon(NULL)
, m_pMainWindow(NULL)
, m_pTree(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();

	RefreshCities();
	RefreshTypes();
}

void udfCsInfo::RefreshTypes()
{
	CChampionshipTypeTable::tTableMap types;
	CChampionshipTypeTable(m_pCon).GetTable(types);

	m_comboType->Clear();

	CChampionshipTypeTable::tTableIt it = types.begin();
	while(it != types.end())
	{
		CChampionshipTypeTable::tDATA& data = it->second;
		int nPos = m_comboType->GetCount();
		int id = m_comboType->Insert(data.name, nPos);
		m_type2id[id] = it->first;
		it++;
	}
	m_comboType->AutoComplete(m_comboType->GetStrings());
}

void udfCsInfo::RefreshCities()
{
	CCountriesTable::tTableMap countries;
	CCountriesTable(m_pCon).GetTable(countries);

	CCitiesTable::tTableMap cities;
	CCitiesTable(m_pCon).GetTable(cities);

	m_comboCity->Clear();

	CCitiesTable::tTableIt it = cities.begin();
	while(it != cities.end())
	{
		CCitiesTable::tDATA& data = it->second;
		int nPos = m_comboCity->GetCount();

		CCountriesTable::tTableIt cIt = countries.find(data.countryId);
		if(cIt != countries.end())
		{
			CCountriesTable::tDATA& cData = cIt->second;
			wxString city = STR_FORMAT(STR_FORMAT_CITY_NAME, data.Name, cData.name);
			int id = m_comboCity->Insert(city, nPos);
			m_city2id[id] = it->first;
		}
		it++;
	}
	m_comboCity->AutoComplete(m_comboCity->GetStrings());
}

int udfCsInfo::GetSelectedType()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboType->GetValue();
		res = m_comboType->FindString(value);
		if(-1 != res)
			break;
		if(wxNO == ShowQuestion(
			  STR_FORMAT(STR_NOT_IN_DB_INSERT, STR_CHAMPIONSHIP_TYPE)
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

bool udfCsInfo::ValidateValues()
{
	bool res = false;
	do
	{
		if(!m_city2id[GetSelectedCity()])
			break;

		if(!m_type2id[GetSelectedType()])
			break;

		wxDateTime date = m_dateDate->GetValue();
		wxDateTime open = m_dateRegOpen->GetValue();
		wxDateTime close = m_dateRegClose->GetValue();

		/*
		if(date < wxDateTime::Now())
		{
			ShowWarning(STR_WARN_NOW_GREATTHEN_ChDATE);
			break;
		}
		*/
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

int udfCsInfo::GetSelectedCity()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboCity->GetValue();
		res = m_comboCity->FindString(value);
		if(-1 != res)
			break;
		if(wxNO == ShowQuestion(
			  STR_FORMAT(STR_NOT_IN_DB_INSERT, STR_CITY)
			, STR_INCORRECT_VALUE
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;

		udfCitiesMngr dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;

		RefreshCities();
		m_comboCity->SetValue(value);
	}

	return res;
}

bool udfCsInfo::Show(bool show)
{
	do
	{
		if(!show)
			break;

		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk())
			break;

		m_textChName->SetValue(STR_EMPTY);
		m_textAddress->SetValue(STR_EMPTY);
		m_textAdditionalInfo->SetValue(STR_EMPTY);
		
		if(m_comboType->GetCount())
			m_comboType->Select(0);
		if(m_comboCity->GetCount())
			m_comboCity->Select(0);
		
		wxDateTime dt = wxDateTime::Now();
		m_dateRegOpen->SetValue(dt);
		m_dateRegClose->SetValue(dt.Add(wxDateSpan().Days(1)));
		m_dateDate->SetValue(dt.Add(wxDateSpan().Days(1)));

		m_textChName->SetFocus();
		
		if(!m_itemId.IsOk())
			break;
			
		CChampionshipTable::tDATA data = {0};
		udfTreeItemData* csItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);

		if(UDF_OK != CChampionshipTable(m_pCon).GetRow(csItem->GetId(), data))
		{
			ShowError(STR_ERR_UPD_CHAMPIONSHIP_FAILED);
			break;
		}

		m_textChName->SetValue(data.name);
		m_textAddress->SetValue(data.address);
		m_textAdditionalInfo->SetValue(data.additionalInfo);

		CChampionshipTypeTable::tDATA typeData = {0};
		if(CChampionshipTypeTable(m_pCon).GetRow(data.type, typeData))
			break;

		int nSel = m_comboType->FindString(typeData.name);
		if(-1 != nSel)
			m_comboType->Select(nSel);

		nSel = m_comboCity->FindString(GetCityNameById(data.city));
		if(-1 != nSel)
			m_comboCity->Select(nSel);

		m_dateDate->SetValue(wxDateTime(data.date));
		m_dateRegOpen->SetValue(wxDateTime(data.regOpenDate));
		m_dateRegClose->SetValue(wxDateTime(data.regCloseDate));

	}while(0);

	return wxPanel::Show(show);
}

void udfCsInfo::OnSave( wxCommandEvent& event )
{
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk())
			break;

		if(!ValidateValues())
			break;

		CChampionshipTable::tDATA data = {0};

		data.type = m_type2id[GetSelectedType()];
		data.city = m_city2id[GetSelectedCity()];
		
		data.name = m_textChName->GetValue();
		data.additionalInfo = m_textAdditionalInfo->GetValue();
		data.address = m_textAddress->GetValue();
		data.date = m_dateDate->GetValue().GetTicks();
		data.regOpenDate = m_dateRegOpen->GetValue().GetTicks();
		data.regCloseDate = m_dateRegClose->GetValue().GetTicks();

		if(m_itemId.IsOk())
		{
			udfTreeItemData* csItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
			data.id = csItem->GetId();

			if(UDF_OK != CChampionshipTable(m_pCon).UpdateRow(csItem->GetId(), data))
			{
				ShowError(STR_ERR_UPD_CHAMPIONSHIP_FAILED);
				break;
			}
			m_pTree->SetItemText(m_itemId, data.name);
		}
		else
		{
			data.id = -1;

			if(UDF_OK != CChampionshipTable(m_pCon).AddRow(data))
			{
				ShowError(STR_ERR_ADD_CHAMPIONSHIP_FAILED);
				break;
			}

			m_pTree->AppendItem(m_parentItem, data.name, -1, -1, new udfTreeItemData(data.id, IT_CS));
		}
	}while(0);
}

void udfCsInfo::OnRemoveChampionship( wxCommandEvent& event )
{
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk() || !m_itemId.IsOk())
		{
			__info("One of item is not set");
			break;
		}

		udfTreeItemData* csItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);

		if(UDF_OK != CChampionshipTable(m_pCon).DelRow(csItem->GetId()))
		{
			ShowError(STR_ERR_DEL_CHAMPIONSHIP_FAILED);
			break;
		}

		wxTreeItemId curr = m_pTree->GetPrevSibling(m_itemId);
		m_pTree->Delete(m_itemId);
		if(curr.IsOk())
			m_pTree->SelectItem(curr);
		else
			this->Hide();
	}while(0);
}

void udfCsInfo::OnDiscard( wxCommandEvent& event )
{
// TODO: Implement OnDiscard
}

void udfCsInfo::OnCategoryMngr( wxCommandEvent& event )
{
	Enter();
	do
	{
		if(!m_pMainWindow)
		{
			__info("Main window not set");
			break;
		}

		m_pMainWindow->ShowCsCategoryManager();
	}while(0);

	event.Skip();
	Leave();
}

void udfCsInfo::OnJudgeMngr( wxCommandEvent& event )
{
	Enter();
	do
	{
		if(!m_pMainWindow)
		{
			__info("Main window not set");
			break;
		}

		m_pMainWindow->ShowCsJudgesManager();
	}while(0);

	event.Skip();
	Leave();
}

void udfCsInfo::OnSendInvitation( wxCommandEvent& event )
{
// TODO: Implement OnSendInvitation
}

void udfCsInfo::OnDancersTeams( wxCommandEvent& event )
{
	do{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk()|| !m_itemId.IsOk())
		{
			__info("One of item is not set");
			break;
		}

		udfTreeItemData *csItem = (udfTreeItemData *)m_pTree->GetItemData(m_itemId);

		if(wxID_OK == udfDancersTeamMngr(this, csItem->GetId()).ShowModal())
		{
			m_pMainWindow->RefreshCs(csItem->GetId(), m_parentItem);
			m_pTree->Expand(m_itemId);
		}
	}while(0);
}

void udfCsInfo::OnStartNumberAssign( wxCommandEvent& event )
{
	if(m_pMainWindow)
		m_pMainWindow->ShowStartNumberAssign();
	event.Skip();
}

void udfCsInfo::OnAddBlock( wxCommandEvent& event )
{
	if(m_pMainWindow)
		m_pMainWindow->OnAddBlock(event);
	event.Skip();
}

void udfCsInfo::OnTourEdit( wxCommandEvent& event )
{
// TODO: Implement OnTourEdit
}

void udfCsInfo::OnRemoveTour( wxCommandEvent& event )
{
// TODO: Implement OnRemoveTour
}

void udfCsInfo::OnJudgesMark( wxCommandEvent& event )
{
// TODO: Implement OnJudgesMark
}

void udfCsInfo::OnCsTourReport( wxCommandEvent& event )
{
// TODO: Implement OnCsTourReport
}
