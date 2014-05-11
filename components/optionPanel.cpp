/**
 * @file optionPanel.cpp
 *
 */
#include "../include/components/optionPanel.h"
#include "../include/components/mainFrame.h"

OptionPanel::OptionPanel(wxPanel* parent,wxString title) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE)
{
	this->m_parent = parent;

	this->m_sb = new wxStaticBox(this,wxID_ANY,title);
	this->m_sbz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);
	this->m_gridSz = new wxGridSizer(2,8,0,0);

	/* Max Key In */
	wxTextValidator validator(wxFILTER_NUMERIC);
	this->m_maxKeyIn = new wxStaticText(this,wxID_ANY,L"Key In Coin Limit",wxDefaultPosition,wxDefaultSize);
	this->m_maxKeyIn_tc = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxDefaultSize,0,validator);
	wxString keyInMax; keyInMax << ((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_maxKeyIn;
	this->m_maxKeyIn_tc->SetValue(keyInMax);

	/* Coin Value */
	this->m_coinValue = new wxStaticText(this,wxID_ANY,L"Coin Value",wxDefaultPosition,wxDefaultSize);

	wxString coinSetStr[sizeof(coinValueTab)/sizeof(coinValueTab[0])];
	for(unsigned int idx=0; idx<sizeof(coinValueTab)/sizeof(coinValueTab[0]); idx++){
		coinSetStr[idx] << coinValueTab[idx];
	}
	this->m_coinValueCB = new wxComboBox(this,CID_COMBOBOX_COINSET,"",wxDefaultPosition,wxDefaultSize,sizeof(coinValueTab)/sizeof(coinValueTab[0])
			,coinSetStr,wxCB_READONLY);
    // Get Default Coin Value
	int select = -1;
	for(unsigned int idx=0; idx<sizeof(coinValueTab)/sizeof(coinValueTab[0]); idx++){
		if(coinValueTab[idx]==((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_coinValue){
			select = idx;
		}
	}
	assert(select >=0);
	LOGD("Setting Value","Default Coin Value = %d \n",coinValueTab[select]);
	this->m_coinValueCB->SetSelection(select);

	/* Max Bet */
	this->m_maxBet = new wxStaticText(this,wxID_ANY,L"Max Bet",wxDefaultPosition,wxDefaultSize);

	wxString maxBetStr[sizeof(maxBetTab)/sizeof(maxBetTab[0])];
	for(unsigned int idx=0; idx<sizeof(maxBetTab)/sizeof(maxBetTab[0]); idx++){
		maxBetStr[idx] << maxBetTab[idx];
	}
	this->m_maxBetCB = new wxComboBox(this,CID_COMBOBOX_MAXBET,"",wxDefaultPosition,wxDefaultSize,sizeof(maxBetTab)/sizeof(maxBetTab[0])
			,maxBetStr,wxCB_READONLY);
	// Get Default Max Bet
	select = -1;
	for(unsigned int idx=0; idx<sizeof(maxBetTab)/sizeof(maxBetTab[0]); idx++){
		if(maxBetTab[idx]==((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_maxBet){
			select = idx;
		}
	}
	assert(select >=0);
	LOGD("Setting Value","Default Max Bet = %d \n",maxBetTab[select]);
	this->m_maxBetCB->SetSelection(select);

	/* Main Game Over Max Win */
	this->m_mainGameMaxWin = new wxStaticText(this,wxID_ANY,L"M-Over Max Win Coin",wxDefaultPosition,wxDefaultSize);

	wxString mainGameMaxWinStr[sizeof(mainOverMaxWinTab)/sizeof(mainOverMaxWinTab[0])];
	for(unsigned int idx=0; idx<sizeof(mainOverMaxWinTab)/sizeof(mainOverMaxWinTab[0]); idx++){
		mainGameMaxWinStr[idx] << mainOverMaxWinTab[idx];
	}
	this->m_mainGameMaxWinCB = new wxComboBox(this,CID_COMBOBOX_MAINGAMEMAXWIN,"",wxDefaultPosition,wxDefaultSize,sizeof(mainOverMaxWinTab)/sizeof(mainOverMaxWinTab[0]),
			mainGameMaxWinStr,wxCB_READONLY);
	// Get Default Main Game Over Max Win
	select = -1;
	for(unsigned int idx=0; idx<sizeof(mainOverMaxWinTab)/sizeof(mainOverMaxWinTab[0]); idx++){
		if(mainOverMaxWinTab[idx]==((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_mainGameOverMaxWin){
			select = idx;
		}
	}
	assert(select >=0);
	LOGD("Setting Value","Default Main Game Over Max Win = %d \n",mainOverMaxWinTab[select]);
	this->m_mainGameMaxWinCB->SetSelection(select);

	/* Double Game Over Max Win */
	this->m_doubleGameMaxWin = new wxStaticText(this,wxID_ANY,L"D-Up Max Win Coin",wxDefaultPosition,wxDefaultSize);

	wxString doubleGameMaxWinStr[sizeof(doubleOverMaxWinTab)/sizeof(doubleOverMaxWinTab[0])];
	for(unsigned int idx=0; idx<sizeof(doubleOverMaxWinTab)/sizeof(doubleOverMaxWinTab[0]); idx++){
		doubleGameMaxWinStr[idx] << doubleOverMaxWinTab[idx];
	}
	this->m_doubleGameMaxWinCB = new wxComboBox(this,CID_COMBOBOX_DOUBLEGAMEMAXWIN,"",wxDefaultPosition,wxDefaultSize,sizeof(doubleOverMaxWinTab)/sizeof(doubleOverMaxWinTab[0]),
			doubleGameMaxWinStr,wxCB_READONLY);
	// Get Default Main Game Over Max Win
	select = -1;
	for(unsigned int idx=0; idx<sizeof(doubleOverMaxWinTab)/sizeof(doubleOverMaxWinTab[0]); idx++){
		if(doubleOverMaxWinTab[idx]==((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_doubleGameOverMaxWin){
			select = idx;
		}
	}
	assert(select >=0);
	LOGD("Setting Value","Default Double Game Over Max Win = %d \n",doubleOverMaxWinTab[select]);
	this->m_doubleGameMaxWinCB->SetSelection(select);

	/* Run Double Game */
	this->m_runDoubleGameChkBox = new wxCheckBox(this,CID_CHECKBOX_RUNDOUBLEGAME,L"Run Double Up",wxDefaultPosition,wxDefaultSize);
	this->m_runDoubleGameChkBox->SetValue(((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_runDoubleGame);
	LOGD("Setting Value","Default Run Double Game = %d \n",((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_runDoubleGame);

	/* Run To Dead (Double Game) */
	this->m_runToDeadChkBox = new wxCheckBox(this,CID_CHECKBOX_RUNTODEAD,L"D-Infinity",wxDefaultPosition,wxDefaultSize);
	this->m_runToDeadChkBox->SetValue(((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_runToDead);
	LOGD("Setting Value","Default Run To Dead = %d \n",((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_runToDead);
	if(((MainFrame*)this->m_parent->GetParent()->GetParent())->m_settingData.m_runDoubleGame==DISABLE){
		this->m_runToDeadChkBox->Disable();
	}

	this->m_gridSz->Add(this->m_maxKeyIn,0);
	this->m_gridSz->Add(this->m_maxKeyIn_tc,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_coinValue,0);
	this->m_gridSz->Add(this->m_coinValueCB,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_maxBet,0);
	this->m_gridSz->Add(this->m_maxBetCB,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_mainGameMaxWin,0);
	this->m_gridSz->Add(this->m_mainGameMaxWinCB,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_doubleGameMaxWin,0);
	this->m_gridSz->Add(this->m_doubleGameMaxWinCB,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_runDoubleGameChkBox ,0);
	this->m_gridSz->Add(this->m_runToDeadChkBox ,0);

	this->m_sbz->Add(this->m_gridSz,0);

    this->SetSizer(this->m_sbz,true);
}




