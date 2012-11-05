#include "udfSettings.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

#include "udfsettingsbase.h"

udfSettings::udfSettings( wxWindow* parent )
: Settings( parent )
, m_pCon(NULL)
{

	m_pCon = CDbManager::Instance()->GetConnection();

	Refresh();
}

udfSettings::~udfSettings()
{

}

void udfSettings::OnSave( wxCommandEvent& event )
{
	wxConfig* pConf = udfSettingsBase::Instance()->GetConfig();

	pConf->Write("host", m_textServer->GetValue());
	pConf->Write("db",  m_textDatabase->GetValue());
	pConf->Write("user", m_textUser->GetValue());
	pConf->Write("pass", m_textPass->GetValue());

	CTourTypesTable::tDATA tourData = {0};
	CTourTypesTable table(m_pCon);

	table.GetRow(1, tourData);
	m_textMaxFinal->GetValue().ToULong((unsigned long*)&tourData.max);
	m_textMinFinal->GetValue().ToULong((unsigned long*)&tourData.min);
	table.UpdateRow(1, tourData);

	table.GetRow(2, tourData);
	m_textMax12->GetValue().ToULong((unsigned long*)&tourData.max);
	m_textMin12->GetValue().ToULong((unsigned long*)&tourData.min);
	table.UpdateRow(2, tourData);

	table.GetRow(3, tourData);
	m_textMax14->GetValue().ToULong((unsigned long*)&tourData.max);
	m_textMin14->GetValue().ToULong((unsigned long*)&tourData.min);
	table.UpdateRow(3, tourData);

	table.GetRow(4, tourData);
	m_textMax18->GetValue().ToULong((unsigned long*)&tourData.max);
	m_textMin18->GetValue().ToULong((unsigned long*)&tourData.min);
	table.UpdateRow(4, tourData);

	table.GetRow(5, tourData);
	m_textMax116->GetValue().ToULong((unsigned long*)&tourData.max);
	m_textMin116->GetValue().ToULong((unsigned long*)&tourData.min);
	table.UpdateRow(5, tourData);

	table.GetRow(6, tourData);
	m_textMax132->GetValue().ToULong((unsigned long*)&tourData.max);
	m_textMin132->GetValue().ToULong((unsigned long*)&tourData.min);
	table.UpdateRow(6, tourData);

	table.GetRow(7, tourData);
	m_textMax164->GetValue().ToULong((unsigned long*)&tourData.max);
	m_textMin164->GetValue().ToULong((unsigned long*)&tourData.min);
	table.UpdateRow(7, tourData);

	EndModal(wxID_OK);
}

void udfSettings::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfSettings::Refresh()
{
	wxConfig* pConf = udfSettingsBase::Instance()->GetConfig();

	m_textServer->SetValue(pConf->Read("host", "localhost:3306"));
	m_textDatabase->SetValue(pConf->Read("db", "udf"));
	m_textUser->SetValue(pConf->Read("user", "andrian"));
	m_textPass->SetValue(pConf->Read("pass", "testpass"));

	CTourTypesTable::tDATA tourData = {0};
	CTourTypesTable table(m_pCon);

	table.GetRow(1, tourData);
	m_textMaxFinal->SetValue(wxString::Format(_("%d"), tourData.max));
	m_textMinFinal->SetValue(wxString::Format(_("%d"), tourData.min));
	__info("Final: id=%d, min=%d, max=%d", tourData.id, tourData.min, tourData.max);

	table.GetRow(2, tourData);
	m_textMax12->SetValue(wxString::Format(_("%d"), tourData.max));
	m_textMin12->SetValue(wxString::Format(_("%d"), tourData.min));

	table.GetRow(3, tourData);
	m_textMax14->SetValue(wxString::Format(_("%d"), tourData.max));
	m_textMin14->SetValue(wxString::Format(_("%d"), tourData.min));

	table.GetRow(4, tourData);
	m_textMax18->SetValue(wxString::Format(_("%d"), tourData.max));
	m_textMin18->SetValue(wxString::Format(_("%d"), tourData.min));

	table.GetRow(5, tourData);
	m_textMax116->SetValue(wxString::Format(_("%d"), tourData.max));
	m_textMin116->SetValue(wxString::Format(_("%d"), tourData.min));

	table.GetRow(6, tourData);
	m_textMax132->SetValue(wxString::Format(_("%d"), tourData.max));
	m_textMin132->SetValue(wxString::Format(_("%d"), tourData.min));

	table.GetRow(7, tourData);
	m_textMax164->SetValue(wxString::Format(_("%d"), tourData.max));
	m_textMin164->SetValue(wxString::Format(_("%d"), tourData.min));

}

