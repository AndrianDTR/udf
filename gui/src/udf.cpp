///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "udf.h"

#include "../res/button_account.xpm"
#include "../res/button_add.xpm"
#include "../res/button_assign.xpm"
#include "../res/button_cancel.xpm"
#include "../res/button_categories.xpm"
#include "../res/button_categoryadd.xpm"
#include "../res/button_categoryremove.xpm"
#include "../res/button_danceradd.xpm"
#include "../res/button_dancerremove.xpm"
#include "../res/button_delete.xpm"
#include "../res/button_judges.xpm"
#include "../res/button_left.xpm"
#include "../res/button_leftall.xpm"
#include "../res/button_mark.xpm"
#include "../res/button_minus.xpm"
#include "../res/button_ok.xpm"
#include "../res/button_other.xpm"
#include "../res/button_plus.xpm"
#include "../res/button_random.xpm"
#include "../res/button_report.xpm"
#include "../res/button_results.xpm"
#include "../res/button_right.xpm"
#include "../res/button_rightall.xpm"
#include "../res/button_startnumber.xpm"
#include "../res/button_undo.xpm"
#include "../res/button_update2.xpm"
#include "../res/button_user.xpm"
#include "../res/mail.xpm"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( DancersTeamMngr, wxDialog )
	EVT_TEXT( ID_SEARCH, DancersTeamMngr::_wxFB_OnSearch )
	EVT_LISTBOX( ID_TEAM_LIST, DancersTeamMngr::_wxFB_OnSelectTeam )
	EVT_BUTTON( wxID_ADD, DancersTeamMngr::_wxFB_OnAddTeam )
	EVT_BUTTON( wxID_REMOVE, DancersTeamMngr::_wxFB_OnRemoveTeam )
	EVT_BUTTON( ID_APPLY, DancersTeamMngr::_wxFB_OnUpdate )
	EVT_BUTTON( wxID_OK, DancersTeamMngr::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, DancersTeamMngr::_wxFB_OnDiscard )
	EVT_COMBOBOX( ID_CLUB, DancersTeamMngr::_wxFB_OnClubChanged )
	EVT_BUTTON( wxID_ADDDANCERTEAMCATEGORY, DancersTeamMngr::_wxFB_OnAddDancerTeamCategory )
	EVT_BUTTON( wxID_REMOVEDANCERTEAMCATEGORY, DancersTeamMngr::_wxFB_OnRemoveDancerTeamCategory )
	EVT_BUTTON( wxID_ADDDANCER, DancersTeamMngr::_wxFB_OnAddDancer2Team )
	EVT_BUTTON( wxID_REMOVEDANCER, DancersTeamMngr::_wxFB_OnRemoveDancerFromTeam )
END_EVENT_TABLE()

