///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __noname__
#define __noname__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/listbox.h>
#include <wx/statbox.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/treectrl.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/checkbox.h>
#include <wx/html/htmlwin.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DancersTeamMngr
///////////////////////////////////////////////////////////////////////////////
class DancersTeamMngr : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText15;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listTeams;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpApply;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText89;
		wxComboBox* m_comboClub;
		wxComboBox* m_comboCsCategories;
		wxListBox* m_listTeamCategories;
		wxBitmapButton* m_bpAddDancerTeamCategory;
		wxBitmapButton* m_bpRemoveDancerTeamCategory;
		wxComboBox* m_comboDancers;
		wxListBox* m_listDancers;
		wxBitmapButton* m_bpAddDancerTeamDancer;
		wxBitmapButton* m_bpRemoveDancerTeamDancer;
	
	public:
		
		DancersTeamMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Dancers team"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 775,485 ), long style = wxDEFAULT_DIALOG_STYLE );
		~DancersTeamMngr();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChampionshipCategoriesMngrDlg
///////////////////////////////////////////////////////////////////////////////
class ChampionshipCategoriesMngrDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText8;
		wxListBox* m_listAll;
		wxListCtrl* m_listAllCategories;
		wxBitmapButton* m_bpAddAll;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpRemoveAll;
		wxStaticText* m_staticText9;
		wxListBox* m_listSelected;
		wxListCtrl* m_listSelectedCategories;
		wxBitmapButton* m_bpButton31;
		wxBitmapButton* m_bpButton32;
	
	public:
		
		ChampionshipCategoriesMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Championship categories management"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 815,396 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU );
		~ChampionshipCategoriesMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CategoriesMngrDlg
///////////////////////////////////////////////////////////////////////////////
class CategoriesMngrDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText15;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listCategories;
		wxBitmapButton* m_bpButton13;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpUpdate;
		wxBitmapButton* m_bpButton29;
		wxBitmapButton* m_bpDiscard;
		wxStaticText* m_staticText191;
		wxComboBox* m_comboAge;
		wxStaticText* m_staticText19;
		wxComboBox* m_comboLiga;
		wxStaticText* m_staticText18;
		wxComboBox* m_comboDance;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_textShortName;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textName;
	
	public:
		
		CategoriesMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Categories manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 715,284 ), long style = wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU );
		~CategoriesMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ClubsMngrDlg
///////////////////////////////////////////////////////////////////////////////
class ClubsMngrDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText20;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listClubs;
		wxBitmapButton* m_bpAddClub;
		wxBitmapButton* m_bpUpdate;
		wxBitmapButton* m_bpRemoveClub;
		wxBitmapButton* m_bpAccountInfo;
		wxBitmapButton* m_bpDirectorInfo;
		wxBitmapButton* m_bpTarinersMngr;
		wxBitmapButton* m_bpDancersMngr;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpCancel;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText22;
		wxComboBox* m_comboCity;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textAddress;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_textEmail;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_textWeb;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_textInfo;
	
	public:
		
		ClubsMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Clubs manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 941,658 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ClubsMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Payment
///////////////////////////////////////////////////////////////////////////////
class Payment : public wxDialog 
{
	private:
	
	protected:
		wxButton* m_buttonPaymentAdd;
		wxButton* m_buttonPaymentEdit;
		wxButton* m_buttonPaymentRemove;
		wxListCtrl* m_listPayments;
		wxBitmapButton* m_bpButton116;
		wxBitmapButton* m_bpButton117;
	
	public:
		
		Payment( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Payment info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 765,279 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Payment();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menuBar;
		wxMenu* m_menuFile;
		wxMenu* m_menu8;
		wxMenu* m_menu2;
		wxMenu* m_menu5;
		wxMenu* m_menu51;
		wxPanel* m_panel1;
		wxStaticText* m_championshipSearchText;
		wxTextCtrl* m_textSearch;
		wxTreeCtrl* m_treeCs;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		wxBitmapButton* m_bpCategoryMngr;
		wxBitmapButton* m_bpJudgesMngr;
		wxBitmapButton* m_bpSendinvitation;
		wxBitmapButton* m_bpDancersTeams;
		wxBitmapButton* m_bpStartNumberMngr;
		wxBitmapButton* m_bpTourAdd;
		wxBitmapButton* m_bpTourEdit;
		wxBitmapButton* m_bpTourRemove;
		wxBitmapButton* m_bpJudgesMark;
		wxBitmapButton* m_bpTourReport;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textChName;
		wxStaticText* m_staticText2;
		wxComboBox* m_comboType;
		wxStaticText* m_staticText5;
		wxDatePickerCtrl* m_dateDate;
		wxStaticText* m_staticText7;
		wxComboBox* m_comboCity;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_textAddress;
		wxStaticText* m_staticText12;
		wxDatePickerCtrl* m_dateRegOpen;
		wxStaticText* m_staticText13;
		wxDatePickerCtrl* m_dateRegClose;
		wxStaticText* m_staticText14;
		wxTextCtrl* m_textAdditionalInfo;
	
	public:
		
		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Championship calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 983,667 ), long style = wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );
		~MainFrameBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DirectorInfo
