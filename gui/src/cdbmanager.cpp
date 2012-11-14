#include "cdbmanager.h"

#include "wx/config.h"
#include "udfsettingsbase.h"
#include "dbutils.h"

CDbManager* CDbManager::ms_instance = 0;

CDbManager::CDbManager()
: m_pCon(NULL)
, m_ok(false)
{
	wxConfig* pConf = udfSettingsBase::Instance()->GetConfig();

	wxString url = pConf->Read("host", "localhost:3306");
	wxString user = pConf->Read("user", "andrian");
	wxString pass = pConf->Read("pass", "testpass");
	wxString schema = pConf->Read("db", "udf");

	Open(url.ToStdString(), schema.ToStdString(), user.ToStdString(), pass.ToStdString());
}

CDbManager::~CDbManager()
{
	if(m_pCon)
	{
		delete m_pCon;
		m_pCon = NULL;
	}
}

bool CDbManager::IsOk()
{
	return m_ok;
}

bool CDbManager::Open(std::string host, std::string db, std::string user, std::string pass)
{
	CDbConnection* pCon = new CDbConnection();
	if(UDF_OK == pCon->Open( host, user, pass, db))
	{
		m_pCon = pCon;
		SetGlobalDbConnection(m_pCon);
		m_ok = true;
	}

	return m_ok;
}

CDbManager* CDbManager::Instance()
{
	if(ms_instance == 0)
	{
		ms_instance = new CDbManager();
	}
	return ms_instance;
}

void CDbManager::Release()
{
	if(ms_instance)
	{
		delete ms_instance;
	}
	ms_instance = 0;
}

