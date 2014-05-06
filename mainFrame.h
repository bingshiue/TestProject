/**
 * @file mainFrame.h
 *
 */

#ifndef MAINFRAME_H_
#define MAINFRAME_H_

#include <iostream>
#include <iomanip>
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/progdlg.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/datstrm.h>
#include <wx/textfile.h>
#include <wx/tokenzr.h>
#include "include/log.h"
#include "include/mersenne_twister/MTRandom.h"
#include "include/setting/setting.h"
#include "slotItemPanel.h"
#include "matchItemPanel.h"
#include "keyInOutPanel.h"

using namespace std;

enum {
	CID_RUN_BUTTON    = 101,
	CID_RESET_BUTTON  = 102,
};

enum {
	CID_SAVE_MENU     = 201,
	CID_LOAD_MENU     = 202,
	CID_ABOUT_MENU    = 203,
};

class MainFrame : public wxFrame{
public:
	MainFrame(const wxString& title);
	MTRANDOM m_mtRandom;/**< Mersenne Twister Algorithm */

	wxPanel    *m_parent;/**< Parent Panel */
	wxNotebook *m_noteBook;/**< Note Book */

	wxSizer    *m_mainTopSizer;/**< Main Top Level Sizer */
	wxSizer    *m_vbox_1;/**< Vertical Sizer 1 */
	wxSizer    *m_hbox_1;/**< Horizontal Sizer 1 */
	wxSizer    *m_hbox_2;/**< Horizontal Sizer 2 */
	wxSizer    *m_hbox_3;/**< Horizontal Sizer 3 */

	wxMenuBar  *m_menubar;/**< Menu Bar */
	wxMenu     *m_file;/**< File Menu */
	wxMenuItem *m_quit;/**< Quit Menu Item */
	wxMenu     *m_about;/**< About Menu */

	SlotItemPanel *m_slotItemPanel_left;/**< Left Slot Item Panel */
	SlotItemPanel *m_slotItemPanel_middle;/**< Middle Slot Item Panel */
	SlotItemPanel *m_slotItemPanel_right;/**< Right Slot Item Panel */

	MatchItemPanel *m_matchItemPanel;/**< Match Item Panel */

	KeyInOutPanel *m_keyInOutPanel;/**< Key InOut Panel */

	/**
	 * @brief Quit Handler.
	 */
	void OnQuit(wxCommandEvent& event);
	/**
	 * @brief About Handler.
	 */
	void OnAbout(wxCommandEvent& event);

	virtual ~MainFrame();

	/**
	 * @brief Set Slot Item Panel Left Default Value.
	 */
	void setSlotItemPanelLeftDefaultValue(void);
    /**
     * @brief Set Slot Item Panel Middle Default Value.
     */
	void setSlotItemPanelMiddleDefaultValue(void);
	/**
	 * @brief Set Slot Item Panel Right Default Value.
	 */
	void setSlotItemPanelRightDefaultValue(void);

	/**
	 * @brief Set Match Item Panel Default Value.
	 */
	void setMatchItemPanelDefaultValue(void);

	/**
	 * @brief Set Key In/Out Panel Default Value.
	 */
	void setKeyInOutDefault(void);

};


#endif /* MAINFRAME_H_ */
