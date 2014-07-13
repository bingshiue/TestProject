/**
 * @file maiFrame.cpp
 *
 */

#include "../include/components/mainFrame.h"
#include "../include/probability/ProDefine.h"
#include "../include/probability/ProDefaultKeyInOut.h"
#include "../include/probability/ProSubFunc.h"
#include "../icons/sample.xpm"

MainFrame::MainFrame(const wxString& title) :
		wxFrame((wxFrame*) NULL, wxID_ANY, title, wxDefaultPosition,
				wxSize(1280, 720)) {
	/* Open Log File */
	OpenLogFile();

	/* Initialize Mersenne Twister Algorithm */
	srand(time(NULL));
	int seed = rand() % 10000;
	m_mtRandom.resetMT(seed); // use 19650218UL as seed for verify Mersenne Twister Algorithm
	LOGD("Mersenne Twister", "Initialized Seed=%d \n", seed);

	/* Set Slot Stop Functions */
	this->m_slotStopSubFunc[0] = GetSlotLeftStopItem;
	this->m_slotStopSubFunc[1] = GetSlotMiddleStopItem;
	this->m_slotStopSubFunc[2] = GetSlotRightStopItem;

	/* Initialize Logic Control Flags */
	m_needToReset = false;
	m_runOneTest = false;

	/* Create wxNotebook Instance */
	this->m_noteBook = new wxNotebook(this, wxID_ANY);

	/* Create Panel Instance */
	this->m_parent = new wxPanel(this->m_noteBook, wxID_ANY);

	/* Add Panels to Notebook */
	this->m_noteBook->AddPage(this->m_parent, L"CrownTrain", true);

	/* Create Main Top Box Sizer */
	this->m_mainTopSizer = new wxBoxSizer(wxVERTICAL);

	/* Create Vertical Box Sizer 1 */
	this->m_vbox_1 = new wxBoxSizer(wxVERTICAL);

	/* Create Horizontal Box Sizer 1 */
	this->m_hbox_1 = new wxBoxSizer(wxHORIZONTAL);

	/* Create Horizontal Box Sizer 2 */
	this->m_hbox_2 = new wxBoxSizer(wxHORIZONTAL);

	/* Create Horizontal Box Sizer 3 */
	this->m_hbox_3 = new wxBoxSizer(wxHORIZONTAL);

	/* Create Horizontal Box Sizer 4 */
	this->m_hbox_4 = new wxBoxSizer(wxHORIZONTAL);

	/* Create Horizontal Box Sizer 5 */
	this->m_hbox_5 = new wxBoxSizer(wxHORIZONTAL);

	/* Create Static Box Instance */
	this->m_sb = new wxStaticBox(this->m_parent, wxID_ANY, L"Run",
			wxDefaultPosition, wxDefaultSize);
	/* Create Static Box Sizer Instance */
	this->m_sz = new wxStaticBoxSizer(this->m_sb, wxVERTICAL);

	/* Create Left Slot Item Panel Instance */
	this->m_slotItemPanel_left = new SlotItemPanel(this->m_parent,
			L"Left Slot");
	/* Create Middle Slot Item Panel Instance */
	this->m_slotItemPanel_middle = new SlotItemPanel(this->m_parent,
			L"Middle Slot");
	/* Create Right Slot Item Panel Instance */
	this->m_slotItemPanel_right = new SlotItemPanel(this->m_parent,
			L"Right Slot");

	/* Create Match Item Panel Instance */
	this->m_matchItemPanel = new MatchItemPanel(this->m_parent,
			L"Match Award Item");

	/* Create Key In/Out Panel */
	this->m_keyInOutPanel = new KeyInOutPanel(this->m_parent, L"Key In/Out");

	/* Create Option Panel */
	this->m_optionPanel = new OptionPanel(this->m_parent, L"Options");

	/* Create Result Panel */
	this->m_resultPanel = new ResultPanel(this->m_parent, L"Result");

	/* Create Start Button Instance */
	this->m_startButton = new wxButton(this->m_parent, CID_START_BUTTON,
			L"Start");
	/* Create Reset Button Instance */
	this->m_resetButton = new wxButton(this->m_parent, CID_RESET_BUTTON,
			L"Reset");

	/* Add 3 Slot Item Panel into Horizontal Box Sizer 1 */
	this->m_hbox_1->Add(this->m_slotItemPanel_left, 1);
	this->m_hbox_1->Add(this->m_slotItemPanel_middle, 1);
	this->m_hbox_1->Add(this->m_slotItemPanel_right, 1);

	/* Add Match Item Panel into Horizontal Box Sizer 2 */
	this->m_hbox_2->Add(this->m_matchItemPanel, 1);

	/* Add Key In/Out Panel into Horizontal Box Sizer 3 */
	this->m_hbox_3->Add(this->m_keyInOutPanel, 1);

	/* Add Option Panel into Horizontal Box Sizer 4 */
	this->m_hbox_4->Add(this->m_optionPanel, 1);

	/* Add Result Panel into Horizontal Box Sizer 5 */
	this->m_hbox_5->Add(this->m_resultPanel, 1);

	/* Add Reset Button into Static Box Sizer */
	this->m_sz->Add(this->m_resetButton, 1, wxEXPAND | wxALL, 1);
	/* Add Start Button into Static Box Sizer */
	this->m_sz->Add(this->m_startButton, 9, wxEXPAND | wxALL, 1);

	/* Add Static Box Sizer into Horizontal Box Sizer 5 */
	this->m_hbox_5->Add(this->m_sz, 1);

	/* Append Horizontal Box 1 To Vertical Box Sizer 1 */
	this->m_vbox_1->Add(this->m_hbox_1, 0, wxEXPAND | (wxALL & ~wxLEFT), 1);

	/* Append Horizontal Box 2 To Vertical Box Sizer 1 */
	this->m_vbox_1->Add(this->m_hbox_2, 0, wxEXPAND | (wxALL & ~wxLEFT), 1);

	/* Append Horizontal Box 3 To Vertical Box Sizer 1 */
	this->m_vbox_1->Add(this->m_hbox_3, 0, wxEXPAND | (wxALL & ~wxLEFT), 1);

	/* Append Horizontal Box 4 To Vertical Box Sizer 1 */
	this->m_vbox_1->Add(this->m_hbox_4, 0, wxEXPAND | (wxALL & ~wxLEFT), 1);

	/* Append Horizontal Box 5 To Vertical Box Sizer 1 */
	this->m_vbox_1->Add(this->m_hbox_5, 0, wxEXPAND | (wxALL & ~wxLEFT), 1);

	/* Append Vertical Box 1 To Main Top Box Sizer */
	this->m_mainTopSizer->Add(this->m_vbox_1, 1, wxEXPAND | (wxALL & ~wxLEFT),
			1);

	/* Setup Main Top Box Sizer To Parent Panel */
	this->m_parent->SetSizer(this->m_mainTopSizer, true);

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
	m_menubar->Append(m_file, L"File");

	/* Create About Menu */
	m_about = new wxMenu();
	m_about->Append(CID_ABOUT_MENU, L"About");

	/* Append About Menu To Menu Bar */
	m_menubar->Append(m_about, L"Other");

	/* Set Menu Bar */
	SetMenuBar(m_menubar);

	/* Connect SaveFile To CID_SAVE_MENU */
	Connect(CID_SAVE_MENU, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::SaveFile));
	/* Connect LoadFile To CID_LOAD_MENU */
	Connect(CID_LOAD_MENU, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::LoadFile));
	/* Connect OnQuit To wxID_EXIT */
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::OnQuit));
	/* Connect OnAbout To CID_ABOUT_MENU */
	Connect(CID_ABOUT_MENU, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(MainFrame::OnAbout));
	/* Connect Start To Start Button */
	Connect(CID_START_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::Start));
	/* Connect Reset To Reset Button */
	Connect(CID_RESET_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::Reset));

	/* Setup Icon */
	SetIcon(sample_xpm);

	/* Set Slot Item Panel Default Value */
	this->setSlotItemPanelLeftDefaultValue();
	this->setSlotItemPanelMiddleDefaultValue();
	this->setSlotItemPanelRightDefaultValue();
	LOGI("Probability", "Set Slot Item Panel Default Value \n");

	/* Set Match Item Panel Default Value */
	this->setMatchItemPanelDefaultValue();
	LOGI("Probability", "Set Match Item Panel Default Value \n");

	/* Set Key In/Out Panel Default Value */
	this->setKeyInOutDefaultValue();
	LOGI("Probability", "Set Key In/Out Panel Default Value \n");

	/* Centre Window */
	Centre();

	LOGD("wxWidgets", "Initialized \n");
}

MainFrame::~MainFrame() {
	/* Close Log File */
	CloseLogFile();
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
	wxString buildDate = VERSION;
	buildDate += L" Build Date : ";
	buildDate += __DATE__;
	buildDate += L" ";
	buildDate += __TIME__;

	wxMessageBox(buildDate, L"CrownTrain Probability Compute Tool",
	wxOK | wxICON_INFORMATION, this);
}