///////////////////////////////////////////////////////////////////////////////
class DirectorInfo : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText29;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText30;
		wxDatePickerCtrl* m_dateBd;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_textPhone;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_textEmail;
		wxBitmapButton* m_bpButton25;
		wxBitmapButton* m_bpButton26;
	
	public:
		
		DirectorInfo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Director info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 459,230 ), long style = wxDEFAULT_DIALOG_STYLE );
		~DirectorInfo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TrainersMngrDlg
///////////////////////////////////////////////////////////////////////////////
class TrainersMngrDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText20;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listTrainers;
		wxBitmapButton* m_bpAddTrainer;
		wxBitmapButton* m_bpUpdate;
		wxBitmapButton* m_bpRemoveTrainer;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText22;
		wxComboBox* m_comboClub;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textPhone;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_textEmail;
		wxStaticText* m_staticText25;
		wxDatePickerCtrl* m_dateBd;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_textInfo;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* m_datePay;
		wxStaticText* m_staticText28;
		wxDatePickerCtrl* m_dateExp;
	
	public:
		
		TrainersMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Trainers"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 777,466 ), long style = wxDEFAULT_DIALOG_STYLE );
		~TrainersMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CsTours
///////////////////////////////////////////////////////////////////////////////
class CsTours : public wxDialog 
{
	private:
	
	protected:
		
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText22;
		wxTextCtrl* m_textLimit;
		
		wxCheckBox* m_checkFinal;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
	
	public:
		
		CsTours( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Championship tour"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 488,194 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CsTours();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CsTourReport
///////////////////////////////////////////////////////////////////////////////
class CsTourReport : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText94;
		
		wxBitmapButton* m_bpPrint;
		wxBitmapButton* m_bpDiscard;
		wxListCtrl* m_listTeams;
		wxBitmapButton* m_bpMoveUp10;
		wxBitmapButton* m_bpMoveUp;
		wxBitmapButton* m_bpMoveDown;
		wxBitmapButton* m_bpMoveDown10;
		wxStaticText* m_staticJudgeDescr;
	
	public:
		
		CsTourReport( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Championship tour report"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,700 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CsTourReport();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DancersMngrDlg
///////////////////////////////////////////////////////////////////////////////
class DancersMngrDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText78;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listDancers;
		wxBitmapButton* m_bpAddDancer;
		wxBitmapButton* m_bpRemoveDancer;
		wxBitmapButton* m_bpUpdate;
		wxBitmapButton* m_bpOk;
		wxBitmapButton* m_bpDiscard;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textRegbook;
		wxStaticText* m_staticText54;
		wxStaticText* m_staticRaiting;
		wxStaticText* m_staticText22;
		wxComboBox* m_comboClub;
		wxStaticText* m_staticText61;
		wxComboBox* m_comboTrainer;
		wxStaticText* m_staticText63;
		wxComboBox* m_comboLiga;
		wxStaticText* m_staticText24;
		wxComboBox* m_comboGender;
		wxStaticText* m_staticText25;
		wxDatePickerCtrl* m_dateBd;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_textInfo;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* m_datePay;
		wxStaticText* m_staticText28;
		wxDatePickerCtrl* m_dateExp;
		wxStaticText* m_staticText62;
		wxTextCtrl* m_textReg;
	
	public:
		
		DancersMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Dancers"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 964,634 ), long style = wxDEFAULT_DIALOG_STYLE );
		~DancersMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AccountInfo
///////////////////////////////////////////////////////////////////////////////
class AccountInfo : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText56;
		wxTextCtrl* m_textLogin;
		wxStaticText* m_staticText57;
		wxTextCtrl* m_textPass;
		
		wxCheckBox* m_checkShowPass;
		wxBitmapButton* m_bpButton39;
		wxBitmapButton* m_bpButton40;
	
	public:
		
		AccountInfo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Account info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 384,185 ), long style = wxCAPTION|wxCLOSE_BOX|wxSTAY_ON_TOP );
		~AccountInfo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddTeamCategory
///////////////////////////////////////////////////////////////////////////////
class AddTeamCategory : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText56;
		wxStaticText* m_staticCategory;
		wxStaticText* m_staticText57;
		wxTextCtrl* m_textComposition;
		wxBitmapButton* m_bpButton39;
		wxBitmapButton* m_bpButton40;
	
	public:
		
		AddTeamCategory( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add team categort"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 384,163 ), long style = wxCAPTION|wxCLOSE_BOX|wxSTAY_ON_TOP );
		~AddTeamCategory();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class JudgesMngr
///////////////////////////////////////////////////////////////////////////////
class JudgesMngr : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText20;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listJudges;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpApply;
		wxBitmapButton* m_bpButton19;
		wxBitmapButton* m_bpButton20;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText77;
		wxComboBox* m_comboCity;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textAttestation;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_textEmail;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_textPhone;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_textInfo;
		
		wxCheckBox* m_checkPracticer;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* m_datePay;
		wxStaticText* m_staticText28;
		wxDatePickerCtrl* m_dateExp;
	
	public:
		
		JudgesMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Judges manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 862,483 ), long style = wxDEFAULT_DIALOG_STYLE );
		~JudgesMngr();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChampionshipJudgesTeamMngrDlg
