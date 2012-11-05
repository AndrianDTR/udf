#ifndef __UDFSETTINGSBASE_H__
#define __UDFSETTINGSBASE_H__

#include "wx/config.h"

class udfSettingsBase
{
private:
	/** Default constructor */
	udfSettingsBase();
	/** Default destructor */
	virtual ~udfSettingsBase();

protected:
private:
	static udfSettingsBase* 	m_pInstance;
	wxConfig* 					m_pCfg;

public:
	static udfSettingsBase* Instance();
	static void				Release();

	wxConfig*				GetConfig() const;

};

#endif // __UDFSETTINGSBASE_H__
