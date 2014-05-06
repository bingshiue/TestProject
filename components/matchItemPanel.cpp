/**
 * @file matchItemPanel.cpp
 *
 */

#include "../include/components/matchItemPanel.h"

MatchItemPanel::MatchItemPanel(wxPanel* parent,wxString title) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE){

	this->m_parent = parent;

	this->m_sb = new wxStaticBox(this,wxID_ANY,title,wxDefaultPosition,wxDefaultSize);
	this->m_sz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);

	this->m_gridSz = new wxGridSizer(2,18,1,1);

	wxTextValidator validator(wxFILTER_NUMERIC);

	this->mItem_cherry_label = new wxStaticText(this,wxID_ANY,L"CHERRY",wxDefaultPosition,wxDefaultSize);
	    this->mItem_cherry_tc = new wxTextCtrl(this,CID_MATCH_ITEM_CHERRY,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->mItem_orange_label = new wxStaticText(this,wxID_ANY,L"ORANGE",wxDefaultPosition,wxDefaultSize);
		this->mItem_orange_tc = new wxTextCtrl(this,CID_MATCH_ITEM_ORANGE,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->mItem_apple_label = new wxStaticText(this,wxID_ANY,L"APPLE",wxDefaultPosition,wxDefaultSize);
		this->mItem_apple_tc = new wxTextCtrl(this,CID_MATCH_ITEM_APPLE,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->mItem_coin_label = new wxStaticText(this,wxID_ANY,L"COIN",wxDefaultPosition,wxDefaultSize);
		this->mItem_coin_tc = new wxTextCtrl(this,CID_MATCH_ITEM_COIN,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->mItem_bar_label = new wxStaticText(this,wxID_ANY,L"BAR",wxDefaultPosition,wxDefaultSize);
		this->mItem_bar_tc = new wxTextCtrl(this,CID_MATCH_ITEM_BAR,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->mItem_diamond_label = new wxStaticText(this,wxID_ANY,L"DIAMOND",wxDefaultPosition,wxDefaultSize);
		this->mItem_diamond_tc = new wxTextCtrl(this,CID_MATCH_ITEM_DIAMOND,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->mItem_crown_label = new wxStaticText(this,wxID_ANY,L"CROWN",wxDefaultPosition,wxDefaultSize);
		this->mItem_crown_tc = new wxTextCtrl(this,CID_MATCH_ITEM_CROWN,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->mItem_multiple_label = new wxStaticText(this,wxID_ANY,L"Multiple",wxDefaultPosition,wxDefaultSize);
		this->mItem_multiple_tc = new wxTextCtrl(this,CID_MATCH_ITEM_MULTIPLE,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->mItem_train_label = new wxStaticText(this,wxID_ANY,L"Train",wxDefaultPosition,wxDefaultSize);
		this->mItem_train_tc = new wxTextCtrl(this,CID_MATCH_ITEM_TRAIN,L"",wxDefaultPosition,wxSize(50,22),0,validator);

	this->mTotalValue_label = new wxStaticText(this,wxID_ANY,L"TOTAL",wxDefaultPosition,wxDefaultSize);
		this->mTotalValue_tc = new wxTextCtrl(this,wxID_ANY,L"10000",wxDefaultPosition,wxSize(50,22));
		this->mTotalValue_tc->SetForegroundColour(wxColour(0,0,255));
		this->mTotalValue_tc->SetEditable(false);

	this->m_gridSz->Add(this->mItem_cherry_label,0);
	this->m_gridSz->Add(this->mItem_cherry_tc,0);

	this->m_gridSz->Add(this->mItem_orange_label,0);
	this->m_gridSz->Add(this->mItem_orange_tc,0);

	this->m_gridSz->Add(this->mItem_apple_label,0);
	this->m_gridSz->Add(this->mItem_apple_tc,0);

	this->m_gridSz->Add(this->mItem_coin_label,0);
	this->m_gridSz->Add(this->mItem_coin_tc,0);

	this->m_gridSz->Add(this->mItem_bar_label,0);
	this->m_gridSz->Add(this->mItem_bar_tc,0);

	this->m_gridSz->Add(this->mItem_diamond_label,0);
	this->m_gridSz->Add(this->mItem_diamond_tc,0);

	this->m_gridSz->Add(this->mItem_crown_label,0);
	this->m_gridSz->Add(this->mItem_crown_tc,0);

	this->m_gridSz->Add(this->mItem_multiple_label,0);
	this->m_gridSz->Add(this->mItem_multiple_tc,0);

	this->m_gridSz->Add(this->mItem_train_label,0);
	this->m_gridSz->Add(this->mItem_train_tc,0);

	this->m_gridSz->Add(this->mTotalValue_label,0);
	this->m_gridSz->Add(this->mTotalValue_tc,0);

	this->m_sz->Add(this->m_gridSz,0);

	this->SetSizer(this->m_sz,true);

	this->mItem_cherry_tc->SetMaxLength(4);
	this->mItem_orange_tc->SetMaxLength(4);
	this->mItem_apple_tc->SetMaxLength(4);
	this->mItem_coin_tc->SetMaxLength(4);
	this->mItem_bar_tc->SetMaxLength(4);
	this->mItem_diamond_tc->SetMaxLength(4);
	this->mItem_crown_tc->SetMaxLength(4);
	this->mItem_multiple_tc->SetMaxLength(4);
	this->mItem_train_tc->SetMaxLength(4);

	Connect(CID_MATCH_ITEM_CHERRY,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchItemPanel::AfterEdit));
	Connect(CID_MATCH_ITEM_ORANGE,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchItemPanel::AfterEdit));
	Connect(CID_MATCH_ITEM_APPLE,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchItemPanel::AfterEdit));
	Connect(CID_MATCH_ITEM_COIN,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchItemPanel::AfterEdit));
	Connect(CID_MATCH_ITEM_BAR,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchItemPanel::AfterEdit));
	Connect(CID_MATCH_ITEM_DIAMOND,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchItemPanel::AfterEdit));
	Connect(CID_MATCH_ITEM_CROWN,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchItemPanel::AfterEdit));
	Connect(CID_MATCH_ITEM_MULTIPLE,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchItemPanel::AfterEdit));
	Connect(CID_MATCH_ITEM_TRAIN,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchItemPanel::AfterEdit));
}

void MatchItemPanel::AfterEdit(wxCommandEvent& event){

}









