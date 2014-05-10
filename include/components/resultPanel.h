/**
 * @file resultPanel.h
 *
 */

#ifndef RESULTPANEL_H_
#define RESULTPANEL_H_

#include <wx/wx.h>

class ResultPanel : public wxPanel{
public:
	wxPanel* m_parent;

	wxStaticBox* m_sb;/**< Static Box */
	wxStaticBoxSizer* m_sz;/**< Static Box Sizer */
	wxGridSizer* m_gridSz;/**< Grid Sizer */
	wxSizer* m_hbox_1;/**< Horizontal Box */
	wxSizer* m_hbox_2;/**< Horizontal Box */
	wxSizer* m_hbox_3;/**< Horizontal Box */
	wxSizer* m_hbox_4;/**< Horizontal Box */
	wxSizer* m_hbox_5;/**< Horizontal Box */
	wxSizer* m_hbox_6;/**< Horizontal Box */

	wxStaticText* m_totalKeyIn;
	wxStaticText* m_totalKeyOut;
	wxStaticText* m_keyInOutPercent;

	wxStaticText* m_totalPlayScore;
	wxStaticText* m_totalWinScore;
	wxStaticText* m_PlayWinScorePercent;

	wxStaticText* m_totalPlayTimes;
	wxStaticText* m_totalWinTimes;
	wxStaticText* m_PlayWinTimesPercent;

	wxStaticText* m_doubleTotalPlayScore;
	wxStaticText* m_doubleTotalWinScore;
	wxStaticText* m_doublePlayWinScorePercent;

	wxStaticText* m_doubleTotalPlayTimes;
	wxStaticText* m_doubleTotalWinTimes;
	wxStaticText* m_doublePlayWinTimesPercent;

	wxStaticText* m_mainGameOverMaxWinTimes;
	wxStaticText* m_doubleGameOverMaxWinTimes;
	wxStaticText* m_doubleGameMaxConsecutivePassTimes;

	wxTextCtrl* m_totalKeyIn_tc;
	wxTextCtrl* m_totalKeyOut_tc;
	wxTextCtrl* m_keyInOutPercent_tc;

	wxTextCtrl* m_totalPlayScore_tc;
	wxTextCtrl* m_totalWinScore_tc;
	wxTextCtrl* m_PlayWinScorePercent_tc;

	wxTextCtrl* m_totalPlayTimes_tc;
	wxTextCtrl* m_totalWinTimes_tc;
	wxTextCtrl* m_PlayWinTimesPercent_tc;

	wxTextCtrl* m_doubleTotalPlayScore_tc;
	wxTextCtrl* m_doubleTotalWinScore_tc;
	wxTextCtrl* m_doublePlayWinScorePercent_tc;

	wxTextCtrl* m_doubleTotalPlayTimes_tc;
	wxTextCtrl* m_doubleTotalWinTimes_tc;
	wxTextCtrl* m_doublePlayWinTimesPercent_tc;

	wxTextCtrl* m_mainGameOverMaxWinTimes_tc;
	wxTextCtrl* m_doubleGameOverMaxWinTimes_tc;
	wxTextCtrl* m_doubleGameMaxConsecutivePassTimes_tc;

	/**
	 * @brief Constructor.
	 *
	 */
	ResultPanel(wxPanel* parent,wxString title);
};


#endif /* RESULTPANEL_H_ */
