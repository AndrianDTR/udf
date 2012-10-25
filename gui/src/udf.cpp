///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
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
#include "../res/button_championship_teams.xpm"
#include "../res/button_danceradd.xpm"
#include "../res/button_dancerremove.xpm"
#include "../res/button_delete.xpm"
#include "../res/button_judges.xpm"
#include "../res/button_left.xpm"
#include "../res/button_leftall.xpm"
#include "../res/button_mark.xpm"
#include "../res/button_minus.xpm"
#include "../res/button_move_down.xpm"
#include "../res/button_move_down10.xpm"
#include "../res/button_move_up.xpm"
#include "../res/button_move_up10.xpm"
#include "../res/button_ok.xpm"
#include "../res/button_other.xpm"
#include "../res/button_payments.xpm"
#include "../res/button_plus.xpm"
#include "../res/button_random.xpm"
#include "../res/button_report.xpm"
#include "../res/button_results.xpm"
#include "../res/button_right.xpm"
#include "../res/button_rightall.xpm"
#include "../res/button_save.xpm"
#include "../res/button_startnumber.xpm"
#include "../res/button_tour_add.xpm"
#include "../res/button_tour_edit.xpm"
#include "../res/button_tour_remove.xpm"
#include "../res/button_update2.xpm"
#include "../res/button_user.xpm"
#include "../res/icon-database.xpm"
#include "../res/mail.xpm"

///////////////////////////////////////////////////////////////////////////

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
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DancersTeamMngr::OnSearch ), NULL, this );
	m_listTeams->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( DancersTeamMngr::OnSelectTeam ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnAddTeam ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnRemoveTeam ), NULL, this );
	m_bpApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnUpdate ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnDiscard ), NULL, this );
	m_comboClub->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( DancersTeamMngr::OnClubChanged ), NULL, this );
	m_bpAddDancerTeamCategory->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnAddDancerTeamCategory ), NULL, this );
	m_bpRemoveDancerTeamCategory->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnRemoveDancerTeamCategory ), NULL, this );
	m_bpAddDancerTeamDancer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnAddDancer2Team ), NULL, this );
	m_bpRemoveDancerTeamDancer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnRemoveDancerFromTeam ), NULL, this );
}

DancersTeamMngr::~DancersTeamMngr()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DancersTeamMngr::OnSearch ), NULL, this );
	m_listTeams->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( DancersTeamMngr::OnSelectTeam ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnAddTeam ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnRemoveTeam ), NULL, this );
	m_bpApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnUpdate ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnDiscard ), NULL, this );
	m_comboClub->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( DancersTeamMngr::OnClubChanged ), NULL, this );
	m_bpAddDancerTeamCategory->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnAddDancerTeamCategory ), NULL, this );
	m_bpRemoveDancerTeamCategory->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnRemoveDancerTeamCategory ), NULL, this );
	m_bpAddDancerTeamDancer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnAddDancer2Team ), NULL, this );
	m_bpRemoveDancerTeamDancer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersTeamMngr::OnRemoveDancerFromTeam ), NULL, this );
	
}

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
	
	m_listAll = new wxListBox( this, ID_LIST_ALL, wxDefaultPosition, wxSize( 350,-1 ), 0, NULL, wxLB_MULTIPLE ); 
	bSizer9->Add( m_listAll, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer9, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxVERTICAL );
	
	m_bpAddAll = new wxBitmapButton( this, wxID_ADDALL, wxBitmap( button_rightall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer131->Add( m_bpAddAll, 0, wxALL, 5 );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADDONE, wxBitmap( button_right_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer131->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVEONE, wxBitmap( button_left_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer131->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpRemoveAll = new wxBitmapButton( this, wxID_REMOVEALL, wxBitmap( button_leftall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer131->Add( m_bpRemoveAll, 0, wxALL, 5 );
	
	bSizer10->Add( bSizer131, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer8->Add( bSizer10, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("Categories for championship"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer11->Add( m_staticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_listSelected = new wxListBox( this, ID_SELECTED_LIST, wxDefaultPosition, wxSize( 350,-1 ), 0, NULL, wxLB_MULTIPLE ); 
	bSizer11->Add( m_listSelected, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer11, 0, wxEXPAND, 5 );
	
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
	
	// Connect Events
	m_bpAddAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnAddAll ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnAdd ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnRemove ), NULL, this );
	m_bpRemoveAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnRemoveAll ), NULL, this );
	m_bpButton31->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnSave ), NULL, this );
	m_bpButton32->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnDiscard ), NULL, this );
}

ChampionshipCategoriesMngrDlg::~ChampionshipCategoriesMngrDlg()
{
	// Disconnect Events
	m_bpAddAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnAddAll ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnAdd ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnRemove ), NULL, this );
	m_bpRemoveAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnRemoveAll ), NULL, this );
	m_bpButton31->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnSave ), NULL, this );
	m_bpButton32->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipCategoriesMngrDlg::OnDiscard ), NULL, this );
	
}

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
	
	m_staticText191 = new wxStaticText( this, wxID_ANY, _("Age"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText191->Wrap( -1 );
	fgSizer2->Add( m_staticText191, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboAge = new wxComboBox( this, ID_AGE_LIST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer2->Add( m_comboAge, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Liga"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer2->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboLiga = new wxComboBox( this, ID_LIGA_LIST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer2->Add( m_comboLiga, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Dance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	fgSizer2->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboDance = new wxComboBox( this, ID_DANCE_LIST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer2->Add( m_comboDance, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer2->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textName->SetMaxLength( 100 ); 
	fgSizer2->Add( m_textName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Short name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	fgSizer2->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textShortName = new wxTextCtrl( this, ID_SHORTNAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textShortName->SetMaxLength( 20 ); 
	fgSizer2->Add( m_textShortName, 0, wxALL|wxEXPAND, 5 );
	
	bSizer181->Add( fgSizer2, 1, wxEXPAND, 5 );
	
	bSizer16->Add( bSizer181, 1, wxEXPAND, 5 );
	
	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CategoriesMngrDlg::OnCategorySearch ), NULL, this );
	m_listCategories->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( CategoriesMngrDlg::OnCategorySelected ), NULL, this );
	m_bpButton13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnAdd ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnRemove ), NULL, this );
	m_bpUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnUpdate ), NULL, this );
	m_bpButton29->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnDiscard ), NULL, this );
	m_comboAge->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CategoriesMngrDlg::OnAgeCganged ), NULL, this );
	m_comboLiga->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CategoriesMngrDlg::OnLigaCganged ), NULL, this );
	m_comboDance->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CategoriesMngrDlg::OnDanceChanged ), NULL, this );
}