void MainFrame::setSlotItemPanelLeftDefaultValue(void) {
	wxString item1Value;
	item1Value << DEFAULT_SLOT_1_CHERRY;
	this->m_slotItemPanel_left->mItem_cherry_tc->SetValue(item1Value);

	wxString item3Value;
	item3Value << DEFAULT_SLOT_1_APPLE;
	this->m_slotItemPanel_left->mItem_apple_tc->SetValue(item3Value);

	wxString item2Value;
	item2Value << DEFAULT_SLOT_1_ORANGE;
	this->m_slotItemPanel_left->mItem_orange_tc->SetValue(item2Value);

	wxString item4Value;
	item4Value << DEFAULT_SLOT_1_COIN;
	this->m_slotItemPanel_left->mItem_coin_tc->SetValue(item4Value);

	wxString item5Value;
	item5Value << DEFAULT_SLOT_1_BAR;
	this->m_slotItemPanel_left->mItem_bar_tc->SetValue(item5Value);

	wxString item6Value;
	item6Value << DEFAULT_SLOT_1_DIAMOND;
	this->m_slotItemPanel_left->mItem_diamond_tc->SetValue(item6Value);

	wxString item7Value;
	item7Value << DEFAULT_SLOT_1_CROWN;
	this->m_slotItemPanel_left->mItem_crown_tc->SetValue(item7Value);

	wxString item8Value;
	item8Value << DEFAULT_SLOT_1_FREECOIN;
	this->m_slotItemPanel_left->mItem_freecoin_tc->SetValue(item8Value);

	wxString item9Value;
	item9Value << DEFAULT_SLOT_1_ROULETTE;
	this->m_slotItemPanel_left->mItem_roulette_tc->SetValue(item9Value);
}

void MainFrame::setSlotItemPanelMiddleDefaultValue(void) {
	wxString item1Value;
	item1Value << DEFAULT_SLOT_2_CHERRY;
	this->m_slotItemPanel_middle->mItem_cherry_tc->SetValue(item1Value);

	wxString item3Value;
	item3Value << DEFAULT_SLOT_2_APPLE;
	this->m_slotItemPanel_middle->mItem_apple_tc->SetValue(item3Value);

	wxString item2Value;
	item2Value << DEFAULT_SLOT_2_ORANGE;
	this->m_slotItemPanel_middle->mItem_orange_tc->SetValue(item2Value);

	wxString item4Value;
	item4Value << DEFAULT_SLOT_2_COIN;
	this->m_slotItemPanel_middle->mItem_coin_tc->SetValue(item4Value);

	wxString item5Value;
	item5Value << DEFAULT_SLOT_2_BAR;
	this->m_slotItemPanel_middle->mItem_bar_tc->SetValue(item5Value);

	wxString item6Value;
	item6Value << DEFAULT_SLOT_2_DIAMOND;
	this->m_slotItemPanel_middle->mItem_diamond_tc->SetValue(item6Value);

	wxString item7Value;
	item7Value << DEFAULT_SLOT_2_CROWN;
	this->m_slotItemPanel_middle->mItem_crown_tc->SetValue(item7Value);

	wxString item8Value;
	item8Value << DEFAULT_SLOT_2_FREECOIN;
	this->m_slotItemPanel_middle->mItem_freecoin_tc->SetValue(item8Value);

	wxString item9Value;
	item9Value << DEFAULT_SLOT_2_ROULETTE;
	this->m_slotItemPanel_middle->mItem_roulette_tc->SetValue(item9Value);
}

void MainFrame::setSlotItemPanelRightDefaultValue(void) {
	wxString item1Value;
	item1Value << DEFAULT_SLOT_3_CHERRY;
	this->m_slotItemPanel_right->mItem_cherry_tc->SetValue(item1Value);

	wxString item3Value;
	item3Value << DEFAULT_SLOT_3_APPLE;
	this->m_slotItemPanel_right->mItem_apple_tc->SetValue(item3Value);

	wxString item2Value;
	item2Value << DEFAULT_SLOT_3_ORANGE;
	this->m_slotItemPanel_right->mItem_orange_tc->SetValue(item2Value);

	wxString item4Value;
	item4Value << DEFAULT_SLOT_3_COIN;
	this->m_slotItemPanel_right->mItem_coin_tc->SetValue(item4Value);

	wxString item5Value;
	item5Value << DEFAULT_SLOT_3_BAR;
	this->m_slotItemPanel_right->mItem_bar_tc->SetValue(item5Value);

	wxString item6Value;
	item6Value << DEFAULT_SLOT_3_DIAMOND;
	this->m_slotItemPanel_right->mItem_diamond_tc->SetValue(item6Value);

	wxString item7Value;
	item7Value << DEFAULT_SLOT_3_CROWN;
	this->m_slotItemPanel_right->mItem_crown_tc->SetValue(item7Value);

	wxString item8Value;
	item8Value << DEFAULT_SLOT_3_FREECOIN;
	this->m_slotItemPanel_right->mItem_freecoin_tc->SetValue(item8Value);

	wxString item9Value;
	item9Value << DEFAULT_SLOT_3_ROULETTE;
	this->m_slotItemPanel_right->mItem_roulette_tc->SetValue(item9Value);
}

void MainFrame::setMatchItemPanelDefaultValue(void) {
	wxString item1Value;
	item1Value << DEFAULT_MATCH_CHERRY;
	this->m_matchItemPanel->mItem_cherry_tc->SetValue(item1Value);

	wxString item3Value;
	item3Value << DEFAULT_MATCH_APPLE;
	this->m_matchItemPanel->mItem_apple_tc->SetValue(item3Value);

	wxString item2Value;
	item2Value << DEFAULT_MATCH_ORANGE;
	this->m_matchItemPanel->mItem_orange_tc->SetValue(item2Value);

	wxString item4Value;
	item4Value << DEFAULT_MATCH_COIN;
	this->m_matchItemPanel->mItem_coin_tc->SetValue(item4Value);

	wxString item5Value;
	item5Value << DEFAULT_MATCH_BAR;
	this->m_matchItemPanel->mItem_bar_tc->SetValue(item5Value);

	wxString item6Value;
	item6Value << DEFAULT_MATCH_DIAMOND;
	this->m_matchItemPanel->mItem_diamond_tc->SetValue(item6Value);

	wxString item7Value;
	item7Value << DEFAULT_MATCH_CROWN;
	this->m_matchItemPanel->mItem_crown_tc->SetValue(item7Value);

	wxString item8Value;
	item8Value << DEFAULT_MATCH_MULTIPLE;
	this->m_matchItemPanel->mItem_multiple_tc->SetValue(item8Value);

	wxString item9Value;
	item9Value << DEFAULT_MATCH_TRAIN;
	this->m_matchItemPanel->mItem_train_tc->SetValue(item9Value);
}

