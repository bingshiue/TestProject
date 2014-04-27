/*
 * simple.cpp
 *
 *  Created on: 2014/04/27
 *      Author: bingshiue
 */

#include "simple.h"
#include "icons/sample.xpm"

Simple::Simple(const wxString& title)
       : wxFrame((wxFrame *)NULL,wxID_ANY,title,wxDefaultPosition,wxSize(500,200))
{

	wxImage::AddHandler( new wxPNGHandler );

	m_parent = new wxPanel(this,wxID_ANY);

	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

    //wxButton* button = new wxButton(m_parent,wxID_EXIT,wxT("Exit"),wxPoint(20,20));
	//Connect(wxID_EXIT,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(Simple::OnQuit));

    m_lp = new LeftPanel(m_parent);
    m_rp = new RightPanel(m_parent);

    hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);
    hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);

    m_parent->SetSizer(hbox,true);

    wxBitmap exit(wxT("icons/exit.png"), wxBITMAP_TYPE_PNG);
    wxBitmap newb(wxT("icons/new.png"),  wxBITMAP_TYPE_PNG);
    wxBitmap open(wxT("icons/open.png"), wxBITMAP_TYPE_PNG);
    wxBitmap save(wxT("icons/save.png"), wxBITMAP_TYPE_PNG);

    //wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    toolbar1 = CreateToolBar();//new wxToolBar(this, wxID_ANY);
    toolbar1->AddTool(wxID_ANY,  newb, wxT("New File"));
    toolbar1->AddTool(wxID_ANY,  open, wxT("Open File"));
    toolbar1->AddTool(wxID_ANY,  save, wxT("Save File"));
    toolbar1->AddTool(wxID_EXIT, exit, wxT("Exit application"));
    toolbar1->Realize();

    //toolbar2 = CreateToolBar();//new wxToolBar(this, wxID_ANY);
    //toolbar2->AddTool(wxID_EXIT, exit, wxT("Exit application"));
    //toolbar2->Realize();

    //vbox->Add(toolbar1, 0, wxEXPAND);
    //vbox->Add(toolbar2, 0, wxEXPAND);

    //SetSizer(vbox);

    Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Simple::OnQuit));


    menubar = new wxMenuBar();
    file    = new wxMenu();

    file->Append(wxID_ANY, wxT("&New"));
    file->Append(wxID_ANY, wxT("&Open"));
    file->Append(wxID_ANY, wxT("&Save"));
    file->AppendSeparator();

    imp = new wxMenu();
    imp->Append(wxID_ANY, wxT("Import newsfeed list..."));
    imp->Append(wxID_ANY, wxT("Import bookmarks..."));
    imp->Append(wxID_ANY, wxT("Import mail..."));

    file->AppendSubMenu(imp, wxT("&Import"));

    quit = new wxMenuItem(file, wxID_EXIT, wxT("&Quit\tCtrl+W"));
    file->Append(quit);


    menubar->Append(file,wxT("&File"));
    SetMenuBar(menubar);

    Connect(wxID_EXIT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Simple::OnQuit));


    //button->SetFocus();
	SetIcon(sample_xpm);
	Centre();
}

Simple::~Simple(){

}

void Simple::OnQuit(wxCommandEvent& WXUNUSED(event)){
	 Close(true);
}