CategoriesMngrDlg::~CategoriesMngrDlg()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CategoriesMngrDlg::OnCategorySearch ), NULL, this );
	m_listCategories->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( CategoriesMngrDlg::OnCategorySelected ), NULL, this );
	m_bpButton13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnAdd ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnRemove ), NULL, this );
	m_bpUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnUpdate ), NULL, this );
	m_bpButton29->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CategoriesMngrDlg::OnDiscard ), NULL, this );
	m_comboAge->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CategoriesMngrDlg::OnAgeCganged ), NULL, this );
	m_comboLiga->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CategoriesMngrDlg::OnLigaCganged ), NULL, this );
	m_comboDance->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CategoriesMngrDlg::OnDanceChanged ), NULL, this );
	
}

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
	
	m_bpPayments = new wxBitmapButton( this, ID_M_BPPAYMENT, wxBitmap( button_payments_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpPayments, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpSave->SetDefault(); 
	bSizer24->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpCancel = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpCancel, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer24, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 6, 2, 0, 0 );
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
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer22->Add( bSizer73, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ClubsMngrDlg::OnSearch ), NULL, this );
	m_listClubs->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ClubsMngrDlg::OnSelectClub ), NULL, this );
	m_bpAddClub->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnAddClub ), NULL, this );
	m_bpUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnUpdate ), NULL, this );
	m_bpRemoveClub->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnRemoveClub ), NULL, this );
	m_bpAccountInfo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnAccountInfo ), NULL, this );
	m_bpDirectorInfo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnDirectorInfo ), NULL, this );
	m_bpTarinersMngr->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnTrainersMngr ), NULL, this );
	m_bpDancersMngr->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnDancersMngr ), NULL, this );
	m_bpPayments->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnPayment ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnSave ), NULL, this );
	m_bpCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnDiscard ), NULL, this );
}

ClubsMngrDlg::~ClubsMngrDlg()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ClubsMngrDlg::OnSearch ), NULL, this );
	m_listClubs->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ClubsMngrDlg::OnSelectClub ), NULL, this );
	m_bpAddClub->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnAddClub ), NULL, this );
	m_bpUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnUpdate ), NULL, this );
	m_bpRemoveClub->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnRemoveClub ), NULL, this );
	m_bpAccountInfo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnAccountInfo ), NULL, this );
	m_bpDirectorInfo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnDirectorInfo ), NULL, this );
	m_bpTarinersMngr->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnTrainersMngr ), NULL, this );
	m_bpDancersMngr->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnDancersMngr ), NULL, this );
	m_bpPayments->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnPayment ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnSave ), NULL, this );
	m_bpCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ClubsMngrDlg::OnDiscard ), NULL, this );
	
}

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
	
	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DSASH );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrameBase::m_splitter2OnIdle ), NULL, this );
	m_splitter2->SetMinimumPaneSize( 300 );
	
	m_panel1 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer150;
	bSizer150 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Championship list") ), wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_championshipSearchText = new wxStaticText( m_panel1, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_championshipSearchText->Wrap( -1 );
	bSizer5->Add( m_championshipSearchText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSearch = new wxTextCtrl( m_panel1, ID_SEARCH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	m_bpAdd = new wxBitmapButton( m_panel1, wxID_CHAMPIONSIP_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer5->Add( m_bpAdd, 0, wxALL, 5 );
	
	sbSizer9->Add( bSizer5, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	m_treeCs = new wxTreeCtrl( m_panel1, ID_CS_TREE, wxDefaultPosition, wxSize( -1,-1 ), wxTR_DEFAULT_STYLE|wxTR_FULL_ROW_HIGHLIGHT|wxTR_HIDE_ROOT|wxTR_SINGLE|wxSUNKEN_BORDER );
	sbSizer9->Add( m_treeCs, 1, wxALL|wxEXPAND, 5 );
	
	bSizer150->Add( sbSizer9, 1, wxEXPAND|wxALL, 5 );
	
	m_panel1->SetSizer( bSizer150 );
	m_panel1->Layout();
	bSizer150->Fit( m_panel1 );
	m_panel12 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook = new wxNotebook( m_panel12, ID_M_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxNB_TOP );
	
	bSizer6->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	m_panel12->SetSizer( bSizer6 );
	m_panel12->Layout();
	bSizer6->Fit( m_panel12 );
	m_splitter2->SplitVertically( m_panel1, m_panel12, 300 );
	mainSizer->Add( m_splitter2, 1, wxEXPAND, 5 );
	
	this->SetSizer( mainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	this->Connect( menuFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnExitClick ) );
	this->Connect( m_menuItem5->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuClubManage ) );
	this->Connect( m_menuItem6->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuJudgeManage ) );
	this->Connect( m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuCategoryManage ) );
	this->Connect( m_menuItem62->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDanceTypesCodeMgr ) );
	this->Connect( m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnLigueCodeMgr ) );
	this->Connect( m_menuItem8->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAgeCodesMgr ) );
	this->Connect( m_menuItem201->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuChampionshipTypes ) );
	this->Connect( m_menuItem10->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnCitiesMngr ) );
	this->Connect( m_menuItem91->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnCountriesMngr ) );
	this->Connect( m_menuItem211->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenySync ) );
	this->Connect( m_menuItem22->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuOptions ) );
	this->Connect( m_menuItem61->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAboutDlg ) );
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrameBase::OnSearch ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnAddChampionsip ), NULL, this );
	m_treeCs->Connect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( MainFrameBase::OnEditTour ), NULL, this );
	m_treeCs->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( MainFrameBase::OnCsSelect ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	this->Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnExitClick ) );
	this->Disconnect( ID_MENU_MNGR_CLUBS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuClubManage ) );
	this->Disconnect( ID_MENU_MNGR_JUDGE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuJudgeManage ) );
	this->Disconnect( ID_MENU_MNGR_CATEGORIES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuCategoryManage ) );
	this->Disconnect( ID_MENU_MNGR_DANCE_TYPES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDanceTypesCodeMgr ) );
	this->Disconnect( ID_MENU_MNGR_LIGUES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnLigueCodeMgr ) );
	this->Disconnect( ID_MENU_MNGR_AGE_CATEGORIES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAgeCodesMgr ) );
	this->Disconnect( ID_MENU_MNGR_ChTYPES_MNGR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuChampionshipTypes ) );
	this->Disconnect( ID_MENU_MNGR_CITIES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnCitiesMngr ) );
	this->Disconnect( ID_MENU_MNGR_COUNTRIES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnCountriesMngr ) );
	this->Disconnect( ID_MENU_TOOLS_SYUNC, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenySync ) );
	this->Disconnect( ID_MENU_TOOLS_OPTIONS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuOptions ) );
	this->Disconnect( ID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAboutDlg ) );
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrameBase::OnSearch ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnAddChampionsip ), NULL, this );
	m_treeCs->Disconnect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( MainFrameBase::OnEditTour ), NULL, this );
	m_treeCs->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( MainFrameBase::OnCsSelect ), NULL, this );
	
}

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
	
	// Connect Events
	m_bpButton25->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DirectorInfo::OnSave ), NULL, this );
	m_bpButton26->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DirectorInfo::OnDiscard ), NULL, this );
}

DirectorInfo::~DirectorInfo()
{
	// Disconnect Events
	m_bpButton25->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DirectorInfo::OnSave ), NULL, this );
	m_bpButton26->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DirectorInfo::OnDiscard ), NULL, this );
	
}

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
	
	m_bpPayments = new wxBitmapButton( this, ID_M_BPPAYMENTS, wxBitmap( button_payments_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpPayments, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpSave->SetDefault(); 
	bSizer76->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer76, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 6, 2, 0, 0 );
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
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( TrainersMngrDlg::OnSearch ), NULL, this );
	m_listTrainers->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( TrainersMngrDlg::OnSelectTrainer ), NULL, this );
	m_bpAddTrainer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnAddTrainer ), NULL, this );
	m_bpUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnUpdate ), NULL, this );
	m_bpRemoveTrainer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnRemoveTrainer ), NULL, this );
	m_bpPayments->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnPayment ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnDiscard ), NULL, this );
}

