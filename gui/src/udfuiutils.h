#ifndef __uiutils_h__
#define __uiutils_h__

#include "wx/string.h"

wxString	GetClubNameById(unsigned int nId);
wxString	GetCityNameById(unsigned int nId);
wxString	GetDancerNameById(unsigned int nId);
wxString	GetJudgeNameById(unsigned int nId);
wxString	GetTrainerNameById(unsigned int nId);
wxString	GetCategoryNameById(unsigned int nId);
wxString	GetTeamNameById(unsigned int nId);
int			GetJudgeMark(unsigned int nChId, unsigned int nChTourId, unsigned int nJudgeId, unsigned int nTeamId);
int			GetTourLimit(unsigned int nTourId);

#endif // __uiutils_h__
