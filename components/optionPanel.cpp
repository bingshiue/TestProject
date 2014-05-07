/**
 * @file optionPanel.cpp
 *
 */
#include "../include/components/optionPanel.h"

OptionPanel::OptionPanel(wxPanel* parent,wxString title) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE)
{
	this->m_parent = parent;

	this->m_sb = new wxStaticBox(this,wxID_ANY,title);
	this->m_sbz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);
	this->m_gridSz = new wxGridSizer(2,8,0,0);

	wxTextValidator validator(wxFILTER_NUMERIC);
	this->m_maxKeyIn = new wxStaticText(this,wxID_ANY,L"Key In Coin Limit",wxDefaultPosition,wxDefaultSize);
	this->m_maxKeyIn_tc = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxDefaultSize,0,validator);

	//
	this->m_coinSet = new wxStaticText(this,wxID_ANY,L"Coin Value",wxDefaultPosition,wxDefaultSize);

	wxString coinSetStr[sizeof(coinValueTab)/sizeof(coinValueTab[0])];
	for(unsigned int idx=0; idx<sizeof(coinValueTab)/sizeof(coinValueTab[0]); idx++){
		coinSetStr[idx] << coinValueTab[idx];
	}
	this->m_coinSetCB = new wxComboBox(this,CID_COMBOBOX_COINSET,"",wxDefaultPosition,wxDefaultSize,sizeof(coinValueTab)/sizeof(coinValueTab[0])
			,coinSetStr,wxCB_READONLY);

	this->m_coinSetCB->SetSelection(2);

	//
	this->m_maxBet = new wxStaticText(this,wxID_ANY,L"Max Bet",wxDefaultPosition,wxDefaultSize);

	wxString maxBetStr[sizeof(maxBetTab)/sizeof(maxBetTab[0])];
	for(unsigned int idx=0; idx<sizeof(maxBetTab)/sizeof(maxBetTab[0]); idx++){
		maxBetStr[idx] << maxBetTab[idx];
	}
	this->m_maxBetCB = new wxComboBox(this,CID_COMBOBOX_MAXBET,"",wxDefaultPosition,wxDefaultSize,sizeof(maxBetTab)/sizeof(maxBetTab[0])
			,maxBetStr,wxCB_READONLY);

	this->m_maxBetCB->SetSelection(7);

	this->m_mainGameMaxWin = new wxStaticText(this,wxID_ANY,L"M-Over Max Win Coin",wxDefaultPosition,wxDefaultSize);

	wxString mainGameMaxWinStr[sizeof(mainOverMaxWinTab)/sizeof(mainOverMaxWinTab[0])];
	for(unsigned int idx=0; idx<sizeof(mainOverMaxWinTab)/sizeof(mainOverMaxWinTab[0]); idx++){
		mainGameMaxWinStr[idx] << mainOverMaxWinTab[idx];
	}
	this->m_mainGameMaxWinCB = new wxComboBox(this,CID_COMBOBOX_MAINGAMEMAXWIN,"",wxDefaultPosition,wxDefaultSize,sizeof(mainOverMaxWinTab)/sizeof(mainOverMaxWinTab[0]),
			mainGameMaxWinStr,wxCB_READONLY);
	this->m_mainGameMaxWinCB->SetSelection(4);

	this->m_doubleGameMaxWin = new wxStaticText(this,wxID_ANY,L"D-Up Max Win Coin",wxDefaultPosition,wxDefaultSize);

	wxString doubleGameMaxWinStr[sizeof(doubleOverMaxWinTab)/sizeof(doubleOverMaxWinTab[0])];
	for(unsigned int idx=0; idx<sizeof(doubleOverMaxWinTab)/sizeof(doubleOverMaxWinTab[0]); idx++){
		doubleGameMaxWinStr[idx] << doubleOverMaxWinTab[idx];
	}
	this->m_doubleGameMaxWinCB = new wxComboBox(this,CID_COMBOBOX_DOUBLEGAMEMAXWIN,"",wxDefaultPosition,wxDefaultSize,sizeof(doubleOverMaxWinTab)/sizeof(doubleOverMaxWinTab[0]),
			doubleGameMaxWinStr,wxCB_READONLY);
	this->m_doubleGameMaxWinCB->SetSelection(4);

	this->m_runDoubleGameChkBox = new wxCheckBox(this,CID_CHECKBOX_RUNDOUBLEGAME,L"Run Double Up",wxDefaultPosition,wxDefaultSize);
	this->m_runDoubleGameChkBox->SetValue(true);

	this->m_runToDeadChkBox     = new wxCheckBox(this,CID_CHECKBOX_RUNTODEAD,L"D-Infinity",wxDefaultPosition,wxDefaultSize);
	//this->m_runToDeadChkBox->SetValue(true);
	//this->m_runToDeadChkBox->Disable();

	this->m_gridSz->Add(this->m_maxKeyIn,0);
	this->m_gridSz->Add(this->m_maxKeyIn_tc,0,wxLEFT,5);

	this->m_gridSz->Add(this->m_coinSet,0);
	this->m_gridSz->Add(this->m_coinSetCB,0,wxLEFT,5);

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