TrainersMngrDlg::~TrainersMngrDlg()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( TrainersMngrDlg::OnSearch ), NULL, this );
	m_listTrainers->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( TrainersMngrDlg::OnSelectTrainer ), NULL, this );
	m_bpAddTrainer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnAddTrainer ), NULL, this );
	m_bpUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnUpdate ), NULL, this );
	m_bpRemoveTrainer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnRemoveTrainer ), NULL, this );
	m_bpPayments->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnPayment ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrainersMngrDlg::OnDiscard ), NULL, this );
	
}

CsTours::CsTours( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer22->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer3->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboType = new wxComboBox( this, ID_M_COMBOTYPE, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboType, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("Selection limit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textLimit = new wxTextCtrl( this, ID_LIMIT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textLimit, 0, wxALL, 5 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkFinal = new wxCheckBox( this, ID_FINAL, _("Final"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_checkFinal, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpSave->SetDefault(); 
	bSizer76->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer76, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer22 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTours::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTours::OnDiscard ), NULL, this );
}

CsTours::~CsTours()
{
	// Disconnect Events
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTours::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTours::OnDiscard ), NULL, this );
	
}

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
	
	m_bListSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_listTeams = new wxListCtrl( this, ID_LIST_TEAMS, wxDefaultPosition, wxDefaultSize, wxLC_AUTOARRANGE|wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_DESCENDING|wxLC_VRULES );
	m_bListSizer->Add( m_listTeams, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer109;
	bSizer109 = new wxBoxSizer( wxVERTICAL );
	
	m_bpMoveUp10 = new wxBitmapButton( this, ID_MOVEUP10, wxBitmap( button_move_up10_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer109->Add( m_bpMoveUp10, 0, wxALL, 5 );
	
	m_bpMoveUp = new wxBitmapButton( this, ID_MOVE_UP, wxBitmap( button_move_up_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer109->Add( m_bpMoveUp, 0, wxALL, 5 );
	
	m_bpMoveDown = new wxBitmapButton( this, ID_MOVE_DOWN, wxBitmap( button_move_down_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer109->Add( m_bpMoveDown, 0, wxALL, 5 );
	
	m_bpMoveDown10 = new wxBitmapButton( this, ID_MOVE_DOWN10, wxBitmap( button_move_down10_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer109->Add( m_bpMoveDown10, 0, wxALL, 5 );
	
	m_bListSizer->Add( bSizer109, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer22->Add( m_bListSizer, 1, wxEXPAND, 5 );
	
	m_staticJudgeDescr = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticJudgeDescr->Wrap( -1 );
	bSizer22->Add( m_staticJudgeDescr, 0, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpPrint->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnReport ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnDiscard ), NULL, this );
	m_listTeams->Connect( wxEVT_COMMAND_LIST_BEGIN_DRAG, wxListEventHandler( CsTourReport::OnStartDrag ), NULL, this );
	m_listTeams->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( CsTourReport::OnTeamSelect ), NULL, this );
	m_bpMoveUp10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnUp10 ), NULL, this );
	m_bpMoveUp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnUp ), NULL, this );
	m_bpMoveDown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnDown ), NULL, this );
	m_bpMoveDown10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnDown10 ), NULL, this );
}

CsTourReport::~CsTourReport()
{
	// Disconnect Events
	m_bpPrint->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnReport ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnDiscard ), NULL, this );
	m_listTeams->Disconnect( wxEVT_COMMAND_LIST_BEGIN_DRAG, wxListEventHandler( CsTourReport::OnStartDrag ), NULL, this );
	m_listTeams->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( CsTourReport::OnTeamSelect ), NULL, this );
	m_bpMoveUp10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnUp10 ), NULL, this );
	m_bpMoveUp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnUp ), NULL, this );
	m_bpMoveDown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnDown ), NULL, this );
	m_bpMoveDown10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsTourReport::OnDown10 ), NULL, this );
	
}

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
	
	m_bpPayments = new wxBitmapButton( this, ID_M_BPPAYMENTS, wxBitmap( button_payments_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer77->Add( m_bpPayments, 0, wxALL, 5 );
	
	m_bpOk = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpOk->SetDefault(); 
	bSizer77->Add( m_bpOk, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer77->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer77, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 10, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 9 );
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
	
	m_staticText62 = new wxStaticText( this, wxID_ANY, _("Reg date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	fgSizer3->Add( m_staticText62, 0, wxALL, 5 );
	
	m_textReg = new wxTextCtrl( this, ID_REG, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer3->Add( m_textReg, 0, wxALL, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Additional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer3->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textInfo = new wxTextCtrl( this, ID_INFO, wxEmptyString, wxDefaultPosition, wxSize( -1,70 ), wxTE_MULTILINE );
	fgSizer3->Add( m_textInfo, 0, wxALL|wxEXPAND, 5 );
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DancersMngrDlg::OnSearch ), NULL, this );
	m_listDancers->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( DancersMngrDlg::OnDancerSelect ), NULL, this );
	m_bpAddDancer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnAddDancer ), NULL, this );
	m_bpRemoveDancer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnRemoveDancer ), NULL, this );
	m_bpUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnUpdate ), NULL, this );
	m_bpPayments->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnPayment ), NULL, this );
	m_bpOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnDiscard ), NULL, this );
}

DancersMngrDlg::~DancersMngrDlg()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DancersMngrDlg::OnSearch ), NULL, this );
	m_listDancers->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( DancersMngrDlg::OnDancerSelect ), NULL, this );
	m_bpAddDancer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnAddDancer ), NULL, this );
	m_bpRemoveDancer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnRemoveDancer ), NULL, this );
	m_bpUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnUpdate ), NULL, this );
	m_bpPayments->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnPayment ), NULL, this );
	m_bpOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DancersMngrDlg::OnDiscard ), NULL, this );
	
}

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
	
	// Connect Events
	m_checkShowPass->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AccountInfo::OnShowPass ), NULL, this );
	m_bpButton39->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccountInfo::OnSave ), NULL, this );
	m_bpButton40->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccountInfo::OnDiscard ), NULL, this );
}

AccountInfo::~AccountInfo()
{
	// Disconnect Events
	m_checkShowPass->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( AccountInfo::OnShowPass ), NULL, this );
	m_bpButton39->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccountInfo::OnSave ), NULL, this );
	m_bpButton40->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccountInfo::OnDiscard ), NULL, this );
	
}

