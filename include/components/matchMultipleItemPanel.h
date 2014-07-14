/**
 * @file matchMultipleItemPanel.h
 *
 */

#ifndef MATCHMULTIPLEITEMPANEL_H_
#define MATCHMULTIPLEITEMPANEL_H_

#include <wx/wx.h>

enum {
	CID_MATCH_MULTIPLE_ITEM_CHERRY = 0,
	CID_MATCH_MULTIPLE_ITEM_ORANGE,
	CID_MATCH_MULTIPLE_ITEM_APPLE,
	CID_MATCH_MULTIPLE_ITEM_COIN,
	CID_MATCH_MULTIPLE_ITEM_BAR,
	CID_MATCH_MULTIPLE_ITEM_DIAMOND,
	CID_MATCH_MULTIPLE_ITEM_CROWN,
	CID_MATCH_MULTIPLE_ITEM_MULTIPLE,
	CID_MATCH_MULTIPLE_ITEM_TRAIN,
};

class MatchMultipleItemPanel : public wxPanel{
public:
	wxPanel *m_parent;/**< Parent Panel */
	wxStaticBox *m_sb;/**< Static Box */
    wxStaticBoxSizer *m_sz;/**< Static Box Sizer */
    wxGridSizer *m_gridSz;/**< Grid Sizer */

    wxStaticText* mItem_cherry_label;/**< Item Cherry Static Text */
    wxStaticText* mItem_orange_label;/**< Item Orange Static Text */
    wxStaticText* mItem_apple_label;/**< Item Apple Static Text */
    wxStaticText* mItem_coin_label;/**< Item Coin Static Text */
    wxStaticText* mItem_bar_label;/**< Item Bar Static Text */
    wxStaticText* mItem_diamond_label;/**< Item Diamond Static Text */
    wxStaticText* mItem_crown_label;/**< Item Crown Static Text */
    wxStaticText* mItem_multiple_label;/**< Item Multiple Static Text */
    wxStaticText* mItem_train_label;/**< Item Train Static Text */

    wxTextCtrl* mItem_cherry_tc;/**< Item Cherry Text Control */
    wxTextCtrl* mItem_orange_tc;/**< Item Orange Text Control */
    wxTextCtrl* mItem_apple_tc;/**< Item Apple Text Control */
    wxTextCtrl* mItem_coin_tc;/**< Item Coin Text Control */
    wxTextCtrl* mItem_bar_tc;/**< Item Bar Text Control */
    wxTextCtrl* mItem_diamond_tc;/**< Item Diamond Text Control */
    wxTextCtrl* mItem_crown_tc;/**< Item Crown Text Control */
    wxTextCtrl* mItem_multiple_tc;/**< Item Freecoin Text Control */
    wxTextCtrl* mItem_train_tc;/**< Item Roulette Text Control */

    wxStaticText* mTotalValue_label;/**< Total Value Text */
    wxTextCtrl* mTotalValue_tc;/**< Total Value Text Control */

	/**
	 * @brief Constructor.
	 */
    MatchMultipleItemPanel(wxPanel* parent,wxString title);
	/**
	 * @brief Handler for Verify Input Value After Edit.
	 */
	void AfterEdit(wxCommandEvent& event);
};



#endif /* MATCHMULTIPLEITEMPANEL_H_ */
