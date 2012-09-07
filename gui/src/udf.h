///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __udf__
#define __udf__

#include <wx/intl.h>

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
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class DancersTeamMngr
///////////////////////////////////////////////////////////////////////////////
class DancersTeamMngr : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnSelectTeam( wxCommandEvent& event ){ OnSelectTeam( event ); }
		void _wxFB_OnAddDancerTeam( wxCommandEvent& event ){ OnAddDancerTeam( event ); }
		void _wxFB_OnRemoveTancerTeam( wxCommandEvent& event ){ OnRemoveTancerTeam( event ); }
		void _wxFB_OnUpdate( wxCommandEvent& event ){ OnUpdate( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		void _wxFB_OnClubChanged( wxCommandEvent& event ){ OnClubChanged( event ); }
		void _wxFB_OnSelectClub( wxCommandEvent& event ){ OnSelectClub( event ); }
		void _wxFB_OnAddDancerTeamCategory( wxCommandEvent& event ){ OnAddDancerTeamCategory( event ); }
		void _wxFB_OnRemoveDancerTeamCategory( wxCommandEvent& event ){ OnRemoveDancerTeamCategory( event ); }
		void _wxFB_OnAddDancer2Team( wxCommandEvent& event ){ OnAddDancer2Team( event ); }
		void _wxFB_OnRemoveDancerFromTeam( wxCommandEvent& event ){ OnRemoveDancerFromTeam( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_TEAM_LIST,
			ID_APPLY,
			ID_TEAM_NAME,
			ID_CLUB,
			ID_CATEGORIES_COMBO,
			ID_TEAM_CATS_LIST,
			wxID_ADDDANCERTEAMCATEGORY,
			wxID_REMOVEDANCERTEAMCATEGORY,
			ID_DANCERS_COMBO,
			ID_DANCERS_LIST,
			wxID_ADDDANCER,
			wxID_REMOVEDANCER,
		};
		
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectTeam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddDancerTeam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveTancerTeam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClubChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectClub( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddDancerTeamCategory( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveDancerTeamCategory( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddDancer2Team( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveDancerFromTeam( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DancersTeamMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Dancers team"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 775,453 ), long style = wxDEFAULT_DIALOG_STYLE );
		~DancersTeamMngr();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChampionshipCategoriesMngrDlg
///////////////////////////////////////////////////////////////////////////////
class ChampionshipCategoriesMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnAddAll( wxCommandEvent& event ){ OnAddAll( event ); }
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnRemoveAll( wxCommandEvent& event ){ OnRemoveAll( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_LIST_ALL = 1000,
			wxID_ADDALL,
			wxID_ADDONE,
			wxID_REMOVEONE,
			wxID_REMOVEALL,
			ID_SELECTED_LIST,
		};
		
		wxStaticText* m_staticText8;
		wxListBox* m_listAll;
		wxBitmapButton* m_bpAddAll;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpRemoveAll;
		wxStaticText* m_staticText9;
		wxListBox* m_listSelected;
		wxBitmapButton* m_bpButton31;
		wxBitmapButton* m_bpButton32;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ChampionshipCategoriesMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Championship categories management"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 664,446 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU );
		~ChampionshipCategoriesMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CategoriesMngrDlg
///////////////////////////////////////////////////////////////////////////////
class CategoriesMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnCategorySearch( wxCommandEvent& event ){ OnCategorySearch( event ); }
		void _wxFB_OnCategorySelected( wxCommandEvent& event ){ OnCategorySelected( event ); }
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnUpdate( wxCommandEvent& event ){ OnUpdate( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_CATEGORY_LIST_SEARCH = 1000,
			ID_CATEGORY_LIST,
			ID_NAME,
			ID_SHORTNAME,
			ID_DANCE_LIST,
			ID_LIGA_LIST,
			ID_AGE_LIST,
		};
		
		wxStaticText* m_staticText15;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listCategories;
		wxBitmapButton* m_bpButton13;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpUpdate;
		wxBitmapButton* m_bpButton29;
		wxBitmapButton* m_bpDiscard;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_textShortName;
		wxStaticText* m_staticText18;
		wxComboBox* m_comboDance;
		wxStaticText* m_staticText19;
		wxComboBox* m_comboLiga;
		wxStaticText* m_staticText191;
		wxComboBox* m_comboAge;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCategorySearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCategorySelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CategoriesMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Categories manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 715,284 ), long style = wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU );
		~CategoriesMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ClubsMngrDlg
///////////////////////////////////////////////////////////////////////////////
class ClubsMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnSelectClub( wxCommandEvent& event ){ OnSelectClub( event ); }
		void _wxFB_OnAddClub( wxCommandEvent& event ){ OnAddClub( event ); }
		void _wxFB_OnUpdate( wxCommandEvent& event ){ OnUpdate( event ); }
		void _wxFB_OnRemoveClub( wxCommandEvent& event ){ OnRemoveClub( event ); }
		void _wxFB_OnAccountInfo( wxCommandEvent& event ){ OnAccountInfo( event ); }
		void _wxFB_OnDirectorInfo( wxCommandEvent& event ){ OnDirectorInfo( event ); }
		void _wxFB_OnTrainersMngr( wxCommandEvent& event ){ OnTrainersMngr( event ); }
		void _wxFB_OnDancersMngr( wxCommandEvent& event ){ OnDancersMngr( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_CLUBLIST,
			wxID_ADDCLUB,
			wxID_REMOVECLUB,
			wxID_ACCOUNTINFO,
			wxID_DIRECTORINFO,
			wxID_TRAINERS,
			wxID_DANCERS,
			ID_NAME,
			ID_CITY,
			ID_ADDRESS,
			ID_EMAIL,
			ID_WEB,
			ID_INFO,
			ID_PAYDATE,
			ID_EXPDATE,
		};
		
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
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* m_datePay;
		wxStaticText* m_staticText28;
		wxDatePickerCtrl* m_dateExp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectClub( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddClub( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveClub( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAccountInfo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDirectorInfo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTrainersMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDancersMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ClubsMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Clubs manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 896,471 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ClubsMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnCloseFrame( wxCloseEvent& event ){ OnCloseFrame( event ); }
		void _wxFB_OnExitClick( wxCommandEvent& event ){ OnExitClick( event ); }
		void _wxFB_OnMenuClubManage( wxCommandEvent& event ){ OnMenuClubManage( event ); }
		void _wxFB_OnMenuJudgeManage( wxCommandEvent& event ){ OnMenuJudgeManage( event ); }
		void _wxFB_OnMenuCategoryManage( wxCommandEvent& event ){ OnMenuCategoryManage( event ); }
		void _wxFB_OnDanceTypesCodeMgr( wxCommandEvent& event ){ OnDanceTypesCodeMgr( event ); }
		void _wxFB_OnLigueCodeMgr( wxCommandEvent& event ){ OnLigueCodeMgr( event ); }
		void _wxFB_OnAgeCodesMgr( wxCommandEvent& event ){ OnAgeCodesMgr( event ); }
		void _wxFB_OnMenuChampionshipTypes( wxCommandEvent& event ){ OnMenuChampionshipTypes( event ); }
		void _wxFB_OnCitiesMngr( wxCommandEvent& event ){ OnCitiesMngr( event ); }
		void _wxFB_OnCountriesMngr( wxCommandEvent& event ){ OnCountriesMngr( event ); }
		void _wxFB_OnMenySync( wxCommandEvent& event ){ OnMenySync( event ); }
		void _wxFB_OnMenuOptions( wxCommandEvent& event ){ OnMenuOptions( event ); }
		void _wxFB_OnAboutDlg( wxCommandEvent& event ){ OnAboutDlg( event ); }
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnSelectChampionship( wxCommandEvent& event ){ OnSelectChampionship( event ); }
		void _wxFB_OnAddChampionsip( wxCommandEvent& event ){ OnAddChampionsip( event ); }
		void _wxFB_OnRemoveChampionship( wxCommandEvent& event ){ OnRemoveChampionship( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		void _wxFB_OnCategoryMngr( wxCommandEvent& event ){ OnCategoryMngr( event ); }
		void _wxFB_OnDancersTeams( wxCommandEvent& event ){ OnDancersTeams( event ); }
		void _wxFB_OnStartNumberAssign( wxCommandEvent& event ){ OnStartNumberAssign( event ); }
		void _wxFB_OnJudgeMngr( wxCommandEvent& event ){ OnJudgeMngr( event ); }
		void _wxFB_OnSendInvitation( wxCommandEvent& event ){ OnSendInvitation( event ); }
		void _wxFB_OnResults( wxCommandEvent& event ){ OnResults( event ); }
		
	
	protected:
		enum
		{
			ID_MAINFRAME_FORM = 1000,
			ID_CS_ADD,
			ID_CS_REMOVE,
			ID_CS_UPDATE,
			ID_CS_CATEGORIES,
			ID_CS_STARTNUMB,
			ID_CS_JUDGESTEAM,
			ID_CS_INVITATIONS,
			ID_CS_RESULTS,
			ID_CS_RAITING,
			ID_MENU_MNGR_CLUBS,
			ID_MENU_MNGR_JUDGE,
			ID_MENU_MNGR_CATEGORIES,
			ID_MENU_MNGR_DANCE_TYPES,
			ID_MENU_MNGR_LIGUES,
			ID_MENU_MNGR_AGE_CATEGORIES,
			ID_MENU_MNGR_ChTYPES_MNGR,
			ID_MENU_MNGR_CITIES,
			ID_MENU_MNGR_COUNTRIES,
			ID_MENU_TOOLS_SYUNC,
			ID_MENU_TOOLS_OPTIONS,
			ID_ABOUT,
			ID_SEARCH,
			ID_LIST_CHAMPIONSHIP,
			wxID_CHAMPIONSIP_ADD,
			wxID_CHAMPIONSIP_REMOVE,
			wxID_CHAMPIONSHIP_SAVE,
			wxID_CHAMPIONSHIP_DISCARD,
			wxID_CHAMPIONSHIP_CATEGORIES,
			ID_TEAMS,
			wxID_CHAMPIONSHIP_STARTNUMBERMNGR,
			wxID_CHAMPIONSHIP_JUDGESTEAMMNGR,
			wxID_CHAMPIONSHIP_SENDINVITATION,
			wxID_RESULTS,
			ID_RAITING,
			ID_NAME,
			ID_TYPE,
			ID_DATE,
			ID_CITY,
			ID_ADDRESS,
			ID_REG_OPEN,
			ID_REG_CLOSE,
			ID_INFO,
		};
		
		wxMenuBar* m_menuBar;
		wxMenu* m_menuFile;
		wxMenu* m_menu8;
		wxMenu* m_menu2;
		wxMenu* m_menu5;
		wxMenu* m_menu51;
		wxPanel* m_panel1;
		wxStaticText* m_championshipSearchText;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listChampionship;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		wxBitmapButton* m_bpCategoryMngr;
		wxBitmapButton* m_bpDancersTeams;
		wxBitmapButton* m_bpStartNumberMngr;
		wxBitmapButton* m_bpJudgesMngr;
		wxBitmapButton* m_bpSendinvitation;
		wxBitmapButton* m_bpResults;
		wxBitmapButton* m_bpRaitings;
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseFrame( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnExitClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuClubManage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuJudgeManage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuCategoryManage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDanceTypesCodeMgr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLigueCodeMgr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAgeCodesMgr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuChampionshipTypes( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCitiesMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCountriesMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenySync( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuOptions( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAboutDlg( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectChampionship( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddChampionsip( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveChampionship( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCategoryMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDancersTeams( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartNumberAssign( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnJudgeMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSendInvitation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResults( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrameBase( wxWindow* parent, wxWindowID id = ID_MAINFRAME_FORM, const wxString& title = _("Championship calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 965,667 ), long style = wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrameBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DirectorInfo
///////////////////////////////////////////////////////////////////////////////
class DirectorInfo : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_NAME = 1000,
			ID_BD,
			ID_PHONE,
			ID_EMAIL,
		};
		
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DirectorInfo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Director info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 459,230 ), long style = wxDEFAULT_DIALOG_STYLE );
		~DirectorInfo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TrainersMngrDlg
///////////////////////////////////////////////////////////////////////////////
class TrainersMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnSelectTrainer( wxCommandEvent& event ){ OnSelectTrainer( event ); }
		void _wxFB_OnAddTrainer( wxCommandEvent& event ){ OnAddTrainer( event ); }
		void _wxFB_OnUpdate( wxCommandEvent& event ){ OnUpdate( event ); }
		void _wxFB_OnRemoveTrainer( wxCommandEvent& event ){ OnRemoveTrainer( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_TRAINERS_LIST,
			wxID_UPDATE,
			ID_NAME,
			ID_CLUB,
			ID_PHONE,
			ID_EMAIL,
			ID_BD,
			ID_INFO,
			ID_PAY,
			ID_EXPIRE,
		};
		
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectTrainer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddTrainer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveTrainer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		TrainersMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Trainers"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 777,466 ), long style = wxDEFAULT_DIALOG_STYLE );
		~TrainersMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DancersMngrDlg
///////////////////////////////////////////////////////////////////////////////
class DancersMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnDancerSelect( wxCommandEvent& event ){ OnDancerSelect( event ); }
		void _wxFB_OnAddDancer( wxCommandEvent& event ){ OnAddDancer( event ); }
		void _wxFB_OnRemoveDancer( wxCommandEvent& event ){ OnRemoveDancer( event ); }
		void _wxFB_OnUpdate( wxCommandEvent& event ){ OnUpdate( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_DANCERS_LIST,
			ID_NAME,
			ID_REGBOOK,
			ID_RAITING,
			ID_CLUB,
			ID_TRAINER,
			ID_LIGA,
			ID_GENDER,
			ID_BD,
			ID_INFO,
			ID_PAY,
			ID_EXPIRE,
			ID_REG,
		};
		
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDancerSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddDancer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveDancer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DancersMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Dancers"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 964,634 ), long style = wxDEFAULT_DIALOG_STYLE );
		~DancersMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AccountInfo
///////////////////////////////////////////////////////////////////////////////
class AccountInfo : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnShowPass( wxCommandEvent& event ){ OnShowPass( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_LOGIN = 1000,
			ID_PASS,
		};
		
		wxStaticText* m_staticText56;
		wxTextCtrl* m_textLogin;
		wxStaticText* m_staticText57;
		wxTextCtrl* m_textPass;
		
		wxCheckBox* m_checkShowPass;
		wxBitmapButton* m_bpButton39;
		wxBitmapButton* m_bpButton40;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnShowPass( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AccountInfo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Account info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 384,185 ), long style = wxCAPTION|wxCLOSE_BOX|wxSTAY_ON_TOP );
		~AccountInfo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddTeamCategory
///////////////////////////////////////////////////////////////////////////////
class AddTeamCategory : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_CATEGORY = 1000,
			ID_PASS,
		};
		
		wxStaticText* m_staticText56;
		wxStaticText* m_staticCategory;
		wxStaticText* m_staticText57;
		wxTextCtrl* m_textComposition;
		wxBitmapButton* m_bpButton39;
		wxBitmapButton* m_bpButton40;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AddTeamCategory( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Add team categort"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 384,163 ), long style = wxCAPTION|wxCLOSE_BOX|wxSTAY_ON_TOP );
		~AddTeamCategory();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class JudgesMngr
///////////////////////////////////////////////////////////////////////////////
class JudgesMngr : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnSelectJudge( wxCommandEvent& event ){ OnSelectJudge( event ); }
		void _wxFB_OnAddJudge( wxCommandEvent& event ){ OnAddJudge( event ); }
		void _wxFB_OnRemoveJudge( wxCommandEvent& event ){ OnRemoveJudge( event ); }
		void _wxFB_OnUpdate( wxCommandEvent& event ){ OnUpdate( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_LIST_JUDGES,
			ID_APPLY,
			ID_NAME,
			ID_CITY,
			ID_ATTESTATION,
			ID_EMAIL,
			ID_PHONE,
			ID_INFO,
			ID_PRACTICER,
			ID_PAY,
			ID_EXP,
		};
		
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectJudge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddJudge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveJudge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		JudgesMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Judges manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 861,463 ), long style = wxDEFAULT_DIALOG_STYLE );
		~JudgesMngr();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TeamCategoryMngrDlg
///////////////////////////////////////////////////////////////////////////////
class TeamCategoryMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnAddAll( wxCommandEvent& event ){ OnAddAll( event ); }
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnRemoveAll( wxCommandEvent& event ){ OnRemoveAll( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_ADDALL = 1000,
			wxID_ADDONE,
			wxID_REMOVEONE,
			wxID_REMOVEALL,
		};
		
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		TeamCategoryMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Team categories manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 546,317 ), long style = wxDEFAULT_DIALOG_STYLE );
		~TeamCategoryMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TeamDancersMngrDlg
///////////////////////////////////////////////////////////////////////////////
class TeamDancersMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnAddAll( wxCommandEvent& event ){ OnAddAll( event ); }
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnRemoveAll( wxCommandEvent& event ){ OnRemoveAll( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_ADDALL = 1000,
			wxID_ADDONE,
			wxID_REMOVEONE,
			wxID_REMOVEALL,
		};
		
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		TeamDancersMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Team dancers manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 546,316 ), long style = wxDEFAULT_DIALOG_STYLE );
		~TeamDancersMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChampionshipJudgesTeamMngrDlg
///////////////////////////////////////////////////////////////////////////////
class ChampionshipJudgesTeamMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnAddAll( wxCommandEvent& event ){ OnAddAll( event ); }
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnRemoveAll( wxCommandEvent& event ){ OnRemoveAll( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_LIST_ALL = 1000,
			wxID_ADDALL,
			wxID_ADDONE,
			wxID_REMOVEONE,
			wxID_REMOVEALL,
			ID_SELECTED,
		};
		
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ChampionshipJudgesTeamMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Championship judges team manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 546,316 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ChampionshipJudgesTeamMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class StartNumberAssignDlg
///////////////////////////////////////////////////////////////////////////////
class StartNumberAssignDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnRandomFind( wxCommandEvent& event ){ OnRandomFind( event ); }
		void _wxFB_OnNextFind( wxCommandEvent& event ){ OnNextFind( event ); }
		void _wxFB_OnAssign( wxCommandEvent& event ){ OnAssign( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_RANDOM = 1000,
			wxID_NEXT,
			wxID_ASSIGN,
		};
		
		wxStaticText* m_staticText15;
		wxTextCtrl* m_textCtrl5;
		wxListBox* m_listBox4;
		wxStaticText* m_staticText85;
		wxStaticText* m_staticTeamName;
		wxTextCtrl* m_textCtrl40;
		wxBitmapButton* m_bpRandomNumber;
		wxBitmapButton* m_bpNextNumber;
		wxBitmapButton* m_bpAssign;
		
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnRandomFind( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNextFind( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAssign( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		StartNumberAssignDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 764,375 ), long style = wxDEFAULT_DIALOG_STYLE );
		~StartNumberAssignDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CodeDialog
///////////////////////////////////////////////////////////////////////////////
class CodeDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnSelectItem( wxCommandEvent& event ){ OnSelectItem( event ); }
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnUpdateCode( wxCommandEvent& event ){ OnUpdateCode( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_ITEM_LIST,
			wxID_UPDATE,
			ID_CODE,
			ID_NAME,
		};
		
		wxStaticBoxSizer* m_sbListSizer;
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
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateCode( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CodeDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Code"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 550,322 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CodeDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CountriesMngr
///////////////////////////////////////////////////////////////////////////////
class CountriesMngr : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnSelectItem( wxCommandEvent& event ){ OnSelectItem( event ); }
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnUpdateCode( wxCommandEvent& event ){ OnUpdateCode( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_ITEM_LIST,
			wxID_UPDATE,
			ID_NAME,
		};
		
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
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateCode( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CountriesMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Countries manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 550,239 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CountriesMngr();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChampionshipTypeMngr
///////////////////////////////////////////////////////////////////////////////
class ChampionshipTypeMngr : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnSelectItem( wxCommandEvent& event ){ OnSelectItem( event ); }
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnUpdateCode( wxCommandEvent& event ){ OnUpdateCode( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_ITEM_LIST,
			wxID_UPDATE,
			ID_NAME,
		};
		
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
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateCode( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ChampionshipTypeMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Championship types manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 550,239 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ChampionshipTypeMngr();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CitiesMngr
///////////////////////////////////////////////////////////////////////////////
class CitiesMngr : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnSelectItem( wxCommandEvent& event ){ OnSelectItem( event ); }
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnUpdateCode( wxCommandEvent& event ){ OnUpdateCode( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_ITEM_LIST,
			wxID_UPDATE,
			ID_NAME,
		};
		
		wxStaticBoxSizer* m_sbListSizer;
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
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectItem( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateCode( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CitiesMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Cities manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 599,322 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CitiesMngr();
	
};

#endif //__udf__
