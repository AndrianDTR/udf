#include "udfsettingsbase.h"

#include "udfcommon.h"

udfSettingsBase* udfSettingsBase::m_pInstance = NULL;

udfSettingsBase::udfSettingsBase()
{
	m_pCfg = wxConfig::Get();
	
	ReadConfig();
}

udfSettingsBase::~udfSettingsBase()
{
	WriteConfig();
	
	if(m_pCfg)
	{
		delete m_pCfg;
		m_pCfg = NULL;
	}
}

udfSettingsBase* udfSettingsBase::Instance()
{
	if(m_pInstance == NULL)
	{
		m_pInstance = new udfSettingsBase();
	}
	return m_pInstance;
}

void udfSettingsBase::Release()
{
	if(m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

wxConfigBase* udfSettingsBase::GetConfig() const
{
	return m_pCfg;
}

void udfSettingsBase::ReadConfig()
{
	m_szHost = m_pCfg->Read("host", "localhost:3306");
	m_szUser = m_pCfg->Read("user", "andrian");
	m_szPass = m_pCfg->Read("pass", "testpass");
	m_szSchema = m_pCfg->Read("db", "udf");
	
	m_nBlockInfoScale = m_pCfg->Read("blockInfoScale", 100l);
	m_nTourInfoScale = m_pCfg->Read("tourInfoScale", 100l);
	m_nFinalMarksScale = m_pCfg->Read("finalMarksScale", 100l);
	m_nJudgeMarksScale = m_pCfg->Read("judgeMarksScale", 100l);
}

void udfSettingsBase::WriteConfig()
{
	__msg("WRITE CONFIG");
	
	m_pCfg->Write("host", m_szHost);
	m_pCfg->Write("user", m_szUser);
	m_pCfg->Write("pass", m_szPass);
	m_pCfg->Write("db", m_szSchema);
	
	m_pCfg->Write("blockInfoScale", m_nBlockInfoScale);
	m_pCfg->Write("tourInfoScale", m_nTourInfoScale);
	m_pCfg->Write("finalMarksScale", m_nFinalMarksScale);
	m_pCfg->Write("judgeMarksScale", m_nJudgeMarksScale);
}