///////////////////////////////////////////////////////////////////////////////
class ChampionshipJudgesTeamMngrDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText8;
		wxListBox* m_listAll;
		wxBitmapButton* m_bpAddAll;
		wxBitmapButton* m_bpAddOne;
		wxBitmapButton* m_bpRemoveOne;
		wxBitmapButton* m_bpRemoveAll;
		wxStaticText* m_staticText9;
		wxListBox* m_listSelected;
		wxBitmapButton* m_bpButton31;
		wxBitmapButton* m_bpButton32;
	
	public:
		
		ChampionshipJudgesTeamMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Championship judges team manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 546,316 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ChampionshipJudgesTeamMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class StartNumberAssignDlg
///////////////////////////////////////////////////////////////////////////////
class StartNumberAssignDlg : public wxDialog 
{
	private:
	
	protected:
		wxListBox* m_listTeams;
		wxStaticText* m_staticText85;
		wxTextCtrl* m_textSearch;
		wxTextCtrl* m_textNumber;
		wxBitmapButton* m_bpRandomNumber;
		wxBitmapButton* m_bpNextNumber;
		wxBitmapButton* m_bpAssign;
		
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
	
	public:
		
		StartNumberAssignDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 816,356 ), long style = wxDEFAULT_DIALOG_STYLE );
		~StartNumberAssignDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class JudgeMark
///////////////////////////////////////////////////////////////////////////////
class JudgeMark : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText92;
		wxComboBox* m_comboJudge;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		wxListBox* m_listNumbers;
		wxCheckBox* m_checkShowAll;
		wxStaticText* m_staticText85;
		wxTextCtrl* m_textSearch;
		wxPanel* m_panelPlus;
		wxBitmapButton* m_bpGood;
		wxPanel* m_panelMinus;
		wxBitmapButton* m_bpBed;
		
	
	public:
		
		JudgeMark( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Judge marks"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 816,356 ), long style = wxDEFAULT_DIALOG_STYLE );
		~JudgeMark();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CodeDialog
///////////////////////////////////////////////////////////////////////////////
class CodeDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText84;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listItems;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpAplly;
		wxBitmapButton* m_bpButton81;
		wxBitmapButton* m_bpButton82;
		
		wxStaticText* m_staticText82;
		wxTextCtrl* m_textCode;
		wxStaticText* m_staticText83;
		wxTextCtrl* m_textName;
		
	
	public:
		
		CodeDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Code"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 550,322 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CodeDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CountriesMngr
///////////////////////////////////////////////////////////////////////////////
class CountriesMngr : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText84;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listItems;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpAplly;
		wxBitmapButton* m_bpButton81;
		wxBitmapButton* m_bpButton82;
		
		wxStaticText* m_staticText83;
		wxTextCtrl* m_textName;
		
	
	public:
		
		CountriesMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Countries manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 550,239 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CountriesMngr();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChampionshipTypeMngr
///////////////////////////////////////////////////////////////////////////////
class ChampionshipTypeMngr : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText84;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listItems;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpAplly;
		wxBitmapButton* m_bpButton81;
		wxBitmapButton* m_bpButton82;
		
		wxStaticText* m_staticText83;
		wxTextCtrl* m_textName;
		
	
	public:
		
		ChampionshipTypeMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Championship types manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 550,239 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ChampionshipTypeMngr();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TeamCategoryMngrDlg
///////////////////////////////////////////////////////////////////////////////
class TeamCategoryMngrDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText8;
		wxListBox* m_listBox2;
		wxBitmapButton* m_bpButton9;
		wxBitmapButton* m_bpButton10;
		wxBitmapButton* m_bpButton11;
		wxBitmapButton* m_bpButton12;
		wxStaticText* m_staticText9;
		wxListBox* m_listBox3;
		wxBitmapButton* m_bpButton31;
		wxBitmapButton* m_bpButton32;
	
	public:
		
		TeamCategoryMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Team categories manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 546,317 ), long style = wxDEFAULT_DIALOG_STYLE );
		~TeamCategoryMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CitiesMngr
///////////////////////////////////////////////////////////////////////////////
class CitiesMngr : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText84;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listItems;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpAplly;
		wxBitmapButton* m_bpButton81;
		wxBitmapButton* m_bpButton82;
		
		wxStaticText* m_staticText82;
		wxComboBox* m_comboCounty;
		wxStaticText* m_staticText83;
		wxTextCtrl* m_textName;
		
	
	public:
		
		CitiesMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Cities manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 599,322 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CitiesMngr();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ReportPreview
///////////////////////////////////////////////////////////////////////////////
class ReportPreview : public wxDialog 
{
	private:
	
	protected:
		wxBitmapButton* m_bpPrint;
		wxBitmapButton* m_bpDiscard;
		wxHtmlWindow* m_htmlReport;
	
	public:
		
		ReportPreview( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Report preview"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 956,636 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ReportPreview();
	
};

#endif //__noname__
