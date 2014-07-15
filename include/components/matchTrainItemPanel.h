/**
 * @file matchTrainItemPanel.h
 *
 */

#ifndef MATCHTRAINITEMPANEL_H_
#define MATCHTRAINITEMPANEL_H_

#include <wx/wx.h>

enum {
	CID_MATCH_TRAIN_FRAME_1 = 0,
	CID_MATCH_TRAIN_FRAME_2,
	CID_MATCH_TRAIN_FRAME_3,
	CID_MATCH_TRAIN_FRAME_4,
	CID_MATCH_TRAIN_FRAME_5,
	CID_MATCH_TRAIN_FRAME_6,
	CID_MATCH_TRAIN_FRAME_7,
	CID_MATCH_TRAIN_FRAME_8,
	CID_MATCH_TRAIN_FRAME_9,
	CID_MATCH_TRAIN_FRAME_10,
	CID_MATCH_TRAIN_FRAME_11,
	CID_MATCH_TRAIN_FRAME_12,
	CID_MATCH_TRAIN_FRAME_13,
	CID_MATCH_TRAIN_FRAME_14,
	CID_MATCH_TRAIN_FRAME_15,
	CID_MATCH_TRAIN_FRAME_16,
	CID_MATCH_TRAIN_FRAME_17,
	CID_MATCH_TRAIN_FRAME_18,
	CID_MATCH_TRAIN_FRAME_19,
	CID_MATCH_TRAIN_FRAME_20,
	CID_MATCH_TRAIN_FRAME_21,
	CID_MATCH_TRAIN_FRAME_22,
	CID_MATCH_TRAIN_FRAME_23,
	CID_MATCH_TRAIN_FRAME_24,
	CID_MATCH_TRAIN_FRAME_25,
	CID_MATCH_TRAIN_FRAME_26,
	CID_MATCH_TRAIN_FRAME_27,
	CID_MATCH_TRAIN_FRAME_28,
	CID_MATCH_TRAIN_FRAME_29
};


class MatchTrainItemPanel : public wxPanel{
public:
	wxPanel *m_parent;/**< Parent Panel */
	wxStaticBox *m_sb;/**< Static Box */
    wxStaticBoxSizer *m_sz;/**< Static Box Sizer */
    wxGridSizer *m_gridSz;/**< Grid Sizer */

    wxStaticText* mItem_label[29];/**< Item Static Text */

    wxTextCtrl* mItem_tc[29];/**< Item Text Control */

    wxStaticText* mTotalValue_label;/**< Total Value Text */
    wxTextCtrl* mTotalValue_tc;/**< Total Value Text Control */

	/**
	 * @brief Constructor.
	 */
    MatchTrainItemPanel(wxPanel* parent,wxString title);
	/**
	 * @brief Handler for Verify Input Value After Edit.
	 */
	void AfterEdit(wxCommandEvent& event);
};


#endif /* MATCHTRAINITEMPANEL_H_ */
