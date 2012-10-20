///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
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
#include <wx/menu.h>
#include <wx/treectrl.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
#include <wx/html/htmlwin.h>
#include <wx/notebook.h>

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
		void _wxFB_OnAddTeam( wxCommandEvent& event ){ OnAddTeam( event ); }
		void _wxFB_OnRemoveTeam( wxCommandEvent& event ){ OnRemoveTeam( event ); }
		void _wxFB_OnUpdate( wxCommandEvent& event ){ OnUpdate( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		void _wxFB_OnClubChanged( wxCommandEvent& event ){ OnClubChanged( event ); }
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
		virtual void OnAddTeam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveTeam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClubChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddDancerTeamCategory( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveDancerTeamCategory( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddDancer2Team( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveDancerFromTeam( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DancersTeamMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Dancers team"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 775,485 ), long style = wxDEFAULT_DIALOG_STYLE );
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
		void _wxFB_OnAgeCganged( wxCommandEvent& event ){ OnAgeCganged( event ); }
		void _wxFB_OnLigaCganged( wxCommandEvent& event ){ OnLigaCganged( event ); }
		void _wxFB_OnDanceChanged( wxCommandEvent& event ){ OnDanceChanged( event ); }
		
	
	protected:
		enum
		{
			ID_CATEGORY_LIST_SEARCH = 1000,
			ID_CATEGORY_LIST,
			ID_AGE_LIST,
			ID_LIGA_LIST,
			ID_DANCE_LIST,
			ID_NAME,
			ID_SHORTNAME,
		};
		
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
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_textShortName;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCategorySearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCategorySelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAgeCganged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLigaCganged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDanceChanged( wxCommandEvent& event ) { event.Skip(); }
		
	
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
		void _wxFB_OnPayment( wxCommandEvent& event ){ OnPayment( event ); }
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
			ID_M_BPPAYMENT,
			ID_NAME,
			ID_CITY,
			ID_ADDRESS,
			ID_EMAIL,
			ID_WEB,
			ID_INFO,
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
		wxBitmapButton* m_bpPayments;
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
		virtual void OnPayment( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ClubsMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Clubs manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 895,484 ), long style = wxDEFAULT_DIALOG_STYLE );
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
		void _wxFB_OnEditTour( wxTreeEvent& event ){ OnEditTour( event ); }
		void _wxFB_OnCsSelect( wxTreeEvent& event ){ OnCsSelect( event ); }
		void _wxFB_OnAddChampionsip( wxCommandEvent& event ){ OnAddChampionsip( event ); }
		void _wxFB_OnRemoveChampionship( wxCommandEvent& event ){ OnRemoveChampionship( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		void _wxFB_OnCategoryMngr( wxCommandEvent& event ){ OnCategoryMngr( event ); }
		void _wxFB_OnJudgeMngr( wxCommandEvent& event ){ OnJudgeMngr( event ); }
		void _wxFB_OnSendInvitation( wxCommandEvent& event ){ OnSendInvitation( event ); }
		void _wxFB_OnDancersTeams( wxCommandEvent& event ){ OnDancersTeams( event ); }
		void _wxFB_OnStartNumberAssign( wxCommandEvent& event ){ OnStartNumberAssign( event ); }
		void _wxFB_OnAddTour( wxCommandEvent& event ){ OnAddTour( event ); }
		void _wxFB_OnTourEdit( wxCommandEvent& event ){ OnTourEdit( event ); }
		void _wxFB_OnRemoveTour( wxCommandEvent& event ){ OnRemoveTour( event ); }
		void _wxFB_OnJudgesMark( wxCommandEvent& event ){ OnJudgesMark( event ); }
		void _wxFB_OnCsTourReport( wxCommandEvent& event ){ OnCsTourReport( event ); }
		
	
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
			ID_CS_TREE,
			wxID_CHAMPIONSIP_ADD,
			wxID_CHAMPIONSIP_REMOVE,
			wxID_CHAMPIONSHIP_SAVE,
			wxID_CHAMPIONSHIP_DISCARD,
			wxID_CHAMPIONSHIP_CATEGORIES,
			wxID_CHAMPIONSHIP_JUDGESTEAMMNGR,
			wxID_CHAMPIONSHIP_SENDINVITATION,
			ID_TEAMS,
			wxID_CHAMPIONSHIP_STARTNUMBERMNGR,
			ID_TOUR_ADD,
			ID_TOUR_EDIT,
			ID_TOUR_REMOVE,
			ID_TOUR_JUIDGES_MARKS,
			ID_TOUR_REPORT,
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
		virtual void OnEditTour( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnCsSelect( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnAddChampionsip( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveChampionship( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCategoryMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnJudgeMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSendInvitation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDancersTeams( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartNumberAssign( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddTour( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTourEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveTour( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnJudgesMark( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCsTourReport( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrameBase( wxWindow* parent, wxWindowID id = ID_MAINFRAME_FORM, const wxString& title = _("Championship calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 983,667 ), long style = wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );
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
		void _wxFB_OnPayment( wxCommandEvent& event ){ OnPayment( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_TRAINERS_LIST,
			wxID_UPDATE,
			ID_M_BPPAYMENTS,
			ID_NAME,
			ID_CLUB,
			ID_PHONE,
			ID_EMAIL,
			ID_BD,
			ID_INFO,
		};
		
		wxStaticText* m_staticText20;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listTrainers;
		wxBitmapButton* m_bpAddTrainer;
		wxBitmapButton* m_bpUpdate;
		wxBitmapButton* m_bpRemoveTrainer;
		wxBitmapButton* m_bpPayments;
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectTrainer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddTrainer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveTrainer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPayment( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		TrainersMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Trainers"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 777,466 ), long style = wxDEFAULT_DIALOG_STYLE );
		~TrainersMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CsTours
///////////////////////////////////////////////////////////////////////////////
class CsTours : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_M_COMBOTYPE = 1000,
			ID_LIMIT,
			ID_FINAL,
		};
		
		
		wxStaticText* m_staticText21;
		wxComboBox* m_comboType;
		wxStaticText* m_staticText22;
		wxTextCtrl* m_textLimit;
		
		wxCheckBox* m_checkFinal;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CsTours( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Championship tour"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 488,194 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CsTours();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CsTourReport
///////////////////////////////////////////////////////////////////////////////
class CsTourReport : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnReport( wxCommandEvent& event ){ OnReport( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		void _wxFB_OnStartDrag( wxListEvent& event ){ OnStartDrag( event ); }
		void _wxFB_OnTeamSelect( wxListEvent& event ){ OnTeamSelect( event ); }
		void _wxFB_OnUp10( wxCommandEvent& event ){ OnUp10( event ); }
		void _wxFB_OnUp( wxCommandEvent& event ){ OnUp( event ); }
		void _wxFB_OnDown( wxCommandEvent& event ){ OnDown( event ); }
		void _wxFB_OnDown10( wxCommandEvent& event ){ OnDown10( event ); }
		
	
	protected:
		enum
		{
			ID_PRINT = 1000,
			ID_LIST_TEAMS,
			ID_MOVEUP10,
			ID_MOVE_UP,
			ID_MOVE_DOWN,
			ID_MOVE_DOWN10,
		};
		
		wxBoxSizer* bSizer76;
		wxStaticText* m_staticText94;
		
		wxBitmapButton* m_bpPrint;
		wxBitmapButton* m_bpDiscard;
		wxBoxSizer* m_bListSizer;
		wxListCtrl* m_listTeams;
		wxBitmapButton* m_bpMoveUp10;
		wxBitmapButton* m_bpMoveUp;
		wxBitmapButton* m_bpMoveDown;
		wxBitmapButton* m_bpMoveDown10;
		wxStaticText* m_staticJudgeDescr;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnReport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartDrag( wxListEvent& event ) { event.Skip(); }
		virtual void OnTeamSelect( wxListEvent& event ) { event.Skip(); }
		virtual void OnUp10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDown( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDown10( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CsTourReport( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Championship tour report"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,700 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CsTourReport();
	
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
		void _wxFB_OnPayment( wxCommandEvent& event ){ OnPayment( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_DANCERS_LIST,
			ID_M_BPPAYMENTS,
			ID_NAME,
			ID_REGBOOK,
			ID_RAITING,
			ID_CLUB,
			ID_TRAINER,
			ID_LIGA,
			ID_GENDER,
			ID_BD,
			ID_REG,
			ID_INFO,
		};
		
		wxStaticText* m_staticText78;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listDancers;
		wxBitmapButton* m_bpAddDancer;
		wxBitmapButton* m_bpRemoveDancer;
		wxBitmapButton* m_bpUpdate;
		wxBitmapButton* m_bpPayments;
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
		wxStaticText* m_staticText62;
		wxTextCtrl* m_textReg;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_textInfo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDancerSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddDancer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveDancer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPayment( wxCommandEvent& event ) { event.Skip(); }
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
		void _wxFB_OnPayment( wxCommandEvent& event ){ OnPayment( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SEARCH = 1000,
			ID_LIST_JUDGES,
			ID_APPLY,
			ID_M_BPPAYMENT,
			ID_NAME,
			ID_CITY,
			ID_ATTESTATION,
			ID_EMAIL,
			ID_PHONE,
			ID_INFO,
			ID_PRACTICER,
		};
		
		wxStaticText* m_staticText20;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listJudges;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpApply;
		wxBitmapButton* m_bpPayments;
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
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectJudge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddJudge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveJudge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPayment( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		JudgesMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Judges manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 862,483 ), long style = wxDEFAULT_DIALOG_STYLE );
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
		void _wxFB_OnSelectTeam( wxCommandEvent& event ){ OnSelectTeam( event ); }
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnRandomFind( wxCommandEvent& event ){ OnRandomFind( event ); }
		void _wxFB_OnNextFind( wxCommandEvent& event ){ OnNextFind( event ); }
		void _wxFB_OnAssign( wxCommandEvent& event ){ OnAssign( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_TEAMS_LIST = 1000,
			ID_SEARCH,
			ID_NUMBER,
			wxID_RANDOM,
			wxID_NEXT,
			wxID_ASSIGN,
		};
		
		wxListBox* m_listTeams;
		wxStaticText* m_staticText85;
		wxTextCtrl* m_textSearch;
		wxTextCtrl* m_textNumber;
		wxBitmapButton* m_bpRandomNumber;
		wxBitmapButton* m_bpNextNumber;
		wxBitmapButton* m_bpAssign;
		
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectTeam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRandomFind( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNextFind( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAssign( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		StartNumberAssignDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 816,356 ), long style = wxDEFAULT_DIALOG_STYLE );
		~StartNumberAssignDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class JudgeMark
///////////////////////////////////////////////////////////////////////////////
class JudgeMark : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSelectJudge( wxCommandEvent& event ){ OnSelectJudge( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		void _wxFB_OnSelectNumber( wxCommandEvent& event ){ OnSelectNumber( event ); }
		void _wxFB_OnShowAll( wxCommandEvent& event ){ OnShowAll( event ); }
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }
		void _wxFB_OnPlus( wxCommandEvent& event ){ OnPlus( event ); }
		void _wxFB_OnMinus( wxCommandEvent& event ){ OnMinus( event ); }
		
	
	protected:
		enum
		{
			ID_TEAMS_LIST = 1000,
			ID_SHOW_ALL,
			ID_SEARCH,
			ID_PANEL_PLUS,
			ID_GOOD,
			ID_PANEL_MINUS,
			ID_BED,
		};
		
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
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectJudge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectNumber( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShowAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMinus( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		JudgeMark( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Judge marks"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 816,356 ), long style = wxDEFAULT_DIALOG_STYLE );
		~JudgeMark();
	
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

///////////////////////////////////////////////////////////////////////////////
/// Class ReportPreview
///////////////////////////////////////////////////////////////////////////////
class ReportPreview : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnPrint( wxCommandEvent& event ){ OnPrint( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_PRINT = 1000,
			ID_REPORT_PREVIEW,
		};
		
		wxBitmapButton* m_bpPrint;
		wxBitmapButton* m_bpDiscard;
		wxHtmlWindow* m_htmlReport;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnPrint( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ReportPreview( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Report preview"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 956,636 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ReportPreview();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PaymentHistory
///////////////////////////////////////////////////////////////////////////////
class PaymentHistory : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnUpdate( wxCommandEvent& event ){ OnUpdate( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_PAYMENTHISTORY = 1000,
			ID_M_BPUPDATE,
			ID_M_BPREMOVE,
			ID_M_LISTPAYMENTS,
		};
		
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpUpdate;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		wxListCtrl* m_listPayments;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PaymentHistory( wxWindow* parent, wxWindowID id = ID_PAYMENTHISTORY, const wxString& title = _("Payments history"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 786,321 ), long style = wxDEFAULT_DIALOG_STYLE );
		~PaymentHistory();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Payment
///////////////////////////////////////////////////////////////////////////////
class Payment : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_PAYMENT = 1000,
			ID_M_DATEPAY,
			ID_M_TEXTSUM,
			ID_M_CHECKFREE,
		};
		
		wxStaticText* m_staticText92;
		wxDatePickerCtrl* m_datePay;
		wxStaticText* m_staticText93;
		wxDatePickerCtrl* m_dateExpire;
		wxStaticText* m_staticText94;
		wxTextCtrl* m_textSum;
		wxStaticText* m_staticText95;
		wxCheckBox* m_checkFree;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Payment( wxWindow* parent, wxWindowID id = ID_PAYMENT, const wxString& title = _("Payment info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 469,164 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Payment();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Settings
///////////////////////////////////////////////////////////////////////////////
class Settings : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			ID_SETTINGS = 1000,
		};
		
		wxNotebook* m_notebook1;
		wxPanel* m_panel4;
		wxStaticText* m_staticText97;
		wxTextCtrl* m_textServer;
		wxStaticText* m_staticText98;
		wxTextCtrl* m_textDatabase;
		wxStaticText* m_staticText99;
		wxTextCtrl* m_textUser;
		wxStaticText* m_staticText100;
		wxTextCtrl* m_textPass;
		wxStaticText* m_staticTestResult;
		
		wxButton* m_buttonTest;
		wxPanel* m_panel5;
		
		wxStaticText* m_staticText88;
		wxStaticText* m_staticText89;
		wxStaticText* m_staticText90;
		wxStaticText* m_staticText91;
		wxStaticText* m_staticText92;
		wxStaticText* m_staticText93;
		wxStaticText* m_staticText94;
		wxStaticText* m_staticText95;
		wxTextCtrl* m_textCtrl53;
		wxTextCtrl* m_textCtrl54;
		wxTextCtrl* m_textCtrl55;
		wxTextCtrl* m_textCtrl56;
		wxTextCtrl* m_textCtrl57;
		wxTextCtrl* m_textCtrl58;
		wxTextCtrl* m_textCtrl59;
		wxStaticText* m_staticText96;
		wxTextCtrl* m_textCtrl60;
		wxTextCtrl* m_textCtrl61;
		wxTextCtrl* m_textCtrl62;
		wxTextCtrl* m_textCtrl63;
		wxTextCtrl* m_textCtrl64;
		wxTextCtrl* m_textCtrl65;
		wxTextCtrl* m_textCtrl66;
		wxPanel* m_panel6;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Settings( wxWindow* parent, wxWindowID id = ID_SETTINGS, const wxString& title = _("Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 704,267 ), long style = wxCAPTION|wxCLOSE_BOX );
		~Settings();
	
};

#endif //__udf__
