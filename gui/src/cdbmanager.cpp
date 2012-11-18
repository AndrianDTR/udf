#include "cdbmanager.h"

#include "wx/config.h"
#include "udfsettingsbase.h"
#include "dbutils.h"

CDbManager* CDbManager::ms_instance = 0;

CDbManager::CDbManager()
: m_pCon(NULL)
, m_ok(false)
{
	udfSettingsBase* pConf = udfSettingsBase::Instance();
	
	Open( pConf->GetHost().ToStdString()
		, pConf->GetSchema().ToStdString()
		, pConf->GetUser().ToStdString()
		, pConf->GetPass().ToStdString()
	);
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

