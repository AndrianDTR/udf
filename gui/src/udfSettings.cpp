#include "udfSettings.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"



udfSettings::udfSettings( wxWindow* parent )
: Settings( parent )
, m_pCon(NULL)
, m_pConf(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	m_pConf = new wxConfig("udf");

	Refresh();
}

udfSettings::~udfSettings()
{
	if(m_pConf)
	{
		delete m_pConf;
		m_pConf = NULL;
	}
}

void udfSettings::OnSave( wxCommandEvent& event )
{
	m_pConf->Write("host", m_textServer->GetValue());
	m_pConf->Write("db",  m_textDatabase->GetValue());
	m_pConf->Write("user", m_textUser->GetValue());
	m_pConf->Write("pass", m_textPass->GetValue());

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
	do
	{
		/*
		 * 1. Read connection data
		 * 2. Read tour type data
		 */
		if(!m_pConf)
			break;

		m_textServer->SetValue(m_pConf->Read("host", "localhost:3306"));
		m_textDatabase->SetValue(m_pConf->Read("db", "udf"));
		m_textUser->SetValue(m_pConf->Read("user", "andrian"));
		m_textPass->SetValue(m_pConf->Read("pass", "testpass"));

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

	}while(0);
}

