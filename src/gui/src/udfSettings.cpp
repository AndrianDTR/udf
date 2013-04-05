#include "udfSettings.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

#include "udfsettingsbase.h"

udfSettings::udfSettings( wxWindow* parent )
: Settings( parent )
, m_pCon(NULL)
{
	if(parent)
	{
		m_pCon = CDbManager::Instance()->GetConnection();
	}
	
	Refresh();
}

udfSettings::~udfSettings()
{

}

void udfSettings::OnSave( wxCommandEvent& event )
{
	udfSettingsBase* pConf = udfSettingsBase::Instance();

	pConf->SetHost(m_textServer->GetValue());
	pConf->SetSchema(m_textDatabase->GetValue());
	pConf->SetUser(m_textUser->GetValue());
	pConf->SetPass(m_textPass->GetValue());
	pConf->WriteConfig();

	CDbManager::Instance()->Release();
	CDbManager::Instance();

	unsigned long min = 0;
	unsigned long max = 0;

	CTourTypesTable::tDATA tourData = {0};
	CTourTypesTable table(m_pCon);

	m_textMaxFinal->GetValue().ToULong(&max);
	m_textMinFinal->GetValue().ToULong(&min);
	tourData.max = max;
	tourData.min = min;
	table.UpdateRow(1, tourData);

	table.GetRow(2, tourData);
	m_textMax12->GetValue().ToULong(&max);
	m_textMin12->GetValue().ToULong(&min);
	tourData.max = max;
	tourData.min = min;
	table.UpdateRow(2, tourData);

	table.GetRow(3, tourData);
	m_textMax14->GetValue().ToULong(&max);
	m_textMin14->GetValue().ToULong(&min);
	tourData.max = max;
	tourData.min = min;
	table.UpdateRow(3, tourData);

	table.GetRow(4, tourData);
	m_textMax18->GetValue().ToULong(&max);
	m_textMin18->GetValue().ToULong(&min);
	tourData.max = max;
	tourData.min = min;
	table.UpdateRow(4, tourData);

	table.GetRow(5, tourData);
	m_textMax116->GetValue().ToULong(&max);
	m_textMin116->GetValue().ToULong(&min);
	tourData.max = max;
	tourData.min = min;
	table.UpdateRow(5, tourData);

	table.GetRow(6, tourData);
	m_textMax132->GetValue().ToULong(&max);
	m_textMin132->GetValue().ToULong(&min);
	tourData.max = max;
	tourData.min = min;
	table.UpdateRow(6, tourData);

	table.GetRow(7, tourData);
	m_textMax164->GetValue().ToULong(&max);
	m_textMin164->GetValue().ToULong(&min);
	tourData.max = max;
	tourData.min = min;
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
		udfSettingsBase* pConf = udfSettingsBase::Instance();

		m_textServer->SetValue(pConf->GetHost());
		m_textDatabase->SetValue(pConf->GetSchema());
		m_textUser->SetValue(pConf->GetUser());
		m_textPass->SetValue(pConf->GetPass());

		if(!m_pCon)
		{
			m_panel5->Hide();
			break;
		}
		else
		{
			m_panel5->Show();
		}

		CTourTypesTable::tDATA tourData = {0};
		CTourTypesTable table(m_pCon);

		table.GetRow(1, tourData);
		m_textMaxFinal->SetValue(STR_FORMAT(_("%d"), tourData.max));
		m_textMinFinal->SetValue(STR_FORMAT(_("%d"), tourData.min));

		table.GetRow(2, tourData);
		m_textMax12->SetValue(STR_FORMAT(_("%d"), tourData.max));
		m_textMin12->SetValue(STR_FORMAT(_("%d"), tourData.min));

		table.GetRow(3, tourData);
		m_textMax14->SetValue(STR_FORMAT(_("%d"), tourData.max));
		m_textMin14->SetValue(STR_FORMAT(_("%d"), tourData.min));

		table.GetRow(4, tourData);
		m_textMax18->SetValue(STR_FORMAT(_("%d"), tourData.max));
		m_textMin18->SetValue(STR_FORMAT(_("%d"), tourData.min));

		table.GetRow(5, tourData);
		m_textMax116->SetValue(STR_FORMAT(_("%d"), tourData.max));
		m_textMin116->SetValue(STR_FORMAT(_("%d"), tourData.min));

		table.GetRow(6, tourData);
		m_textMax132->SetValue(STR_FORMAT(_("%d"), tourData.max));
		m_textMin132->SetValue(STR_FORMAT(_("%d"), tourData.min));

		table.GetRow(7, tourData);
		m_textMax164->SetValue(STR_FORMAT(_("%d"), tourData.max));
		m_textMin164->SetValue(STR_FORMAT(_("%d"), tourData.min));
	}while(0);
}

void udfSettings::OnTest(wxCommandEvent& event)
{
	long res = UDF_E_FAIL;
	CTourTypesTable::tTableMap data;
	
	m_textTest->SetValue(_("Connecting..."));
	
	try
	{
		CDbConnection* pCon = new CDbConnection();
		pCon->Open( m_textServer->GetValue().ToStdString()
			, m_textUser->GetValue().ToStdString()
			, m_textPass->GetValue().ToStdString()
			, m_textDatabase->GetValue().ToStdString()
		);

		
		res = CTourTypesTable(pCon).GetTable(data);
	}
	catch(...)
	{
		
	}
	
	if(UDF_OK == res && data.size())
	{
		m_textTest->SetValue(_("Connected successfully."));
	}
	else
	{
		m_textTest->SetValue(_("Connection failed."));
	}
}