UserRolesMgr::UserRolesMgr( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer123;
	bSizer123 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer124;
	bSizer124 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText103 = new wxStaticText( this, wxID_ANY, _("Role"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText103->Wrap( -1 );
	bSizer124->Add( m_staticText103, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textRole = new wxTextCtrl( this, ID_M_TEXTROLE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer124->Add( m_textRole, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText104 = new wxStaticText( this, wxID_ANY, _("Url"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText104->Wrap( -1 );
	bSizer124->Add( m_staticText104, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textUrl = new wxTextCtrl( this, ID_M_TEXTURL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer124->Add( m_textUrl, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpAdd = new wxBitmapButton( this, ID_M_BPADD, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer124->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpUpdate = new wxBitmapButton( this, ID_M_BPUPDATE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer124->Add( m_bpUpdate, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, ID_M_BPREMOVE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer124->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer124->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer124->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer123->Add( bSizer124, 0, wxALIGN_RIGHT, 5 );
	
	m_listRoles = new wxListCtrl( this, ID_M_LISTROLES, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VRULES|wxSUNKEN_BORDER );
	bSizer123->Add( m_listRoles, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer123 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnAdd ), NULL, this );
	m_bpUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnUpdate ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnRemove ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnDiscard ), NULL, this );
	m_listRoles->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( UserRolesMgr::OnSelectRole ), NULL, this );
}

UserRolesMgr::~UserRolesMgr()
{
	// Disconnect Events
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnAdd ), NULL, this );
	m_bpUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnUpdate ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnRemove ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( UserRolesMgr::OnDiscard ), NULL, this );
	m_listRoles->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( UserRolesMgr::OnSelectRole ), NULL, this );
	
}

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
	
	m_staticText102 = new wxStaticText( this, wxID_ANY, _("Length"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText102->Wrap( -1 );
	fgSizer7->Add( m_staticText102, 0, wxALL, 5 );
	
	m_textLenght = new wxTextCtrl( this, ID_LENGHT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_textLenght, 0, wxALL, 5 );
	
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
	
	// Connect Events
	m_bpButton39->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTeamCategory::OnSave ), NULL, this );
	m_bpButton40->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTeamCategory::OnDiscard ), NULL, this );
}

AddTeamCategory::~AddTeamCategory()
{
	// Disconnect Events
	m_bpButton39->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTeamCategory::OnSave ), NULL, this );
	m_bpButton40->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddTeamCategory::OnDiscard ), NULL, this );
	
}

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
	
	m_bpApply = new wxBitmapButton( this, ID_APPLY, wxBitmap( button_save_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpApply, 0, wxALL, 5 );
	
	m_bpCategories = new wxBitmapButton( this, ID_CATEGORIES, wxBitmap( button_categories_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpCategories, 0, wxALL, 5 );
	
	m_bpPayments = new wxBitmapButton( this, ID_M_BPPAYMENT, wxBitmap( button_payments_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpPayments, 0, wxALL, 5 );
	
	m_bpButton19 = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton19->SetDefault(); 
	bSizer76->Add( m_bpButton19, 0, wxALL, 5 );
	
	m_bpButton20 = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpButton20, 0, wxALL, 5 );
	
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
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( JudgesMngr::OnSearch ), NULL, this );
	m_listJudges->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( JudgesMngr::OnSelectJudge ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnAddJudge ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnRemoveJudge ), NULL, this );
	m_bpApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnUpdate ), NULL, this );
	m_bpCategories->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnCategories ), NULL, this );
	m_bpPayments->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnPayment ), NULL, this );
	m_bpButton19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnSave ), NULL, this );
	m_bpButton20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnDiscard ), NULL, this );
}

JudgesMngr::~JudgesMngr()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( JudgesMngr::OnSearch ), NULL, this );
	m_listJudges->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( JudgesMngr::OnSelectJudge ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnAddJudge ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnRemoveJudge ), NULL, this );
	m_bpApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnUpdate ), NULL, this );
	m_bpCategories->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnCategories ), NULL, this );
	m_bpPayments->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnPayment ), NULL, this );
	m_bpButton19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnSave ), NULL, this );
	m_bpButton20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgesMngr::OnDiscard ), NULL, this );
	
}

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
	
	m_listAll = new wxListBox( this, ID_LIST_ALL, wxDefaultPosition, wxSize( 350,-1 ), 0, NULL, wxLB_MULTIPLE ); 
	bSizer9->Add( m_listAll, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer9, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxVERTICAL );
	
	m_bpAddAll = new wxBitmapButton( this, wxID_ADDALL, wxBitmap( button_rightall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpAddAll, 0, wxALL, 5 );
	
	m_bpAddOne = new wxBitmapButton( this, wxID_ADDONE, wxBitmap( button_right_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpAddOne, 0, wxALL, 5 );
	
	m_bpRemoveOne = new wxBitmapButton( this, wxID_REMOVEONE, wxBitmap( button_left_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpRemoveOne, 0, wxALL, 5 );
	
	m_bpRemoveAll = new wxBitmapButton( this, wxID_REMOVEALL, wxBitmap( button_leftall_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer132->Add( m_bpRemoveAll, 0, wxALL, 5 );
	
	bSizer10->Add( bSizer132, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer8->Add( bSizer10, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("Championship related"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer11->Add( m_staticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_listSelected = new wxListBox( this, ID_SELECTED, wxDefaultPosition, wxSize( 350,-1 ), 0, NULL, wxLB_MULTIPLE ); 
	bSizer11->Add( m_listSelected, 1, wxALL, 5 );
	
	bSizer8->Add( bSizer11, 0, wxEXPAND, 5 );
	
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
	
	// Connect Events
	m_bpAddAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnAddAll ), NULL, this );
	m_bpAddOne->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnAdd ), NULL, this );
	m_bpRemoveOne->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnRemove ), NULL, this );
	m_bpRemoveAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnRemoveAll ), NULL, this );
	m_bpButton31->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnSave ), NULL, this );
	m_bpButton32->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnDiscard ), NULL, this );
}

ChampionshipJudgesTeamMngrDlg::~ChampionshipJudgesTeamMngrDlg()
{
	// Disconnect Events
	m_bpAddAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnAddAll ), NULL, this );
	m_bpAddOne->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnAdd ), NULL, this );
	m_bpRemoveOne->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnRemove ), NULL, this );
	m_bpRemoveAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnRemoveAll ), NULL, this );
	m_bpButton31->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnSave ), NULL, this );
	m_bpButton32->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipJudgesTeamMngrDlg::OnDiscard ), NULL, this );
	
}

