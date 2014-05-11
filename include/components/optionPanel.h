/**
 * @file optionPanel.h
 *
 */

#ifndef OPTIONPANEL_H_
#define OPTIONPANEL_H_

#include <assert.h>
#include <wx/wx.h>
#include <wx/combobox.h>
#include "../log.h"
#include "../setting/settingDefault.h"
#include "../setting/settingArray.h"

enum {
	CID_COMBOBOX_COINSET          = 901,
	CID_COMBOBOX_MAXBET           = 902,
	CID_COMBOBOX_MAINGAMEMAXWIN   = 903,
	CID_COMBOBOX_DOUBLEGAMEMAXWIN = 904,
	CID_CHECKBOX_RUNDOUBLEGAME    = 905,
	CID_CHECKBOX_RUNTODEAD        = 906,

};

class OptionPanel : public wxPanel {
public:
	wxPanel* m_parent;
	wxStaticBox* m_sb;
	wxStaticBoxSizer* m_sbz;
	wxGridSizer* m_gridSz;
	wxStaticText* m_maxKeyIn;
	wxTextCtrl* m_maxKeyIn_tc;
	wxStaticText* m_coinValue;
	wxComboBox* m_coinValueCB;
	wxStaticText* m_maxBet;
	wxComboBox* m_maxBetCB;
	wxStaticText* m_mainGameMaxWin;
	wxComboBox* m_mainGameMaxWinCB;
	wxStaticText* m_doubleGameMaxWin;
	wxComboBox* m_doubleGameMaxWinCB;
	wxCheckBox* m_runDoubleGameChkBox;
	wxCheckBox* m_runToDeadChkBox;

	/**
	 * @brief Constructor.
	 */
	OptionPanel(wxPanel* parent,wxString title);
};



#endif /* OPTIONPANEL_H_ */
