/**
 * @file maiFrame.cpp
 *
 */

#include "mainFrame.h"
#include "icons/sample.xpm"
#include "include/probability/ProDefine.h"

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

	/* Set Slot Item Panel Default Value */
	this->setSlotItemPanelLeftDefautValue();
	this->setSlotItemPanelMiddleDefautValue();
	this->setSlotItemPanelRightDefautValue();
	LOGI("Probability","Set Slot Item Panel Default Value \n");

	/* Centre Window */
	Centre();

	LOGD("wxWidgets","Initialized \n");
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
        L"CrownTrain Probability Compute Tool", wxOK | wxICON_INFORMATION, this);
}

void MainFrame::setSlotItemPanelLeftDefautValue(void){
	wxString item1Value; item1Value << DEFAULT_SLOT_1_CHERRY;
	this->m_slotItemPanel_left->mItem_cherry_tc->SetValue(item1Value);

	wxString item2Value; item2Value << DEFAULT_SLOT_1_ORANGE;
	this->m_slotItemPanel_left->mItem_orange_tc->SetValue(item2Value);

	wxString item3Value; item3Value << DEFAULT_SLOT_1_APPLE;
	this->m_slotItemPanel_left->mItem_apple_tc->SetValue(item3Value);

	wxString item4Value; item4Value << DEFAULT_SLOT_1_COIN;
	this->m_slotItemPanel_left->mItem_coin_tc->SetValue(item4Value);

	wxString item5Value; item5Value << DEFAULT_SLOT_1_BAR;
	this->m_slotItemPanel_left->mItem_bar_tc->SetValue(item5Value);

	wxString item6Value; item6Value << DEFAULT_SLOT_1_DIAMOND;
	this->m_slotItemPanel_left->mItem_diamond_tc->SetValue(item6Value);

	wxString item7Value; item7Value << DEFAULT_SLOT_1_CROWN;
	this->m_slotItemPanel_left->mItem_crown_tc->SetValue(item7Value);

	wxString item8Value; item8Value << DEFAULT_SLOT_1_FREECOIN;
	this->m_slotItemPanel_left->mItem_freecoin_tc->SetValue(item8Value);

	wxString item9Value; item9Value << DEFAULT_SLOT_1_ROULETTE;
	this->m_slotItemPanel_left->mItem_roulette_tc->SetValue(item9Value);
}

void MainFrame::setSlotItemPanelMiddleDefautValue(void){
	wxString item1Value; item1Value << DEFAULT_SLOT_2_CHERRY;
	this->m_slotItemPanel_middle->mItem_cherry_tc->SetValue(item1Value);

	wxString item2Value; item2Value << DEFAULT_SLOT_2_ORANGE;
	this->m_slotItemPanel_middle->mItem_orange_tc->SetValue(item2Value);

	wxString item3Value; item3Value << DEFAULT_SLOT_2_APPLE;
	this->m_slotItemPanel_middle->mItem_apple_tc->SetValue(item3Value);

	wxString item4Value; item4Value << DEFAULT_SLOT_2_COIN;
	this->m_slotItemPanel_middle->mItem_coin_tc->SetValue(item4Value);

	wxString item5Value; item5Value << DEFAULT_SLOT_2_BAR;
	this->m_slotItemPanel_middle->mItem_bar_tc->SetValue(item5Value);

	wxString item6Value; item6Value << DEFAULT_SLOT_2_DIAMOND;
	this->m_slotItemPanel_middle->mItem_diamond_tc->SetValue(item6Value);

	wxString item7Value; item7Value << DEFAULT_SLOT_2_CROWN;
	this->m_slotItemPanel_middle->mItem_crown_tc->SetValue(item7Value);

	wxString item8Value; item8Value << DEFAULT_SLOT_2_FREECOIN;
	this->m_slotItemPanel_middle->mItem_freecoin_tc->SetValue(item8Value);

	wxString item9Value; item9Value << DEFAULT_SLOT_2_ROULETTE;
	this->m_slotItemPanel_middle->mItem_roulette_tc->SetValue(item9Value);
}

void MainFrame::setSlotItemPanelRightDefautValue(void){
	wxString item1Value; item1Value << DEFAULT_SLOT_3_CHERRY;
	this->m_slotItemPanel_right->mItem_cherry_tc->SetValue(item1Value);

	wxString item2Value; item2Value << DEFAULT_SLOT_3_ORANGE;
	this->m_slotItemPanel_right->mItem_orange_tc->SetValue(item2Value);

	wxString item3Value; item3Value << DEFAULT_SLOT_3_APPLE;
	this->m_slotItemPanel_right->mItem_apple_tc->SetValue(item3Value);

	wxString item4Value; item4Value << DEFAULT_SLOT_3_COIN;
	this->m_slotItemPanel_right->mItem_coin_tc->SetValue(item4Value);

	wxString item5Value; item5Value << DEFAULT_SLOT_3_BAR;
	this->m_slotItemPanel_right->mItem_bar_tc->SetValue(item5Value);

	wxString item6Value; item6Value << DEFAULT_SLOT_3_DIAMOND;
	this->m_slotItemPanel_right->mItem_diamond_tc->SetValue(item6Value);

	wxString item7Value; item7Value << DEFAULT_SLOT_3_CROWN;
	this->m_slotItemPanel_right->mItem_crown_tc->SetValue(item7Value);

	wxString item8Value; item8Value << DEFAULT_SLOT_3_FREECOIN;
	this->m_slotItemPanel_right->mItem_freecoin_tc->SetValue(item8Value);

	wxString item9Value; item9Value << DEFAULT_SLOT_3_ROULETTE;
	this->m_slotItemPanel_right->mItem_roulette_tc->SetValue(item9Value);
}


