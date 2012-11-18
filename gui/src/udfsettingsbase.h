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
	wxConfigBase* 				m_pCfg;
	
	long						m_nBlockInfoScale;
	long						m_nTourInfoScale;
	long						m_nJudgeMarksScale;
	long						m_nFinalMarksScale;
	
	wxString 					m_szHost;
	wxString 					m_szUser;
	wxString 					m_szPass;
	wxString 					m_szSchema;

public:
	static udfSettingsBase* 	Instance();
	static void					Release();

	wxConfigBase*				GetConfig() const;
	
	void						ReadConfig();
	void						WriteConfig();
	
	wxString					GetHost() const {return m_szHost;};
	void						SetHost(wxString val){m_szHost = val;};
	
	wxString					GetUser() const {return m_szUser;};
	void						SetUser(wxString val){m_szUser = val;};
	
	wxString					GetPass() const {return m_szPass;};
	void						SetPass(wxString val){m_szPass = val;};
	
	wxString					GetSchema() const {return m_szSchema;};
	void						SetSchema(wxString val){m_szSchema = val;};
	
	long						GetBlockInfoScale() const {return m_nBlockInfoScale;};
	void						SetBlockInfoScale(long val){m_nBlockInfoScale = val;};
	
	long						GetTourInfoScale() const {return m_nTourInfoScale;};
	void						SetTourInfoScale(long val){m_nTourInfoScale = val;};
	
	long						GetJudgeMarksScale() const {return m_nJudgeMarksScale;};
	void						SetJudgeMarksScale(long val){m_nJudgeMarksScale = val;};
	
	long						GetFinalMarksScale() const {return m_nFinalMarksScale;};
	void						SetFinalMarksScale(long val){m_nFinalMarksScale = val;};

};

#endif // __UDFSETTINGSBASE_H__