void MainFrame::setKeyInOutDefaultValue(void) {
	//Step 1
	wxString set_1_start;
	set_1_start << DefaultKeyInOut[0][0];
	this->m_keyInOutPanel->m_keyIn_tc_1->SetValue(set_1_start);
	wxString set_1_end;
	set_1_end << DefaultKeyInOut[0][1];
	this->m_keyInOutPanel->m_keyOut_tc_1->SetValue(set_1_end);
	wxString set_1_percent;
	set_1_percent << DefaultKeyInOut[0][2];
	this->m_keyInOutPanel->m_percent_tc_1->SetValue(set_1_percent);

	//Step 2
	wxString set_2_start;
	set_2_start << DefaultKeyInOut[1][0];
	this->m_keyInOutPanel->m_keyIn_tc_2->SetValue(set_2_start);
	wxString set_2_end;
	set_2_end << DefaultKeyInOut[1][1];
	this->m_keyInOutPanel->m_keyOut_tc_2->SetValue(set_2_end);
	wxString set_2_percent;
	set_2_percent << DefaultKeyInOut[1][2];
	this->m_keyInOutPanel->m_percent_tc_2->SetValue(set_2_percent);

	//Step 3
	wxString set_3_start;
	set_3_start << DefaultKeyInOut[2][0];
	this->m_keyInOutPanel->m_keyIn_tc_3->SetValue(set_3_start);
	wxString set_3_end;
	set_3_end << DefaultKeyInOut[2][1];
	this->m_keyInOutPanel->m_keyOut_tc_3->SetValue(set_3_end);
	wxString set_3_percent;
	set_3_percent << DefaultKeyInOut[2][2];
	this->m_keyInOutPanel->m_percent_tc_3->SetValue(set_3_percent);

	//Step 4
	wxString set_4_start;
	set_4_start << DefaultKeyInOut[3][0];
	this->m_keyInOutPanel->m_keyIn_tc_4->SetValue(set_4_start);
	wxString set_4_end;
	set_4_end << DefaultKeyInOut[3][1];
	this->m_keyInOutPanel->m_keyOut_tc_4->SetValue(set_4_end);
	wxString set_4_percent;
	set_4_percent << DefaultKeyInOut[3][2];
	this->m_keyInOutPanel->m_percent_tc_4->SetValue(set_4_percent);

	//Step 5
	wxString set_5_start;
	set_5_start << DefaultKeyInOut[4][0];
	this->m_keyInOutPanel->m_keyIn_tc_5->SetValue(set_5_start);
	wxString set_5_end;
	set_5_end << DefaultKeyInOut[4][1];
	this->m_keyInOutPanel->m_keyOut_tc_5->SetValue(set_5_end);
	wxString set_5_percent;
	set_5_percent << DefaultKeyInOut[4][2];
	this->m_keyInOutPanel->m_percent_tc_5->SetValue(set_5_percent);

	//Step 6
	wxString set_6_start;
	set_6_start << DefaultKeyInOut[5][0];
	this->m_keyInOutPanel->m_keyIn_tc_6->SetValue(set_6_start);
	wxString set_6_end;
	set_6_end << DefaultKeyInOut[5][1];
	this->m_keyInOutPanel->m_keyOut_tc_6->SetValue(set_6_end);
	wxString set_6_percent;
	set_6_percent << DefaultKeyInOut[5][2];
	this->m_keyInOutPanel->m_percent_tc_6->SetValue(set_6_percent);

	//Step 7
	wxString set_7_start;
	set_7_start << DefaultKeyInOut[6][0];
	this->m_keyInOutPanel->m_keyIn_tc_7->SetValue(set_7_start);
	wxString set_7_end;
	set_7_end << DefaultKeyInOut[6][1];
	this->m_keyInOutPanel->m_keyOut_tc_7->SetValue(set_7_end);
	wxString set_7_percent;
	set_7_percent << DefaultKeyInOut[6][2];
	this->m_keyInOutPanel->m_percent_tc_7->SetValue(set_7_percent);

	//Step 8
	wxString set_8_start;
	set_8_start << DefaultKeyInOut[7][0];
	this->m_keyInOutPanel->m_keyIn_tc_8->SetValue(set_8_start);
	wxString set_8_end;
	set_8_end << DefaultKeyInOut[7][1];
	this->m_keyInOutPanel->m_keyOut_tc_8->SetValue(set_8_end);
	wxString set_8_percent;
	set_8_percent << DefaultKeyInOut[7][2];
	this->m_keyInOutPanel->m_percent_tc_8->SetValue(set_8_percent);

	//Step 9
	wxString set_9_start;
	set_9_start << DefaultKeyInOut[8][0];
	this->m_keyInOutPanel->m_keyIn_tc_9->SetValue(set_9_start);
	wxString set_9_end;
	set_9_end << DefaultKeyInOut[8][1];
	this->m_keyInOutPanel->m_keyOut_tc_9->SetValue(set_9_end);
	wxString set_9_percent;
	set_9_percent << DefaultKeyInOut[8][2];
	this->m_keyInOutPanel->m_percent_tc_9->SetValue(set_9_percent);

	//Step 10
	wxString set_10_start;
	set_10_start << DefaultKeyInOut[9][0];
	this->m_keyInOutPanel->m_keyIn_tc_10->SetValue(set_10_start);
	wxString set_10_end;
	set_10_end << DefaultKeyInOut[9][1];
	this->m_keyInOutPanel->m_keyOut_tc_10->SetValue(set_10_end);
	wxString set_10_percent;
	set_10_percent << DefaultKeyInOut[9][2];
	this->m_keyInOutPanel->m_percent_tc_10->SetValue(set_10_percent);
}

void MainFrame::SetSlot1ProStep(void) {
	//step 1
	m_slot1Step.step1 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue());
	//step 2
	m_slot1Step.step2 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue());
	//step 3
	m_slot1Step.step3 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue());
	//step 4
	m_slot1Step.step4 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue());
	//step 5
	m_slot1Step.step5 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_bar_tc->GetValue());
	//step 6
	m_slot1Step.step6 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_diamond_tc->GetValue());
	//step 7
	m_slot1Step.step7 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_crown_tc->GetValue());
	//step 8
	m_slot1Step.step8 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_crown_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_freecoin_tc->GetValue());
	//step 9
	m_slot1Step.step9 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_crown_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_freecoin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_roulette_tc->GetValue());

	LOGD("Probability",
			"Set Slot 1 Probability Step => %d,%d,%d,%d,%d,%d,%d,%d,%d \n",
			m_slot1Step.step1, m_slot1Step.step2, m_slot1Step.step3,
			m_slot1Step.step4, m_slot1Step.step5, m_slot1Step.step6,
			m_slot1Step.step7, m_slot1Step.step8, m_slot1Step.step9);
}

void MainFrame::SetSlot2ProStep(void) {
	//step 1
	m_slot2Step.step1 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue());
	//step 2
	m_slot2Step.step2 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue());
	//step 3
	m_slot2Step.step3 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue());

	//step 4
	m_slot2Step.step4 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_coin_tc->GetValue());
	//step 5
	m_slot2Step.step5 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_bar_tc->GetValue());
	//step 6
	m_slot2Step.step6 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_bar_tc->GetValue())
			+ wxAtoi(
					this->m_slotItemPanel_middle->mItem_diamond_tc->GetValue());
	//step 7
	m_slot2Step.step7 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_crown_tc->GetValue());
	//step 8
	m_slot2Step.step8 =
			wxAtoi(this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_coin_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_bar_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_diamond_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_crown_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_freecoin_tc->GetValue());
	//step 9
	m_slot2Step.step9 =
			wxAtoi(this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_coin_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_bar_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_diamond_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_crown_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_freecoin_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_roulette_tc->GetValue());

	LOGD("Probability",
			"Set Slot 2 Probability Step => %d,%d,%d,%d,%d,%d,%d,%d,%d \n",
			m_slot2Step.step1, m_slot2Step.step2, m_slot2Step.step3,
			m_slot2Step.step4, m_slot2Step.step5, m_slot2Step.step6,
			m_slot2Step.step7, m_slot2Step.step8, m_slot2Step.step9);
}

void MainFrame::SetSlot3ProStep(void) {
	//step 1
	m_slot3Step.step1 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue());
	//step 2
	m_slot3Step.step2 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue());
	//step 3
	m_slot3Step.step3 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue());
	//step 4
	m_slot3Step.step4 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue());
	//step 5
	m_slot3Step.step5 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue());
	//step 6
	m_slot3Step.step6 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_diamond_tc->GetValue());
	//step 7
	m_slot3Step.step7 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_crown_tc->GetValue());
	//step 8
	m_slot3Step.step8 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_crown_tc->GetValue())
			+ wxAtoi(
					this->m_slotItemPanel_right->mItem_freecoin_tc->GetValue());
	//step 9
	m_slot3Step.step9 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_crown_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_freecoin_tc->GetValue())
			+ wxAtoi(
					this->m_slotItemPanel_right->mItem_roulette_tc->GetValue());

	LOGD("Probability",
			"Set Slot 3 Probability Step => %d,%d,%d,%d,%d,%d,%d,%d,%d \n",
			m_slot3Step.step1, m_slot3Step.step2, m_slot3Step.step3,
			m_slot3Step.step4, m_slot3Step.step5, m_slot3Step.step6,
			m_slot3Step.step7, m_slot3Step.step8, m_slot3Step.step9);
}

void MainFrame::SetMatchProStep(void) {
	//step 1
	m_matchStep.step1 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue());
	//step 2
	m_matchStep.step2 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue());
	//step 3
	m_matchStep.step3 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue());
	//step 4
	m_matchStep.step4 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue());
	//step 5
	m_matchStep.step5 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_bar_tc->GetValue());
	//step 6
	m_matchStep.step6 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_diamond_tc->GetValue());
	//step 7
	m_matchStep.step7 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_crown_tc->GetValue());
	//step 8
	m_matchStep.step8 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_crown_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_multiple_tc->GetValue());
	//step 9
	m_matchStep.step9 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_crown_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_multiple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_train_tc->GetValue());

	LOGD("Probability",
			"Set Match Probability Step => %d,%d,%d,%d,%d,%d,%d,%d,%d \n",
			m_matchStep.step1, m_matchStep.step2, m_matchStep.step3,
			m_matchStep.step4, m_matchStep.step5, m_matchStep.step6,
			m_matchStep.step7, m_matchStep.step8, m_matchStep.step9);
}

void MainFrame::ResetResultPanel(void) {
	this->m_resultPanel->m_totalKeyIn_tc->SetValue("0");
	this->m_resultPanel->m_totalKeyOut_tc->SetValue("0");
	this->m_resultPanel->m_keyInOutPercent_tc->SetValue("0");

	this->m_resultPanel->m_totalPlayScore_tc->SetValue("0");
	this->m_resultPanel->m_totalWinScore_tc->SetValue("0");
	this->m_resultPanel->m_PlayWinScorePercent_tc->SetValue("0");

	this->m_resultPanel->m_totalPlayTimes_tc->SetValue("0");
	this->m_resultPanel->m_totalWinTimes_tc->SetValue("0");
	this->m_resultPanel->m_PlayWinTimesPercent_tc->SetValue("0");

	this->m_resultPanel->m_doubleTotalPlayScore_tc->SetValue("0");
	this->m_resultPanel->m_doubleTotalWinScore_tc->SetValue("0");
	this->m_resultPanel->m_doublePlayWinScorePercent_tc->SetValue("0");

	this->m_resultPanel->m_doubleTotalPlayTimes_tc->SetValue("0");
	this->m_resultPanel->m_doubleTotalWinTimes_tc->SetValue("0");
	this->m_resultPanel->m_doublePlayWinTimesPercent_tc->SetValue("0");

	this->m_resultPanel->m_mainGameOverMaxWinTimes_tc->SetValue("0");
	this->m_resultPanel->m_doubleGameOverMaxWinTimes_tc->SetValue("0");
	this->m_resultPanel->m_doubleGameMaxConsecutivePassTimes_tc->SetValue("0");
}