JudgeCategories::JudgeCategories( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer133;
	bSizer133 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer22;
	fgSizer22 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer22->SetFlexibleDirection( wxBOTH );
	fgSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText112 = new wxStaticText( this, wxID_ANY, _("Judge"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText112->Wrap( -1 );
	fgSizer22->Add( m_staticText112, 0, wxALL, 5 );
	
	m_staticJudge = new wxStaticText( this, wxID_ANY, _(" "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticJudge->Wrap( -1 );
	fgSizer22->Add( m_staticJudge, 0, wxALL, 5 );
	
	bSizer133->Add( fgSizer22, 0, wxEXPAND, 5 );
	
	wxArrayString m_checkCategoriesChoices;
	m_checkCategories = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_checkCategoriesChoices, wxLB_MULTIPLE );
	bSizer133->Add( m_checkCategories, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer136;
	bSizer136 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonAll = new wxButton( this, ID_SET, _("Set all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer136->Add( m_buttonAll, 0, wxALL, 5 );
	
	m_buttonClear = new wxButton( this, ID_CLEAR, _("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer136->Add( m_buttonClear, 0, wxALL, 5 );
	
	bSizer133->Add( bSizer136, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer135;
	bSizer135 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer135->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer135->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer133->Add( bSizer135, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer133 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeCategories::OnSetAll ), NULL, this );
	m_buttonClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeCategories::OnClearAll ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeCategories::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeCategories::OnDiscard ), NULL, this );
}

JudgeCategories::~JudgeCategories()
{
	// Disconnect Events
	m_buttonAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeCategories::OnSetAll ), NULL, this );
	m_buttonClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeCategories::OnClearAll ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeCategories::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeCategories::OnDiscard ), NULL, this );
	
}

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
	
	// Connect Events
	m_listTeams->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( StartNumberAssignDlg::OnSelectTeam ), NULL, this );
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( StartNumberAssignDlg::OnSearch ), NULL, this );
	m_bpRandomNumber->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnRandomFind ), NULL, this );
	m_bpNextNumber->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnNextFind ), NULL, this );
	m_bpAssign->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnAssign ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnDiscard ), NULL, this );
}

StartNumberAssignDlg::~StartNumberAssignDlg()
{
	// Disconnect Events
	m_listTeams->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( StartNumberAssignDlg::OnSelectTeam ), NULL, this );
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( StartNumberAssignDlg::OnSearch ), NULL, this );
	m_bpRandomNumber->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnRandomFind ), NULL, this );
	m_bpNextNumber->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnNextFind ), NULL, this );
	m_bpAssign->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnAssign ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( StartNumberAssignDlg::OnDiscard ), NULL, this );
	
}

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
	
	// Connect Events
	m_comboJudge->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( JudgeMark::OnSelectJudge ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeMark::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeMark::OnDiscard ), NULL, this );
	m_listNumbers->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( JudgeMark::OnSelectNumber ), NULL, this );
	m_checkShowAll->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( JudgeMark::OnShowAll ), NULL, this );
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( JudgeMark::OnSearch ), NULL, this );
	m_bpGood->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeMark::OnPlus ), NULL, this );
	m_bpBed->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeMark::OnMinus ), NULL, this );
}

JudgeMark::~JudgeMark()
{
	// Disconnect Events
	m_comboJudge->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( JudgeMark::OnSelectJudge ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeMark::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeMark::OnDiscard ), NULL, this );
	m_listNumbers->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( JudgeMark::OnSelectNumber ), NULL, this );
	m_checkShowAll->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( JudgeMark::OnShowAll ), NULL, this );
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( JudgeMark::OnSearch ), NULL, this );
	m_bpGood->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeMark::OnPlus ), NULL, this );
	m_bpBed->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( JudgeMark::OnMinus ), NULL, this );
	
}

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
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CodeDialog::OnSearch ), NULL, this );
	m_listItems->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( CodeDialog::OnSelectItem ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnAdd ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnRemove ), NULL, this );
	m_bpAplly->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnUpdateCode ), NULL, this );
	m_bpButton81->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnSave ), NULL, this );
	m_bpButton82->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnDiscard ), NULL, this );
}

CodeDialog::~CodeDialog()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CodeDialog::OnSearch ), NULL, this );
	m_listItems->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( CodeDialog::OnSelectItem ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnAdd ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnRemove ), NULL, this );
	m_bpAplly->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnUpdateCode ), NULL, this );
	m_bpButton81->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnSave ), NULL, this );
	m_bpButton82->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CodeDialog::OnDiscard ), NULL, this );
	
}

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
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CountriesMngr::OnSearch ), NULL, this );
	m_listItems->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( CountriesMngr::OnSelectItem ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnAdd ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnRemove ), NULL, this );
	m_bpAplly->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnUpdateCode ), NULL, this );
	m_bpButton81->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnSave ), NULL, this );
	m_bpButton82->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnDiscard ), NULL, this );
}

CountriesMngr::~CountriesMngr()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CountriesMngr::OnSearch ), NULL, this );
	m_listItems->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( CountriesMngr::OnSelectItem ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnAdd ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnRemove ), NULL, this );
	m_bpAplly->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnUpdateCode ), NULL, this );
	m_bpButton81->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnSave ), NULL, this );
	m_bpButton82->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CountriesMngr::OnDiscard ), NULL, this );
	
}

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
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ChampionshipTypeMngr::OnSearch ), NULL, this );
	m_listItems->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ChampionshipTypeMngr::OnSelectItem ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnAdd ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnRemove ), NULL, this );
	m_bpAplly->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnUpdateCode ), NULL, this );
	m_bpButton81->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnSave ), NULL, this );
	m_bpButton82->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnDiscard ), NULL, this );
}

ChampionshipTypeMngr::~ChampionshipTypeMngr()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ChampionshipTypeMngr::OnSearch ), NULL, this );
	m_listItems->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ChampionshipTypeMngr::OnSelectItem ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnAdd ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnRemove ), NULL, this );
	m_bpAplly->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnUpdateCode ), NULL, this );
	m_bpButton81->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnSave ), NULL, this );
	m_bpButton82->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChampionshipTypeMngr::OnDiscard ), NULL, this );
	
}

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
	
	// Connect Events
	m_textSearch->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CitiesMngr::OnSearch ), NULL, this );
	m_listItems->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( CitiesMngr::OnSelectItem ), NULL, this );
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnAdd ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnRemove ), NULL, this );
	m_bpAplly->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnUpdateCode ), NULL, this );
	m_bpButton81->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnSave ), NULL, this );
	m_bpButton82->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnDiscard ), NULL, this );
}

CitiesMngr::~CitiesMngr()
{
	// Disconnect Events
	m_textSearch->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( CitiesMngr::OnSearch ), NULL, this );
	m_listItems->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( CitiesMngr::OnSelectItem ), NULL, this );
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnAdd ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnRemove ), NULL, this );
	m_bpAplly->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnUpdateCode ), NULL, this );
	m_bpButton81->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnSave ), NULL, this );
	m_bpButton82->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CitiesMngr::OnDiscard ), NULL, this );
	
}

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
	
	// Connect Events
	m_bpPrint->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReportPreview::OnPrint ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReportPreview::OnDiscard ), NULL, this );
}

ReportPreview::~ReportPreview()
{
	// Disconnect Events
	m_bpPrint->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReportPreview::OnPrint ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReportPreview::OnDiscard ), NULL, this );
	
}

PaymentHistory::PaymentHistory( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer110;
	bSizer110 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer111->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpUpdate = new wxBitmapButton( this, ID_M_BPUPDATE, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer111->Add( m_bpUpdate, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, ID_M_BPREMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer111->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer111->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpDiscard->SetDefault(); 
	bSizer111->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer110->Add( bSizer111, 0, wxALIGN_RIGHT, 5 );
	
	m_listPayments = new wxListCtrl( this, ID_M_LISTPAYMENTS, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES|wxSUNKEN_BORDER );
	bSizer110->Add( m_listPayments, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer112;
	bSizer112 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer110->Add( bSizer112, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer110 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnAdd ), NULL, this );
	m_bpUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnUpdate ), NULL, this );
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnRemove ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnDiscard ), NULL, this );
}

