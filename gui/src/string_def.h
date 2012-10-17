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
STR_DEFINITION(STR_EMPTY, "");

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

STR_DEFINITION(STR_ERR_ADD_TEAM_FAILED, "Team could not be added.");
STR_DEFINITION(STR_ERR_UPD_TEAM_FAILED, "Team could not be updated.");
STR_DEFINITION(STR_ERR_DEL_TEAM_FAILED, "Team could not be removed.");

STR_DEFINITION(STR_ERR_ADD_CHAMPIONSHIP_TOUR_FAILED, "Championship tour could not be added.");
STR_DEFINITION(STR_ERR_UPD_CHAMPIONSHIP_TOUR_FAILED, "Championship tour could not be updated.");
STR_DEFINITION(STR_ERR_DEL_CHAMPIONSHIP_TOUR_FAILED, "Championship tour could not be removed.");

////////////////////////////////////////////////////////////////////////////////////
STR_DEFINITION(STR_WARN_ALREADY_PRESENT, "This item is already inserted.");

STR_DEFINITION(STR_WARN_DATE_INTHEPAST, "Could not be modified during championship or after it.");

STR_DEFINITION(STR_WARN_NOW_GREATTHEN_ChDATE, "Championship date must be great then today.");
STR_DEFINITION(STR_WARN_REGCLOSE_GREATTHEN_ChDATE, "Championship date must be lower then reg close date.");
STR_DEFINITION(STR_WARN_REGOPEN_GREATTHEN_REGCLOSE, "Championship reg open date must be lower then reg close date.");
STR_DEFINITION(STR_WARN_PAY_GREATTHEN_EXP, "Pay date is greater then expire date.");
STR_DEFINITION(STR_WARN_REMOVE_ALL_TEAM_DANCERS, "If you change the club. All team dencers will be removed. \n\nRemove them all?");

STR_DEFINITION(STR_WARNING_CS_ALREADY_HAS_FINAL, "Selected championship already has final tour.");

STR_DEFINITION(STR_FORMAT_SUM, "%.02f");
STR_DEFINITION(STR_FORMAT_DATE, "%Y-%B-%d");
STR_DEFINITION(STR_FORMAT_TEAM_CATEGORY_NAME, "%s (%s)");
STR_DEFINITION(STR_FORMAT_START_NUMBER, "%05ld");
STR_DEFINITION(STR_FORMAT_TOUR_NAME, "%s (%d)");
STR_DEFINITION(STR_FORMAT_CAT_NAME, "%s, %s, %s");
STR_DEFINITION(STR_FORMAT_CAT_SNAME, "%1d%1d%02d");

/***********************************************************************************/
STR_DEFINITION(STR_HTML_BEGIN, "\
<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\"> \
<html xmlns=\"http://www.w3.org/1999/xhtml\" ><head> \
<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\"><title></title></head><body>");
STR_DEFINITION(STR_HTML_END, "</boby></html>");
STR_DEFINITION(STR_HTML_REPORT_BR, "<br />");
STR_DEFINITION(STR_HTML_TABLE_BEGIN, "<table width=\"100%\" cellspacing=\"0\" cellpadding=\"10\" border=\"0\">");
STR_DEFINITION(STR_HTML_TABLE_END, "</table>");

STR_DEFINITION(STR_FORMAT_HTML_TABLE_COL, "<td style=\"border:1px solid black;\">%s</td>");
STR_DEFINITION(STR_FORMAT_HTML_TABLE_HDR, "<th width=\"1px\" style=\"text-align:left; border:1px solid black;\">%s</th>");
STR_DEFINITION(STR_FORMAT_HTML_TABLE_ROW, "<tr>%s</tr>");
STR_DEFINITION(STR_FORMAT_HTML_REPORT_TITLE, "<tr><td colspan=\"2\">%s</td></tr> <tr><td width=\"1px\">%s</td><td>%s</td></tr> <tr><td width=\"1px\">%s</td><td>%s</td></tr>");

STR_DEFINITION(STR_FORMAT_REPORT_JUDGE_SHORTCUT, "%c - %s; ");
STR_DEFINITION(STR_REPORT_START_NUMBER, "Start number");
STR_DEFINITION(STR_REPORT_TEAM, "Team");
STR_DEFINITION(STR_REPORT_SUM, "Sum");
STR_DEFINITION(STR_REPORT_REPORT, "Report");
STR_DEFINITION(STR_REPORT_TOUR, "Tour");
STR_DEFINITION(STR_REPORT_CHAMPIONSHIP, "Championship");

STR_DEFINITION(STR_FORMAT_REPORT_PREVIEW_CMD, "xdg-open %s");

/**********************************************************************************/

STR_DEFINITION(STR_PAY_DATE, "Pay date");
STR_DEFINITION(STR_EXP_DATE, "Expire on");
STR_DEFINITION(STR_SUM, "Sum");

STR_DEFINITION(STR_FREE, "Free");

STR_DEFINITION(STR_ERR_INVALID_SUM, "Invalid sum value. Please correct.");

/**********************************************************************************/

STR_DEFINITION(STR_INCORRECT_VALUE, "Incorrect value");
STR_DEFINITION(STR_NOT_IN_DB_INSERT, "Selected '%s' not present in database. Insert it?");
STR_DEFINITION(STR_NOT_IN_DB, "Selected '%s' not present in database.");
STR_DEFINITION(STR_CITY, "city");
STR_DEFINITION(STR_COUNTRY, "country");
STR_DEFINITION(STR_CATEGORY, "category");
STR_DEFINITION(STR_DANCER, "dancer");
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
