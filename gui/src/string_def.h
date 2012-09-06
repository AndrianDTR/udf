#ifndef __udf_string_def_h__
#define __udf_string_def_h__

#include "wx/string.h"
#include "wx/intl.h"

/****************************************************
 * String definitions
 ****************************************************/ 

//MACRO constant declaration
#define STR_DEFINITION(x,y)		const wxString x = _( y )


//Constant definitions
STR_DEFINITION(STR_ERROR, "Error");
STR_DEFINITION(STR_WARNING, "Warning");

STR_DEFINITION(STR_ERR_ADD_COUNTRY_FAILED, "Country could not be added.");
STR_DEFINITION(STR_ERR_UPD_COUNTRY_FAILED, "Country could not be updated.");
STR_DEFINITION(STR_ERR_DEL_COUNTRY_FAILED, "Country could not be removed.");

STR_DEFINITION(STR_ERR_ADD_CITY_FAILED, "City could not be added.");
STR_DEFINITION(STR_ERR_UPD_CITY_FAILED, "City could not be updated.");
STR_DEFINITION(STR_ERR_DEL_CITY_FAILED, "City could not be removed.");

STR_DEFINITION(STR_ERR_ADD_LIGUE_FAILED, "Ligue could not be added.");
STR_DEFINITION(STR_ERR_UPD_LIGUE_FAILED, "Ligue could not be updated.");
STR_DEFINITION(STR_ERR_DEL_LIGUE_FAILED, "Ligue could not be removed.");

STR_DEFINITION(STR_ERR_ADD_DANCETYPE_FAILED, "Dance type could not be added.");
STR_DEFINITION(STR_ERR_UPD_DANCETYPE_FAILED, "Dance type could not be updated.");
STR_DEFINITION(STR_ERR_DEL_DANCETYPE_FAILED, "Dance type could not be removed.");

STR_DEFINITION(STR_ERR_ADD_AGECAT_FAILED, "Age category could not be added.");
STR_DEFINITION(STR_ERR_UPD_AGECAT_FAILED, "Age category could not be updated.");
STR_DEFINITION(STR_ERR_DEL_AGECAT_FAILED, "Age category could not be removed.");

STR_DEFINITION(STR_ERR_ADD_CAT_FAILED, "Category could not be added.");
STR_DEFINITION(STR_ERR_UPD_CAT_FAILED, "Category could not be updated.");
STR_DEFINITION(STR_ERR_DEL_CAT_FAILED, "Category could not be removed.");

STR_DEFINITION(STR_ERR_ADD_ChTYPE_FAILED, "Championship type could not be added.");
STR_DEFINITION(STR_ERR_UPD_ChTYPE_FAILED, "Championship type could not be updated.");
STR_DEFINITION(STR_ERR_DEL_ChTYPE_FAILED, "Championship type could not be removed.");

STR_DEFINITION(STR_ERR_ADD_CHAMPIONSHIP_FAILED, "Championship could not be added.");
STR_DEFINITION(STR_ERR_UPD_CHAMPIONSHIP_FAILED, "Championship could not be updated.");
STR_DEFINITION(STR_ERR_DEL_CHAMPIONSHIP_FAILED, "Championship could not be removed.");

STR_DEFINITION(STR_ERR_ADD_CLUB_FAILED, "Club could not be added.");
STR_DEFINITION(STR_ERR_UPD_CLUB_FAILED, "Club could not be updated.");
STR_DEFINITION(STR_ERR_DEL_CLUB_FAILED, "Club could not be removed.");

STR_DEFINITION(STR_ERR_ADD_JUDGE_FAILED, "Judge could not be added.");
STR_DEFINITION(STR_ERR_UPD_JUDGE_FAILED, "Judge could not be updated.");
STR_DEFINITION(STR_ERR_DEL_JUDGE_FAILED, "Judge could not be removed.");

////////////////////////////////////////////////////////////////////////////////////
STR_DEFINITION(STR_WARN_DATE_INTHEPAST, "Could not be modified during championship or after it.");

STR_DEFINITION(STR_WARN_NOW_GREATTHEN_ChDATE, "Championship date must be great then today.");
STR_DEFINITION(STR_WARN_REGCLOSE_GREATTHEN_ChDATE, "Championship date must be lower then reg close date.");
STR_DEFINITION(STR_WARN_REGOPEN_GREATTHEN_REGCLOSE, "Championship reg open date must be lower then reg close date.");
STR_DEFINITION(STR_WARN_PAY_GREATTHEN_EXP, "Pay date is greater then expire date.");

STR_DEFINITION(STR_FORMAT_DATE, "%04d-%02d-%02d");
STR_DEFINITION(STR_INCORRECT_VALUE, "Incorrect value");
STR_DEFINITION(STR_NOT_IN_DB_INSERT, "Selected '%s' not present in database. Insert it?");
STR_DEFINITION(STR_NOT_IN_DB, "Selected '%s' not present in database.");
STR_DEFINITION(STR_CITY, "city");
STR_DEFINITION(STR_COUNTRY, "country");
STR_DEFINITION(STR_AGE_CATEGORY, "age category");
STR_DEFINITION(STR_DANCE_TYPE, "dance type");
STR_DEFINITION(STR_LIGUE, "ligue");
STR_DEFINITION(STR_CLUB, "club");
STR_DEFINITION(STR_TRAINER, "trainer");
STR_DEFINITION(STR_GENDER, "gender");
STR_DEFINITION(STR_CHAMPIONSHIP_TYPE, "championship type");
STR_DEFINITION(STR_FORMAT_CITY_NAME, "%s, %s");
STR_DEFINITION(STR_FORMAT_CLUB_NAME, "%s, %s, %s");
STR_DEFINITION(STR_AGE_CATEGORY_CODE_MNGR, "Age category code manager");
STR_DEFINITION(STR_AGE_CATEGORY_CODE_LIST, "Age categories list");
STR_DEFINITION(STR_DANCE_TYPES_CODE_MNGR, "Age category code manager");
STR_DEFINITION(STR_DANCE_TYPES_CODE_LIST, "Age categories list");
STR_DEFINITION(STR_LIGUES_CODE_MNGR, "Age category code manager");
STR_DEFINITION(STR_LIGUES_CODE_LIST, "Age categories list");



#endif //__udf_string_def_h__