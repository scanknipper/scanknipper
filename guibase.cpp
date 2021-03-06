///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "guibase.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 630,-1 ), wxDefaultSize );
	
	m_menubar1 = new wxMenuBar( 0 );
	m_fileMenu = new wxMenu();
	wxMenuItem* m_openFile;
	m_openFile = new wxMenuItem( m_fileMenu, wxID_OPEN, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_fileMenu->Append( m_openFile );
	
	wxMenuItem* m_save;
	m_save = new wxMenuItem( m_fileMenu, wxID_SAVE, wxString( wxT("Save All") ) , wxEmptyString, wxITEM_NORMAL );
	m_fileMenu->Append( m_save );
	
	wxMenuItem* m_close;
	m_close = new wxMenuItem( m_fileMenu, wxID_CLOSE, wxString( wxT("Close") ) , wxEmptyString, wxITEM_NORMAL );
	m_fileMenu->Append( m_close );
	
	m_menubar1->Append( m_fileMenu, wxT("File") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_saveAndNextButton = new wxButton( this, wxID_ANY, wxT("Save, Next Image"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_saveAndNextButton, 0, wxALL|wxEXPAND, 5 );
	
	m_skipAndNextButton = new wxButton( this, wxID_ANY, wxT("Don't Save , Next Image"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_skipAndNextButton, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_prevImage = new wxButton( this, wxID_ANY, wxT("Previous Image"), wxDefaultPosition, wxDefaultSize, 0 );
	m_prevImage->Enable( false );
	
	bSizer2->Add( m_prevImage, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->AddGrowableRow( 2 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Columns"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer3->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_columnsSpinCtrl = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 26, 8 );
	bSizer3->Add( m_columnsSpinCtrl, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Rows"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer5->Add( m_staticText31, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_rowsSpinCtrl = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 26, 1 );
	bSizer5->Add( m_rowsSpinCtrl, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Column names."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer2->Add( m_staticText4, 0, wxALL, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Row Names"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->Enable( false );
	
	fgSizer2->Add( m_staticText5, 0, wxALL, 5 );
	
	wxString m_choice2Choices[] = { wxT("A,B,C..."), wxT("1,2,3,..."), wxT("Custom") };
	int m_choice2NChoices = sizeof( m_choice2Choices ) / sizeof( wxString );
	m_choice2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice2NChoices, m_choice2Choices, 0 );
	m_choice2->SetSelection( 0 );
	fgSizer2->Add( m_choice2, 0, wxALL, 5 );
	
	wxString m_choice4Choices[] = { wxT("A,B,C,..."), wxT("1,2,3,..."), wxT("Custom") };
	int m_choice4NChoices = sizeof( m_choice4Choices ) / sizeof( wxString );
	m_choice4 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice4NChoices, m_choice4Choices, 0 );
	m_choice4->SetSelection( 1 );
	m_choice4->Enable( false );
	
	fgSizer2->Add( m_choice4, 0, wxALL, 5 );
	
	m_columnNames = new wxEditableListBox(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxEL_ALLOW_EDIT |  wxEL_NO_REORDER);
	m_columnNames->SetMaxSize( wxSize( 150,-1 ) );
	
	fgSizer2->Add( m_columnNames, 1, wxALL|wxEXPAND, 5 );
	
	m_rowNames = new wxEditableListBox(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxEL_ALLOW_EDIT |  wxEL_NO_REORDER);
	m_rowNames->Enable( false );
	m_rowNames->SetMaxSize( wxSize( 150,-1 ) );
	
	fgSizer2->Add( m_rowNames, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer2->Add( fgSizer2, 0, wxEXPAND, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 3, 2, 0, 0 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Save Format"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gSizer1->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	wxString m_saveFormatChoiceChoices[] = { wxT("Jpeg"), wxT("Png") };
	int m_saveFormatChoiceNChoices = sizeof( m_saveFormatChoiceChoices ) / sizeof( wxString );
	m_saveFormatChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_saveFormatChoiceNChoices, m_saveFormatChoiceChoices, 0 );
	m_saveFormatChoice->SetSelection( 0 );
	gSizer1->Add( m_saveFormatChoice, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer2->Add( gSizer1, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	m_canvas = new ImageCanvas(this);
	bSizer1->Add( m_canvas, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	this->Connect( m_openFile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOpenFile ) );
	this->Connect( m_save->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnSave ) );
	this->Connect( m_close->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnClose ) );
	m_saveAndNextButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnSaveAndNext ), NULL, this );
	m_skipAndNextButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnSkipAndNext ), NULL, this );
	m_prevImage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnPrevious ), NULL, this );
	m_columnsSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MainFrameBase::OnColumns ), NULL, this );
	m_rowsSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MainFrameBase::OnRows ), NULL, this );
	m_saveFormatChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileType ), NULL, this );
	m_canvas->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MainFrameBase::OnLeftDown ), NULL, this );
	m_canvas->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrameBase::OnLeftUp ), NULL, this );
	m_canvas->Connect( wxEVT_MOTION, wxMouseEventHandler( MainFrameBase::OnMotion ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOpenFile ) );
	this->Disconnect( wxID_SAVE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnSave ) );
	this->Disconnect( wxID_CLOSE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnClose ) );
	m_saveAndNextButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnSaveAndNext ), NULL, this );
	m_skipAndNextButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnSkipAndNext ), NULL, this );
	m_prevImage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnPrevious ), NULL, this );
	m_columnsSpinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MainFrameBase::OnColumns ), NULL, this );
	m_rowsSpinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MainFrameBase::OnRows ), NULL, this );
	m_saveFormatChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileType ), NULL, this );
	m_canvas->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MainFrameBase::OnLeftDown ), NULL, this );
	m_canvas->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MainFrameBase::OnLeftUp ), NULL, this );
	m_canvas->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MainFrameBase::OnMotion ), NULL, this );
	
}
