#include "udfsettingsbase.h"


udfSettingsBase* udfSettingsBase::m_pInstance = NULL;

udfSettingsBase::udfSettingsBase()
{
	m_pCfg = new wxConfig("udf");
}

udfSettingsBase::~udfSettingsBase()
{
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

wxConfig* udfSettingsBase::GetConfig() const
{
	return m_pCfg;
}