void MainFrame::UpdateResultPanel(void) {
	//Total Key In coins & Key Out coins
	wxString total_keyin_coins;
	total_keyin_coins << this->m_gameFrame.m_gameRecord.m_totalKeyInCoin;
	this->m_resultPanel->m_totalKeyIn_tc->SetValue(total_keyin_coins);

	wxString total_keyout_coins;
	total_keyout_coins << this->m_gameFrame.m_gameRecord.m_totalKeyOutCoin;
	this->m_resultPanel->m_totalKeyOut_tc->SetValue(total_keyout_coins);

	wxString keyinKeyOutPercent;
	keyinKeyOutPercent
			<< 100 * (float) this->m_gameFrame.m_gameRecord.m_totalKeyOutCoin
					/ (float) this->m_gameFrame.m_gameRecord.m_totalKeyInCoin;
	keyinKeyOutPercent += " %";
	this->m_resultPanel->m_keyInOutPercent_tc->SetValue(keyinKeyOutPercent);

	//Total main play scores & Total main win scores
	wxString total_play_scores;
	total_play_scores << this->m_gameFrame.m_gameRecord.m_totalMainPlayScores;
	this->m_resultPanel->m_totalPlayScore_tc->SetValue(total_play_scores);

	wxString total_win_scores;
	total_win_scores << this->m_gameFrame.m_gameRecord.m_totalMainWinScores;
	this->m_resultPanel->m_totalWinScore_tc->SetValue(total_win_scores);

	wxString playWinScoresPercent;
	playWinScoresPercent
			<< 100 * (float) this->m_gameFrame.m_gameRecord.m_totalMainWinScores
					/ (float) this->m_gameFrame.m_gameRecord.m_totalMainPlayScores;
	playWinScoresPercent += " %";
	this->m_resultPanel->m_PlayWinScorePercent_tc->SetValue(
			playWinScoresPercent);

	//Total main played times & Total main win times
	wxString total_play_times;
	total_play_times << this->m_gameFrame.m_gameRecord.m_totalMainPlayTimes;
	this->m_resultPanel->m_totalPlayTimes_tc->SetValue(total_play_times);

	wxString total_win_times;
	total_win_times << this->m_gameFrame.m_gameRecord.m_totalMainWinTimes;
	this->m_resultPanel->m_totalWinTimes_tc->SetValue(total_win_times);

	wxString playedHitPercent;
	playedHitPercent
			<< 100 * (float) this->m_gameFrame.m_gameRecord.m_totalMainWinTimes
					/ this->m_gameFrame.m_gameRecord.m_totalMainPlayTimes;
	playedHitPercent += " %";
	this->m_resultPanel->m_PlayWinTimesPercent_tc->SetValue(playedHitPercent);

	//Double total played scores & total win scores
	wxString total_dplay_scores;
	total_dplay_scores
			<< this->m_gameFrame.m_gameRecord.m_totalDoublePlayScores;
	this->m_resultPanel->m_doubleTotalPlayScore_tc->SetValue(
			total_dplay_scores);

	wxString total_dwin_scores;
	total_dwin_scores << this->m_gameFrame.m_gameRecord.m_totalDoubleWinScores;
	this->m_resultPanel->m_doubleTotalWinScore_tc->SetValue(total_dwin_scores);

	if (this->m_gameFrame.m_gameRecord.m_totalDoublePlayScores > 0) {
		wxString DplayWinScoresPercent;
		DplayWinScoresPercent
				<< 100
						* (float) this->m_gameFrame.m_gameRecord.m_totalDoubleWinScores
						/ (float) this->m_gameFrame.m_gameRecord.m_totalDoublePlayScores;
		playedHitPercent += " %";
		this->m_resultPanel->m_doublePlayWinScorePercent_tc->SetValue(
				DplayWinScoresPercent);
	} else {
		this->m_resultPanel->m_doublePlayWinScorePercent_tc->SetValue("0");
	}

	//Double total played times & total win times
	wxString total_dplay_times;
	total_dplay_times << this->m_gameFrame.m_gameRecord.m_totalDoublePlayTimes;
	this->m_resultPanel->m_doubleTotalPlayTimes_tc->SetValue(total_dplay_times);

	wxString total_dwin_times;
	total_dwin_times << this->m_gameFrame.m_gameRecord.m_totalDoubleWinTimes;
	this->m_resultPanel->m_doubleTotalWinTimes_tc->SetValue(total_dwin_times);

	if (this->m_gameFrame.m_gameRecord.m_totalDoublePlayTimes > 0) {
		wxString DplayWinTimesPercent;
		DplayWinTimesPercent
				<< 100
						* (float) this->m_gameFrame.m_gameRecord.m_totalDoubleWinTimes
						/ (float) this->m_gameFrame.m_gameRecord.m_totalDoublePlayTimes;
		playWinScoresPercent += " %";
		this->m_resultPanel->m_doublePlayWinTimesPercent_tc->SetValue(
				DplayWinTimesPercent);
	} else {
		this->m_resultPanel->m_doublePlayWinTimesPercent_tc->SetValue("0");
	}

	//Main game over max win times
	wxString mainGameOver;
	mainGameOver << this->m_gameFrame.m_gameRecord.m_totalMainOverMaxWinTimes;
	this->m_resultPanel->m_mainGameOverMaxWinTimes_tc->SetValue(mainGameOver);

	//Double game over max win times
	wxString doubleGameOver;
	doubleGameOver
			<< this->m_gameFrame.m_gameRecord.m_totalDoubleOverMaxWinTimes;
	this->m_resultPanel->m_doubleGameOverMaxWinTimes_tc->SetValue(
			doubleGameOver);

	//Double game max consecutive pass times
	wxString dconsecutive;
	dconsecutive << this->m_gameFrame.m_gameRecord.m_maxDoubleContinousWinTimes;
	this->m_resultPanel->m_doubleGameMaxConsecutivePassTimes_tc->SetValue(
			dconsecutive);
}

void MainFrame::PrintAwardDetail() {
	const char *matchAwardStr[NUM_MTACH_AWARDS] = { "Match Award None",
			"Match Award Cherry", "Match Award Apple", "Match Award Orange",
			"Match Award Coin", "Match Award Bar", "Match Award Diamond",
			"Match Award Crown", "Match Award Multiple", "Match Award Train", };

	const char *slotAwardStr[NUM_STRAIGHT_AWARDS] = { "Slot Award None",
			"Slot Award Cherry", "Slot Award Apple", "Slot Award Orange",
			"Slot Award Coin", "Slot Award Bar", "Slot Award Diamond",
			"Slot Award Crown", "Slot Award Freecoin", "Slot Award Roulette", };

	LOGI("Probability", "----- Match Award Detail -----\n");
	for (unsigned int idx = 0; idx < NUM_MTACH_AWARDS; idx++) {
		LOGI("Probability", "%s : %d \n", matchAwardStr[idx],
				this->m_gameFrame.m_gameRecord.m_matchAwardRec[idx]);
	}
	LOGI("Probability", "------------------------------\n");

	LOGI("Probability", "----- Slot Award Detail -----\n");
	for (unsigned int idx = 0; idx < NUM_STRAIGHT_AWARDS; idx++) {
		LOGI("Probability", "%s : %d \n", slotAwardStr[idx],
				this->m_gameFrame.m_gameRecord.m_slotAwardRec[idx]);
	}
	LOGI("Probability", "------------------------------\n");

	LOGI("Probability", "----- Free Times Detail -----\n");
	LOGI("Probability", "Total Free Times = %d \n", this->m_gameFrame.m_gameRecord.m_totalFreeTimes);
}

void MainFrame::PrintAwardDetail(wxTextOutputStream& store) {
	const char *matchAwardStr[NUM_MTACH_AWARDS] = { "Match Award None",
			"Match Award Cherry", "Match Award Apple", "Match Award Orange",
			"Match Award Coin", "Match Award Bar", "Match Award Diamond",
			"Match Award Crown", "Match Award Multiple", "Match Award Train", };

	const char *slotAwardStr[NUM_STRAIGHT_AWARDS] = { "Slot Award None",
			"Slot Award Cherry", "Slot Award Apple", "Slot Award Orange",
			"Slot Award Coin", "Slot Award Bar", "Slot Award Diamond",
			"Slot Award Crown", "Slot Award Freecoin", "Slot Award Roulette", };

	store << "----- Match Award Detail -----" << endl;
	for (unsigned int idx = 0; idx < NUM_MTACH_AWARDS; idx++) {
		store << matchAwardStr[idx] << ":"
				<< (unsigned int) this->m_gameFrame.m_gameRecord.m_matchAwardRec[idx]
				<< endl;
	}
	store << "------------------------------" << endl;

	store << "----- Slot Award Detail -----" << endl;
	for (unsigned int idx = 0; idx < NUM_STRAIGHT_AWARDS; idx++) {
		store << slotAwardStr[idx] << ":"
				<< (unsigned int) this->m_gameFrame.m_gameRecord.m_slotAwardRec[idx]
				<< endl;
	}
	store << "------------------------------" << endl;

}

