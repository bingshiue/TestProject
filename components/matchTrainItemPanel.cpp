/**
 * @file matchTrainItemPanel.cpp
 *
 */
#include "../include/components/matchTrainItemPanel.h"

MatchTrainItemPanel::MatchTrainItemPanel(wxPanel* parent,wxString title) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE){
	this->m_parent = parent;

	this->m_sb = new wxStaticBox(this,wxID_ANY,title,wxDefaultPosition,wxDefaultSize);
	this->m_sz = new wxStaticBoxSizer(this->m_sb,wxVERTICAL);

	this->m_gridSz = new wxGridSizer(6,10,1,1);

	wxTextValidator validator(wxFILTER_NUMERIC);

	for(unsigned int idx=0; idx<FRAME_CNT; idx++){
		wchar_t name[128];
		swprintf(name,sizeof(name),L"Frame %d",idx+1);
		wxString label(name);
		this->mItem_label[idx] = new wxStaticText(this,wxID_ANY,label,wxDefaultPosition,wxDefaultSize);
	}

	for(unsigned int idx=0; idx<FRAME_CNT; idx++){
		this->mItem_tc[idx] = new wxTextCtrl(this,idx,L"",wxDefaultPosition,wxSize(50,22),0,validator);
	}

	this->mTotalValue_label = new wxStaticText(this,wxID_ANY,L"TOTAL",wxDefaultPosition,wxDefaultSize);
		this->mTotalValue_tc = new wxTextCtrl(this,wxID_ANY,L"10000",wxDefaultPosition,wxSize(50,22));
		this->mTotalValue_tc->SetForegroundColour(wxColour(0,0,255));
		this->mTotalValue_tc->SetEditable(false);

	for(unsigned int idx=0; idx<FRAME_CNT; idx++){
		this->m_gridSz->Add(this->mItem_label[idx],0);
		this->m_gridSz->Add(this->mItem_tc[idx],0);
	}

	this->m_gridSz->Add(this->mTotalValue_label,0);
	this->m_gridSz->Add(this->mTotalValue_tc,0);

	this->m_sz->Add(this->m_gridSz,0);

	this->SetSizer(this->m_sz,true);

	for(unsigned int idx=0; idx<FRAME_CNT; idx++){
		this->mItem_tc[idx]->SetMaxLength(4);
	}

	for(unsigned int idx=0; idx<FRAME_CNT; idx++){
		Connect(idx,wxEVT_COMMAND_TEXT_UPDATED,wxCommandEventHandler(MatchTrainItemPanel::AfterEdit));
	}

	// Default Value
	m_defaultValue[0]  = DEFAULT_MATCH_TRAIN_FRAME_1;
	m_defaultValue[1]  = DEFAULT_MATCH_TRAIN_FRAME_2;
	m_defaultValue[2]  = DEFAULT_MATCH_TRAIN_FRAME_3;
	m_defaultValue[3]  = DEFAULT_MATCH_TRAIN_FRAME_4;
	m_defaultValue[4]  = DEFAULT_MATCH_TRAIN_FRAME_5;
	m_defaultValue[5]  = DEFAULT_MATCH_TRAIN_FRAME_6;
	m_defaultValue[6]  = DEFAULT_MATCH_TRAIN_FRAME_7;
	m_defaultValue[7]  = DEFAULT_MATCH_TRAIN_FRAME_8;
	m_defaultValue[8]  = DEFAULT_MATCH_TRAIN_FRAME_9;
	m_defaultValue[9]  = DEFAULT_MATCH_TRAIN_FRAME_10;
	m_defaultValue[10] = DEFAULT_MATCH_TRAIN_FRAME_11;
	m_defaultValue[11] = DEFAULT_MATCH_TRAIN_FRAME_12;
	m_defaultValue[12] = DEFAULT_MATCH_TRAIN_FRAME_13;
	m_defaultValue[13] = DEFAULT_MATCH_TRAIN_FRAME_14;
	m_defaultValue[14] = DEFAULT_MATCH_TRAIN_FRAME_15;
	m_defaultValue[15] = DEFAULT_MATCH_TRAIN_FRAME_16;
	m_defaultValue[16] = DEFAULT_MATCH_TRAIN_FRAME_17;
	m_defaultValue[17] = DEFAULT_MATCH_TRAIN_FRAME_18;
	m_defaultValue[18] = DEFAULT_MATCH_TRAIN_FRAME_19;
	m_defaultValue[19] = DEFAULT_MATCH_TRAIN_FRAME_20;
	m_defaultValue[20] = DEFAULT_MATCH_TRAIN_FRAME_21;
	m_defaultValue[21] = DEFAULT_MATCH_TRAIN_FRAME_22;
	m_defaultValue[22] = DEFAULT_MATCH_TRAIN_FRAME_23;
	m_defaultValue[23] = DEFAULT_MATCH_TRAIN_FRAME_24;
	m_defaultValue[24] = DEFAULT_MATCH_TRAIN_FRAME_25;
	m_defaultValue[25] = DEFAULT_MATCH_TRAIN_FRAME_26;
	m_defaultValue[26] = DEFAULT_MATCH_TRAIN_FRAME_27;
	m_defaultValue[27] = DEFAULT_MATCH_TRAIN_FRAME_28;
	m_defaultValue[28] = DEFAULT_MATCH_TRAIN_FRAME_29;
}

void MatchTrainItemPanel::AfterEdit(wxCommandEvent& event){
	unsigned int tmp=0;

	for(unsigned int idx=0; idx<FRAME_CNT; idx++){
		tmp += wxAtoi(this->mItem_tc[idx]->GetValue());
	}

	wxString result(L"");
	result << tmp;
	this->mTotalValue_tc->SetValue(result);

	if(tmp > 10000){
      this->mTotalValue_tc->SetForegroundColour(wxColour(255,0,0));
	  wxMessageDialog *dial = new wxMessageDialog(NULL,L"Sum Over 10000",L"Error", wxOK | wxICON_ERROR);
	  dial->ShowModal();
	}else if(tmp < 10000){
	  this->mTotalValue_tc->SetForegroundColour(wxColour(255,0,0));
	}else{
	  this->mTotalValue_tc->SetForegroundColour(wxColour(0,0,255));
	}
}


