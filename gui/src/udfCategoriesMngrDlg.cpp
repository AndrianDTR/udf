#include "udfCategoriesMngrDlg.h"

#include "string_def.h"
#include "common.h"

#include "wx/msgdlg.h"
#include "udfMainFrameBase.h"

udfCategoriesMngrDlg::udfCategoriesMngrDlg( wxWindow* parent )
: CategoriesMngrDlg( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshData();
}

void udfCategoriesMngrDlg::RefreshData()
{
	CCategoriesTable tableCat(m_pCon);
	tableCat.GetTable(m_Categories);
	
	m_listCategories->Clear();
	for(CCategoriesTable::tTableIt it = m_Categories.begin(); it != m_Categories.end(); it++)
	{
		CCategoriesTable::tDATA& data = it->second;
		
		int nCount = m_listCategories->GetCount();
		m_listCategories->Insert(data.shortName, nCount, (void*)&it->first);
	}
	
	RefreshAgeCategories();
	RefreshDanceTypes();
	RefreshLigues();
}

void udfCategoriesMngrDlg::RefreshDanceTypes()
{
	CDanceTypesTable tableDanceTypes(m_pCon);
	tableDanceTypes.GetTable(m_DanceTypes);

	m_comboDance->Clear();
	for(CDanceTypesTable::tTableIt it = m_DanceTypes.begin(); it != m_DanceTypes.end(); it++)
	{
		CDanceTypesTable::tDATA& data = it->second;
		
		int nPos = m_comboDance->GetCount();
		m_comboDance->Insert(data.name, nPos, (void*)&it->first);
	}
	m_comboDance->AutoComplete(m_comboDance->GetStrings());
}

void udfCategoriesMngrDlg::RefreshLigues()
{
	CLigaTable tableLiga(m_pCon);
	tableLiga.GetTable(m_Ligues);

	m_comboLiga->Clear();
	for(CLigaTable::tTableIt it = m_Ligues.begin(); it != m_Ligues.end(); it++)
	{
		CLigaTable::tDATA& data = it->second;
		
		int nPos = m_comboLiga->GetCount();
		m_comboLiga->Insert(data.name, nPos, (void*)&it->first);
	}
	m_comboLiga->AutoComplete(m_comboLiga->GetStrings());
}

void udfCategoriesMngrDlg::RefreshAgeCategories()
{
	CAgeCategoryTable tableAgeCat(m_pCon);
	tableAgeCat.GetTable(m_AgeCats);
	
	m_comboAge->Clear();
	for(CAgeCategoryTable::tTableIt it = m_AgeCats.begin(); it != m_AgeCats.end(); it++)
	{
		CAgeCategoryTable::tDATA& data = it->second;
		
		int nPos = m_comboAge->GetCount();
		m_comboAge->Insert(data.name, nPos, (void*)&it->first);
	}
	m_comboAge->AutoComplete(m_comboAge->GetStrings());
}

void udfCategoriesMngrDlg::OnAdd( wxCommandEvent& event )
{
	int nItem = m_listCategories->GetCount();
	
	CCategoriesTable::tDATA data = {0};
	data.id = -nItem;
	data.name = m_textName->GetValue();
	data.shortName = m_textShortName->GetValue();
	
	int nDance = GetSelectedDanceType();
	int nLigue = GetSelectedLigue();
	int nAgeCat = GetSelectedAgeCat();
	
	data.dance = *(int*)m_comboDance->GetClientData(nDance);
	data.liga = *(int*)m_comboLiga->GetClientData(nLigue);
	data.age_category = *(int*)m_comboAge->GetClientData(nAgeCat);
	
	CCategoriesTable::tTableIt it = m_Categories.insert(std::make_pair(data.id, data)).first;
	m_listCategories->Insert(data.shortName, nItem, (void*)&it->first);
	m_listCategories->SetSelection(nItem);
}

void udfCategoriesMngrDlg::OnRemove( wxCommandEvent& event )
{
	int nItem = m_listCategories->GetSelection();
	unsigned int nId = *(int*)m_listCategories->GetClientData(nItem);
	
	m_Categories.erase(nId);
	m_listCategories->Delete(nItem);
}