void MainFrame::Start(wxCommandEvent& event) {
	bool RunFlag = true;
	unsigned long PreviousKeyIn = 0;

	LOGI("Start Button", "In Start Button Handle \n");

	if (m_needToReset == true) {
		wxMessageDialog *dial = new wxMessageDialog(NULL,
				L"Please Press Reset Button", L"ERROR", wxOK | wxICON_ERROR);
		dial->ShowModal();
		return;
	} else if (m_needToReset == false) {

		// Check Sum of Draw
		bool check_draw_cnt_ok = true;
		if(wxAtoi(this->m_slotItemPanel_left->mTotalValue_tc->GetValue()) != 10000) check_draw_cnt_ok = false;
		if(wxAtoi(this->m_slotItemPanel_middle->mTotalValue_tc->GetValue()) != 10000) check_draw_cnt_ok = false;
		if(wxAtoi(this->m_slotItemPanel_right->mTotalValue_tc->GetValue()) != 10000) check_draw_cnt_ok = false;
		if(wxAtoi(this->m_matchItemPanel->mTotalValue_tc->GetValue()) != 10000) check_draw_cnt_ok = false;

		if(check_draw_cnt_ok==false){
			wxMessageDialog *dial = new wxMessageDialog(NULL,
					L"Sum of Draw Count Error", L"ERROR", wxOK | wxICON_ERROR);
			dial->ShowModal();
			return;
		}

		m_needToReset = true;
	}

	/* Set Probability Steps */
	SetSlot1ProStep();
	SetSlot2ProStep();
	SetSlot3ProStep();
	SetMatchProStep();

	/* Set Options */
	// Set Max Key In
	this->m_settingData.m_maxKeyIn = wxAtoi(
			this->m_optionPanel->m_maxKeyIn_tc->GetValue());
	LOGD("Setting", "Max Key In=%d \n", this->m_settingData.m_maxKeyIn);

	// Set Coin Value
	this->m_settingData.m_coinValue = wxAtoi(
			this->m_optionPanel->m_coinValueCB->GetValue());
	LOGD("Setting", "Coin Value=%d \n", this->m_settingData.m_coinValue);

	// Set Main Over Max Win
	this->m_settingData.m_mainGameOverMaxWin = wxAtoi(
			this->m_optionPanel->m_mainGameMaxWinCB->GetValue());
	LOGD("Setting", "Main Over Max Win=%d \n",
			this->m_settingData.m_mainGameOverMaxWin);

	// Set Double Over Max Win
	this->m_settingData.m_doubleGameOverMaxWin = wxAtoi(
			this->m_optionPanel->m_doubleGameMaxWinCB->GetValue());
	LOGD("Setting", "Double Over Max Win=%d \n",
			this->m_settingData.m_doubleGameOverMaxWin);

	// Set Max Bet
	this->m_settingData.m_maxBet = wxAtoi(
			this->m_optionPanel->m_maxBetCB->GetValue());
	LOGD("Setting", "Max Bet=%d \n", this->m_settingData.m_maxBet);

	// Set Run Double Game
	this->m_settingData.m_runDoubleGame =
			this->m_optionPanel->m_runDoubleGameChkBox->GetValue() == true ?
					1 : 0;

	// Set Run To Dead
	this->m_settingData.m_runToDead =
			this->m_optionPanel->m_runToDeadChkBox->GetValue() == true ? 1 : 0;

	unsigned int progressMaxValue = 100;
	wxProgressDialog* progressDial =
			new wxProgressDialog(L"Computing", L"Please Wait", progressMaxValue,
					NULL,
					wxPD_AUTO_HIDE | wxPD_APP_MODAL | wxPD_ELAPSED_TIME
							| wxPD_CAN_ABORT);
	progressDial->Show();

	while (this->m_gameFrame.m_gameRecord.m_totalKeyInCoin
			< this->m_settingData.m_maxKeyIn && RunFlag == true) {
		// Check Credit/KeyIn
		if (this->m_gameFrame.m_gameCredit.m_credit <= 20 * this->m_settingData.m_coinValue ||
			    this->m_gameFrame.m_gameCredit.m_credit < this->m_settingData.m_maxBet * 4)
		{
			//
			if ((this->m_settingData.m_maxKeyIn
					- this->m_gameFrame.m_gameRecord.m_totalKeyInCoin) >= 100) {
				this->m_gameFrame.m_gameRecord.m_totalKeyInCoin += 100;
				this->m_gameFrame.m_gameCredit.m_credit += 100
						* this->m_settingData.m_coinValue;
			} else {
				this->m_gameFrame.m_gameRecord.m_totalKeyInCoin +=
						(this->m_settingData.m_maxKeyIn
								- this->m_gameFrame.m_gameRecord.m_totalKeyInCoin);
				this->m_gameFrame.m_gameCredit.m_credit +=
						(this->m_settingData.m_maxKeyIn
								- this->m_gameFrame.m_gameRecord.m_totalKeyInCoin)
								* this->m_settingData.m_coinValue;
			}
		}

		// Credit >= this->m_settingData.m_maxBet * 4
		assert(this->m_gameFrame.m_gameCredit.m_credit >= this->m_settingData.m_maxBet * 4);

		// Bet
		if(this->m_gameFrame.m_gameCredit.m_freetimes > 0){
			LOGI("Free Time","Play Free Time = %d, Credit=%d \n",this->m_gameFrame.m_gameCredit.m_freetimes,this->m_gameFrame.m_gameCredit.m_credit);
			this->m_gameFrame.m_gameCredit.m_freetimes--;
			//Record
			this->m_gameFrame.m_gameRecord.m_totalFreeTimes++;
		}else{
			this->m_gameFrame.m_gameCredit.m_credit -= this->m_settingData.m_maxBet * 4;
		}

		this->m_gameFrame.m_gameCredit.m_matchBet =
				this->m_settingData.m_maxBet;
		this->m_gameFrame.m_gameCredit.m_slotBet[0] =
				this->m_settingData.m_maxBet;
		this->m_gameFrame.m_gameCredit.m_slotBet[1] =
				this->m_settingData.m_maxBet;
		this->m_gameFrame.m_gameCredit.m_slotBet[2] =
				this->m_settingData.m_maxBet;

		// Record
		this->m_gameFrame.m_gameRecord.m_totalMainPlayScores +=
				this->m_settingData.m_maxBet * 4;
		this->m_gameFrame.m_gameRecord.m_totalMainPlayTimes++;

		// Get Match Stop Item
		this->m_gameFrame.m_match.item = GetMatchStopItem(&this->m_mtRandom,
				this);
		// Get Slot Stop Item
		for (int idx = 0; idx < 3; idx++) {
			this->m_gameFrame.m_slot[idx].item = m_slotStopSubFunc[idx](
					&this->m_mtRandom, this);
		}

		// Get Win
		this->m_gameFrame.m_matchAwardType = GetMatchAward(&this->m_gameFrame);
		this->m_gameFrame.m_gameCredit.m_win += GetMatchWin(
				this->m_gameFrame.m_matchAwardType,
				this->m_gameFrame.m_gameCredit.m_matchBet);

		this->m_gameFrame.m_slotAwardType = GetSlotStraightAward(
				&this->m_gameFrame);
		this->m_gameFrame.m_gameCredit.m_win += GetSlotStraightWin(
				this->m_gameFrame.m_slotAwardType,
				this->m_gameFrame.m_gameCredit.m_slotBet[0]);

		if (this->m_gameFrame.m_gameCredit.m_win > 0) {
			this->m_gameFrame.m_gameCredit.m_credit +=
					this->m_gameFrame.m_gameCredit.m_win;
			if (this->m_gameFrame.m_gameCredit.m_credit
					/ this->m_settingData.m_coinValue
					> this->m_settingData.m_mainGameOverMaxWin) {
				this->m_gameFrame.m_gameRecord.m_totalMainOverMaxWinTimes++;
			}

			// Record
			this->m_gameFrame.m_gameRecord.m_matchAwardRec[this->m_gameFrame.m_matchAwardType]++;
			this->m_gameFrame.m_gameRecord.m_slotAwardRec[this->m_gameFrame.m_slotAwardType]++;

			this->m_gameFrame.m_gameRecord.m_totalMainWinScores +=
					this->m_gameFrame.m_gameCredit.m_win;
			this->m_gameFrame.m_gameRecord.m_totalMainWinTimes++;

			this->m_gameFrame.m_gameCredit.m_win = 0;
		}

		// Check Key Out
		if (KeyOutCheck(this) == true) {
			LOGD("KeyOut","Credit=%d \n",this->m_gameFrame.m_gameCredit.m_credit);
			while (this->m_gameFrame.m_gameCredit.m_credit
					>= 100 * this->m_settingData.m_coinValue) {
				this->m_gameFrame.m_gameCredit.m_credit -= 100
						* this->m_settingData.m_coinValue;
				this->m_gameFrame.m_gameRecord.m_totalKeyOutCoin += 100;
				LOGD("KeyOut", "Credit=%d,Total Key Out=%d \n",
						this->m_gameFrame.m_gameCredit.m_credit,
						this->m_gameFrame.m_gameRecord.m_totalKeyOutCoin);
			}
		}

		// Check Reach Max Key In
		if ((unsigned int) (this->m_gameFrame.m_gameRecord.m_totalKeyInCoin
				/ (this->m_settingData.m_maxKeyIn / progressMaxValue))
				== progressMaxValue) {
			m_runOneTest = true;
		}

		if (PreviousKeyIn != this->m_gameFrame.m_gameRecord.m_totalKeyInCoin) {
			PreviousKeyIn = this->m_gameFrame.m_gameRecord.m_totalKeyInCoin;
			// Update Result Panel
			this->UpdateResultPanel();
			// Update Progress Dialog
			this->PrintAwardDetail();
			LOGD("progressBar","progress=%d ,%d, %d, %d \n"
					,(int) ((((float)this->m_gameFrame.m_gameRecord.m_totalKeyInCoin)/ (float)(this->m_settingData.m_maxKeyIn)) * 100)
					,this->m_gameFrame.m_gameRecord.m_totalKeyInCoin
					,this->m_settingData.m_maxKeyIn
					,progressMaxValue);
			if (progressDial->Update(
					(int) ((((float)this->m_gameFrame.m_gameRecord.m_totalKeyInCoin)/ (float)(this->m_settingData.m_maxKeyIn)) * 100))
					== false) {
				progressDial->Destroy();
				this->m_gameFrame.m_gameRecord.m_totalKeyOutCoin +=
						this->m_gameFrame.m_gameCredit.m_credit
								/ this->m_settingData.m_coinValue;
				this->m_gameFrame.m_gameCredit.m_credit = 0;
				this->UpdateResultPanel();
				RunFlag = false;
			}

		}

	}

}

