#ifndef __uiutils_h__
#define __uiutils_h__

#include "wx/string.h"

wxString	GetVerticalText(wxString str);


wxString	GetClubNameById(unsigned int nId);
wxString	GetCityNameById(unsigned int nId);
wxString	GetDancerNameById(unsigned int nId);
wxString	GetJudgeNameById(unsigned int nId);
wxString	GetCsJudgeNameById(unsigned int nId);
wxString	GetTrainerNameById(unsigned int nId);
wxString	GetCategoryShortNameById(unsigned int nId);
wxString	GetCategoryNameById(unsigned int nId);
wxString	GetCsCategoryNameById(unsigned int nId);
wxString	GetTeamNameById(unsigned int nId);

void		GetTourTypeLimitsById(unsigned int nId, int& min, int& max);
int			GetJudgeMark(unsigned int nChId, unsigned int nChTourId, unsigned int nJudgeId, unsigned int nTeamId);
int			GetTourLimit(unsigned int nTourId);
int			GetAgeCodeById(unsigned int nAgeId);
std::string	GetAgeNameById(unsigned int nAgeId);
int			GetLigueCodeById(unsigned int nLigueId);
std::string	GetLigueNameById(unsigned int nLigueId);
int			GetDanceCodeById(unsigned int nDanceId);
std::string	GetDanceNameById(unsigned int nDanceId);

#endif // __uiutils_h__
