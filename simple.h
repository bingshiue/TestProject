/*
 * simple.h
 *
 *  Created on: 2014/04/27
 *      Author: bingshiue
 */

#ifndef SIMPLE_H_
#define SIMPLE_H_

#include <wx/wx.h>
#include <wx/wxprec.h>
#include "panels.h"

class Simple : public wxFrame{
	public:
	    Simple(const wxString& title);
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


	    virtual ~Simple();
};


#endif /* SIMPLE_H_ */