void MainFrame::Reset(wxCommandEvent& event) {
	LOGI("Reset Button", "In Reset Button Handle \n");

	this->ResetResultPanel();

	this->m_gameFrame.Clean();
	this->m_gameFrame.m_gameCredit.Clean();
	this->m_gameFrame.m_gameRecord.Clean();
	this->m_gameFrame.m_match.Clean();
	this->m_gameFrame.m_slot[0].Clean();
	this->m_gameFrame.m_slot[1].Clean();
	this->m_gameFrame.m_slot[2].Clean();

	wxMessageDialog *dial = new wxMessageDialog(NULL, L"Reset All Parameters",
			L"Information", wxOK | wxICON_INFORMATION);
	dial->ShowModal();

	if (m_needToReset == true) {
		m_needToReset = false;
	}

	if (m_runOneTest == true) {
		m_runOneTest = false;
	}
}

void MainFrame::SaveFile(wxCommandEvent& event) {
	LOGD("SaveFile", "In SaveFile Function \n");
	if (m_runOneTest == false) {
		wxMessageDialog *dial = new wxMessageDialog(NULL, L"Pleae Run Once",
				L"Error", wxOK | wxICON_ERROR);
		dial->ShowModal();
		return;
	}
	wxFileDialog saveFileDialog(this, L"Save TXT file", "", "result",
			"TXT files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea...

	wxFFileOutputStream output_stream(saveFileDialog.GetPath());
	if (!output_stream.IsOk()) {
		wxLogError
		("Cannot save current contents in file '%s'.",
				saveFileDialog.GetPath());
		return;
	}
	wxTextOutputStream store(output_stream);
	this->SaveFileContent(store);
	store.Flush();
}

void MainFrame::SaveFileContent(wxTextOutputStream& store) {
	//File Header
	store << "CrownTrain Probability Compute Save File" << endl;
	store << endl;

	//Left Slot
	store << wxString(L"Left Slot Setting Value") << endl;
	store << " # ";
	store << this->m_slotItemPanel_left->mItem_cherry_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_left->mItem_apple_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_left->mItem_orange_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_left->mItem_coin_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_left->mItem_bar_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_left->mItem_diamond_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_left->mItem_crown_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_left->mItem_freecoin_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_left->mItem_roulette_tc->GetValue() << endl;
	store << endl;

	//Middle Slot
	store << wxString(L"Middle Slot Setting Value") << endl;
	store << " # ";
	store << this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_middle->mItem_apple_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_middle->mItem_orange_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_middle->mItem_coin_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_middle->mItem_bar_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_middle->mItem_diamond_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_middle->mItem_crown_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_middle->mItem_freecoin_tc->GetValue()
			<< "  ";
	store << this->m_slotItemPanel_middle->mItem_roulette_tc->GetValue()
			<< endl;
	store << endl;

	//Right Slot
	store << wxString(L"Right Slot Setting Value") << endl;
	store << " # ";
	store << this->m_slotItemPanel_right->mItem_cherry_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_right->mItem_apple_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_right->mItem_orange_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_right->mItem_coin_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_right->mItem_bar_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_right->mItem_diamond_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_right->mItem_crown_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_right->mItem_freecoin_tc->GetValue() << "  ";
	store << this->m_slotItemPanel_right->mItem_roulette_tc->GetValue() << endl;
	store << endl;

	//Match Item
	store << wxString(L"Match Item Setting Value") << endl;
	store << " # ";
	store << this->m_matchItemPanel->mItem_cherry_tc->GetValue() << "  ";
	store << this->m_matchItemPanel->mItem_apple_tc->GetValue() << "  ";
	store << this->m_matchItemPanel->mItem_orange_tc->GetValue() << "  ";
	store << this->m_matchItemPanel->mItem_coin_tc->GetValue() << "  ";
	store << this->m_matchItemPanel->mItem_bar_tc->GetValue() << "  ";
	store << this->m_matchItemPanel->mItem_diamond_tc->GetValue() << "  ";
	store << this->m_matchItemPanel->mItem_crown_tc->GetValue() << "  ";
	store << this->m_matchItemPanel->mItem_multiple_tc->GetValue() << "  ";
	store << this->m_matchItemPanel->mItem_train_tc->GetValue() << endl;
	store << endl;

	store << endl;

	store << L"Max KeyIn Coin :" << endl;
	store << " $ " << this->m_settingData.m_maxKeyIn << endl;

	store << L"Coin Value :" << endl;
	store << " $ " << this->m_settingData.m_coinValue << endl;

	store << L"Max Bet :" << endl;
	store << " $ " << this->m_settingData.m_maxBet << endl;

	store << L"Main Over Max Win Coin :" << endl;
	store << " $ " << this->m_settingData.m_mainGameOverMaxWin << endl;

	store << L"Double Over Max Win Coin :" << endl;
	store << " $ " << this->m_settingData.m_doubleGameOverMaxWin << endl;

	store << L"Run Double Game :" << endl;
	store << " $ " << this->m_settingData.m_runDoubleGame << endl;

	store << L"Double Game Run To Dead :" << endl;
	store << " $ " << this->m_settingData.m_runToDead << endl;

	store << endl;
	store << endl;

	//Total KeyIn & KeyOut
	store << L"T-Key In Coins  : "
			<< this->m_resultPanel->m_totalKeyIn_tc->GetValue() << endl;

	store << L"T-Key Out Coins  : "
			<< this->m_resultPanel->m_totalKeyOut_tc->GetValue() << endl;

	store << L"T-KeyIn/Out %  : "
			<< 100 * (float) this->m_gameFrame.m_gameRecord.m_totalKeyOutCoin
					/ (float) this->m_gameFrame.m_gameRecord.m_totalKeyInCoin
			<< " % " << endl;

	//Total Main Play & Win scores
	store << L"T-Play Scores  : "
			<< this->m_resultPanel->m_totalPlayScore_tc->GetValue() << endl;

	store << L"T-Win Scores  : "
			<< this->m_resultPanel->m_totalWinScore_tc->GetValue() << endl;

	store << L"T-Play/Win Scores %  : "
			<< 100 * (float) this->m_gameFrame.m_gameRecord.m_totalMainWinScores
					/ (float) this->m_gameFrame.m_gameRecord.m_totalMainPlayScores
			<< " % " << endl;

	//Total Main Play & Win times
	store << L"T-Play Times  : "
			<< this->m_resultPanel->m_totalPlayTimes_tc->GetValue() << endl;

	store << L"T-Win Times  : "
			<< this->m_resultPanel->m_totalWinTimes_tc->GetValue() << endl;

	store << L"T-Play/Win Times %  : "
			<< 100 * (float) this->m_gameFrame.m_gameRecord.m_totalMainWinTimes
					/ (float) this->m_gameFrame.m_gameRecord.m_totalMainPlayTimes
			<< " % " << endl;

	//Double up game total Play & Win Scores
	store << L"D-Play Scores : "
			<< this->m_resultPanel->m_doubleTotalPlayScore_tc->GetValue()
			<< endl;

	store << L"D-Win Scores : "
			<< this->m_resultPanel->m_doubleTotalWinScore_tc->GetValue()
			<< endl;
	if (this->m_gameFrame.m_gameRecord.m_totalDoublePlayScores != 0) {
		store << L"D-Play/Win Scores % : "
				<< 100
						* (float) this->m_gameFrame.m_gameRecord.m_totalDoubleWinScores
						/ (float) this->m_gameFrame.m_gameRecord.m_totalDoublePlayScores
				<< " % " << endl;
	} else {
		store << L"D-Play/Win Scores % : " << "0" << endl;
	}

	//Double up game total Play & Win Times
	store << L"D-Play Times : "
			<< this->m_resultPanel->m_doubleTotalPlayTimes_tc->GetValue()
			<< endl;

	store << L"D-Win Times : "
			<< this->m_resultPanel->m_doubleTotalWinTimes_tc->GetValue()
			<< endl;
	if (this->m_gameFrame.m_gameRecord.m_totalDoublePlayTimes != 0) {
		store << L"D-Play/Win Times % : "
				<< 100
						* (float) this->m_gameFrame.m_gameRecord.m_totalDoubleWinTimes
						/ (float) this->m_gameFrame.m_gameRecord.m_totalDoublePlayTimes
				<< " % " << endl;
	} else {
		store << L"D-Play/Win Times % : " << "0" << endl;
	}

	//Main game over max win times
	store << L"Main Over Max Win Times : "
			<< (unsigned int) this->m_gameFrame.m_gameRecord.m_totalMainOverMaxWinTimes
			<< endl;
	//Double up game over max win times
	store << L"Double Over Max Win Times : "
			<< (unsigned int) this->m_gameFrame.m_gameRecord.m_totalDoubleOverMaxWinTimes
			<< endl;
	//Double up game max consecutive pass times
	store << L"Double Max Consecutive Pass Times : "
			<< (unsigned int) this->m_gameFrame.m_gameRecord.m_maxDoubleContinousWinTimes
			<< endl;

	store << endl;
	store << endl;

	this->PrintAwardDetail(store);
}

void MainFrame::LoadFile(wxCommandEvent& event) {
	LOGD("LoadFile", "In LoadFile Function \n");
	if (m_runOneTest == true) {
		wxMessageDialog *dial = new wxMessageDialog(NULL,
				L"Please Reset At First", L"Error", wxOK | wxICON_ERROR);
		dial->ShowModal();
		return;
	}

	wxFileDialog loadFileDialog(this, L"Save TXT file", "", "",
			"TXT files (*.txt)|*.txt", wxFD_OPEN);

	if (loadFileDialog.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea...

	this->LoadFileContent(loadFileDialog.GetPath());
}

void MainFrame::LoadFileContent(wxString filePath) {
	wxTextFile tfile;
	tfile.Open(filePath);
	wxString content;
	int times = 0;
	int settingTimes = 0;
	int index = 0;
	int slotItem_percent[3][9];
	int matchItem_percent[9];

	//Reset Array
	for (unsigned int i = 0;
			i < sizeof(slotItem_percent) / sizeof(slotItem_percent[0]); i++) {
		for (unsigned int j = 0;
				j < sizeof(slotItem_percent[0]) / sizeof(slotItem_percent[0][0]);
				j++) {
			slotItem_percent[i][j] = 0;
		}
	}
	for (unsigned int i = 0;
			i < sizeof(matchItem_percent) / sizeof(matchItem_percent[0]); i++) {
		matchItem_percent[i] = 0;
	}

	// Get First Line
	content = tfile.GetFirstLine();
	// Check The File Is Our Save File or Not
	if (!content.Contains(
			wxString("CrownTrain Probability Compute Save File"))) {
		wxMessageDialog *dial = new wxMessageDialog(NULL,
				L"Please Select CrownTrain Save File", L"Error",
				wxOK | wxICON_ERROR);
		dial->ShowModal();
		return;
	} else {
		LOGD("Load File", "Loaded File is Correct CrownTrain Save File \n");
	}

	// Start Load
	content = tfile.GetNextLine();
	while (!tfile.Eof()) {
		if (content.Contains(wxString("#"))) { //Parse Slot/Match Item Setting Value
			LOGD("Parse Save File", "%s \n", (const char* )content.mb_str());
			++times;
			wxStringTokenizer tokenizer(content, " ");
			index = 0;

			switch (times) {

			case 1:     // Left Slot
				while (tokenizer.HasMoreTokens() == true) {
					wxString token = tokenizer.GetNextToken();
					if (token.IsNumber() == true) {
						//printf("Left SLOT Token: %s\n",(const char*)token.mb_str());
						slotItem_percent[0][index] = wxAtoi(token);
						//printf("%d : %d \n",index,item_percent[0][index]);
						index++;
					}
				}
				break;

			case 2:     // Middle Slot
				while (tokenizer.HasMoreTokens() == true) {
					wxString token = tokenizer.GetNextToken();
					if (token.IsNumber() == true) {
						//printf("Middle SLOT Token: %s\n",(const char*)token.mb_str());
						slotItem_percent[1][index] = wxAtoi(token);
						//printf("%d : %d \n",index,slotItem_percent[1][index]);
						index++;
					}
				}
				break;

			case 3:     // Right Slot
				while (tokenizer.HasMoreTokens() == true) {
					wxString token = tokenizer.GetNextToken();
					if (token.IsNumber() == true) {
						//printf("Right SLOT Token: %s\n",(const char*)token.mb_str());
						slotItem_percent[2][index] = wxAtoi(token);
						//printf("%d : %d \n",index,slotItem_percent[2][index]);
						index++;
					}
				}
				break;

			case 4:     // Match Item
				while (tokenizer.HasMoreTokens() == true) {
					wxString token = tokenizer.GetNextToken();
					if (token.IsNumber() == true) {
						//printf("Match Item Token: %s\n",(const char*)token.mb_str());
						matchItem_percent[index] = wxAtoi(token);
						//printf("%d : %d \n",index,matchItem_percent[index]);
						index++;
					}
				}
				break;

			default:
				LOGE("Parse Save File", "Something Error! \n");
				break;
			}
		} else if (content.Contains(wxString("$"))) {
			++settingTimes;
			wxStringTokenizer setting_tokenizer(content, wxString(" "));

			switch (settingTimes) {

			case 1:     // Max Key In Coins Limit
				while (setting_tokenizer.HasMoreTokens()) {
					wxString setting_tmp = setting_tokenizer.GetNextToken();
					if (setting_tmp.IsNumber() == true) {
						//Load Max Key In Coins Limit
						unsigned int saveMaxKeyInCoinsLimit = wxAtoi(
								setting_tmp);
						LOGD("Parse Save File",
								"Saved MaxKeyInCoinsLimit=%d \n",
								saveMaxKeyInCoinsLimit);

						wxString strMaxKeyInCoinsLimit("");
						strMaxKeyInCoinsLimit << saveMaxKeyInCoinsLimit;
						this->m_optionPanel->m_maxKeyIn_tc->SetValue(
								strMaxKeyInCoinsLimit);
						this->m_settingData.m_maxKeyIn = saveMaxKeyInCoinsLimit;

					}
				}
				break;

			case 2:     // Coin Value
				while (setting_tokenizer.HasMoreTokens()) {
					wxString setting_tmp = setting_tokenizer.GetNextToken();
					if (setting_tmp.IsNumber() == true) {
						//Load Save Coin Value
						unsigned int saveCoinValue = wxAtoi(setting_tmp);
						for (unsigned int idx = 0;
								idx
										< sizeof(coinValueTab)
												/ sizeof(coinValueTab[0]);
								idx++) {
							if (coinValueTab[idx] == saveCoinValue) {
								LOGD("Parse Save File", "Saved CoinValue=%d \n",
										saveCoinValue);
								this->m_optionPanel->m_coinValueCB->SetSelection(
										idx);
								this->m_settingData.m_coinValue =
										coinValueTab[idx];
								break;
							}
						}
					}
				}
				break;

			case 3:     // Max Bet
				while (setting_tokenizer.HasMoreTokens()) {
					wxString setting_tmp = setting_tokenizer.GetNextToken();
					if (setting_tmp.IsNumber() == true) {
						//Load Save Max Bet
						unsigned int saveMaxBet = wxAtoi(setting_tmp);
						for (unsigned int idx = 0;
								idx < sizeof(maxBetTab) / sizeof(maxBetTab[0]);
								idx++) {
							if (maxBetTab[idx] == saveMaxBet) {
								LOGD("Parse Save File", "Saved MaxBet=%d \n",
										saveMaxBet);
								this->m_optionPanel->m_maxBetCB->SetSelection(
										idx);
								this->m_settingData.m_maxBet = maxBetTab[idx];
								break;
							}
						}
					}
				}
				break;

			case 4:     // Main Over Max Win Coin
				while (setting_tokenizer.HasMoreTokens()) {
					wxString setting_tmp = setting_tokenizer.GetNextToken();
					if (setting_tmp.IsNumber() == true) {
						//Load Main Over Max Win Coin
						unsigned int saveMainOverMaxWin = wxAtoi(setting_tmp);
						for (unsigned int idx = 0;
								idx
										< sizeof(mainOverMaxWinTab)
												/ sizeof(mainOverMaxWinTab[0]);
								idx++) {
							if (mainOverMaxWinTab[idx] == saveMainOverMaxWin) {
								LOGD("Parse Save File",
										"Saved MainOverMaxWin=%d \n",
										saveMainOverMaxWin);
								this->m_optionPanel->m_mainGameMaxWinCB->SetSelection(
										idx);
								this->m_settingData.m_mainGameOverMaxWin =
										mainOverMaxWinTab[idx];
								break;
							}
						}
					}
				}
				break;

			case 5:     // Double Over Max Win Coin
				while (setting_tokenizer.HasMoreTokens()) {
					wxString setting_tmp = setting_tokenizer.GetNextToken();
					if (setting_tmp.IsNumber() == true) {
						//Load Main Over Max Win Coin
						unsigned int saveDoubleOverMaxWin = wxAtoi(setting_tmp);
						for (unsigned int idx = 0;
								idx
										< sizeof(doubleOverMaxWinTab)
												/ sizeof(doubleOverMaxWinTab[0]);
								idx++) {
							if (doubleOverMaxWinTab[idx]
									== saveDoubleOverMaxWin) {
								LOGD("Parse Save File",
										"Saved DoubleOverMaxWin=%d \n",
										saveDoubleOverMaxWin);
								this->m_optionPanel->m_doubleGameMaxWinCB->SetSelection(
										idx);
								this->m_settingData.m_doubleGameOverMaxWin =
										doubleOverMaxWinTab[idx];
								break;
							}
						}
					}
				}
				break;

			case 6:     // Run Double Game
				while (setting_tokenizer.HasMoreTokens()) {
					wxString setting_tmp = setting_tokenizer.GetNextToken();
					if (setting_tmp.IsNumber() == true) {
						//Load Run Double Game
						unsigned int saveRunDoubleGame = wxAtoi(setting_tmp);
						LOGD("Parse Save File", "Saved RunDoubleGame=%d \n",
								saveRunDoubleGame);
						switch (saveRunDoubleGame) {
						case 1:
							this->m_optionPanel->m_runDoubleGameChkBox->SetValue(
									true);
							this->m_settingData.m_runDoubleGame =
									saveRunDoubleGame;
							break;

						case 0:
							this->m_optionPanel->m_runDoubleGameChkBox->SetValue(
									false);
							this->m_settingData.m_runDoubleGame =
									saveRunDoubleGame;
							break;

						default:
							LOGE("Parse Save File",
									"Load Saved Run Double Game Error! \n");
							break;
						}
					}
				}
				break;

			case 7:     // Double Game Run To Dead
				while (setting_tokenizer.HasMoreTokens()) {
					wxString setting_tmp = setting_tokenizer.GetNextToken();
					if (setting_tmp.IsNumber() == true) {
						//Load Run To Dead
						unsigned int saveRunToDead = wxAtoi(setting_tmp);
						LOGD("Parse Save File", "Saved RunToDead=%d \n",
								saveRunToDead);
						switch (saveRunToDead) {
						case 1:
							this->m_optionPanel->m_runToDeadChkBox->SetValue(
									true);
							this->m_settingData.m_runToDead = saveRunToDead;
							break;

						case 0:
							this->m_optionPanel->m_runToDeadChkBox->SetValue(
									false);
							this->m_settingData.m_runToDead = saveRunToDead;
							break;

						default:
							LOGE("Parse Save File",
									"Load Saved Run To Dead Error! \n");
							break;
						}
					}
				}
				break;

			default:
				break;
			}
		}

		// Get Next Line
		content = tfile.GetNextLine();

		// Done ?
		if (times == 4 && settingTimes == 7)
			break;

		//  Write Saved Slot/Match Item Setting Value To
		if (times == 4) {
			wxString _item;

			// Left Slot
			_item.Clear();
			_item << slotItem_percent[0][0];
			this->m_slotItemPanel_left->mItem_cherry_tc->SetValue(_item);
			LOGD("Parse Save File", "_item=%s \n",
					(const char* )_item.mb_str());
			_item.Clear();
			_item << slotItem_percent[0][1];
			this->m_slotItemPanel_left->mItem_apple_tc->SetValue(_item);
			LOGD("Parse Save File", "_item=%s \n",
					(const char* )_item.mb_str());
			_item.Clear();
			_item << slotItem_percent[0][2];
			this->m_slotItemPanel_left->mItem_orange_tc->SetValue(_item);
			LOGD("Parse Save File", "_item=%s \n",
					(const char* )_item.mb_str());
			_item.Clear();
			_item << slotItem_percent[0][3];
			this->m_slotItemPanel_left->mItem_coin_tc->SetValue(_item);
			LOGD("Parse Save File", "_item=%s \n",
					(const char* )_item.mb_str());
			_item.Clear();
			_item << slotItem_percent[0][4];
			this->m_slotItemPanel_left->mItem_bar_tc->SetValue(_item);
			LOGD("Parse Save File", "_item=%s \n",
					(const char* )_item.mb_str());
			_item.Clear();
			_item << slotItem_percent[0][5];
			this->m_slotItemPanel_left->mItem_diamond_tc->SetValue(_item);
			LOGD("Parse Save File", "_item=%s \n",
					(const char* )_item.mb_str());
			_item.Clear();
			_item << slotItem_percent[0][6];
			this->m_slotItemPanel_left->mItem_crown_tc->SetValue(_item);
			LOGD("Parse Save File", "_item=%s \n",
					(const char* )_item.mb_str());
			_item.Clear();
			_item << slotItem_percent[0][7];
			this->m_slotItemPanel_left->mItem_freecoin_tc->SetValue(_item);
			LOGD("Parse Save File", "_item=%s \n",
					(const char* )_item.mb_str());
			_item.Clear();
			_item << slotItem_percent[0][8];
			this->m_slotItemPanel_left->mItem_roulette_tc->SetValue(_item);
			LOGD("Parse Save File", "_item=%s \n",
					(const char* )_item.mb_str());
			_item.Clear();

			// Middle Slot
			_item.Clear();
			_item << slotItem_percent[1][0];
			this->m_slotItemPanel_middle->mItem_cherry_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[1][1];
			this->m_slotItemPanel_middle->mItem_apple_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[1][2];
			this->m_slotItemPanel_middle->mItem_orange_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[1][3];
			this->m_slotItemPanel_middle->mItem_coin_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[1][4];
			this->m_slotItemPanel_middle->mItem_bar_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[1][5];
			this->m_slotItemPanel_middle->mItem_diamond_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[1][6];
			this->m_slotItemPanel_middle->mItem_crown_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[1][7];
			this->m_slotItemPanel_middle->mItem_freecoin_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[1][8];
			this->m_slotItemPanel_middle->mItem_roulette_tc->SetValue(_item);
			_item.Clear();

			// Right Slot
			_item.Clear();
			_item << slotItem_percent[2][0];
			this->m_slotItemPanel_right->mItem_cherry_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[2][1];
			this->m_slotItemPanel_right->mItem_apple_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[2][2];
			this->m_slotItemPanel_right->mItem_orange_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[2][3];
			this->m_slotItemPanel_right->mItem_coin_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[2][4];
			this->m_slotItemPanel_right->mItem_bar_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[2][5];
			this->m_slotItemPanel_right->mItem_diamond_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[2][6];
			this->m_slotItemPanel_right->mItem_crown_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[2][7];
			this->m_slotItemPanel_right->mItem_freecoin_tc->SetValue(_item);
			_item.Clear();
			_item << slotItem_percent[2][8];
			this->m_slotItemPanel_right->mItem_roulette_tc->SetValue(_item);
			_item.Clear();

			// Match Item
			_item.Clear();
			_item << matchItem_percent[0];
			this->m_matchItemPanel->mItem_cherry_tc->SetValue(_item);
			_item.Clear();
			_item << matchItem_percent[1];
			this->m_matchItemPanel->mItem_apple_tc->SetValue(_item);
			_item.Clear();
			_item << matchItem_percent[2];
			this->m_matchItemPanel->mItem_orange_tc->SetValue(_item);
			_item.Clear();
			_item << matchItem_percent[3];
			this->m_matchItemPanel->mItem_coin_tc->SetValue(_item);
			_item.Clear();
			_item << matchItem_percent[4];
			this->m_matchItemPanel->mItem_bar_tc->SetValue(_item);
			_item.Clear();
			_item << matchItem_percent[5];
			this->m_matchItemPanel->mItem_diamond_tc->SetValue(_item);
			_item.Clear();
			_item << matchItem_percent[6];
			this->m_matchItemPanel->mItem_crown_tc->SetValue(_item);
			_item.Clear();
			_item << matchItem_percent[7];
			this->m_matchItemPanel->mItem_multiple_tc->SetValue(_item);
			_item.Clear();
			_item << matchItem_percent[8];
			this->m_matchItemPanel->mItem_train_tc->SetValue(_item);
			_item.Clear();
		}
	}
}