PaymentHistory::~PaymentHistory()
{
	// Disconnect Events
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnAdd ), NULL, this );
	m_bpUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnUpdate ), NULL, this );
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnRemove ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PaymentHistory::OnDiscard ), NULL, this );
	
}

Payment::Payment( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer113;
	bSizer113 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 2, 4, 0, 0 );
	fgSizer18->AddGrowableCol( 1 );
	fgSizer18->AddGrowableCol( 3 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText92 = new wxStaticText( this, wxID_ANY, _("Pay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	fgSizer18->Add( m_staticText92, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePay = new wxDatePickerCtrl( this, ID_M_DATEPAY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer18->Add( m_datePay, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText93 = new wxStaticText( this, wxID_ANY, _("Expire"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	fgSizer18->Add( m_staticText93, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateExpire = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer18->Add( m_dateExpire, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText94 = new wxStaticText( this, wxID_ANY, _("Sum"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	fgSizer18->Add( m_staticText94, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textSum = new wxTextCtrl( this, ID_M_TEXTSUM, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer18->Add( m_textSum, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText95 = new wxStaticText( this, wxID_ANY, _("Free"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText95->Wrap( -1 );
	fgSizer18->Add( m_staticText95, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkFree = new wxCheckBox( this, ID_M_CHECKFREE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer18->Add( m_checkFree, 0, wxALL, 5 );
	
	bSizer113->Add( fgSizer18, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer114->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpDiscard->SetDefault(); 
	bSizer114->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer113->Add( bSizer114, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer113 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Payment::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Payment::OnDiscard ), NULL, this );
}

Payment::~Payment()
{
	// Disconnect Events
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Payment::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Payment::OnDiscard ), NULL, this );
	
}

Settings::Settings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel4 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer117;
	bSizer117 = new wxBoxSizer( wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText97 = new wxStaticText( m_panel4, wxID_ANY, _("Server"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText97->Wrap( -1 );
	fgSizer21->Add( m_staticText97, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textServer = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textServer->SetMinSize( wxSize( 150,-1 ) );
	
	fgSizer21->Add( m_textServer, 0, wxALL, 5 );
	
	m_staticText98 = new wxStaticText( m_panel4, wxID_ANY, _("Database"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText98->Wrap( -1 );
	fgSizer21->Add( m_staticText98, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textDatabase = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textDatabase->SetMinSize( wxSize( 150,-1 ) );
	
	fgSizer21->Add( m_textDatabase, 0, wxALL, 5 );
	
	m_staticText99 = new wxStaticText( m_panel4, wxID_ANY, _("User name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99->Wrap( -1 );
	fgSizer21->Add( m_staticText99, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textUser = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textUser->SetMinSize( wxSize( 150,-1 ) );
	
	fgSizer21->Add( m_textUser, 0, wxALL, 5 );
	
	m_staticText100 = new wxStaticText( m_panel4, wxID_ANY, _("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText100->Wrap( -1 );
	fgSizer21->Add( m_staticText100, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textPass = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textPass->SetMinSize( wxSize( 150,-1 ) );
	
	fgSizer21->Add( m_textPass, 0, wxALL, 5 );
	
	bSizer117->Add( fgSizer21, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer119;
	bSizer119 = new wxBoxSizer( wxVERTICAL );
	
	m_staticTestResult = new wxStaticText( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTestResult->Wrap( -1 );
	bSizer119->Add( m_staticTestResult, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer119->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonTest = new wxButton( m_panel4, wxID_ANY, _("Test connection"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer119->Add( m_buttonTest, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer117->Add( bSizer119, 1, wxEXPAND, 5 );
	
	m_panel4->SetSizer( bSizer117 );
	m_panel4->Layout();
	bSizer117->Fit( m_panel4 );
	m_notebook1->AddPage( m_panel4, _("Connection"), false );
	m_panel5 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer118;
	bSizer118 = new wxBoxSizer( wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 3, 8, 0, 0 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer19->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText88 = new wxStaticText( m_panel5, wxID_ANY, _("Final"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText88->Wrap( -1 );
	fgSizer19->Add( m_staticText88, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText89 = new wxStaticText( m_panel5, wxID_ANY, _("1/2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText89->Wrap( -1 );
	fgSizer19->Add( m_staticText89, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText90 = new wxStaticText( m_panel5, wxID_ANY, _("1/4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText90->Wrap( -1 );
	fgSizer19->Add( m_staticText90, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText91 = new wxStaticText( m_panel5, wxID_ANY, _("1/8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	fgSizer19->Add( m_staticText91, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText92 = new wxStaticText( m_panel5, wxID_ANY, _("1/16"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	fgSizer19->Add( m_staticText92, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText93 = new wxStaticText( m_panel5, wxID_ANY, _("1/32"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	fgSizer19->Add( m_staticText93, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText94 = new wxStaticText( m_panel5, wxID_ANY, _("1/64"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	fgSizer19->Add( m_staticText94, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText95 = new wxStaticText( m_panel5, wxID_ANY, _("min"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText95->Wrap( -1 );
	fgSizer19->Add( m_staticText95, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textMinFinal = new wxTextCtrl( m_panel5, ID_M_TEXTMINFINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMinFinal, 0, wxALL, 5 );
	
	m_textMin12 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMin12, 0, wxALL, 5 );
	
	m_textMin14 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMin14, 0, wxALL, 5 );
	
	m_textMin18 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMin18, 0, wxALL, 5 );
	
	m_textMin116 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMin116, 0, wxALL, 5 );
	
	m_textMin132 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMin132, 0, wxALL, 5 );
	
	m_textMin164 = new wxTextCtrl( m_panel5, ID_M_TEXTMIN164, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMin164, 0, wxALL, 5 );
	
	m_staticText96 = new wxStaticText( m_panel5, wxID_ANY, _("max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText96->Wrap( -1 );
	fgSizer19->Add( m_staticText96, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textMaxFinal = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMaxFinal, 0, wxALL, 5 );
	
	m_textMax12 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMax12, 0, wxALL, 5 );
	
	m_textMax14 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMax14, 0, wxALL, 5 );
	
	m_textMax18 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMax18, 0, wxALL, 5 );
	
	m_textMax116 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMax116, 0, wxALL, 5 );
	
	m_textMax132 = new wxTextCtrl( m_panel5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMax132, 0, wxALL, 5 );
	
	m_textMax164 = new wxTextCtrl( m_panel5, ID_M_TEXTMAX164, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textMax164, 0, wxALL, 5 );
	
	bSizer118->Add( fgSizer19, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panel5->SetSizer( bSizer118 );
	m_panel5->Layout();
	bSizer118->Fit( m_panel5 );
	m_notebook1->AddPage( m_panel5, _("Tours data"), true );
	m_panel6 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook1->AddPage( m_panel6, _("Other"), false );
	
	bSizer115->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer116->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer116->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer115->Add( bSizer116, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer115 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnDiscard ), NULL, this );
}

Settings::~Settings()
{
	// Disconnect Events
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnDiscard ), NULL, this );
	
}

Staff::Staff( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ANY, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer121->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpUpdate = new wxBitmapButton( this, ID_M_BPUPDATE, wxBitmap( button_save_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer121->Add( m_bpUpdate, 0, wxALL, 5 );
	
	m_bpDelete = new wxBitmapButton( this, ID_M_BPDELETE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer121->Add( m_bpDelete, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_OK, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer121->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CANCEL, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer121->Add( m_bpDiscard, 0, wxALL, 5 );
	
	m_bSizerMain->Add( bSizer121, 0, wxALIGN_RIGHT, 5 );
	
	this->SetSizer( m_bSizerMain );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_bpAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnAdd ), NULL, this );
	m_bpUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnUpdate ), NULL, this );
	m_bpDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnRemove ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnDiscard ), NULL, this );
}

Staff::~Staff()
{
	// Disconnect Events
	m_bpAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnAdd ), NULL, this );
	m_bpUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnUpdate ), NULL, this );
	m_bpDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnRemove ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Staff::OnDiscard ), NULL, this );
	
}

CsInfo::CsInfo( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpRemove = new wxBitmapButton( this, wxID_CHAMPIONSIP_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpRemove, 0, wxALL, 5 );
	
	m_bpSave = new wxBitmapButton( this, wxID_CHAMPIONSHIP_SAVE, wxBitmap( button_save_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_CHAMPIONSHIP_DISCARD, wxBitmap( button_update2_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpDiscard, 0, wxALL, 5 );
	
	m_bpCategoryMngr = new wxBitmapButton( this, wxID_CHAMPIONSHIP_CATEGORIES, wxBitmap( button_categories_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpCategoryMngr, 0, wxALL, 5 );
	
	m_bpJudgesMngr = new wxBitmapButton( this, wxID_CHAMPIONSHIP_JUDGESTEAMMNGR, wxBitmap( button_judges_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpJudgesMngr, 0, wxALL, 5 );
	
	m_bpSendinvitation = new wxBitmapButton( this, wxID_CHAMPIONSHIP_SENDINVITATION, wxBitmap( mail_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpSendinvitation, 0, wxALL, 5 );
	
	m_bpDancersTeams = new wxBitmapButton( this, ID_TEAMS, wxBitmap( button_championship_teams_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpDancersTeams, 0, wxALL, 5 );
	
	m_bpStartNumberMngr = new wxBitmapButton( this, wxID_CHAMPIONSHIP_STARTNUMBERMNGR, wxBitmap( button_startnumber_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpStartNumberMngr, 0, wxALL, 5 );
	
	m_bpTourAdd = new wxBitmapButton( this, ID_TOUR_ADD, wxBitmap( button_tour_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpTourAdd, 0, wxALL, 5 );
	
	bSizer13->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpTourEdit = new wxBitmapButton( this, ID_TOUR_EDIT, wxBitmap( button_tour_edit_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer71->Add( m_bpTourEdit, 0, wxALL, 5 );
	
	m_bpTourRemove = new wxBitmapButton( this, ID_TOUR_REMOVE, wxBitmap( button_tour_remove_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer71->Add( m_bpTourRemove, 0, wxALL, 5 );
	
	m_bpJudgesMark = new wxBitmapButton( this, ID_TOUR_JUIDGES_MARKS, wxBitmap( button_mark_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer71->Add( m_bpJudgesMark, 0, wxALL, 5 );
	
	m_bpTourReport = new wxBitmapButton( this, ID_TOUR_REPORT, wxBitmap( button_results_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer71->Add( m_bpTourReport, 0, wxALL, 5 );
	
	bSizer13->Add( bSizer71, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 6, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer1->Add( m_staticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textChName = new wxTextCtrl( this, ID_NAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textChName->SetMaxLength( 100 ); 
	fgSizer1->Add( m_textChName, 0, wxEXPAND|wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_comboType = new wxComboBox( this, ID_TYPE, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, 0 ); 
	fgSizer1->Add( m_comboType, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("Date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer1->Add( m_staticText5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_dateDate = new wxDatePickerCtrl( this, ID_DATE, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY );
	fgSizer1->Add( m_dateDate, 0, wxALL, 5 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, _("City"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_comboCity = new wxComboBox( this, ID_CITY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, 0 ); 
	fgSizer1->Add( m_comboCity, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("Adsress"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer1->Add( m_staticText8, 0, wxALL, 5 );
	
	m_textAddress = new wxTextCtrl( this, ID_ADDRESS, wxEmptyString, wxDefaultPosition, wxSize( -1,50 ), wxTE_MULTILINE );
	fgSizer1->Add( m_textAddress, 0, wxEXPAND|wxALL, 5 );
	
	bSizer13->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Online registration") ), wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, _("Open date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	sbSizer1->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateRegOpen = new wxDatePickerCtrl( this, ID_REG_OPEN, wxDefaultDateTime, wxDefaultPosition, wxSize( -1,25 ), wxDP_DEFAULT|wxDP_SHOWCENTURY );
	sbSizer1->Add( m_dateRegOpen, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, _("Close date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	sbSizer1->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateRegClose = new wxDatePickerCtrl( this, ID_REG_CLOSE, wxDefaultDateTime, wxDefaultPosition, wxSize( -1,25 ), wxDP_DEFAULT|wxDP_SHOWCENTURY );
	sbSizer1->Add( m_dateRegClose, 0, wxALL|wxEXPAND, 5 );
	
	bSizer13->Add( sbSizer1, 0, wxEXPAND|wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, _("Aditional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer13->Add( m_staticText14, 0, wxALL, 5 );
	
	m_textAdditionalInfo = new wxTextCtrl( this, ID_INFO, wxEmptyString, wxDefaultPosition, wxSize( -1,100 ), wxTE_MULTILINE );
	bSizer13->Add( m_textAdditionalInfo, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer13 );
	this->Layout();
	
	// Connect Events
	m_bpRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnRemoveChampionship ), NULL, this );
	m_bpSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnSave ), NULL, this );
	m_bpDiscard->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnDiscard ), NULL, this );
	m_bpCategoryMngr->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnCategoryMngr ), NULL, this );
	m_bpJudgesMngr->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnJudgeMngr ), NULL, this );
	m_bpSendinvitation->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnSendInvitation ), NULL, this );
	m_bpDancersTeams->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnDancersTeams ), NULL, this );
	m_bpStartNumberMngr->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnStartNumberAssign ), NULL, this );
	m_bpTourAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnAddBlock ), NULL, this );
	m_bpTourEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnTourEdit ), NULL, this );
	m_bpTourRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnRemoveTour ), NULL, this );
	m_bpJudgesMark->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnJudgesMark ), NULL, this );
	m_bpTourReport->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnCsTourReport ), NULL, this );
}

CsInfo::~CsInfo()
{
	// Disconnect Events
	m_bpRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnRemoveChampionship ), NULL, this );
	m_bpSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnSave ), NULL, this );
	m_bpDiscard->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnDiscard ), NULL, this );
	m_bpCategoryMngr->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnCategoryMngr ), NULL, this );
	m_bpJudgesMngr->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnJudgeMngr ), NULL, this );
	m_bpSendinvitation->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnSendInvitation ), NULL, this );
	m_bpDancersTeams->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnDancersTeams ), NULL, this );
	m_bpStartNumberMngr->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnStartNumberAssign ), NULL, this );
	m_bpTourAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnAddBlock ), NULL, this );
	m_bpTourEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnTourEdit ), NULL, this );
	m_bpTourRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnRemoveTour ), NULL, this );
	m_bpJudgesMark->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnJudgesMark ), NULL, this );
	m_bpTourReport->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CsInfo::OnCsTourReport ), NULL, this );
	
}