DancersTeamMngr::DancersTeamMngr( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Teams") ), wxVERTICAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer18->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer2->Add( bSizer18, 0, wxEXPAND, 5 );
	
	m_listTeams = new wxListBox( this, ID_TEAM_LIST, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer2->Add( m_listTeams, 1, wxALL|wxEXPAND, 5 );
	
	bSizer73->Add( sbSizer2, 1, wxEXPAND|wxALL, 5 );
	
	bSizer16->Add( bSizer73, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer74->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer74->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpApply = new wxBitmapButton( this, ID_APPLY, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer74->Add( m_bpApply, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpSave->SetDefault(); 
	bSizer74->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer74->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer181->Add( bSizer74, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("Team name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer2->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_TEAM_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText89 = new wxStaticText( this, wxID_ANY, _("Club"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText89->Wrap( -1 );
	fgSizer2->Add( m_staticText89, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboClub = new wxComboBox( this, ID_CLUB, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0, NULL, 0 ); 
	fgSizer2->Add( m_comboClub, 1, wxALL|wxEXPAND, 5 );
	
	bSizer181->Add( fgSizer2, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Categories") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer11->AddGrowableCol( 0 );
	fgSizer11->AddGrowableRow( 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );
	
	m_comboCsCategories = new wxComboBox( this, ID_CATEGORIES_COMBO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer91->Add( m_comboCsCategories, 0, wxALL|wxEXPAND, 5 );
	
	m_listTeamCategories = new wxListBox( this, ID_TEAM_CATS_LIST, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer91->Add( m_listTeamCategories, 0, wxALL|wxEXPAND, 5 );
	
	fgSizer11->Add( bSizer91, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxVERTICAL );
	
	m_bpAddDancerTeamCategory = new wxBitmapButton( this, wxID_ADDDANCERTEAMCATEGORY, wxBitmap( button_categoryadd_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer92->Add( m_bpAddDancerTeamCategory, 0, wxALL, 5 );
	
	m_bpRemoveDancerTeamCategory = new wxBitmapButton( this, wxID_REMOVEDANCERTEAMCATEGORY, wxBitmap( button_categoryremove_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer92->Add( m_bpRemoveDancerTeamCategory, 0, wxALL, 5 );
	
	fgSizer11->Add( bSizer92, 1, wxEXPAND, 5 );
	
	sbSizer3->Add( fgSizer11, 1, wxEXPAND, 5 );
	
	bSizer181->Add( sbSizer3, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Dancers") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer12->AddGrowableCol( 0 );
	fgSizer12->AddGrowableRow( 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer90;
	bSizer90 = new wxBoxSizer( wxVERTICAL );
	
	m_comboDancers = new wxComboBox( this, ID_DANCERS_COMBO, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer90->Add( m_comboDancers, 0, wxALL|wxEXPAND, 5 );
	
	m_listDancers = new wxListBox( this, ID_DANCERS_LIST, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer90->Add( m_listDancers, 1, wxALL|wxEXPAND, 5 );
	
	fgSizer12->Add( bSizer90, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );
	
	m_bpAddDancerTeamDancer = new wxBitmapButton( this, wxID_ADDDANCER, wxBitmap( button_danceradd_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer57->Add( m_bpAddDancerTeamDancer, 0, wxALL, 5 );
	
	m_bpRemoveDancerTeamDancer = new wxBitmapButton( this, wxID_REMOVEDANCER, wxBitmap( button_dancerremove_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer57->Add( m_bpRemoveDancerTeamDancer, 0, wxALL, 5 );
	
	fgSizer12->Add( bSizer57, 1, wxEXPAND, 5 );
	
	sbSizer4->Add( fgSizer12, 1, wxEXPAND, 5 );
	
	bSizer181->Add( sbSizer4, 1, wxEXPAND|wxALL, 5 );
	
	bSizer16->Add( bSizer181, 1, wxEXPAND, 5 );
	
	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

DancersTeamMngr::~DancersTeamMngr()
{
}

BEGIN_EVENT_TABLE( ChampionshipCategoriesMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADDALL, ChampionshipCategoriesMngrDlg::_wxFB_OnAddAll )
	EVT_BUTTON( wxID_ADDONE, ChampionshipCategoriesMngrDlg::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVEONE, ChampionshipCategoriesMngrDlg::_wxFB_OnRemove )
	EVT_BUTTON( wxID_REMOVEALL, ChampionshipCategoriesMngrDlg::_wxFB_OnRemoveAll )
	EVT_BUTTON( wxID_OK, ChampionshipCategoriesMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, ChampionshipCategoriesMngrDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

ChampionshipCategoriesMngrDlg::ChampionshipCategoriesMngrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("All categories"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer9->Add( m_staticText8, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_listAll = new wxListBox( this, ID_LIST_ALL, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_MULTIPLE ); 
	bSizer9->Add( m_listAll, 1, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_bpAddAll = new wxBitmapButton( this, wxID_ADDALL, wxBitmap( button_rightall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpAddAll, 0, wxALL, 5 );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADDONE, wxBitmap( button_right_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVEONE, wxBitmap( button_left_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpRemoveAll = new wxBitmapButton( this, wxID_REMOVEALL, wxBitmap( button_leftall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpRemoveAll, 0, wxALL, 5 );
	
	bSizer8->Add( bSizer10, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("Categories for championship"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer11->Add( m_staticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_listSelected = new wxListBox( this, ID_SELECTED_LIST, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_MULTIPLE ); 
	bSizer11->Add( m_listSelected, 1, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer11, 1, wxEXPAND, 5 );
	
	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton31 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton31->SetDefault(); 
	bSizer34->Add( m_bpButton31, 0, wxALL, 5 );
	
	m_bpButton32 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpButton32, 0, wxALL, 5 );
	
	bSizer7->Add( bSizer34, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

ChampionshipCategoriesMngrDlg::~ChampionshipCategoriesMngrDlg()
{
}

BEGIN_EVENT_TABLE( CategoriesMngrDlg, wxDialog )
	EVT_TEXT( ID_CATEGORY_LIST_SEARCH, CategoriesMngrDlg::_wxFB_OnCategorySearch )
	EVT_LISTBOX( ID_CATEGORY_LIST, CategoriesMngrDlg::_wxFB_OnCategorySelected )
	EVT_BUTTON( wxID_ADD, CategoriesMngrDlg::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVE, CategoriesMngrDlg::_wxFB_OnRemove )
	EVT_BUTTON( wxID_APPLY, CategoriesMngrDlg::_wxFB_OnUpdate )
	EVT_BUTTON( wxID_OK, CategoriesMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, CategoriesMngrDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

CategoriesMngrDlg::CategoriesMngrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Categories list") ), wxVERTICAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer18->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_CATEGORY_LIST_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer10->Add( bSizer18, 0, wxEXPAND, 5 );
	
	m_listCategories = new wxListBox( this, ID_CATEGORY_LIST, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer10->Add( m_listCategories, 1, wxALL, 5 );
	
	bSizer16->Add( sbSizer10, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton13 = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer75->Add( m_bpButton13, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer75->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpUpdate = new wxBitmapButton( this, wxID_APPLY, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer75->Add( m_bpUpdate, 0, wxALL, 5 );
	
	m_bpButton29 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton29->SetDefault(); 
	bSizer75->Add( m_bpButton29, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer75->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer181->Add( bSizer75, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 5, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer2->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textName->SetMaxLength( 30 ); 
	fgSizer2->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Short name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	fgSizer2->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textShortName = new wxTextCtrl( this, ID_SHORTNAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textShortName->SetMaxLength( 100 ); 
	fgSizer2->Add( m_textShortName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Dance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	fgSizer2->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboDance = new wxComboBox( this, ID_DANCE_LIST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer2->Add( m_comboDance, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Liga"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer2->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboLiga = new wxComboBox( this, ID_LIGA_LIST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer2->Add( m_comboLiga, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText191 = new wxStaticText( this, wxID_ANY, _("Age"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText191->Wrap( -1 );
	fgSizer2->Add( m_staticText191, 0, wxALL, 5 );
	
	m_comboAge = new wxComboBox( this, ID_AGE_LIST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer2->Add( m_comboAge, 0, wxALL|wxEXPAND, 5 );
	
	bSizer181->Add( fgSizer2, 1, wxEXPAND, 5 );
	
	bSizer16->Add( bSizer181, 1, wxEXPAND, 5 );
	
	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

CategoriesMngrDlg::~CategoriesMngrDlg()
{
}

BEGIN_EVENT_TABLE( ClubsMngrDlg, wxDialog )
	EVT_TEXT( ID_SEARCH, ClubsMngrDlg::_wxFB_OnSearch )
	EVT_LISTBOX( ID_CLUBLIST, ClubsMngrDlg::_wxFB_OnSelectClub )
	EVT_BUTTON( wxID_ADDCLUB, ClubsMngrDlg::_wxFB_OnAddClub )
	EVT_BUTTON( wxID_APPLY, ClubsMngrDlg::_wxFB_OnUpdate )
	EVT_BUTTON( wxID_REMOVECLUB, ClubsMngrDlg::_wxFB_OnRemoveClub )
	EVT_BUTTON( wxID_ACCOUNTINFO, ClubsMngrDlg::_wxFB_OnAccountInfo )
	EVT_BUTTON( wxID_DIRECTORINFO, ClubsMngrDlg::_wxFB_OnDirectorInfo )
	EVT_BUTTON( wxID_TRAINERS, ClubsMngrDlg::_wxFB_OnTrainersMngr )
	EVT_BUTTON( wxID_DANCERS, ClubsMngrDlg::_wxFB_OnDancersMngr )
	EVT_BUTTON( wxID_OK, ClubsMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, ClubsMngrDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

ClubsMngrDlg::ClubsMngrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("List of clubs") ), wxVERTICAL );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer23->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer8->Add( bSizer23, 0, wxEXPAND, 5 );
	
	m_listClubs = new wxListBox( this, ID_CLUBLIST, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer8->Add( m_listClubs, 1, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( sbSizer8, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAddClub = new wxBitmapButton( this, wxID_ADDCLUB, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpAddClub, 0, wxALL, 5 );
	
	m_bpUpdate = new wxBitmapButton( this, wxID_APPLY, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpUpdate, 0, wxALL, 5 );
	
	m_bpRemoveClub = new wxBitmapButton( this, wxID_REMOVECLUB, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpRemoveClub, 0, wxALL, 5 );
	
	m_bpAccountInfo = new wxBitmapButton( this, wxID_ACCOUNTINFO, wxBitmap( button_account_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpAccountInfo, 0, wxALL, 5 );
	
	m_bpDirectorInfo = new wxBitmapButton( this, wxID_DIRECTORINFO, wxBitmap( button_user_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpDirectorInfo, 0, wxALL, 5 );
	
	m_bpTarinersMngr = new wxBitmapButton( this, wxID_TRAINERS, wxBitmap( button_other_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpTarinersMngr, 0, wxALL, 5 );
	
	m_bpDancersMngr = new wxBitmapButton( this, wxID_DANCERS, wxBitmap( button_other_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpDancersMngr, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpSave->SetDefault(); 
	bSizer24->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpCancel = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpCancel, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer24, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 8, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 5 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer3->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textName->SetMaxLength( 50 ); 
	fgSizer3->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("City"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboCity = new wxComboBox( this, ID_CITY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboCity, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer3->Add( m_staticText23, 0, wxALL, 5 );
	
	m_textAddress = new wxTextCtrl( this, ID_ADDRESS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	fgSizer3->Add( m_textAddress, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer3->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textEmail = new wxTextCtrl( this, ID_EMAIL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textEmail->SetMaxLength( 50 ); 
	fgSizer3->Add( m_textEmail, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Web"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer3->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textWeb = new wxTextCtrl( this, ID_WEB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textWeb->SetMaxLength( 50 ); 
	fgSizer3->Add( m_textWeb, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Additional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer3->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textInfo = new wxTextCtrl( this, ID_INFO, wxEmptyString, wxDefaultPosition, wxSize( -1,70 ), wxTE_MULTILINE );
	fgSizer3->Add( m_textInfo, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Pay date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer3->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePay = new wxDatePickerCtrl( this, ID_PAYDATE, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_datePay, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("Exp. date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer3->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateExp = new wxDatePickerCtrl( this, ID_EXPDATE, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_dateExp, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer22->Add( bSizer73, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

ClubsMngrDlg::~ClubsMngrDlg()
{
}

BEGIN_EVENT_TABLE( MainFrameBase, wxFrame )
	EVT_CLOSE( MainFrameBase::_wxFB_OnCloseFrame )
	EVT_MENU( wxID_EXIT, MainFrameBase::_wxFB_OnExitClick )
	EVT_MENU( ID_MENU_MNGR_CLUBS, MainFrameBase::_wxFB_OnMenuClubManage )
	EVT_MENU( ID_MENU_MNGR_JUDGE, MainFrameBase::_wxFB_OnMenuJudgeManage )
	EVT_MENU( ID_MENU_MNGR_CATEGORIES, MainFrameBase::_wxFB_OnMenuCategoryManage )
	EVT_MENU( ID_MENU_MNGR_DANCE_TYPES, MainFrameBase::_wxFB_OnDanceTypesCodeMgr )
	EVT_MENU( ID_MENU_MNGR_LIGUES, MainFrameBase::_wxFB_OnLigueCodeMgr )
	EVT_MENU( ID_MENU_MNGR_AGE_CATEGORIES, MainFrameBase::_wxFB_OnAgeCodesMgr )
	EVT_MENU( ID_MENU_MNGR_ChTYPES_MNGR, MainFrameBase::_wxFB_OnMenuChampionshipTypes )
	EVT_MENU( ID_MENU_MNGR_CITIES, MainFrameBase::_wxFB_OnCitiesMngr )
	EVT_MENU( ID_MENU_MNGR_COUNTRIES, MainFrameBase::_wxFB_OnCountriesMngr )
	EVT_MENU( ID_MENU_TOOLS_SYUNC, MainFrameBase::_wxFB_OnMenySync )
	EVT_MENU( ID_MENU_TOOLS_OPTIONS, MainFrameBase::_wxFB_OnMenuOptions )
	EVT_MENU( ID_ABOUT, MainFrameBase::_wxFB_OnAboutDlg )
	EVT_TEXT( ID_SEARCH, MainFrameBase::_wxFB_OnSearch )
	EVT_LISTBOX( ID_LIST_CHAMPIONSHIP, MainFrameBase::_wxFB_OnSelectChampionship )
	EVT_TREE_SEL_CHANGED( ID_CS_TREE, MainFrameBase::_wxFB_OnCsSelect )
	EVT_BUTTON( wxID_CHAMPIONSIP_ADD, MainFrameBase::_wxFB_OnAddChampionsip )
	EVT_BUTTON( wxID_CHAMPIONSIP_REMOVE, MainFrameBase::_wxFB_OnRemoveChampionship )
	EVT_BUTTON( wxID_CHAMPIONSHIP_SAVE, MainFrameBase::_wxFB_OnSave )
	EVT_BUTTON( wxID_CHAMPIONSHIP_DISCARD, MainFrameBase::_wxFB_OnDiscard )
	EVT_BUTTON( wxID_CHAMPIONSHIP_CATEGORIES, MainFrameBase::_wxFB_OnCategoryMngr )
	EVT_BUTTON( wxID_CHAMPIONSHIP_JUDGESTEAMMNGR, MainFrameBase::_wxFB_OnJudgeMngr )
	EVT_BUTTON( wxID_CHAMPIONSHIP_SENDINVITATION, MainFrameBase::_wxFB_OnSendInvitation )
	EVT_BUTTON( ID_TEAMS, MainFrameBase::_wxFB_OnDancersTeams )
	EVT_BUTTON( wxID_CHAMPIONSHIP_STARTNUMBERMNGR, MainFrameBase::_wxFB_OnStartNumberAssign )
	EVT_BUTTON( ID_TOURS, MainFrameBase::_wxFB_OnToursManager )
END_EVENT_TABLE()

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menuBar = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	wxMenuItem* menuFileExit;
	menuFileExit = new wxMenuItem( m_menuFile, wxID_EXIT, wxString( _("E&xit") ) + wxT('\t') + wxT("Alt+X"), wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( menuFileExit );
	
	m_menuBar->Append( m_menuFile, _("&File") );
	
	m_menu8 = new wxMenu();
	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( m_menu8, ID_CS_ADD, wxString( _("Add new championship") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem11 );
	
	wxMenuItem* m_menuItem12;
	m_menuItem12 = new wxMenuItem( m_menu8, ID_CS_REMOVE, wxString( _("Remove current championship") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem12 );
	
	wxMenuItem* m_menuItem13;
	m_menuItem13 = new wxMenuItem( m_menu8, ID_CS_UPDATE, wxString( _("Save changes") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem13 );
	
	wxMenuItem* m_separator2;
	m_separator2 = m_menu8->AppendSeparator();
	
	wxMenuItem* m_menuItem15;
	m_menuItem15 = new wxMenuItem( m_menu8, ID_CS_CATEGORIES, wxString( _("Categories") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem15 );
	
	wxMenuItem* m_menuItem17;
	m_menuItem17 = new wxMenuItem( m_menu8, ID_CS_STARTNUMB, wxString( _("Start number assign") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem17 );
	
	wxMenuItem* m_menuItem18;
	m_menuItem18 = new wxMenuItem( m_menu8, ID_CS_JUDGESTEAM, wxString( _("Judges team") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem18 );
	
	wxMenuItem* m_menuItem19;
	m_menuItem19 = new wxMenuItem( m_menu8, ID_CS_INVITATIONS, wxString( _("Send invitations") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem19 );
	
	wxMenuItem* m_menuItem20;
	m_menuItem20 = new wxMenuItem( m_menu8, ID_CS_RESULTS, wxString( _("Results") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem20 );
	
	wxMenuItem* m_menuItem21;
	m_menuItem21 = new wxMenuItem( m_menu8, ID_CS_RAITING, wxString( _("Raiting") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem21 );
	
	m_menuBar->Append( m_menu8, _("Championship") );
	
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu2, ID_MENU_MNGR_CLUBS, wxString( _("Clubs") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem5 );
	
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu2, ID_MENU_MNGR_JUDGE, wxString( _("Judges") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem6 );
	
	wxMenuItem* m_separator21;
	m_separator21 = m_menu2->AppendSeparator();
	
	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( m_menu2, ID_MENU_MNGR_CATEGORIES, wxString( _("Categories") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem9 );
	
	wxMenuItem* m_menuItem62;
	m_menuItem62 = new wxMenuItem( m_menu2, ID_MENU_MNGR_DANCE_TYPES, wxString( _("Dance types") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem62 );
	
	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem( m_menu2, ID_MENU_MNGR_LIGUES, wxString( _("Ligues") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem7 );
	
	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( m_menu2, ID_MENU_MNGR_AGE_CATEGORIES, wxString( _("Age gategories") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem8 );
	
	wxMenuItem* m_menuItem201;
	m_menuItem201 = new wxMenuItem( m_menu2, ID_MENU_MNGR_ChTYPES_MNGR, wxString( _("Championship types") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem201 );
	
	wxMenuItem* m_separator3;
	m_separator3 = m_menu2->AppendSeparator();
	
	wxMenuItem* m_menuItem10;
	m_menuItem10 = new wxMenuItem( m_menu2, ID_MENU_MNGR_CITIES, wxString( _("Cities") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem10 );
	
	wxMenuItem* m_menuItem91;
	m_menuItem91 = new wxMenuItem( m_menu2, ID_MENU_MNGR_COUNTRIES, wxString( _("Countries") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem91 );
	
	m_menuBar->Append( m_menu2, _("Manage") );
	
	m_menu5 = new wxMenu();
	wxMenuItem* m_menuItem211;
	m_menuItem211 = new wxMenuItem( m_menu5, ID_MENU_TOOLS_SYUNC, wxString( _("Synchronize DB") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItem211 );
	
	wxMenuItem* m_separator4;
	m_separator4 = m_menu5->AppendSeparator();
	
	wxMenuItem* m_menuItem22;
	m_menuItem22 = new wxMenuItem( m_menu5, ID_MENU_TOOLS_OPTIONS, wxString( _("Options") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItem22 );
	
	m_menuBar->Append( m_menu5, _("Tools") );
	
	m_menu51 = new wxMenu();
	wxMenuItem* m_menuItem61;
	m_menuItem61 = new wxMenuItem( m_menu51, ID_ABOUT, wxString( _("About") ) , _("Show information about program."), wxITEM_NORMAL );
	m_menu51->Append( m_menuItem61 );
	
	m_menuBar->Append( m_menu51, _("Help") );
	
	this->SetMenuBar( m_menuBar );
	
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Championship list") ), wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_championshipSearchText = new wxStaticText( m_panel1, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_championshipSearchText->Wrap( -1 );
	bSizer5->Add( m_championshipSearchText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( m_panel1, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer9->Add( bSizer5, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	m_listChampionship = new wxListBox( m_panel1, ID_LIST_CHAMPIONSHIP, wxDefaultPosition, wxSize( 310,-1 ), 0, NULL, 0 ); 
	sbSizer9->Add( m_listChampionship, 1, wxALL|wxEXPAND, 5 );
	
	m_treeCs = new wxTreeCtrl( m_panel1, ID_CS_TREE, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_FULL_ROW_HIGHLIGHT|wxTR_HIDE_ROOT|wxTR_SINGLE );
	sbSizer9->Add( m_treeCs, 1, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( sbSizer9, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( m_panel1, wxID_CHAMPIONSIP_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( m_panel1, wxID_CHAMPIONSIP_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_SAVE, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_DISCARD, wxBitmap( button_undo_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpDiscard, 0, wxALL, 5 );
	
	m_bpCategoryMngr = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_CATEGORIES, wxBitmap( button_categories_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpCategoryMngr, 0, wxALL, 5 );
	
	m_bpJudgesMngr = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_JUDGESTEAMMNGR, wxBitmap( button_judges_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpJudgesMngr, 0, wxALL, 5 );
	
	m_bpSendinvitation = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_SENDINVITATION, wxBitmap( mail_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpSendinvitation, 0, wxALL, 5 );
	
	m_bpDancersTeams = new wxBitmapButton( m_panel1, ID_TEAMS, wxBitmap( button_other_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpDancersTeams, 0, wxALL, 5 );
	
	m_bpStartNumberMngr = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_STARTNUMBERMNGR, wxBitmap( button_startnumber_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpStartNumberMngr, 0, wxALL, 5 );
	
	m_bpTours = new wxBitmapButton( m_panel1, ID_TOURS, wxBitmap( button_results_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpTours, 0, wxALL, 5 );
	
	bSizer13->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 6, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( m_panel1, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer1->Add( m_staticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textChName = new wxTextCtrl( m_panel1, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textChName->SetMaxLength( 100 ); 
	fgSizer1->Add( m_textChName, 0, wxEXPAND|wxALL, 5 );
	
	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_comboType = new wxComboBox( m_panel1, ID_TYPE, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, 0 ); 
	fgSizer1->Add( m_comboType, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText5 = new wxStaticText( m_panel1, wxID_ANY, _("Date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer1->Add( m_staticText5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_dateDate = new wxDatePickerCtrl( m_panel1, ID_DATE, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer1->Add( m_dateDate, 0, wxALL, 5 );
	
	m_staticText7 = new wxStaticText( m_panel1, wxID_ANY, _("City"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_comboCity = new wxComboBox( m_panel1, ID_CITY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, 0 ); 
	fgSizer1->Add( m_comboCity, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText8 = new wxStaticText( m_panel1, wxID_ANY, _("Adsress"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer1->Add( m_staticText8, 0, wxALL, 5 );
	
	m_textAddress = new wxTextCtrl( m_panel1, ID_ADDRESS, wxEmptyString, wxDefaultPosition, wxSize( -1,50 ), wxTE_MULTILINE );
	fgSizer1->Add( m_textAddress, 0, wxEXPAND|wxALL, 5 );
	
	bSizer13->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Online registration") ), wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( m_panel1, wxID_ANY, _("Open date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	sbSizer1->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateRegOpen = new wxDatePickerCtrl( m_panel1, ID_REG_OPEN, wxDefaultDateTime, wxDefaultPosition, wxSize( -1,25 ), wxDP_DEFAULT|wxDP_SHOWCENTURY );
	sbSizer1->Add( m_dateRegOpen, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( m_panel1, wxID_ANY, _("Close date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	sbSizer1->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateRegClose = new wxDatePickerCtrl( m_panel1, ID_REG_CLOSE, wxDefaultDateTime, wxDefaultPosition, wxSize( -1,25 ), wxDP_DEFAULT|wxDP_SHOWCENTURY );
	sbSizer1->Add( m_dateRegClose, 0, wxALL|wxEXPAND, 5 );
	
	bSizer13->Add( sbSizer1, 0, wxEXPAND|wxALL, 5 );
	
	m_staticText14 = new wxStaticText( m_panel1, wxID_ANY, _("Aditional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer13->Add( m_staticText14, 0, wxALL, 5 );
	
	m_textAdditionalInfo = new wxTextCtrl( m_panel1, ID_INFO, wxEmptyString, wxDefaultPosition, wxSize( -1,100 ), wxTE_MULTILINE );
	bSizer13->Add( m_textAdditionalInfo, 1, wxALL|wxEXPAND, 5 );
	
	bSizer6->Add( bSizer13, 1, wxEXPAND, 5 );
	
	bSizer2->Add( bSizer6, 1, wxEXPAND, 5 );
	
	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	mainSizer->Add( m_panel1, 1, wxEXPAND, 5 );
	
	this->SetSizer( mainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

MainFrameBase::~MainFrameBase()
{
}

BEGIN_EVENT_TABLE( DirectorInfo, wxDialog )
	EVT_BUTTON( wxID_OK, DirectorInfo::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, DirectorInfo::_wxFB_OnDiscard )
END_EVENT_TABLE()

DirectorInfo::DirectorInfo( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 6, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer4->Add( m_staticText29, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText30 = new wxStaticText( this, wxID_ANY, _("Birth date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	fgSizer4->Add( m_staticText30, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateBd = new wxDatePickerCtrl( this, ID_BD, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer4->Add( m_dateBd, 0, wxALL, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Phone"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer4->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textPhone = new wxTextCtrl( this, ID_PHONE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textPhone, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, _("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	fgSizer4->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textEmail = new wxTextCtrl( this, ID_EMAIL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textEmail, 0, wxALL|wxEXPAND, 5 );
	
	bSizer25->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton25 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton25->SetDefault(); 
	bSizer26->Add( m_bpButton25, 0, wxALL, 5 );
	
	m_bpButton26 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer26->Add( m_bpButton26, 0, wxALL, 5 );
	
	bSizer25->Add( bSizer26, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer25 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

DirectorInfo::~DirectorInfo()
{
}

BEGIN_EVENT_TABLE( TrainersMngrDlg, wxDialog )
	EVT_TEXT( ID_SEARCH, TrainersMngrDlg::_wxFB_OnSearch )
	EVT_LISTBOX( ID_TRAINERS_LIST, TrainersMngrDlg::_wxFB_OnSelectTrainer )
	EVT_BUTTON( wxID_ADD, TrainersMngrDlg::_wxFB_OnAddTrainer )
	EVT_BUTTON( wxID_UPDATE, TrainersMngrDlg::_wxFB_OnUpdate )
	EVT_BUTTON( wxID_REMOVE, TrainersMngrDlg::_wxFB_OnRemoveTrainer )
	EVT_BUTTON( wxID_OK, TrainersMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, TrainersMngrDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

TrainersMngrDlg::TrainersMngrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Tariners list") ), wxVERTICAL );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer23->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer5->Add( bSizer23, 0, wxEXPAND, 5 );
	
	m_listTrainers = new wxListBox( this, ID_TRAINERS_LIST, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer5->Add( m_listTrainers, 1, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( sbSizer5, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAddTrainer = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpAddTrainer, 0, wxALL, 5 );
	
	m_bpUpdate = new wxBitmapButton( this, wxID_UPDATE, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpUpdate, 0, wxALL, 5 );
	
	m_bpRemoveTrainer = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpRemoveTrainer, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpSave->SetDefault(); 
	bSizer76->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer76, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 8, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 5 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer3->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("Club"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboClub = new wxComboBox( this, ID_CLUB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboClub, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Phone"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer3->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textPhone = new wxTextCtrl( this, ID_PHONE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textPhone, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer3->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textEmail = new wxTextCtrl( this, ID_EMAIL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textEmail, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Birth date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer3->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateBd = new wxDatePickerCtrl( this, ID_BD, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_dateBd, 0, wxALL, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Additional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer3->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textInfo = new wxTextCtrl( this, ID_INFO, wxEmptyString, wxDefaultPosition, wxSize( -1,70 ), wxTE_MULTILINE );
	fgSizer3->Add( m_textInfo, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Pay date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer3->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePay = new wxDatePickerCtrl( this, ID_PAY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_datePay, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("Exp. date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer3->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateExp = new wxDatePickerCtrl( this, ID_EXPIRE, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_dateExp, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

TrainersMngrDlg::~TrainersMngrDlg()
{
}

BEGIN_EVENT_TABLE( CsTours, wxDialog )
	EVT_LISTBOX( ID_TOURS_LIST, CsTours::_wxFB_OnSelectTour )
	EVT_BUTTON( wxID_ADD, CsTours::_wxFB_OnAddTour )
	EVT_BUTTON( wxID_REMOVE, CsTours::_wxFB_OnRemoveTour )
	EVT_BUTTON( ID_MARKS, CsTours::_wxFB_OnJudgesMark )
	EVT_BUTTON( ID_REPORT, CsTours::_wxFB_OnReport )
	EVT_BUTTON( wxID_OK, CsTours::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, CsTours::_wxFB_OnDiscard )
END_EVENT_TABLE()

CsTours::CsTours( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Tours") ), wxVERTICAL );
	
	m_listTours = new wxListBox( this, ID_TOURS_LIST, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer5->Add( m_listTours, 1, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( sbSizer5, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpMarks = new wxBitmapButton( this, ID_MARKS, wxBitmap( button_mark_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpMarks, 0, wxALL, 5 );
	
	m_bpReport = new wxBitmapButton( this, ID_REPORT, wxBitmap( button_report_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpReport, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpSave->SetDefault(); 
	bSizer76->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer76, 0, wxALIGN_RIGHT, 5 );
	
	
	bSizer22->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer3->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("Selection limit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textLimit = new wxTextCtrl( this, ID_LIMIT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textLimit, 0, wxALL, 5 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkFinal = new wxCheckBox( this, ID_FINAL, _("Final"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_checkFinal, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 0, wxEXPAND, 5 );
	
	
	bSizer22->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

CsTours::~CsTours()
{
}

BEGIN_EVENT_TABLE( CsTourReport, wxDialog )
	EVT_BUTTON( ID_PRINT, CsTourReport::_wxFB_OnReport )
	EVT_BUTTON( wxID_CANCEL, CsTourReport::_wxFB_OnDiscard )
	EVT_LIST_BEGIN_DRAG( ID_LIST_TEAMS, CsTourReport::_wxFB_OnBeginDrag )
	EVT_LIST_ITEM_SELECTED( ID_LIST_TEAMS, CsTourReport::_wxFB_OnTeamSelect )
END_EVENT_TABLE()

CsTourReport::CsTourReport( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText94 = new wxStaticText( this, wxID_ANY, _("Teams"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	m_staticText94->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer76->Add( m_staticText94, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	
	bSizer76->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bpPrint = new wxBitmapButton( this, ID_PRINT, wxBitmap( button_report_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpPrint, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer76, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	m_listTeams = new wxListCtrl( this, ID_LIST_TEAMS, wxDefaultPosition, wxDefaultSize, wxLC_AUTOARRANGE|wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_DESCENDING|wxLC_VRULES );
	bSizer22->Add( m_listTeams, 1, wxALL|wxEXPAND, 5 );
	
	m_staticJudgeDescr = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticJudgeDescr->Wrap( -1 );
	bSizer22->Add( m_staticJudgeDescr, 0, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

CsTourReport::~CsTourReport()
{
}

BEGIN_EVENT_TABLE( DancersMngrDlg, wxDialog )
	EVT_TEXT( ID_SEARCH, DancersMngrDlg::_wxFB_OnSearch )
	EVT_LISTBOX( ID_DANCERS_LIST, DancersMngrDlg::_wxFB_OnDancerSelect )
	EVT_BUTTON( wxID_ADD, DancersMngrDlg::_wxFB_OnAddDancer )
	EVT_BUTTON( wxID_REMOVE, DancersMngrDlg::_wxFB_OnRemoveDancer )
	EVT_BUTTON( wxID_APPLY, DancersMngrDlg::_wxFB_OnUpdate )
	EVT_BUTTON( wxID_OK, DancersMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, DancersMngrDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

DancersMngrDlg::DancersMngrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 957,544 ), wxDefaultSize );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Club dancers list") ), wxVERTICAL );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText78 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText78->Wrap( -1 );
	bSizer21->Add( m_staticText78, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_textSearch, 1, wxALL, 5 );
	
	sbSizer6->Add( bSizer21, 0, wxEXPAND, 5 );
	
	m_listDancers = new wxListBox( this, ID_DANCERS_LIST, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer6->Add( m_listDancers, 1, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( sbSizer6, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAddDancer = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer77->Add( m_bpAddDancer, 0, wxALL, 5 );
	
	m_bpRemoveDancer = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer77->Add( m_bpRemoveDancer, 0, wxALL, 5 );
	
	m_bpUpdate = new wxBitmapButton( this, wxID_APPLY, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer77->Add( m_bpUpdate, 0, wxALL, 5 );
	
	m_bpOk = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpOk->SetDefault(); 
	bSizer77->Add( m_bpOk, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer77->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer77, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 12, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 8 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer3->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Reg book ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer3->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textRegbook = new wxTextCtrl( this, ID_REGBOOK, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textRegbook, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText54 = new wxStaticText( this, wxID_ANY, _("Raiting"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	fgSizer3->Add( m_staticText54, 0, wxALL, 5 );
	
	m_staticRaiting = new wxStaticText( this, ID_RAITING, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRaiting->Wrap( -1 );
	m_staticRaiting->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer3->Add( m_staticRaiting, 0, wxALL, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("Club"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboClub = new wxComboBox( this, ID_CLUB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboClub, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText61 = new wxStaticText( this, wxID_ANY, _("Trainer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer3->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboTrainer = new wxComboBox( this, ID_TRAINER, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboTrainer, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText63 = new wxStaticText( this, wxID_ANY, _("Liga"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText63->Wrap( -1 );
	fgSizer3->Add( m_staticText63, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboLiga = new wxComboBox( this, ID_LIGA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboLiga, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("Gender"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer3->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboGender = new wxComboBox( this, ID_GENDER, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN ); 
	fgSizer3->Add( m_comboGender, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Birth date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer3->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateBd = new wxDatePickerCtrl( this, ID_BD, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_dateBd, 0, wxALL, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Additional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer3->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textInfo = new wxTextCtrl( this, ID_INFO, wxEmptyString, wxDefaultPosition, wxSize( -1,70 ), wxTE_MULTILINE );
	fgSizer3->Add( m_textInfo, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Pay date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer3->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePay = new wxDatePickerCtrl( this, ID_PAY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_datePay, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("Exp. date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer3->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateExp = new wxDatePickerCtrl( this, ID_EXPIRE, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_dateExp, 0, wxALL, 5 );
	
	m_staticText62 = new wxStaticText( this, wxID_ANY, _("Reg date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	fgSizer3->Add( m_staticText62, 0, wxALL, 5 );
	
	m_textReg = new wxTextCtrl( this, ID_REG, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer3->Add( m_textReg, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

DancersMngrDlg::~DancersMngrDlg()
{
}

BEGIN_EVENT_TABLE( AccountInfo, wxDialog )
	EVT_CHECKBOX( wxID_ANY, AccountInfo::_wxFB_OnShowPass )
	EVT_BUTTON( wxID_OK, AccountInfo::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, AccountInfo::_wxFB_OnDiscard )
END_EVENT_TABLE()

AccountInfo::AccountInfo( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizer7->AddGrowableCol( 1 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText56 = new wxStaticText( this, wxID_ANY, _("Login"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText56->Wrap( -1 );
	fgSizer7->Add( m_staticText56, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textLogin = new wxTextCtrl( this, ID_LOGIN, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_textLogin, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText57 = new wxStaticText( this, wxID_ANY, _("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText57->Wrap( -1 );
	fgSizer7->Add( m_staticText57, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textPass = new wxTextCtrl( this, ID_PASS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	fgSizer7->Add( m_textPass, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer7->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkShowPass = new wxCheckBox( this, wxID_ANY, _("Show password"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_checkShowPass, 0, wxALL, 5 );
	
	bSizer44->Add( fgSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton39 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton39->SetDefault(); 
	bSizer43->Add( m_bpButton39, 0, wxALL, 5 );
	
	m_bpButton40 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer43->Add( m_bpButton40, 0, wxALL, 5 );
	
	bSizer44->Add( bSizer43, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer44 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

AccountInfo::~AccountInfo()
{
}

BEGIN_EVENT_TABLE( AddTeamCategory, wxDialog )
	EVT_BUTTON( wxID_OK, AddTeamCategory::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, AddTeamCategory::_wxFB_OnDiscard )
END_EVENT_TABLE()

AddTeamCategory::AddTeamCategory( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizer7->AddGrowableCol( 1 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText56 = new wxStaticText( this, wxID_ANY, _("Category"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText56->Wrap( -1 );
	fgSizer7->Add( m_staticText56, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticCategory = new wxStaticText( this, ID_CATEGORY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticCategory->Wrap( -1 );
	fgSizer7->Add( m_staticCategory, 0, wxALL, 5 );
	
	m_staticText57 = new wxStaticText( this, wxID_ANY, _("Compocition name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText57->Wrap( -1 );
	fgSizer7->Add( m_staticText57, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textComposition = new wxTextCtrl( this, ID_PASS, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_textComposition, 0, wxALL|wxEXPAND, 5 );
	
	bSizer44->Add( fgSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton39 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton39->SetDefault(); 
	bSizer43->Add( m_bpButton39, 0, wxALL, 5 );
	
	m_bpButton40 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer43->Add( m_bpButton40, 0, wxALL, 5 );
	
	bSizer44->Add( bSizer43, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer44 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

AddTeamCategory::~AddTeamCategory()
{
}

BEGIN_EVENT_TABLE( JudgesMngr, wxDialog )
	EVT_TEXT( ID_SEARCH, JudgesMngr::_wxFB_OnSearch )
	EVT_LISTBOX( ID_LIST_JUDGES, JudgesMngr::_wxFB_OnSelectJudge )
	EVT_BUTTON( wxID_ADD, JudgesMngr::_wxFB_OnAddJudge )
	EVT_BUTTON( wxID_REMOVE, JudgesMngr::_wxFB_OnRemoveJudge )
	EVT_BUTTON( ID_APPLY, JudgesMngr::_wxFB_OnUpdate )
	EVT_BUTTON( wxID_OK, JudgesMngr::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, JudgesMngr::_wxFB_OnDiscard )
END_EVENT_TABLE()

JudgesMngr::JudgesMngr( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Judges list") ), wxVERTICAL );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer23->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer7->Add( bSizer23, 0, wxEXPAND, 5 );
	
	m_listJudges = new wxListBox( this, ID_LIST_JUDGES, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer7->Add( m_listJudges, 1, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( sbSizer7, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpApply = new wxBitmapButton( this, ID_APPLY, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpApply, 0, wxALL, 5 );
	
	m_bpButton19 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton19->SetDefault(); 
	bSizer76->Add( m_bpButton19, 0, wxALL, 5 );
	
	m_bpButton20 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpButton20, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer76, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 10, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 5 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer3->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText77 = new wxStaticText( this, wxID_ANY, _("City"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText77->Wrap( -1 );
	fgSizer3->Add( m_staticText77, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboCity = new wxComboBox( this, ID_CITY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboCity, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Last attestation info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer3->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textAttestation = new wxTextCtrl( this, ID_ATTESTATION, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textAttestation, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer3->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textEmail = new wxTextCtrl( this, ID_EMAIL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textEmail, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Phone"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer3->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textPhone = new wxTextCtrl( this, ID_PHONE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textPhone, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Additional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer3->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textInfo = new wxTextCtrl( this, ID_INFO, wxEmptyString, wxDefaultPosition, wxSize( -1,70 ), wxTE_MULTILINE );
	fgSizer3->Add( m_textInfo, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkPracticer = new wxCheckBox( this, ID_PRACTICER, _("Practicer"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_checkPracticer, 0, wxALL, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Pay date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer3->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePay = new wxDatePickerCtrl( this, ID_PAY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_datePay, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("Exp. date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer3->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateExp = new wxDatePickerCtrl( this, ID_EXP, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer3->Add( m_dateExp, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

JudgesMngr::~JudgesMngr()
{
}

BEGIN_EVENT_TABLE( TeamCategoryMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADDALL, TeamCategoryMngrDlg::_wxFB_OnAddAll )
	EVT_BUTTON( wxID_ADDONE, TeamCategoryMngrDlg::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVEONE, TeamCategoryMngrDlg::_wxFB_OnRemove )
	EVT_BUTTON( wxID_REMOVEALL, TeamCategoryMngrDlg::_wxFB_OnRemoveAll )
	EVT_BUTTON( wxID_OK, TeamCategoryMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, TeamCategoryMngrDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

TeamCategoryMngrDlg::TeamCategoryMngrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("Championship categories"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer9->Add( m_staticText8, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_listBox2 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer9->Add( m_listBox2, 1, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_bpButton9 = new wxBitmapButton( this, wxID_ADDALL, wxBitmap( button_rightall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpButton9, 0, wxALL, 5 );
	
	m_bpButton10 = new wxBitmapButton( this, wxID_ADDONE, wxBitmap( button_right_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpButton10, 0, wxALL, 5 );
	
	m_bpButton11 = new wxBitmapButton( this, wxID_REMOVEONE, wxBitmap( button_left_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpButton11, 0, wxALL, 5 );
	
	m_bpButton12 = new wxBitmapButton( this, wxID_REMOVEALL, wxBitmap( button_leftall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpButton12, 0, wxALL, 5 );
	
	bSizer8->Add( bSizer10, 0, wxALIGN_BOTTOM, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("Team categories"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer11->Add( m_staticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_listBox3 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer11->Add( m_listBox3, 1, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer11, 1, wxEXPAND, 5 );
	
	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton31 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton31->SetDefault(); 
	bSizer34->Add( m_bpButton31, 0, wxALL, 5 );
	
	m_bpButton32 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpButton32, 0, wxALL, 5 );
	
	bSizer7->Add( bSizer34, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

TeamCategoryMngrDlg::~TeamCategoryMngrDlg()
{
}

BEGIN_EVENT_TABLE( ChampionshipJudgesTeamMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADDALL, ChampionshipJudgesTeamMngrDlg::_wxFB_OnAddAll )
	EVT_BUTTON( wxID_ADDONE, ChampionshipJudgesTeamMngrDlg::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVEONE, ChampionshipJudgesTeamMngrDlg::_wxFB_OnRemove )
	EVT_BUTTON( wxID_REMOVEALL, ChampionshipJudgesTeamMngrDlg::_wxFB_OnRemoveAll )
	EVT_BUTTON( wxID_OK, ChampionshipJudgesTeamMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, ChampionshipJudgesTeamMngrDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

ChampionshipJudgesTeamMngrDlg::ChampionshipJudgesTeamMngrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("All  judges"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer9->Add( m_staticText8, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_listAll = new wxListBox( this, ID_LIST_ALL, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer9->Add( m_listAll, 1, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_bpAddAll = new wxBitmapButton( this, wxID_ADDALL, wxBitmap( button_rightall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpAddAll, 0, wxALL, 5 );
	
	m_bpAddOne = new wxBitmapButton( this, wxID_ADDONE, wxBitmap( button_right_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpAddOne, 0, wxALL, 5 );
	
	m_bpRemoveOne = new wxBitmapButton( this, wxID_REMOVEONE, wxBitmap( button_left_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpRemoveOne, 0, wxALL, 5 );
	
	m_bpRemoveAll = new wxBitmapButton( this, wxID_REMOVEALL, wxBitmap( button_leftall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer10->Add( m_bpRemoveAll, 0, wxALL, 5 );
	
	bSizer8->Add( bSizer10, 0, wxALIGN_BOTTOM, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("Championship related"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer11->Add( m_staticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_listSelected = new wxListBox( this, ID_SELECTED, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer11->Add( m_listSelected, 1, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer11, 1, wxEXPAND, 5 );
	
	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton31 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton31->SetDefault(); 
	bSizer34->Add( m_bpButton31, 0, wxALL, 5 );
	
	m_bpButton32 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpButton32, 0, wxALL, 5 );
	
	bSizer7->Add( bSizer34, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

ChampionshipJudgesTeamMngrDlg::~ChampionshipJudgesTeamMngrDlg()
{
}

BEGIN_EVENT_TABLE( StartNumberAssignDlg, wxDialog )
	EVT_LISTBOX( ID_TEAMS_LIST, StartNumberAssignDlg::_wxFB_OnSelectTeam )
	EVT_TEXT( ID_SEARCH, StartNumberAssignDlg::_wxFB_OnSearch )
	EVT_BUTTON( wxID_RANDOM, StartNumberAssignDlg::_wxFB_OnRandomFind )
	EVT_BUTTON( wxID_NEXT, StartNumberAssignDlg::_wxFB_OnNextFind )
	EVT_BUTTON( wxID_ASSIGN, StartNumberAssignDlg::_wxFB_OnAssign )
	EVT_BUTTON( wxID_OK, StartNumberAssignDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, StartNumberAssignDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

StartNumberAssignDlg::StartNumberAssignDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Teams") ), wxVERTICAL );
	
	m_listTeams = new wxListBox( this, ID_TEAMS_LIST, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer2->Add( m_listTeams, 1, wxALL|wxEXPAND, 5 );
	
	bSizer95->Add( sbSizer2, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer98;
	bSizer98 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText85 = new wxStaticText( this, wxID_ANY, _("Team"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer98->Add( m_staticText85, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_textSearch->SetFont( wxFont( 18, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer98->Add( m_textSearch, 0, wxALL|wxEXPAND, 5 );
	
	m_textNumber = new wxTextCtrl( this, ID_NUMBER, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_textNumber->SetFont( wxFont( 42, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer98->Add( m_textNumber, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer99;
	bSizer99 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpRandomNumber = new wxBitmapButton( this, wxID_RANDOM, wxBitmap( button_random_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer99->Add( m_bpRandomNumber, 0, wxALL, 5 );
	
	m_bpNextNumber = new wxBitmapButton( this, wxID_NEXT, wxBitmap( button_right_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpNextNumber->SetDefault(); 
	bSizer99->Add( m_bpNextNumber, 0, wxALL, 5 );
	
	m_bpAssign = new wxBitmapButton( this, wxID_ASSIGN, wxBitmap( button_assign_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpAssign->SetDefault(); 
	bSizer99->Add( m_bpAssign, 0, wxALL, 5 );
	
	bSizer98->Add( bSizer99, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer98->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer83->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer83->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer98->Add( bSizer83, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer95->Add( bSizer98, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer95 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

StartNumberAssignDlg::~StartNumberAssignDlg()
{
}

BEGIN_EVENT_TABLE( JudgeMark, wxDialog )
	EVT_COMBOBOX( wxID_ANY, JudgeMark::_wxFB_OnSelectJudge )
	EVT_BUTTON( wxID_OK, JudgeMark::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, JudgeMark::_wxFB_OnDiscard )
	EVT_LISTBOX( ID_TEAMS_LIST, JudgeMark::_wxFB_OnSelectNumber )
	EVT_CHECKBOX( ID_SHOW_ALL, JudgeMark::_wxFB_OnShowAll )
	EVT_TEXT( ID_SEARCH, JudgeMark::_wxFB_OnSearch )
	EVT_BUTTON( ID_GOOD, JudgeMark::_wxFB_OnPlus )
	EVT_BUTTON( ID_BED, JudgeMark::_wxFB_OnMinus )
END_EVENT_TABLE()

JudgeMark::JudgeMark( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer113;
	bSizer113 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText92 = new wxStaticText( this, wxID_ANY, _("Judge"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	bSizer113->Add( m_staticText92, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboJudge = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_comboJudge->SetFont( wxFont( 18, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer113->Add( m_comboJudge, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer83->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer83->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer113->Add( bSizer83, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer95->Add( bSizer113, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer112;
	bSizer112 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Start numbers") ), wxVERTICAL );
	
	m_listNumbers = new wxListBox( this, ID_TEAMS_LIST, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer2->Add( m_listNumbers, 1, wxALL|wxEXPAND, 5 );
	
	m_checkShowAll = new wxCheckBox( this, ID_SHOW_ALL, _("Show all"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_checkShowAll, 0, wxALL, 5 );
	
	bSizer112->Add( sbSizer2, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer98;
	bSizer98 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText85 = new wxStaticText( this, wxID_ANY, _("Start number"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer98->Add( m_staticText85, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_textSearch->SetFont( wxFont( 18, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer98->Add( m_textSearch, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer99;
	bSizer99 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panelPlus = new wxPanel( this, ID_PANEL_PLUS, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpGood = new wxBitmapButton( m_panelPlus, ID_GOOD, wxBitmap( button_plus_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer101->Add( m_bpGood, 0, wxALL, 15 );
	
	m_panelPlus->SetSizer( bSizer101 );
	m_panelPlus->Layout();
	bSizer101->Fit( m_panelPlus );
	bSizer99->Add( m_panelPlus, 1, wxEXPAND | wxALL, 5 );
	
	m_panelMinus = new wxPanel( this, ID_PANEL_MINUS, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxVERTICAL );
	
	m_bpBed = new wxBitmapButton( m_panelMinus, ID_BED, wxBitmap( button_minus_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer102->Add( m_bpBed, 0, wxALL, 15 );
	
	m_panelMinus->SetSizer( bSizer102 );
	m_panelMinus->Layout();
	bSizer102->Fit( m_panelMinus );
	bSizer99->Add( m_panelMinus, 1, wxEXPAND | wxALL, 5 );
	
	bSizer98->Add( bSizer99, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer98->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer112->Add( bSizer98, 1, wxEXPAND, 5 );
	
	bSizer95->Add( bSizer112, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer95 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

JudgeMark::~JudgeMark()
{
}

BEGIN_EVENT_TABLE( CodeDialog, wxDialog )
	EVT_TEXT( ID_SEARCH, CodeDialog::_wxFB_OnSearch )
	EVT_LISTBOX( ID_ITEM_LIST, CodeDialog::_wxFB_OnSelectItem )
	EVT_BUTTON( wxID_ADD, CodeDialog::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVE, CodeDialog::_wxFB_OnRemove )
	EVT_BUTTON( wxID_UPDATE, CodeDialog::_wxFB_OnUpdateCode )
	EVT_BUTTON( wxID_OK, CodeDialog::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, CodeDialog::_wxFB_OnDiscard )
END_EVENT_TABLE()

CodeDialog::CodeDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	m_sbListSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("list") ), wxVERTICAL );
	
	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText84 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer88->Add( m_staticText84, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer88->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	m_sbListSizer->Add( bSizer88, 0, wxEXPAND, 5 );
	
	m_listItems = new wxListBox( this, ID_ITEM_LIST, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_SINGLE ); 
	m_sbListSizer->Add( m_listItems, 1, wxALL|wxEXPAND, 5 );
	
	bSizer84->Add( m_sbListSizer, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpAplly = new wxBitmapButton( this, wxID_UPDATE, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpAplly, 0, wxALL, 5 );
	
	m_bpButton81 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton81->SetDefault(); 
	bSizer87->Add( m_bpButton81, 0, wxALL, 5 );
	
	m_bpButton82 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpButton82, 0, wxALL, 5 );
	
	bSizer86->Add( bSizer87, 0, wxALIGN_RIGHT, 5 );
	
	
	bSizer86->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer13->AddGrowableCol( 1 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText82 = new wxStaticText( this, wxID_ANY, _("Code"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText82->Wrap( -1 );
	fgSizer13->Add( m_staticText82, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCode = new wxTextCtrl( this, ID_CODE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer13->Add( m_textCode, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText83 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	fgSizer13->Add( m_staticText83, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textName->SetMaxLength( 50 ); 
	fgSizer13->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	bSizer86->Add( fgSizer13, 1, wxEXPAND, 5 );
	
	
	bSizer86->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer84->Add( bSizer86, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer84 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

CodeDialog::~CodeDialog()
{
}

BEGIN_EVENT_TABLE( CountriesMngr, wxDialog )
	EVT_TEXT( ID_SEARCH, CountriesMngr::_wxFB_OnSearch )
	EVT_LISTBOX( ID_ITEM_LIST, CountriesMngr::_wxFB_OnSelectItem )
	EVT_BUTTON( wxID_ADD, CountriesMngr::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVE, CountriesMngr::_wxFB_OnRemove )
	EVT_BUTTON( wxID_UPDATE, CountriesMngr::_wxFB_OnUpdateCode )
	EVT_BUTTON( wxID_OK, CountriesMngr::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, CountriesMngr::_wxFB_OnDiscard )
END_EVENT_TABLE()

CountriesMngr::CountriesMngr( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* m_sbListSizer;
	m_sbListSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Countires list") ), wxVERTICAL );
	
	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText84 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer88->Add( m_staticText84, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer88->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	m_sbListSizer->Add( bSizer88, 0, wxEXPAND, 5 );
	
	m_listItems = new wxListBox( this, ID_ITEM_LIST, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_SINGLE ); 
	m_sbListSizer->Add( m_listItems, 1, wxALL|wxEXPAND, 5 );
	
	bSizer84->Add( m_sbListSizer, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpAplly = new wxBitmapButton( this, wxID_UPDATE, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpAplly, 0, wxALL, 5 );
	
	m_bpButton81 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton81->SetDefault(); 
	bSizer87->Add( m_bpButton81, 0, wxALL, 5 );
	
	m_bpButton82 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpButton82, 0, wxALL, 5 );
	
	bSizer86->Add( bSizer87, 0, wxALIGN_RIGHT, 5 );
	
	
	bSizer86->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer13->AddGrowableCol( 1 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText83 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	fgSizer13->Add( m_staticText83, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textName->SetMaxLength( 30 ); 
	fgSizer13->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	bSizer86->Add( fgSizer13, 1, wxEXPAND, 5 );
	
	
	bSizer86->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer84->Add( bSizer86, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer84 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

CountriesMngr::~CountriesMngr()
{
}

BEGIN_EVENT_TABLE( ChampionshipTypeMngr, wxDialog )
	EVT_TEXT( ID_SEARCH, ChampionshipTypeMngr::_wxFB_OnSearch )
	EVT_LISTBOX( ID_ITEM_LIST, ChampionshipTypeMngr::_wxFB_OnSelectItem )
	EVT_BUTTON( wxID_ADD, ChampionshipTypeMngr::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVE, ChampionshipTypeMngr::_wxFB_OnRemove )
	EVT_BUTTON( wxID_UPDATE, ChampionshipTypeMngr::_wxFB_OnUpdateCode )
	EVT_BUTTON( wxID_OK, ChampionshipTypeMngr::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, ChampionshipTypeMngr::_wxFB_OnDiscard )
END_EVENT_TABLE()

ChampionshipTypeMngr::ChampionshipTypeMngr( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* m_sbListSizer;
	m_sbListSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("List of championship types") ), wxVERTICAL );
	
	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText84 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer88->Add( m_staticText84, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer88->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	m_sbListSizer->Add( bSizer88, 0, wxEXPAND, 5 );
	
	m_listItems = new wxListBox( this, ID_ITEM_LIST, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_SINGLE ); 
	m_sbListSizer->Add( m_listItems, 1, wxALL|wxEXPAND, 5 );
	
	bSizer84->Add( m_sbListSizer, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpAplly = new wxBitmapButton( this, wxID_UPDATE, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpAplly, 0, wxALL, 5 );
	
	m_bpButton81 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton81->SetDefault(); 
	bSizer87->Add( m_bpButton81, 0, wxALL, 5 );
	
	m_bpButton82 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpButton82, 0, wxALL, 5 );
	
	bSizer86->Add( bSizer87, 0, wxALIGN_RIGHT, 5 );
	
	
	bSizer86->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer13->AddGrowableCol( 1 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText83 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	fgSizer13->Add( m_staticText83, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textName->SetMaxLength( 50 ); 
	fgSizer13->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	bSizer86->Add( fgSizer13, 1, wxEXPAND, 5 );
	
	
	bSizer86->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer84->Add( bSizer86, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer84 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

ChampionshipTypeMngr::~ChampionshipTypeMngr()
{
}

BEGIN_EVENT_TABLE( CitiesMngr, wxDialog )
	EVT_TEXT( ID_SEARCH, CitiesMngr::_wxFB_OnSearch )
	EVT_LISTBOX( ID_ITEM_LIST, CitiesMngr::_wxFB_OnSelectItem )
	EVT_BUTTON( wxID_ADD, CitiesMngr::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVE, CitiesMngr::_wxFB_OnRemove )
	EVT_BUTTON( wxID_UPDATE, CitiesMngr::_wxFB_OnUpdateCode )
	EVT_BUTTON( wxID_OK, CitiesMngr::_wxFB_OnSave )
	EVT_BUTTON( wxID_CANCEL, CitiesMngr::_wxFB_OnDiscard )
END_EVENT_TABLE()

CitiesMngr::CitiesMngr( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	m_sbListSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Cities list") ), wxVERTICAL );
	
	wxBoxSizer* bSizer90;
	bSizer90 = new wxBoxSizer( wxHORIZONTAL );
	
	m_sbListSizer->Add( bSizer90, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText84 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText84->Wrap( -1 );
	bSizer88->Add( m_staticText84, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( this, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer88->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	m_sbListSizer->Add( bSizer88, 0, wxEXPAND, 5 );
	
	m_listItems = new wxListBox( this, ID_ITEM_LIST, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_SINGLE ); 
	m_sbListSizer->Add( m_listItems, 1, wxALL|wxEXPAND, 5 );
	
	bSizer84->Add( m_sbListSizer, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpAplly = new wxBitmapButton( this, wxID_UPDATE, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpAplly, 0, wxALL, 5 );
	
	m_bpButton81 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton81->SetDefault(); 
	bSizer87->Add( m_bpButton81, 0, wxALL, 5 );
	
	m_bpButton82 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer87->Add( m_bpButton82, 0, wxALL, 5 );
	
	bSizer86->Add( bSizer87, 0, wxALIGN_RIGHT, 5 );
	
	
	bSizer86->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer13->AddGrowableCol( 1 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText82 = new wxStaticText( this, wxID_ANY, _("County"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText82->Wrap( -1 );
	fgSizer13->Add( m_staticText82, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboCounty = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer13->Add( m_comboCounty, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText83 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	fgSizer13->Add( m_staticText83, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textName->SetMaxLength( 50 ); 
	fgSizer13->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	bSizer86->Add( fgSizer13, 1, wxEXPAND, 5 );
	
	
	bSizer86->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer84->Add( bSizer86, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer84 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

CitiesMngr::~CitiesMngr()
{
}

BEGIN_EVENT_TABLE( ReportPreview, wxDialog )
	EVT_BUTTON( ID_PRINT, ReportPreview::_wxFB_OnPrint )
	EVT_BUTTON( wxID_CANCEL, ReportPreview::_wxFB_OnDiscard )
END_EVENT_TABLE()

ReportPreview::ReportPreview( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer108;
	bSizer108 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer109;
	bSizer109 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpPrint = new wxBitmapButton( this, ID_PRINT, wxBitmap( button_other_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer109->Add( m_bpPrint, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer109->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer108->Add( bSizer109, 0, wxALIGN_RIGHT, 5 );
	
	m_htmlReport = new wxHtmlWindow( this, ID_REPORT_PREVIEW, wxDefaultPosition, wxDefaultSize, wxHW_NO_SELECTION|wxHW_SCROLLBAR_AUTO );
	bSizer108->Add( m_htmlReport, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer108 );
	this->Layout();
}

ReportPreview::~ReportPreview()
{
}
