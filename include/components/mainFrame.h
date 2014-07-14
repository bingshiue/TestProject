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
#include "../version.h"
#include "../log.h"
#include "../mersenne_twister/MTRandom.h"
#include "../setting/settingType.h"
#include "../probability/ProType.h"
#include "../probability/ProAward.h"
#include "../game/GameFrame.h"
#include "slotItemPanel.h"
#include "matchItemPanel.h"
#include "matchMultipleItemPanel.h"
#include "keyInOutPanel.h"
#include "optionPanel.h"
#include "resultPanel.h"

using namespace std;

enum {
	CID_START_BUTTON = 101,
	CID_RESET_BUTTON = 102,
};

enum {
	CID_SAVE_MENU = 201,
	CID_LOAD_MENU = 202,
	CID_ABOUT_MENU = 203,
};

class MainFrame: public wxFrame {
public:
	MainFrame(const wxString& title);
	MTRANDOM m_mtRandom;/**< Mersenne Twister Algorithm */

	SLOTPROSTEP m_slot1Step;/**< Slot 1 Probability Item */
	SLOTPROSTEP m_slot2Step;/**< Slot 2 Probability Item */
	SLOTPROSTEP m_slot3Step;/**< Slot 3 Probability Item */
	MATCHPROSTEP m_matchStep;/**< Match Probability Item */

	MatchMultipleStep m_matchMultipleStep;/**< Match Multiple Probability Item */

	SETTINGDATA m_settingData;/**< Setting Data */

	GAMEFRAME m_gameFrame;/**< Game Frame */

	typedef unsigned int (*SLOTSTOPSUBFUNC)(MTRANDOM* mtRandom,MainFrame* mainFrame);
	SLOTSTOPSUBFUNC m_slotStopSubFunc[3];/**< Slot Stop Functions */

	bool m_needToReset;/**< Need To Reset */
	bool m_runOneTest;/**< Run One Test */

	wxPanel *m_parent;/**< Parent Panel */
	wxNotebook *m_noteBook;/**< Note Book */

	wxSizer *m_mainTopSizer;/**< Main Top Level Sizer */
	wxSizer *m_vbox_1;/**< Vertical Sizer 1 */
	wxSizer *m_hbox_1;/**< Horizontal Sizer 1 */
	wxSizer *m_hbox_2;/**< Horizontal Sizer 2 */
	wxSizer *m_hbox_3;/**< Horizontal Sizer 3 */
	wxSizer *m_hbox_4;/**< Horizontal Sizer 4 */
	wxSizer *m_hbox_5;/**< Horizontal Sizer 5 */

	wxStaticBox *m_sb;/**< Static Box */
	wxStaticBoxSizer *m_sz;/**< Static Box Sizer */

	wxMenuBar *m_menubar;/**< Menu Bar */
	wxMenu *m_file;/**< File Menu */
	wxMenuItem *m_quit;/**< Quit Menu Item */
	wxMenu *m_about;/**< About Menu */

	SlotItemPanel *m_slotItemPanel_left;/**< Left Slot Item Panel */
	SlotItemPanel *m_slotItemPanel_middle;/**< Middle Slot Item Panel */
	SlotItemPanel *m_slotItemPanel_right;/**< Right Slot Item Panel */

	MatchItemPanel *m_matchItemPanel;/**< Match Item Panel */

	MatchMultipleItemPanel *m_matchMultipleItemPanel;/**< Match Multiple Panle */

	KeyInOutPanel *m_keyInOutPanel;/**< Key InOut Panel */

	OptionPanel *m_optionPanel;/**< Option Panel */

	ResultPanel *m_resultPanel;/**< Result Panel */

	wxButton* m_startButton;/**< Start Button */
	wxButton* m_resetButton;/**< Reset Button */

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
	 * @brief Set Match Multiple Item Panel Default Value.
	 */
	void setMatchMultipleItemPanelDefaultValue(void);

	/**
	 * @brief Set Key In/Out Panel Default Value.
	 */
	void setKeyInOutDefaultValue(void);

	/**
	 * @brief Set Slot 1 Probability Step.
	 */
	void SetSlot1ProStep(void);

	/**
	 * @brief Set Slot 2 Probability Step.
	 */
	void SetSlot2ProStep(void);

	/**
	 * @brief Set Slot 3 Probability Step.
	 */
	void SetSlot3ProStep(void);

	/**
	 * @brief Set Match Probability Step.
	 */
	void SetMatchProStep(void);

	/**
	 * @brief Set Match Multiple Probability Step.
	 */
	void SetMatchMultipleProStep(void);

	/**
	 * @brief Reset Result Panel.
	 */
	void ResetResultPanel(void);

	/**
	 * @brief Update Result Panel.
	 */
	void UpdateResultPanel(void);

	/**
	 * @brief Print Award Detail.
	 */
	void PrintAwardDetail();
	/**
	 * @brief Print Award Detail(To wxTextOutputStream).
	 */
	void PrintAwardDetail(wxTextOutputStream& store);
	/**
	 * @brief Start.
	 */
	void Start(wxCommandEvent& event);
	/**
	 * @brief Reset.
	 */
	void Reset(wxCommandEvent& event);
	/**
	 * @brief Save File.
	 */
	void SaveFile(wxCommandEvent& event);
	/**
	 * @brief Save data content to file.
	 */
	void SaveFileContent(wxTextOutputStream& store);
	/**
	 * @brief Load file.
	 */
	void LoadFile(wxCommandEvent& event);
	/**
	 * @brief Load data from file.
	 */
	void LoadFileContent(wxString filePath);

};

#endif /* MAINFRAME_H_ */
