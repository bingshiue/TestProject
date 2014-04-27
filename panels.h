/*
 * panels.h
 *
 *  Created on: 2014/04/27
 *      Author: bingshiue
 */

#ifndef PANELS_H_
#define PANELS_H_

#include <wx/wx.h>
#include <wx/panel.h>

class LeftPanel : public wxPanel{
public:
	LeftPanel(wxPanel* parent);
    void OnPlus(wxCommandEvent& event);
    void OnMinus(wxCommandEvent& event);

    wxPanel*  m_parent;
    wxButton* m_plus;
    wxButton* m_minus;
    int count;
};

class RightPanel : public wxPanel{
public:
	RightPanel(wxPanel* parent);
	void OnSetText(wxCommandEvent& event);

	wxStaticText* m_text;
};

const int ID_PLUS = 101;
const int ID_MINUS = 102;


#endif /* PANELS_H_ */
