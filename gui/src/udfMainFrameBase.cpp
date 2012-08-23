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

#include "cdbmanager.h"
#include "udfCodeDialog.h"

#include "version.h"
#include "wx/aboutdlg.h"

udfMainFrameBase::udfMainFrameBase( wxWindow* parent )
:
MainFrameBase( parent )
{

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
	m_nCSid = -1;
	m_textName->SetValue(_("New cnampionship name"));
	
}

void udfMainFrameBase::OnRemoveChampionship( wxCommandEvent& event )
{
	if(m_nCSid != -1)
	{
		// TODO: Implement Remove from DB
	}
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
	if(dlg.ShowModal() == wxID_OK)
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
				CAgeCategoryTable::tDATA data;
				udfCodeDialog::tDATA cData = rLstIt->second;
				data.code = cData.code;
				data.name = cData.name;
				table.UpdateRow(listIt->first, data);
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
}

void udfMainFrameBase::OnDanceTypesCodeMgr(wxCommandEvent& event)
{
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
	if(dlg.ShowModal() == wxID_OK)
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
				CDanceTypesTable::tDATA data;
				udfCodeDialog::tDATA cData = rLstIt->second;
				data.code = cData.code;
				data.name = cData.name;
				table.UpdateRow(listIt->first, data);
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
}

void udfMainFrameBase::OnLigueCodeMgr(wxCommandEvent& event)
{
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
	if(dlg.ShowModal() == wxID_OK)
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
}