BlockInfo::BlockInfo( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer125;
	bSizer125 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer126;
	bSizer126 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpUpdate = new wxBitmapButton( this, ID_M_BPUPDATE, wxBitmap( button_save_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer126->Add( m_bpUpdate, 0, wxALL, 5 );
	
	m_bpCsCategories = new wxBitmapButton( this, ID_M_BPCSCATEGORIES, wxBitmap( button_categories_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer126->Add( m_bpCsCategories, 0, wxALL, 5 );
	
	m_bpJudges = new wxBitmapButton( this, ID_M_BPJUDGES, wxBitmap( button_judges_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer126->Add( m_bpJudges, 0, wxALL, 5 );
	
	bSizer125->Add( bSizer126, 0, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer130;
	bSizer130 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1091 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1091->Wrap( -1 );
	bSizer130->Add( m_staticText1091, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textName = new wxTextCtrl( this, ID_M_TEXTNAME, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer130->Add( m_textName, 0, wxALL, 5 );
	
	m_staticText106 = new wxStaticText( this, wxID_ANY, _("Start time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText106->Wrap( -1 );
	bSizer130->Add( m_staticText106, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textStart = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer130->Add( m_textStart, 0, wxALL, 5 );
	
	m_staticText109 = new wxStaticText( this, wxID_ANY, _("Pause, sec"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText109->Wrap( -1 );
	bSizer130->Add( m_staticText109, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textPause = new wxTextCtrl( this, ID_M_TEXTPAUSE, _("30"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textPause->SetMaxLength( 3 ); 
	bSizer130->Add( m_textPause, 0, wxALL, 5 );
	
	m_staticText107 = new wxStaticText( this, wxID_ANY, _("End time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText107->Wrap( -1 );
	bSizer130->Add( m_staticText107, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticLenght = new wxStaticText( this, ID_M_STATICLENGHT, _("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticLenght->Wrap( -1 );
	m_staticLenght->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer130->Add( m_staticLenght, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer125->Add( bSizer130, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer17;
	sbSizer17 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Judges per categories") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer22;
	fgSizer22 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer22->SetFlexibleDirection( wxBOTH );
	fgSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText119 = new wxStaticText( this, wxID_ANY, _("Category description"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText119->Wrap( -1 );
	fgSizer22->Add( m_staticText119, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticDescription = new wxStaticText( this, ID_M_STATICDESCRIPTION, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDescription->Wrap( -1 );
	m_staticDescription->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer22->Add( m_staticDescription, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer17->Add( fgSizer22, 0, wxEXPAND, 5 );
	
	m_gridJudgesCats = new wxGrid( this, ID_M_GRIDJUDGESCATS, wxDefaultPosition, wxDefaultSize, wxRAISED_BORDER|wxVSCROLL );
	
	// Grid
	m_gridJudgesCats->CreateGrid( 0, 0 );
	m_gridJudgesCats->EnableEditing( true );
	m_gridJudgesCats->EnableGridLines( true );
	m_gridJudgesCats->EnableDragGridSize( false );
	m_gridJudgesCats->SetMargins( 0, 0 );
	
	// Columns
	m_gridJudgesCats->AutoSizeColumns();
	m_gridJudgesCats->EnableDragColMove( false );
	m_gridJudgesCats->EnableDragColSize( true );
	m_gridJudgesCats->SetColLabelSize( 170 );
	m_gridJudgesCats->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_TOP );
	
	// Rows
	m_gridJudgesCats->AutoSizeRows();
	m_gridJudgesCats->EnableDragRowSize( false );
	m_gridJudgesCats->SetRowLabelSize( 100 );
	m_gridJudgesCats->SetRowLabelAlignment( wxALIGN_RIGHT, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridJudgesCats->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sbSizer17->Add( m_gridJudgesCats, 1, wxALL|wxEXPAND, 5 );
	
	bSizer125->Add( sbSizer17, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer125 );
	this->Layout();
	
	// Connect Events
	m_bpUpdate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BlockInfo::OnUpdateBlock ), NULL, this );
	m_bpCsCategories->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BlockInfo::OnBlockCategories ), NULL, this );
	m_bpJudges->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BlockInfo::OnJudgesTemManager ), NULL, this );
	m_textStart->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BlockInfo::OnTextChanged ), NULL, this );
	m_textPause->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( BlockInfo::OnPauseKillFocuss ), NULL, this );
	m_gridJudgesCats->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( BlockInfo::OnCellChange ), NULL, this );
	m_gridJudgesCats->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( BlockInfo::OnCellLeftClick ), NULL, this );
}

BlockInfo::~BlockInfo()
{
	// Disconnect Events
	m_bpUpdate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BlockInfo::OnUpdateBlock ), NULL, this );
	m_bpCsCategories->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BlockInfo::OnBlockCategories ), NULL, this );
	m_bpJudges->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BlockInfo::OnJudgesTemManager ), NULL, this );
	m_textStart->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BlockInfo::OnTextChanged ), NULL, this );
	m_textPause->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( BlockInfo::OnPauseKillFocuss ), NULL, this );
	m_gridJudgesCats->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( BlockInfo::OnCellChange ), NULL, this );
	m_gridJudgesCats->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( BlockInfo::OnCellLeftClick ), NULL, this );
	
}

CategoryInfo::CategoryInfo( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer129;
	bSizer129 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button2 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer131->Add( m_button2, 0, wxALL, 5 );
	
	m_button3 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer131->Add( m_button3, 0, wxALL, 5 );
	
	bSizer129->Add( bSizer131, 0, wxALIGN_RIGHT, 5 );
	
	m_listRegisteredTeams = new wxListCtrl( this, ID_M_LISTREGISTEREDTEAMS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxSUNKEN_BORDER );
	bSizer129->Add( m_listRegisteredTeams, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer129 );
	this->Layout();
}

CategoryInfo::~CategoryInfo()
{
}

TourInfo::TourInfo( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer133;
	bSizer133 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton146 = new wxBitmapButton( this, wxID_ANY, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer133->Add( m_bpButton146, 0, wxALL, 5 );
	
	m_bpButton147 = new wxBitmapButton( this, wxID_ANY, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer133->Add( m_bpButton147, 0, wxALL, 5 );
	
	bSizer132->Add( bSizer133, 0, wxALIGN_RIGHT, 5 );
	
	m_listSuccessTeams = new wxListCtrl( this, ID_M_LISTSUCCESSTEAMS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxSUNKEN_BORDER );
	bSizer132->Add( m_listSuccessTeams, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer132 );
	this->Layout();
}

TourInfo::~TourInfo()
{
}
