#include "cdbmanager.h"

#include "wx/config.h"
#include "udfsettingsbase.h"

CDbManager* CDbManager::ms_instance = 0;

CDbManager::CDbManager()
{
	wxConfig* pConf = udfSettingsBase::Instance()->GetConfig();

	wxString url = pConf->Read("host", "localhost:3306");
	wxString user = pConf->Read("user", "andrian");
	wxString pass = pConf->Read("pass", "testpass");
	wxString schema = pConf->Read("db", "udf");

	m_pCon = new CDbConnection();
	m_pCon->Open( url.ToStdString(), user.ToStdString(), pass.ToStdString(), schema.ToStdString() );
}

CDbManager::~CDbManager()
{
	if(m_pCon)
	{
		delete m_pCon;
		m_pCon = NULL;
	}
}

CDbManager* CDbManager::Instance()
{
	if(ms_instance == 0){
		ms_instance = new CDbManager();
	}
	return ms_instance;
}

void CDbManager::Release()
{
	if(ms_instance){
		delete ms_instance;
	}
	ms_instance = 0;
}

