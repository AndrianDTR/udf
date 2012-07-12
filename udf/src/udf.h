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
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/statbox.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
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
		void _wxFB_OnAddDancerTeam( wxCommandEvent& event ){ OnAddDancerTeam( event ); }
		void _wxFB_OnRemoveTancerTeam( wxCommandEvent& event ){ OnRemoveTancerTeam( event ); }
		void _wxFB_OnAddDancerTeamCategory( wxCommandEvent& event ){ OnAddDancerTeamCategory( event ); }
		void _wxFB_OnRemoveDancerTeamCategory( wxCommandEvent& event ){ OnRemoveDancerTeamCategory( event ); }
		void _wxFB_OnAddDancerTeamDancer( wxCommandEvent& event ){ OnAddDancerTeamDancer( event ); }
		void _wxFB_OnRemoveDancerTeamDancer( wxCommandEvent& event ){ OnRemoveDancerTeamDancer( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_ADDDANCERTEAMCATEGORY = 1000,
			wxID_REMOVEDANCERTEAMCATEGORY,
			wxID_ADDDANCER,
			wxID_REMOVEDANCER,
			wxID_DISCARD,
		};
		
		wxStaticText* m_staticText88;
		wxComboBox* m_comboBox19;
		wxStaticText* m_staticText89;
		wxComboBox* m_comboBox20;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_textCtrl5;
		wxListBox* m_listBox4;
		wxBitmapButton* m_bpButton13;
		wxBitmapButton* m_bpButton14;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textCtrl6;
		wxComboBox* m_comboBox17;
		wxListBox* m_listBox22;
		wxBitmapButton* m_bpAddDancerTeamCategory;
		wxBitmapButton* m_bpRemoveDancerTeamCategory;
		wxComboBox* m_comboBox16;
		wxListBox* m_listBox21;
		wxBitmapButton* m_bpAddDancerTeamDancer;
		wxBitmapButton* m_bpRemoveDancerTeamDancer;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddDancerTeam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveTancerTeam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddDancerTeamCategory( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveDancerTeamCategory( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddDancerTeamDancer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveDancerTeamDancer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
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
			wxID_ADDALL = 1000,
			wxID_ADDONE,
			wxID_REMOVEONE,
			wxID_REMOVEALL,
			wxID_DISCARD,
		};
		
		wxStaticText* m_staticText8;
		wxListBox* m_listBox2;
		wxBitmapButton* m_bpAddAll;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpRemoveAll;
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
		
		ChampionshipCategoriesMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Championship categories management"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 664,446 ), long style = wxDEFAULT_DIALOG_STYLE );
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
		void _wxFB_OnAdd( wxCommandEvent& event ){ OnAdd( event ); }
		void _wxFB_OnRemove( wxCommandEvent& event ){ OnRemove( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_DISCARD = 1000,
		};
		
		wxStaticText* m_staticText15;
		wxTextCtrl* m_textCtrl5;
		wxListBox* m_listBox4;
		wxBitmapButton* m_bpButton13;
		wxBitmapButton* m_bpRemove;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textCtrl6;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_textCtrl7;
		wxStaticText* m_staticText18;
		wxComboBox* m_comboBox4;
		wxStaticText* m_staticText19;
		wxComboBox* m_comboBox5;
		wxBitmapButton* m_bpButton29;
		wxBitmapButton* m_bpDiscard;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CategoriesMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Categories manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 715,287 ), long style = wxDEFAULT_DIALOG_STYLE );
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
		void _wxFB_OnAddClub( wxCommandEvent& event ){ OnAddClub( event ); }
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
			wxID_ADDCLUB = 1000,
			wxID_REMOVECLUB,
			wxID_ACCOUNTINFO,
			wxID_DIRECTORINFO,
			wxID_TRAINERS,
			wxID_DANCERS,
			wxID_DISCARD,
		};
		
		wxStaticText* m_staticText20;
		wxTextCtrl* m_textCtrl8;
		wxListBox* m_listBox5;
		wxBitmapButton* m_bpAddClub;
		wxBitmapButton* m_bpRemoveClub;
		wxBitmapButton* m_bpAccountInfo;
		wxBitmapButton* m_bpDirectorInfo;
		wxBitmapButton* m_bpTarinersMngr;
		wxBitmapButton* m_bpDancersMngr;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textCtrl9;
		wxStaticText* m_staticText22;
		wxComboBox* m_comboBox6;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textCtrl10;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_textCtrl11;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_textCtrl12;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_textCtrl13;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* m_datePicker6;
		wxStaticText* m_staticText28;
		wxDatePickerCtrl* m_datePicker7;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddClub( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveClub( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAccountInfo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDirectorInfo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTrainersMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDancersMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ClubsMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Clubs manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 785,477 ), long style = wxDEFAULT_DIALOG_STYLE );
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
		void _wxFB_OnMenuCategoryManage( wxCommandEvent& event ){ OnMenuCategoryManage( event ); }
		void _wxFB_OnMenuClubManage( wxCommandEvent& event ){ OnMenuClubManage( event ); }
		void _wxFB_OnMenuJudgeManage( wxCommandEvent& event ){ OnMenuJudgeManage( event ); }
		void _wxFB_OnAddChampionsip( wxCommandEvent& event ){ OnAddChampionsip( event ); }
		void _wxFB_OnRemoveChampionship( wxCommandEvent& event ){ OnRemoveChampionship( event ); }
		void _wxFB_OnCategoryMngr( wxCommandEvent& event ){ OnCategoryMngr( event ); }
		void _wxFB_OnStartNumberAssign( wxCommandEvent& event ){ OnStartNumberAssign( event ); }
		void _wxFB_OnJudgeMngr( wxCommandEvent& event ){ OnJudgeMngr( event ); }
		void _wxFB_OnSendInvitation( wxCommandEvent& event ){ OnSendInvitation( event ); }
		void _wxFB_OnResults( wxCommandEvent& event ){ OnResults( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_MENU_CAT_MNGR = 1000,
			wxID_MENU_CLUBS_MNGR,
			wxID_MENU_JUDGE_MNGR,
			wxID_CHAMPIONSIP_ADD,
			wxID_CHAMPIONSIP_REMOVE,
			wxID_CHAMPIONSHIP_CATEGORIES,
			wxID_CHAMPIONSHIP_STARTNUMBERMNGR,
			wxID_CHAMPIONSHIP_JUDGESTEAMMNGR,
			wxID_CHAMPIONSHIP_SENDINVITATION,
			wxID_RESULTS,
			wxID_CHAMPIONSHIP_SAVE,
			wxID_CHAMPIONSHIPDISCARD,
		};
		
		wxMenuBar* m_menuBar;
		wxMenu* m_menuFile;
		wxMenu* m_menu2;
		wxMenu* m_menu3;
		wxMenu* m_menu5;
		wxPanel* m_panel1;
		wxStaticText* m_championshipSearchText;
		wxTextCtrl* m_textSearch;
		wxListBox* m_listChamlionshipList;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxBitmapButton* m_bpCategoryMngr;
		wxBitmapButton* m_bpStartNumberMngr;
		wxBitmapButton* m_bpJudgesMngr;
		wxBitmapButton* m_bpSendinvitation;
		wxBitmapButton* m_bpResults;
		wxBitmapButton* m_bpButton64;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textName;
		wxStaticText* m_staticText2;
		wxComboBox* m_comboType;
		wxStaticText* m_staticText5;
		wxDatePickerCtrl* m_dateDate;
		wxStaticText* m_staticText6;
		wxComboBox* m_comboCountry;
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
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		wxStatusBar* m_statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseFrame( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnExitClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuCategoryManage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuClubManage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuJudgeManage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddChampionsip( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveChampionship( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCategoryMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartNumberAssign( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnJudgeMngr( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSendInvitation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResults( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Test"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 965,667 ), long style = wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
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
			wxID_DISCARD = 1000,
		};
		
		wxStaticText* m_staticText29;
		wxTextCtrl* m_textCtrl14;
		wxStaticText* m_staticText30;
		wxDatePickerCtrl* m_datePicker8;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_textCtrl15;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_textCtrl16;
		wxStaticText* m_staticText33;
		wxDatePickerCtrl* m_datePicker9;
		wxStaticText* m_staticText34;
		wxDatePickerCtrl* m_datePicker10;
		wxBitmapButton* m_bpButton25;
		wxBitmapButton* m_bpButton26;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DirectorInfo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Director info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 435,300 ), long style = wxDEFAULT_DIALOG_STYLE );
		~DirectorInfo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class TarinersMngrDlg
///////////////////////////////////////////////////////////////////////////////
class TarinersMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnAddTrainer( wxCommandEvent& event ){ OnAddTrainer( event ); }
		void _wxFB_OnRemoveTrainer( wxCommandEvent& event ){ OnRemoveTrainer( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_DISCARD = 1000,
		};
		
		wxStaticText* m_staticText20;
		wxTextCtrl* m_textCtrl8;
		wxListBox* m_listBox5;
		wxBitmapButton* m_bpAddTrainer;
		wxBitmapButton* m_bpRemoveTrainer;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textCtrl9;
		wxStaticText* m_staticText22;
		wxComboBox* m_comboBox6;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textCtrl10;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_textCtrl11;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_textCtrl12;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_textCtrl13;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* m_datePicker6;
		wxStaticText* m_staticText28;
		wxDatePickerCtrl* m_datePicker7;
		wxBitmapButton* m_bpSave;
		wxBitmapButton* m_bpDiscard;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddTrainer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveTrainer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		TarinersMngrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Trainers"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 777,466 ), long style = wxDEFAULT_DIALOG_STYLE );
		~TarinersMngrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DancersMngrDlg
///////////////////////////////////////////////////////////////////////////////
class DancersMngrDlg : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnAddDancer( wxCommandEvent& event ){ OnAddDancer( event ); }
		void _wxFB_OnRemoveDancer( wxCommandEvent& event ){ OnRemoveDancer( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_DISCARD = 1000,
		};
		
		wxStaticText* m_staticText78;
		wxTextCtrl* m_textCtrl38;
		wxListBox* m_listBox5;
		wxBitmapButton* m_bpAddDancer;
		wxBitmapButton* m_bpRemoveDancer;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textCtrl9;
		wxStaticText* m_staticText54;
		wxStaticText* m_staticText55;
		wxStaticText* m_staticText22;
		wxComboBox* m_comboBox6;
		wxStaticText* m_staticText61;
		wxComboBox* m_comboBox13;
		wxStaticText* m_staticText63;
		wxComboBox* m_comboBox15;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textCtrl10;
		wxStaticText* m_staticText24;
		wxComboBox* m_comboBox14;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_textCtrl12;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_textCtrl13;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* m_datePicker6;
		wxStaticText* m_staticText28;
		wxDatePickerCtrl* m_datePicker7;
		wxStaticText* m_staticText62;
		wxDatePickerCtrl* m_datePicker15;
		wxBitmapButton* m_bpButton24;
		wxBitmapButton* m_bpDiscard;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddDancer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveDancer( wxCommandEvent& event ) { event.Skip(); }
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
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_DISCARD = 1000,
		};
		
		wxStaticText* m_staticText56;
		wxTextCtrl* m_textCtrl28;
		wxStaticText* m_staticText57;
		wxTextCtrl* m_textCtrl29;
		
		wxCheckBox* m_checkBox1;
		wxBitmapButton* m_bpButton39;
		wxBitmapButton* m_bpButton40;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AccountInfo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Account info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 384,185 ), long style = wxCAPTION|wxCLOSE_BOX|wxSTAY_ON_TOP );
		~AccountInfo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class JudgesMngr
///////////////////////////////////////////////////////////////////////////////
class JudgesMngr : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_OnAddJudge( wxCommandEvent& event ){ OnAddJudge( event ); }
		void _wxFB_OnRemoveJudge( wxCommandEvent& event ){ OnRemoveJudge( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnDiscard( wxCommandEvent& event ){ OnDiscard( event ); }
		
	
	protected:
		enum
		{
			wxID_DISCARD = 1000,
		};
		
		wxStaticText* m_staticText20;
		wxTextCtrl* m_textCtrl8;
		wxListBox* m_listBox5;
		wxBitmapButton* m_bpAdd;
		wxBitmapButton* m_bpRemove;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textCtrl9;
		wxStaticText* m_staticText22;
		wxComboBox* m_comboBox6;
		wxStaticText* m_staticText77;
		wxComboBox* m_comboBox14;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textCtrl10;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_textCtrl11;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_textCtrl12;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_textCtrl13;
		
		wxCheckBox* m_checkBox2;
		wxStaticText* m_staticText27;
		wxDatePickerCtrl* m_datePicker6;
		wxStaticText* m_staticText28;
		wxDatePickerCtrl* m_datePicker7;
		wxBitmapButton* m_bpButton19;
		wxBitmapButton* m_bpButton20;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddJudge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveJudge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDiscard( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		JudgesMngr( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Judges manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 765,557 ), long style = wxDEFAULT_DIALOG_STYLE );
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
			wxID_DISCARD,
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
			wxID_DISCARD,
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
			wxID_ADDALL = 1000,
			wxID_ADDONE,
			wxID_REMOVEONE,
			wxID_REMOVEALL,
			wxID_DISCARD,
		};
		
		wxStaticText* m_staticText8;
		wxListBox* m_listBox2;
		wxBitmapButton* m_bpAddAll;
		wxBitmapButton* m_bpAddOne;
		wxBitmapButton* m_bpRemoveOne;
		wxBitmapButton* m_bpRemoveAll;
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
			wxID_DISCARD,
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

#endif //__udf__