void udfCategoriesMngrDlg::OnSave( wxCommandEvent& event )
{
	OnUpdate(event);
	
	CCategoriesTable table(m_pCon);
	CCategoriesTable::tTableMap storedCats;
	table.GetTable(storedCats);
	
	CCategoriesTable::tTableIt listIt = storedCats.begin();
	while(listIt != storedCats.end())
	{
		CCategoriesTable::tTableIt rLstIt = m_Categories.find(listIt->first);
		if(rLstIt == m_Categories.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_Categories.end() && rLstIt->first == listIt->first)
		{
			CCategoriesTable::tDATA& data = listIt->second;
			CCategoriesTable::tDATA& cData = rLstIt->second;
			if(data.dance != cData.dance 
				|| data.liga != cData.liga
				|| data.age_category != cData.age_category
				|| data.name != cData.name
				|| data.shortName != cData.shortName
				)
			{
				data.dance = cData.dance;
				data.liga = cData.liga;
				data.age_category = cData.age_category;
				data.name = cData.name;
				data.shortName = cData.shortName;
				table.UpdateRow(listIt->first, data);
			}
			m_Categories.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_Categories.size() > 0)
	{
		//insert data here
		CCategoriesTable::tTableIt rLstIt = m_Categories.begin();
		while(rLstIt != m_Categories.end())
		{
			CCategoriesTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}
	
	EndModal(wxID_OK);
}

void udfCategoriesMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfCategoriesMngrDlg::OnCategorySelected(wxCommandEvent& event)
{
	unsigned int nItem = m_listCategories->GetSelection();
	unsigned int* pnId = (unsigned int*)m_listCategories->GetClientData(nItem);
	CCategoriesTable::tTableIt it = m_Categories.find(*pnId);
	
	if(it != m_Categories.end())
	{
		CCategoriesTable::tDATA& currCategory = it->second;
		m_textName->SetValue(currCategory.name);
		m_textShortName->SetValue(currCategory.shortName);
		
		CDanceTypesTable::tDATA& dance = m_DanceTypes.find(currCategory.dance)->second;
		m_comboDance->SetValue(dance.name);
		
		CLigaTable::tDATA& liga = m_Ligues.find(currCategory.liga)->second;
		m_comboLiga->SetValue(liga.name);
		
		CAgeCategoryTable::tDATA& age = m_AgeCats.find(currCategory.age_category)->second;
		m_comboAge->SetValue(age.name);
	}
}

void udfCategoriesMngrDlg::OnCategorySearch(wxCommandEvent& event)
{
	wxString search = m_textSearch->GetValue().Upper();
	CCategoriesTable::tTableIt item;
	
	m_listCategories->Clear();
	for(item = m_Categories.begin(); item != m_Categories.end(); item++)
	{
		CCategoriesTable::tDATA& data = item->second;
		wxString name(data.name);
		wxString sname(data.shortName);
		
		if(name.Upper().Contains(search) || sname.Upper().Contains(search))
		{
			int pos = m_listCategories->GetCount();
			m_listCategories->Insert(data.shortName, pos, (void*)&item->first);
		}
	}
}

void udfCategoriesMngrDlg::OnUpdate(wxCommandEvent& event)
{
	do
	{
		int nItem = m_listCategories->GetSelection();
		
		if(-1 == nItem)
			break;
			
		int nId = *(int*)m_listCategories->GetClientData(nItem);
		CCategoriesTable::tTableIt it = m_Categories.find(nId);
		
		if(it == m_Categories.end())
			break;
			
		CCategoriesTable::tDATA& data = it->second;
		
		data.name = m_textName->GetValue();
		data.shortName = m_textShortName->GetValue();
		m_listCategories->SetString(nItem, data.shortName);
		
		int nDance = GetSelectedDanceType();
		data.dance = *(int*)m_comboDance->GetClientData(nDance);
		
		int nLigue = GetSelectedLigue();
		data.liga = *(int*)m_comboLiga->GetClientData(nLigue);
		
		int nAgeCat = GetSelectedAgeCat();
		data.age_category = *(int*)m_comboAge->GetClientData(nAgeCat);
		
	}while(0);
}

int udfCategoriesMngrDlg::GetSelectedAgeCat()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboAge->GetValue();
		res = m_comboAge->FindString(value);
		if(-1 != res)
			break;
		
		if(wxNO == wxMessageBox(
			  wxString::Format(STR_NOT_IN_DB_INSERT, STR_AGE_CATEGORY)
			, STR_INCORRECT_VALUE
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		udfMainFrameBase* main = (udfMainFrameBase*)m_parent;
		if(wxID_OK != main->ShowAgeCatsMngrDlg())
			break;
		
		RefreshAgeCategories();
		m_comboAge->SetValue(value);
	}
	
	return res;
}

int udfCategoriesMngrDlg::GetSelectedDanceType()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboDance->GetValue();
		res = m_comboDance->FindString(value);
		if(-1 != res)
			break;
		
		if(wxNO == wxMessageBox(
			  wxString::Format(STR_NOT_IN_DB_INSERT, STR_DANCE_TYPE)
			, STR_INCORRECT_VALUE
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		udfMainFrameBase* main = (udfMainFrameBase*)m_parent;
		if(wxID_OK != main->ShowDanceTypesMngrDlg())
			break;
		
		RefreshDanceTypes();
		m_comboDance->SetValue(value);
	}
	
	return res;
}

int udfCategoriesMngrDlg::GetSelectedLigue()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboLiga->GetValue();
		res = m_comboLiga->FindString(value);
		if(-1 != res)
			break;
		
		if(wxNO == wxMessageBox(
			  wxString::Format(STR_NOT_IN_DB_INSERT, STR_LIGUE)
			, STR_INCORRECT_VALUE
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		udfMainFrameBase* main = (udfMainFrameBase*)m_parent;
		if(wxID_OK != main->ShowLiguesMngrDlg())
			break;
		
		RefreshLigues();
		m_comboLiga->SetValue(value);
	}
	
	return res;
}
