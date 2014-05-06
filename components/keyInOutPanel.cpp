/**
 * @file keyInOutPanel.cpp
 *
 */

#include "../include/components/keyInOutPanel.h"

KeyInOutPanel::KeyInOutPanel(wxPanel* parent,wxString title) : wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxBORDER_NONE)
{
	this->m_parent = parent;

	this->m_sb = new wxStaticBox(this,wxID_ANY,title,wxDefaultPosition,wxDefaultSize);
	this->m_sz = new wxStaticBoxSizer(this->m_sb,wxHORIZONTAL);
	this->m_fgsz_1 = new wxFlexGridSizer(5,5,15,15);
	this->m_fgsz_2 = new wxFlexGridSizer(5,5,15,15);

	wxTextValidator validator(wxFILTER_NUMERIC);
	this->m_keyInOut_Label_1 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 1",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_1 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_1 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_1 = new wxStaticText(this,wxID_ANY,L"/1000     ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_1 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_1->SetMaxLength(4);

	this->m_keyInOut_Label_2 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 2",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_2 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_2 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_2 = new wxStaticText(this,wxID_ANY,L"/1000     ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_2 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_2->SetMaxLength(4);

	this->m_keyInOut_Label_3 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 3",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_3 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_3 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_3 = new wxStaticText(this,wxID_ANY,L"/1000     ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_3 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_3->SetMaxLength(4);

	this->m_keyInOut_Label_4 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 4",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_4 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_4 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_4 = new wxStaticText(this,wxID_ANY,L"/1000      ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_4 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_4->SetMaxLength(4);

	this->m_keyInOut_Label_5 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 5",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_5 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_5 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_5 = new wxStaticText(this,wxID_ANY,L"/1000      ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_5 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_5->SetMaxLength(4);

	this->m_keyInOut_Label_6 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 6",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_6 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_6 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_6 = new wxStaticText(this,wxID_ANY,L"/1000      ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_6 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_6->SetMaxLength(4);

	this->m_keyInOut_Label_7 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 7",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_7 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_7 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_7 = new wxStaticText(this,wxID_ANY,L"/1000      ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_7 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_7->SetMaxLength(4);

	this->m_keyInOut_Label_8 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 8",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_8 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_8 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_8 = new wxStaticText(this,wxID_ANY,L"/1000      ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_8 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_8->SetMaxLength(4);

	this->m_keyInOut_Label_9 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 9",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_9 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_9 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_9 = new wxStaticText(this,wxID_ANY,L"/1000      ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_9 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_9->SetMaxLength(4);

	this->m_keyInOut_Label_10 = new wxStaticText(this,wxID_ANY,L"Auto Key In/Out Step 10",wxDefaultPosition,wxDefaultSize);
	this->m_keyIn_tc_10 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_keyOut_tc_10 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(75,22),0,validator);
	this->m_percent_Label_10 = new wxStaticText(this,wxID_ANY,L"/1000     ",wxDefaultPosition,wxDefaultSize);
	this->m_percent_tc_10 = new wxTextCtrl(this,wxID_ANY,L"",wxDefaultPosition,wxSize(40,22),0,validator);
	this->m_percent_tc_10->SetMaxLength(4);

	this->m_fgsz_1->Add(this->m_keyInOut_Label_1,0);
	this->m_fgsz_1->Add(this->m_keyIn_tc_1,0);
	this->m_fgsz_1->Add(this->m_keyOut_tc_1,0);
	this->m_fgsz_1->Add(this->m_percent_tc_1,1,0);
	this->m_fgsz_1->Add(this->m_percent_Label_1,1,0);

	this->m_fgsz_1->Add(this->m_keyInOut_Label_2,0);
	this->m_fgsz_1->Add(this->m_keyIn_tc_2,0);
	this->m_fgsz_1->Add(this->m_keyOut_tc_2,0);
	this->m_fgsz_1->Add(this->m_percent_tc_2,1,0);
	this->m_fgsz_1->Add(this->m_percent_Label_2,1,0);

	this->m_fgsz_1->Add(this->m_keyInOut_Label_3,0);
	this->m_fgsz_1->Add(this->m_keyIn_tc_3,0);
	this->m_fgsz_1->Add(this->m_keyOut_tc_3,0);
	this->m_fgsz_1->Add(this->m_percent_tc_3,1,0);
	this->m_fgsz_1->Add(this->m_percent_Label_3,1,0);

	this->m_fgsz_1->Add(this->m_keyInOut_Label_4,0);
	this->m_fgsz_1->Add(this->m_keyIn_tc_4,0);
	this->m_fgsz_1->Add(this->m_keyOut_tc_4,0);
	this->m_fgsz_1->Add(this->m_percent_tc_4,1,0);
	this->m_fgsz_1->Add(this->m_percent_Label_4,1,0);

	this->m_fgsz_1->Add(this->m_keyInOut_Label_5,0);
	this->m_fgsz_1->Add(this->m_keyIn_tc_5,0);
	this->m_fgsz_1->Add(this->m_keyOut_tc_5,0);
	this->m_fgsz_1->Add(this->m_percent_tc_5,1,0);
	this->m_fgsz_1->Add(this->m_percent_Label_5,1,0);

	this->m_fgsz_2->Add(this->m_keyInOut_Label_6,0);
	this->m_fgsz_2->Add(this->m_keyIn_tc_6,0);
	this->m_fgsz_2->Add(this->m_keyOut_tc_6,0);
	this->m_fgsz_2->Add(this->m_percent_tc_6,1,0);
	this->m_fgsz_2->Add(this->m_percent_Label_6,1,0);

	this->m_fgsz_2->Add(this->m_keyInOut_Label_7,0);
	this->m_fgsz_2->Add(this->m_keyIn_tc_7,0);
	this->m_fgsz_2->Add(this->m_keyOut_tc_7,0);
	this->m_fgsz_2->Add(this->m_percent_tc_7,1,0);
	this->m_fgsz_2->Add(this->m_percent_Label_7,1,0);

	this->m_fgsz_2->Add(this->m_keyInOut_Label_8,0);
	this->m_fgsz_2->Add(this->m_keyIn_tc_8,0);
	this->m_fgsz_2->Add(this->m_keyOut_tc_8,0);
	this->m_fgsz_2->Add(this->m_percent_tc_8,1,0);
	this->m_fgsz_2->Add(this->m_percent_Label_8,1,0);

	this->m_fgsz_2->Add(this->m_keyInOut_Label_9,0);
	this->m_fgsz_2->Add(this->m_keyIn_tc_9,0);
	this->m_fgsz_2->Add(this->m_keyOut_tc_9,0);
	this->m_fgsz_2->Add(this->m_percent_tc_9,1,0);
	this->m_fgsz_2->Add(this->m_percent_Label_9,1,0);

	this->m_fgsz_2->Add(this->m_keyInOut_Label_10,0);
	this->m_fgsz_2->Add(this->m_keyIn_tc_10,0);
	this->m_fgsz_2->Add(this->m_keyOut_tc_10,0);
	this->m_fgsz_2->Add(this->m_percent_tc_10,1,0);
	this->m_fgsz_2->Add(this->m_percent_Label_10,1,0);

	this->m_sz->Add(this->m_fgsz_1,0);
	this->m_sz->Add(this->m_fgsz_2,0);

	this->SetSizer(this->m_sz,true);
}

