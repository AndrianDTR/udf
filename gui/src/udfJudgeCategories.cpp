#include "udfJudgeCategories.h"

#include "udfcommon.h"
#include "string_def.h"
#include "udfexceptions.h"
#include "udfuiutils.h"

udfJudgeCategories::udfJudgeCategories( wxWindow* parent, unsigned int nId )
: JudgeCategories( parent )
, m_pCon(NULL)
, m_nId(nId)
{
	m_pCon = CDbManager::Instance()->GetConnection();

	m_staticJudge->SetLabel(GetJudgeNameById(m_nId));

	RefreshList();
}

void udfJudgeCategories::RefreshList()
{
	m_checkCategories->Clear();

	CCategoriesTable(m_pCon).GetTable(m_cats);

	CCategoriesTable::tTableIt it = m_cats.begin();
	while(it != m_cats.end())
	{
		CCategoriesTable::tDATA& data = it->second;

		wxString name = STR_FORMAT(STR_FORMAT_CATEGORY_LIST_ITEM, data.shortName, data.name);
		int nItem = m_checkCategories->Insert(name, m_checkCategories->GetCount(), (void*)&it->first);
		unsigned int rowId = 0;
		if(UDF_OK == JudgeHaveCategory(m_nId, it->first, rowId))
		{
			m_checkCategories->Check(nItem);
		}
		it++;
	}
}

void udfJudgeCategories::OnSave( wxCommandEvent& event )
{
	Enter();

	int item = 0;
	for(item = 0; item < m_checkCategories->GetCount(); ++item)
	{
		bool ok = m_checkCategories->IsChecked(item);
		unsigned int nId = *(int*)m_checkCategories->GetClientData(item);
		unsigned int rowId = 0;

		long haveCat = JudgeHaveCategory(m_nId, nId, rowId);

		__info("Item: %d, checked: %d, nId: %d, have: %ld", item, ok, nId, haveCat);
		if(!ok && UDF_OK == haveCat)
		{
			__info("Remove: %d", rowId);
			CJudgesCategoriesHaveTable(m_pCon).DelRow(rowId);
		}
		else if(ok && UDF_OK != haveCat)
		{
			__info("Add cat: %d, jud: %d", nId, m_nId);
			CJudgesCategoriesHaveTable::tDATA data = {0};
			data.judCatId = nId;
			data.judgeId = m_nId;
			CJudgesCategoriesHaveTable(m_pCon).AddRow(data);
		}
	}

	EndModal(wxID_OK);
	Leave();
}

void udfJudgeCategories::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfJudgeCategories::OnClearAll(wxCommandEvent& event)
{
	int item = 0;
	for(item = 0; item < m_checkCategories->GetCount(); ++item)
	{
		m_checkCategories->Check(item, false);
	}
}

void udfJudgeCategories::OnSetAll(wxCommandEvent& event)
{
	int item = 0;
	for(item = 0; item < m_checkCategories->GetCount(); ++item)
	{
		m_checkCategories->Check(item, true);
	}
}

