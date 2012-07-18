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
#include "../res/button_ok.xpm"
#include "../res/button_raiting.xpm"
#include "../res/button_random.xpm"
#include "../res/button_results.xpm"
#include "../res/button_right.xpm"
#include "../res/button_rightall.xpm"
#include "../res/button_startnumber.xpm"
#include "../res/button_user.xpm"
#include "../res/mail.xpm"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( DancersTeamMngr, wxDialog )
	EVT_BUTTON( wxID_ADD, DancersTeamMngr::_wxFB_OnAddDancerTeam )
	EVT_BUTTON( wxID_REMOVE, DancersTeamMngr::_wxFB_OnRemoveTancerTeam )
	EVT_BUTTON( wxID_ADDDANCERTEAMCATEGORY, DancersTeamMngr::_wxFB_OnAddDancerTeamCategory )
	EVT_BUTTON( wxID_REMOVEDANCERTEAMCATEGORY, DancersTeamMngr::_wxFB_OnRemoveDancerTeamCategory )
	EVT_BUTTON( wxID_ADDDANCER, DancersTeamMngr::_wxFB_OnAddDancerTeamDancer )
	EVT_BUTTON( wxID_REMOVEDANCER, DancersTeamMngr::_wxFB_OnRemoveDancerTeamDancer )
	EVT_BUTTON( wxID_SAVE, DancersTeamMngr::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, DancersTeamMngr::_wxFB_OnDiscard )
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
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer13->AddGrowableCol( 1 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText88 = new wxStaticText( this, wxID_ANY, _("Championship"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText88->Wrap( -1 );
	fgSizer13->Add( m_staticText88, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox19 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxSize( 100,-1 ), 0, NULL, 0 ); 
	fgSizer13->Add( m_comboBox19, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText89 = new wxStaticText( this, wxID_ANY, _("Club"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText89->Wrap( -1 );
	fgSizer13->Add( m_staticText89, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox20 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxSize( 100,-1 ), 0, NULL, 0 ); 
	fgSizer13->Add( m_comboBox20, 1, wxALL|wxEXPAND, 5 );
	
	bSizer73->Add( fgSizer13, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Teams") ), wxVERTICAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer18->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl5 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_textCtrl5, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer2->Add( bSizer18, 0, wxEXPAND, 5 );
	
	m_listBox4 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer2->Add( m_listBox4, 1, wxALL|wxEXPAND, 5 );
	
	bSizer73->Add( sbSizer2, 1, wxEXPAND|wxALL, 5 );
	
	bSizer16->Add( bSizer73, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton13 = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer74->Add( m_bpButton13, 0, wxALL, 5 );
	
	m_bpButton14 = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer74->Add( m_bpButton14, 0, wxALL, 5 );
	
	bSizer181->Add( bSizer74, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("Team name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer2->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl6 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_textCtrl6, 0, wxALL|wxEXPAND, 5 );
	
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
	
	m_comboBox17 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer91->Add( m_comboBox17, 0, wxALL|wxEXPAND, 5 );
	
	m_listBox22 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer91->Add( m_listBox22, 0, wxALL|wxEXPAND, 5 );
	
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
	
	m_comboBox16 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer90->Add( m_comboBox16, 0, wxALL|wxEXPAND, 5 );
	
	m_listBox21 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer90->Add( m_listBox21, 1, wxALL|wxEXPAND, 5 );
	
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
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer33->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer33->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer181->Add( bSizer33, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer16->Add( bSizer181, 1, wxEXPAND, 5 );
	
	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer15 );
	this->Layout();
}

DancersTeamMngr::~DancersTeamMngr()
{
}

BEGIN_EVENT_TABLE( ChampionshipCategoriesMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADDALL, ChampionshipCategoriesMngrDlg::_wxFB_OnAddAll )
	EVT_BUTTON( wxID_ADDONE, ChampionshipCategoriesMngrDlg::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVEONE, ChampionshipCategoriesMngrDlg::_wxFB_OnRemove )
	EVT_BUTTON( wxID_REMOVEALL, ChampionshipCategoriesMngrDlg::_wxFB_OnRemoveAll )
	EVT_BUTTON( wxID_SAVE, ChampionshipCategoriesMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, ChampionshipCategoriesMngrDlg::_wxFB_OnDiscard )
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
	
	m_listBox2 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer9->Add( m_listBox2, 1, wxALL|wxEXPAND, 5 );
	
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
	
	m_listBox3 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer11->Add( m_listBox3, 1, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer11, 1, wxEXPAND, 5 );
	
	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpSave->SetDefault(); 
	bSizer34->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer7->Add( bSizer34, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
}

ChampionshipCategoriesMngrDlg::~ChampionshipCategoriesMngrDlg()
{
}

BEGIN_EVENT_TABLE( CategoriesMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADD, CategoriesMngrDlg::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVE, CategoriesMngrDlg::_wxFB_OnRemove )
	EVT_BUTTON( wxID_SAVE, CategoriesMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, CategoriesMngrDlg::_wxFB_OnDiscard )
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
	
	m_textCtrl5 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_textCtrl5, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer10->Add( bSizer18, 0, wxEXPAND, 5 );
	
	m_listBox4 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer10->Add( m_listBox4, 1, wxALL, 5 );
	
	bSizer16->Add( sbSizer10, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton13 = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer75->Add( m_bpButton13, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer75->Add( m_bpRemove, 0, wxALL, 5 );
	
	bSizer181->Add( bSizer75, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 4, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	fgSizer2->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl6 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_textCtrl6, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Short name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	fgSizer2->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl7 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_textCtrl7, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Dance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	fgSizer2->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox4 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer2->Add( m_comboBox4, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Liga"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer2->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox5 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer2->Add( m_comboBox5, 0, wxALL|wxEXPAND, 5 );
	
	bSizer181->Add( fgSizer2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton29 = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer33->Add( m_bpButton29, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer33->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer181->Add( bSizer33, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer16->Add( bSizer181, 1, wxEXPAND, 5 );
	
	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer15 );
	this->Layout();
}

CategoriesMngrDlg::~CategoriesMngrDlg()
{
}

BEGIN_EVENT_TABLE( ClubsMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADDCLUB, ClubsMngrDlg::_wxFB_OnAddClub )
	EVT_BUTTON( wxID_REMOVECLUB, ClubsMngrDlg::_wxFB_OnRemoveClub )
	EVT_BUTTON( wxID_ACCOUNTINFO, ClubsMngrDlg::_wxFB_OnAccountInfo )
	EVT_BUTTON( wxID_DIRECTORINFO, ClubsMngrDlg::_wxFB_OnDirectorInfo )
	EVT_BUTTON( wxID_TRAINERS, ClubsMngrDlg::_wxFB_OnTrainersMngr )
	EVT_BUTTON( wxID_DANCERS, ClubsMngrDlg::_wxFB_OnDancersMngr )
	EVT_BUTTON( wxID_SAVE, ClubsMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, ClubsMngrDlg::_wxFB_OnDiscard )
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
	
	m_textCtrl8 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_textCtrl8, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer8->Add( bSizer23, 0, wxEXPAND, 5 );
	
	m_listBox5 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer8->Add( m_listBox5, 1, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( sbSizer8, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAddClub = new wxBitmapButton( this, wxID_ADDCLUB, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpAddClub, 0, wxALL, 5 );
	
	m_bpRemoveClub = new wxBitmapButton( this, wxID_REMOVECLUB, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpRemoveClub, 0, wxALL, 5 );
	
	m_bpAccountInfo = new wxBitmapButton( this, wxID_ACCOUNTINFO, wxBitmap( button_account_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpAccountInfo, 0, wxALL, 5 );
	
	m_bpDirectorInfo = new wxBitmapButton( this, wxID_DIRECTORINFO, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpDirectorInfo, 0, wxALL, 5 );
	
	m_bpTarinersMngr = new wxBitmapButton( this, wxID_TRAINERS, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpTarinersMngr, 0, wxALL, 5 );
	
	m_bpDancersMngr = new wxBitmapButton( this, wxID_DANCERS, wxBitmap( button_user_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpDancersMngr, 0, wxALL, 5 );
	
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
	
	m_textCtrl9 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl9, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("City"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox6 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboBox6, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer3->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl10 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl10, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer3->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl11, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Web"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer3->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl12 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl12, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Additional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer3->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textCtrl13 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,70 ), 0 );
	fgSizer3->Add( m_textCtrl13, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Pay date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer3->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker6 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer3->Add( m_datePicker6, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("Exp. date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer3->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker7 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer3->Add( m_datePicker7, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer73->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpCancel = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer73->Add( m_bpCancel, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer73, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
}

ClubsMngrDlg::~ClubsMngrDlg()
{
}

BEGIN_EVENT_TABLE( MainFrameBase, wxFrame )
	EVT_CLOSE( MainFrameBase::_wxFB_OnCloseFrame )
	EVT_MENU( wxID_EXIT, MainFrameBase::_wxFB_OnExitClick )
	EVT_MENU( wxID_MENU_CAT_MNGR, MainFrameBase::_wxFB_OnMenuCategoryManage )
	EVT_MENU( wxID_MENU_CLUBS_MNGR, MainFrameBase::_wxFB_OnMenuClubManage )
	EVT_MENU( wxID_MENU_JUDGE_MNGR, MainFrameBase::_wxFB_OnMenuJudgeManage )
	EVT_BUTTON( wxID_CHAMPIONSIP_ADD, MainFrameBase::_wxFB_OnAddChampionsip )
	EVT_BUTTON( wxID_CHAMPIONSIP_REMOVE, MainFrameBase::_wxFB_OnRemoveChampionship )
	EVT_BUTTON( wxID_CHAMPIONSHIP_CATEGORIES, MainFrameBase::_wxFB_OnCategoryMngr )
	EVT_BUTTON( wxID_CHAMPIONSHIP_STARTNUMBERMNGR, MainFrameBase::_wxFB_OnStartNumberAssign )
	EVT_BUTTON( wxID_CHAMPIONSHIP_JUDGESTEAMMNGR, MainFrameBase::_wxFB_OnJudgeMngr )
	EVT_BUTTON( wxID_CHAMPIONSHIP_SENDINVITATION, MainFrameBase::_wxFB_OnSendInvitation )
	EVT_BUTTON( wxID_RESULTS, MainFrameBase::_wxFB_OnResults )
	EVT_BUTTON( wxID_CHAMPIONSHIP_SAVE, MainFrameBase::_wxFB_OnSave )
	EVT_BUTTON( wxID_CHAMPIONSHIPDISCARD, MainFrameBase::_wxFB_OnDiscard )
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
	
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( m_menu2, wxID_MENU_CAT_MNGR, wxString( _("Manage") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem9 );
	
	m_menuBar->Append( m_menu2, _("Categories") );
	
	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu3, wxID_MENU_CLUBS_MNGR, wxString( _("Manage") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem5 );
	
	m_menuBar->Append( m_menu3, _("Clubs") );
	
	m_menu5 = new wxMenu();
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu5, wxID_MENU_JUDGE_MNGR, wxString( _("Manage") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItem6 );
	
	m_menuBar->Append( m_menu5, _("Judges") );
	
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
	
	m_textSearch = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_textSearch, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer9->Add( bSizer5, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	m_listChamlionshipList = new wxListBox( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer9->Add( m_listChamlionshipList, 1, wxALL, 5 );
	
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
	
	m_bpCategoryMngr = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_CATEGORIES, wxBitmap( button_categories_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpCategoryMngr, 0, wxALL, 5 );
	
	m_bpStartNumberMngr = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_STARTNUMBERMNGR, wxBitmap( button_startnumber_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpStartNumberMngr, 0, wxALL, 5 );
	
	m_bpJudgesMngr = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_JUDGESTEAMMNGR, wxBitmap( button_judges_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpJudgesMngr, 0, wxALL, 5 );
	
	m_bpSendinvitation = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_SENDINVITATION, wxBitmap( mail_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpSendinvitation, 0, wxALL, 5 );
	
	m_bpResults = new wxBitmapButton( m_panel1, wxID_RESULTS, wxBitmap( button_results_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpResults, 0, wxALL, 5 );
	
	m_bpButton64 = new wxBitmapButton( m_panel1, wxID_ANY, wxBitmap( button_raiting_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer7->Add( m_bpButton64, 0, wxALL, 5 );
	
	bSizer13->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 6, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( m_panel1, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer1->Add( m_staticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textName = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_textName, 0, wxEXPAND|wxALL, 5 );
	
	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_comboType = new wxComboBox( m_panel1, wxID_ANY, _("Combo!"), wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, 0 ); 
	fgSizer1->Add( m_comboType, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText5 = new wxStaticText( m_panel1, wxID_ANY, _("Date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer1->Add( m_staticText5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_dateDate = new wxDatePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer1->Add( m_dateDate, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( m_panel1, wxID_ANY, _("Country"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer1->Add( m_staticText6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_comboCountry = new wxComboBox( m_panel1, wxID_ANY, _("Combo!"), wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, 0 ); 
	fgSizer1->Add( m_comboCountry, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText7 = new wxStaticText( m_panel1, wxID_ANY, _("City"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_comboCity = new wxComboBox( m_panel1, wxID_ANY, _("Combo!"), wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, 0 ); 
	fgSizer1->Add( m_comboCity, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText8 = new wxStaticText( m_panel1, wxID_ANY, _("Adsress"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer1->Add( m_staticText8, 0, wxALL, 5 );
	
	m_textAddress = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,50 ), wxTE_MULTILINE );
	fgSizer1->Add( m_textAddress, 0, wxEXPAND|wxALL, 5 );
	
	bSizer13->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Online registration") ), wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( m_panel1, wxID_ANY, _("Open date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	sbSizer1->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateRegOpen = new wxDatePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	sbSizer1->Add( m_dateRegOpen, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( m_panel1, wxID_ANY, _("Close date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	sbSizer1->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_dateRegClose = new wxDatePickerCtrl( m_panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	sbSizer1->Add( m_dateRegClose, 0, wxALL, 5 );
	
	bSizer13->Add( sbSizer1, 0, wxEXPAND|wxALL, 5 );
	
	m_staticText14 = new wxStaticText( m_panel1, wxID_ANY, _("Aditional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer13->Add( m_staticText14, 0, wxALL, 5 );
	
	m_textAdditionalInfo = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,100 ), wxTE_MULTILINE );
	bSizer13->Add( m_textAdditionalInfo, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIP_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer35->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( m_panel1, wxID_CHAMPIONSHIPDISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer35->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer13->Add( bSizer35, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer6->Add( bSizer13, 1, wxEXPAND, 5 );
	
	bSizer2->Add( bSizer6, 1, wxEXPAND, 5 );
	
	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	mainSizer->Add( m_panel1, 1, wxEXPAND, 5 );
	
	this->SetSizer( mainSizer );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
}

MainFrameBase::~MainFrameBase()
{
}

BEGIN_EVENT_TABLE( DirectorInfo, wxDialog )
	EVT_BUTTON( wxID_SAVE, DirectorInfo::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, DirectorInfo::_wxFB_OnDiscard )
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
	
	m_textCtrl14 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textCtrl14, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText30 = new wxStaticText( this, wxID_ANY, _("Birth date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	fgSizer4->Add( m_staticText30, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker8 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer4->Add( m_datePicker8, 0, wxALL, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Phone"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer4->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl15 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textCtrl15, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, _("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	fgSizer4->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl16 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_textCtrl16, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText33 = new wxStaticText( this, wxID_ANY, _("Pay date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	fgSizer4->Add( m_staticText33, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker9 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer4->Add( m_datePicker9, 0, wxALL, 5 );
	
	m_staticText34 = new wxStaticText( this, wxID_ANY, _("Exp. date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	fgSizer4->Add( m_staticText34, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker10 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer4->Add( m_datePicker10, 0, wxALL, 5 );
	
	bSizer25->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton25 = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer26->Add( m_bpButton25, 0, wxALL, 5 );
	
	m_bpButton26 = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer26->Add( m_bpButton26, 0, wxALL, 5 );
	
	bSizer25->Add( bSizer26, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer25 );
	this->Layout();
}

DirectorInfo::~DirectorInfo()
{
}

BEGIN_EVENT_TABLE( TarinersMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADD, TarinersMngrDlg::_wxFB_OnAddTrainer )
	EVT_BUTTON( wxID_REMOVE, TarinersMngrDlg::_wxFB_OnRemoveTrainer )
	EVT_BUTTON( wxID_SAVE, TarinersMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, TarinersMngrDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

TarinersMngrDlg::TarinersMngrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
	
	m_textCtrl8 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_textCtrl8, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer5->Add( bSizer23, 0, wxEXPAND, 5 );
	
	m_listBox5 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer5->Add( m_listBox5, 1, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( sbSizer5, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAddTrainer = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpAddTrainer, 0, wxALL, 5 );
	
	m_bpRemoveTrainer = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpRemoveTrainer, 0, wxALL, 5 );
	
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
	
	m_textCtrl9 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl9, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("Club"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox6 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboBox6, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Phone"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer3->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl10 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl10, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer3->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl11, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Birth date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer3->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl12 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl12, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Additional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer3->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textCtrl13 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,70 ), 0 );
	fgSizer3->Add( m_textCtrl13, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Pay date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer3->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker6 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer3->Add( m_datePicker6, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("Exp. date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer3->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker7 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer3->Add( m_datePicker7, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer24, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
}

TarinersMngrDlg::~TarinersMngrDlg()
{
}

BEGIN_EVENT_TABLE( DancersMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADD, DancersMngrDlg::_wxFB_OnAddDancer )
	EVT_BUTTON( wxID_REMOVE, DancersMngrDlg::_wxFB_OnRemoveDancer )
	EVT_BUTTON( wxID_SAVE, DancersMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, DancersMngrDlg::_wxFB_OnDiscard )
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
	
	m_textCtrl38 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_textCtrl38, 1, wxALL, 5 );
	
	sbSizer6->Add( bSizer21, 0, wxEXPAND, 5 );
	
	m_listBox5 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer6->Add( m_listBox5, 1, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( sbSizer6, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAddDancer = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_danceradd_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer77->Add( m_bpAddDancer, 0, wxALL, 5 );
	
	m_bpRemoveDancer = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_dancerremove_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer77->Add( m_bpRemoveDancer, 0, wxALL, 5 );
	
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
	
	m_textCtrl9 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl9, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText54 = new wxStaticText( this, wxID_ANY, _("Raiting"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	fgSizer3->Add( m_staticText54, 0, wxALL, 5 );
	
	m_staticText55 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	m_staticText55->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer3->Add( m_staticText55, 0, wxALL, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("Club"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox6 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboBox6, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText61 = new wxStaticText( this, wxID_ANY, _("Trainer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	fgSizer3->Add( m_staticText61, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox13 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboBox13, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText63 = new wxStaticText( this, wxID_ANY, _("Liga"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText63->Wrap( -1 );
	fgSizer3->Add( m_staticText63, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox15 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboBox15, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Reg book ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer3->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl10 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl10, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("Gender"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer3->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox14 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN ); 
	fgSizer3->Add( m_comboBox14, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Birth date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer3->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl12 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl12, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Additional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer3->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textCtrl13 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,70 ), 0 );
	fgSizer3->Add( m_textCtrl13, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Pay date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer3->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker6 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer3->Add( m_datePicker6, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("Exp. date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer3->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker7 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer3->Add( m_datePicker7, 0, wxALL, 5 );
	
	m_staticText62 = new wxStaticText( this, wxID_ANY, _("Reg date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	fgSizer3->Add( m_staticText62, 0, wxALL, 5 );
	
	m_datePicker15 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer3->Add( m_datePicker15, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton24 = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpButton24, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer24, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer19, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer33 );
	this->Layout();
}

DancersMngrDlg::~DancersMngrDlg()
{
}

BEGIN_EVENT_TABLE( AccountInfo, wxDialog )
	EVT_BUTTON( wxID_SAVE, AccountInfo::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, AccountInfo::_wxFB_OnDiscard )
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
	
	m_textCtrl28 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_textCtrl28, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText57 = new wxStaticText( this, wxID_ANY, _("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText57->Wrap( -1 );
	fgSizer7->Add( m_staticText57, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl29 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_textCtrl29, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer7->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox1 = new wxCheckBox( this, wxID_ANY, _("Show password"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_checkBox1, 0, wxALL, 5 );
	
	bSizer44->Add( fgSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton39 = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer43->Add( m_bpButton39, 0, wxALL, 5 );
	
	m_bpButton40 = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer43->Add( m_bpButton40, 0, wxALL, 5 );
	
	bSizer44->Add( bSizer43, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer44 );
	this->Layout();
}

AccountInfo::~AccountInfo()
{
}

BEGIN_EVENT_TABLE( JudgesMngr, wxDialog )
	EVT_BUTTON( wxID_ADD, JudgesMngr::_wxFB_OnAddJudge )
	EVT_BUTTON( wxID_REMOVE, JudgesMngr::_wxFB_OnRemoveJudge )
	EVT_BUTTON( wxID_SAVE, JudgesMngr::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, JudgesMngr::_wxFB_OnDiscard )
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
	
	m_textCtrl8 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_textCtrl8, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer7->Add( bSizer23, 0, wxEXPAND, 5 );
	
	m_listBox5 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer7->Add( m_listBox5, 1, wxALL|wxEXPAND, 5 );
	
	bSizer20->Add( sbSizer7, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpAdd = new wxBitmapButton( this, wxID_ADD, wxBitmap( button_add_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpAdd, 0, wxALL, 5 );
	
	m_bpRemove = new wxBitmapButton( this, wxID_REMOVE, wxBitmap( button_delete_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer76->Add( m_bpRemove, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer76, 0, wxALIGN_RIGHT, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 10, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 6 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer3->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl9 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl9, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, _("Country"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	fgSizer3->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox6 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboBox6, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText77 = new wxStaticText( this, wxID_ANY, _("City"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText77->Wrap( -1 );
	fgSizer3->Add( m_staticText77, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_comboBox14 = new wxComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_comboBox14, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Last attestation info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer3->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl10 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl10, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("E-mail"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	fgSizer3->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl11, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Phone"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer3->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl12 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_textCtrl12, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, _("Additional info"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer3->Add( m_staticText26, 0, wxALL, 5 );
	
	m_textCtrl13 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,70 ), 0 );
	fgSizer3->Add( m_textCtrl13, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBox2 = new wxCheckBox( this, wxID_ANY, _("Practicer"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_checkBox2, 0, wxALL, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Pay date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer3->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker6 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer3->Add( m_datePicker6, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, _("Exp. date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer3->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_datePicker7 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	fgSizer3->Add( m_datePicker7, 0, wxALL, 5 );
	
	bSizer22->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton19 = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpButton19, 0, wxALL, 5 );
	
	m_bpButton20 = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer24->Add( m_bpButton20, 0, wxALL, 5 );
	
	bSizer22->Add( bSizer24, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer19 );
	this->Layout();
}

JudgesMngr::~JudgesMngr()
{
}

BEGIN_EVENT_TABLE( TeamCategoryMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADDALL, TeamCategoryMngrDlg::_wxFB_OnAddAll )
	EVT_BUTTON( wxID_ADDONE, TeamCategoryMngrDlg::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVEONE, TeamCategoryMngrDlg::_wxFB_OnRemove )
	EVT_BUTTON( wxID_REMOVEALL, TeamCategoryMngrDlg::_wxFB_OnRemoveAll )
	EVT_BUTTON( wxID_SAVE, TeamCategoryMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, TeamCategoryMngrDlg::_wxFB_OnDiscard )
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
	
	m_bpButton31 = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpButton31, 0, wxALL, 5 );
	
	m_bpButton32 = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpButton32, 0, wxALL, 5 );
	
	bSizer7->Add( bSizer34, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
}

TeamCategoryMngrDlg::~TeamCategoryMngrDlg()
{
}

BEGIN_EVENT_TABLE( TeamDancersMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADDALL, TeamDancersMngrDlg::_wxFB_OnAddAll )
	EVT_BUTTON( wxID_ADDONE, TeamDancersMngrDlg::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVEONE, TeamDancersMngrDlg::_wxFB_OnRemove )
	EVT_BUTTON( wxID_REMOVEALL, TeamDancersMngrDlg::_wxFB_OnRemoveAll )
	EVT_BUTTON( wxID_SAVE, TeamDancersMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, TeamDancersMngrDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

TeamDancersMngrDlg::TeamDancersMngrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
	
	m_bpButton31 = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpButton31, 0, wxALL, 5 );
	
	m_bpButton32 = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpButton32, 0, wxALL, 5 );
	
	bSizer7->Add( bSizer34, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
}

TeamDancersMngrDlg::~TeamDancersMngrDlg()
{
}

BEGIN_EVENT_TABLE( ChampionshipJudgesTeamMngrDlg, wxDialog )
	EVT_BUTTON( wxID_ADDALL, ChampionshipJudgesTeamMngrDlg::_wxFB_OnAddAll )
	EVT_BUTTON( wxID_ADDONE, ChampionshipJudgesTeamMngrDlg::_wxFB_OnAdd )
	EVT_BUTTON( wxID_REMOVEONE, ChampionshipJudgesTeamMngrDlg::_wxFB_OnRemove )
	EVT_BUTTON( wxID_REMOVEALL, ChampionshipJudgesTeamMngrDlg::_wxFB_OnRemoveAll )
	EVT_BUTTON( wxID_SAVE, ChampionshipJudgesTeamMngrDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, ChampionshipJudgesTeamMngrDlg::_wxFB_OnDiscard )
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
	
	m_listBox2 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer9->Add( m_listBox2, 1, wxALL|wxEXPAND, 5 );
	
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
	
	m_listBox3 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer11->Add( m_listBox3, 1, wxALL|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer11, 1, wxEXPAND, 5 );
	
	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton31 = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpButton31, 0, wxALL, 5 );
	
	m_bpButton32 = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer34->Add( m_bpButton32, 0, wxALL, 5 );
	
	bSizer7->Add( bSizer34, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
}

ChampionshipJudgesTeamMngrDlg::~ChampionshipJudgesTeamMngrDlg()
{
}

BEGIN_EVENT_TABLE( StartNumberAssignDlg, wxDialog )
	EVT_BUTTON( wxID_RANDOM, StartNumberAssignDlg::_wxFB_OnRandomFind )
	EVT_BUTTON( wxID_NEXT, StartNumberAssignDlg::_wxFB_OnNextFind )
	EVT_BUTTON( wxID_ASSIGN, StartNumberAssignDlg::_wxFB_OnAssign )
	EVT_BUTTON( wxID_SAVE, StartNumberAssignDlg::_wxFB_OnSave )
	EVT_BUTTON( wxID_DISCARD, StartNumberAssignDlg::_wxFB_OnDiscard )
END_EVENT_TABLE()

StartNumberAssignDlg::StartNumberAssignDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Teams") ), wxVERTICAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, _("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer18->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl5 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_textCtrl5, 1, wxALL|wxEXPAND, 5 );
	
	sbSizer2->Add( bSizer18, 0, wxEXPAND, 5 );
	
	m_listBox4 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, 0 ); 
	sbSizer2->Add( m_listBox4, 1, wxALL|wxEXPAND, 5 );
	
	bSizer95->Add( sbSizer2, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer98;
	bSizer98 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText85 = new wxStaticText( this, wxID_ANY, _("Team"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText85->Wrap( -1 );
	bSizer98->Add( m_staticText85, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTeamName = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTeamName->Wrap( -1 );
	m_staticTeamName->SetFont( wxFont( 18, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer98->Add( m_staticTeamName, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrl40 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_textCtrl40->SetFont( wxFont( 42, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer98->Add( m_textCtrl40, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer99;
	bSizer99 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpRandomNumber = new wxBitmapButton( this, wxID_RANDOM, wxBitmap( button_random_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer99->Add( m_bpRandomNumber, 0, wxALL, 5 );
	
	m_bpNextNumber = new wxBitmapButton( this, wxID_NEXT, wxBitmap( button_right_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpNextNumber->SetDefault(); 
	bSizer99->Add( m_bpNextNumber, 0, wxALL, 5 );
	
	m_bpAssign = new wxBitmapButton( this, wxID_ASSIGN, wxBitmap( button_assign_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer99->Add( m_bpAssign, 0, wxALL, 5 );
	
	bSizer98->Add( bSizer99, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer98->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpSave = new wxBitmapButton( this, wxID_SAVE, wxBitmap( button_ok_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer83->Add( m_bpSave, 0, wxALL, 5 );
	
	m_bpDiscard = new wxBitmapButton( this, wxID_DISCARD, wxBitmap( button_cancel_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer83->Add( m_bpDiscard, 0, wxALL, 5 );
	
	bSizer98->Add( bSizer83, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer95->Add( bSizer98, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer95 );
	this->Layout();
}

StartNumberAssignDlg::~StartNumberAssignDlg()
{
}
