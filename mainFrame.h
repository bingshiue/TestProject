/**
 * @file mainFrame.h
 *
 */

#ifndef MAINFRAME_H_
#define MAINFRAME_H_

#include <iostream>
#include <wx/wx.h>
#include <wx/wxprec.h>
#include "include/log.h"
#include "include/mersenne_twister/MTRandom.h"
#include "panels.h"

using namespace std;

class MainFrame : public wxFrame{
public:
	MainFrame(const wxString& title);
	MTRANDOM m_mtRandom;/**< Mersenne Twister Algorithm */

	wxPanel    *m_parent;
	LeftPanel  *m_lp;
	RightPanel *m_rp;

	wxToolBar*  toolbar1;
	//wxToolBar*  toolbar2;

	wxMenuBar*  menubar;
	wxMenu*     file;
	wxMenu*     imp;
	wxMenuItem* quit;

	void OnQuit(wxCommandEvent& event);

	virtual ~MainFrame();
};


#endif /* MAINFRAME_H_ */
