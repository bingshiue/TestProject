/**
 * @file maiFrame.cpp
 *
 */

#include "mainFrame.h"
#include "icons/sample.xpm"

MainFrame::MainFrame(const wxString& title) : wxFrame((wxFrame*)NULL,wxID_ANY,title,wxDefaultPosition,wxSize(1280,720))
{
	/* Initialize Mersenne Twister Algorithm */
	srand(time(NULL));
	int seed = rand()%10000;
	m_mtRandom.resetMT(seed); // use 19650218UL as seed for verify Mersenne Twister Algorithm
	LOGD("Mersenne Twister","Initialized Seed=%d \n",seed);

	/* Create wxNotebook Instance */
	this->m_noteBook = new wxNotebook(this,wxID_ANY);

	/* Create Panel Instance */
	this->m_parent = new wxPanel(this->m_noteBook,wxID_ANY);

    /* Add Panels to Notebook */
	this->m_noteBook->AddPage(this->m_parent,L"CrownTrain",true);

	/* Create Main Top Box Sizer */
	this->m_mainTopSizer = new wxBoxSizer(wxVERTICAL);

	/* Create Horizontal Box Sizer 1 */
	this->m_hbox_1 = new wxBoxSizer(wxHORIZONTAL);

	/* Create Left Slot Item Panel Instance */
	this->m_slotItemPanel_left = new SlotItemPanel(this->m_parent,L"Left Slot");
	/* Create Middle Slot Item Panel Instance */
	this->m_slotItemPanel_middle = new SlotItemPanel(this->m_parent,L"Middle Slot");
	/* Create Right Slot Item Panel Instance */
	this->m_slotItemPanel_right = new SlotItemPanel(this->m_parent,L"Right Slot");

	/* Add 3 Slot Item Panel into Horizontal Box Sizer */
	this->m_hbox_1->Add(this->m_slotItemPanel_left,1);
	this->m_hbox_1->Add(this->m_slotItemPanel_middle,1);
	this->m_hbox_1->Add(this->m_slotItemPanel_right,1);

	/* Append Horizontal Box 1 To Main Top Box Sizer */
	this->m_mainTopSizer->Add(this->m_hbox_1,   1, wxEXPAND | (wxALL & ~wxLEFT), 1);

	/* Setup Main Top Box Sizer To Parent Panel */
	this->m_parent->SetSizer(this->m_mainTopSizer,true);

	//wxImage::AddHandler( new wxPNGHandler );

    /* Create Menu Bar Instance */
    m_menubar = new wxMenuBar();
    /* Create File Menu */
    m_file = new wxMenu();
    /* Setup File Menu */
	m_file->Append(CID_SAVE_MENU, L"Save");
	m_file->Append(CID_LOAD_MENU, L"Load");
	m_file->AppendSeparator();

	/* Create Quit Menu Item */
	m_quit = new wxMenuItem(m_file, wxID_EXIT);
	m_file->Append(m_quit);

	/* Append File Menu To Menu Bar */
	m_menubar->Append(m_file,L"File");

	/* Create About Menu */
	m_about = new wxMenu();
	m_about->Append(CID_ABOUT_MENU,L"About");

	/* Append About Menu To Menu Bar */
	m_menubar->Append(m_about,L"Other");

	/* Set Menu Bar */
    SetMenuBar(m_menubar);

    /* Connect OnQuit To wxID_EXIT */
    Connect(wxID_EXIT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainFrame::OnQuit));
    /* Connect OnAbout To CID_ABOUT_MENU */
	Connect(CID_ABOUT_MENU,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MainFrame::OnAbout));

    /* Setup Icon */
	SetIcon(sample_xpm);

	/* Centre Window */
	Centre();

	LOGD("wxWidgets","Initialized");
}

MainFrame::~MainFrame(){

}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event)){
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event){
	wxString buildDate = L"Build Date : ";
	buildDate += __DATE__;
	buildDate += L" ";
	buildDate += __TIME__;

	wxMessageBox( buildDate,
        L"列車機率計算", wxOK | wxICON_INFORMATION, this);
}


