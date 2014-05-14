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
	/* Initialize Mersenne Twister Algorithm */
	srand(time(NULL));
	int seed = rand() % 10000;
	m_mtRandom.resetMT(seed); // use 19650218UL as seed for verify Mersenne Twister Algorithm
	LOGD("Mersenne Twister", "Initialized Seed=%d \n", seed);

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

}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
	wxString buildDate = L"Build Date : ";
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

	wxString item2Value;
	item2Value << DEFAULT_SLOT_1_ORANGE;
	this->m_slotItemPanel_left->mItem_orange_tc->SetValue(item2Value);

	wxString item3Value;
	item3Value << DEFAULT_SLOT_1_APPLE;
	this->m_slotItemPanel_left->mItem_apple_tc->SetValue(item3Value);

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

	wxString item2Value;
	item2Value << DEFAULT_SLOT_2_ORANGE;
	this->m_slotItemPanel_middle->mItem_orange_tc->SetValue(item2Value);

	wxString item3Value;
	item3Value << DEFAULT_SLOT_2_APPLE;
	this->m_slotItemPanel_middle->mItem_apple_tc->SetValue(item3Value);

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

	wxString item2Value;
	item2Value << DEFAULT_SLOT_3_ORANGE;
	this->m_slotItemPanel_right->mItem_orange_tc->SetValue(item2Value);

	wxString item3Value;
	item3Value << DEFAULT_SLOT_3_APPLE;
	this->m_slotItemPanel_right->mItem_apple_tc->SetValue(item3Value);

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

	wxString item2Value;
	item2Value << DEFAULT_MATCH_ORANGE;
	this->m_matchItemPanel->mItem_orange_tc->SetValue(item2Value);

	wxString item3Value;
	item3Value << DEFAULT_MATCH_APPLE;
	this->m_matchItemPanel->mItem_apple_tc->SetValue(item3Value);

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
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue());
	//step 3
	m_slot1Step.step3 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue());
	//step 4
	m_slot1Step.step4 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue());
	//step 5
	m_slot1Step.step5 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_bar_tc->GetValue());
	//step 6
	m_slot1Step.step6 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_diamond_tc->GetValue());
	//step 7
	m_slot1Step.step7 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_crown_tc->GetValue());
	//step 8
	m_slot1Step.step8 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_crown_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_freecoin_tc->GetValue());
	//step 9
	m_slot1Step.step9 = wxAtoi(
			this->m_slotItemPanel_left->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_left->mItem_apple_tc->GetValue())
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
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue());
	//step 3
	m_slot2Step.step3 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue());
	//step 4
	m_slot2Step.step4 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_coin_tc->GetValue());
	//step 5
	m_slot2Step.step5 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_bar_tc->GetValue());
	//step 6
	m_slot2Step.step6 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_bar_tc->GetValue())
			+ wxAtoi(
					this->m_slotItemPanel_middle->mItem_diamond_tc->GetValue());
	//step 7
	m_slot2Step.step7 = wxAtoi(
			this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_middle->mItem_crown_tc->GetValue());
	//step 8
	m_slot2Step.step8 =
			wxAtoi(this->m_slotItemPanel_middle->mItem_cherry_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
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
							this->m_slotItemPanel_middle->mItem_orange_tc->GetValue())
					+ wxAtoi(
							this->m_slotItemPanel_middle->mItem_apple_tc->GetValue())
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
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue());
	//step 3
	m_slot3Step.step3 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue());
	//step 4
	m_slot3Step.step4 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue());
	//step 5
	m_slot3Step.step5 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue());
	//step 6
	m_slot3Step.step6 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_diamond_tc->GetValue());
	//step 7
	m_slot3Step.step7 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_crown_tc->GetValue());
	//step 8
	m_slot3Step.step8 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_crown_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_freecoin_tc->GetValue());
	//step 9
	m_slot3Step.step9 = wxAtoi(
			this->m_slotItemPanel_right->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_crown_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_freecoin_tc->GetValue())
			+ wxAtoi(this->m_slotItemPanel_right->mItem_roulette_tc->GetValue());

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
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue());
	//step 3
	m_matchStep.step3 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue());
	//step 4
	m_matchStep.step4 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue());
	//step 5
	m_matchStep.step5 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_bar_tc->GetValue());
	//step 6
	m_matchStep.step6 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_diamond_tc->GetValue());
	//step 7
	m_matchStep.step7 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_crown_tc->GetValue());
	//step 8
	m_matchStep.step8 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_coin_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_bar_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_diamond_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_crown_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_multiple_tc->GetValue());
	//step 9
	m_matchStep.step9 = wxAtoi(
			this->m_matchItemPanel->mItem_cherry_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_orange_tc->GetValue())
			+ wxAtoi(this->m_matchItemPanel->mItem_apple_tc->GetValue())
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

void MainFrame::Start(wxCommandEvent& event) {
	LOGI("Start Button", "In Start Button Handle \n");

	/* Set Probability Steps */
	SetSlot1ProStep();
	SetSlot2ProStep();
	SetSlot3ProStep();
	SetMatchProStep();

	/* Test Get Stop Item */
	SLOTSTOPSUBFUNC SlotStopSubFunc[3] = {
			GetSlotLeftStopItem,
			GetSlotMiddleStopItem,
			GetSlotRightStopItem
	};

	for(int time=0; time<1000; time++){
		for(int idx=0; idx<3; idx++){
			SlotStopSubFunc[idx](&this->m_mtRandom,this);
		}
		GetMatchStopItem(&this->m_mtRandom,this);
	}
}

void MainFrame::Reset(wxCommandEvent& event) {
	LOGI("Reset Button", "In Reset Button Handle \n");
}

