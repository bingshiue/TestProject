/**
 * @file keyInOutPanel.h
 *
 */

#ifndef KEYINOUTPANEL_H_
#define KEYINOUTPANEL_H_

#include <wx/wx.h>

class KeyInOutPanel : public wxPanel{
public:
	wxPanel* m_parent;/**< Parent Panel */
    wxStaticBox* m_sb;/**< Static Box */
    wxStaticBoxSizer* m_sz;/**< Static Box Sizer */
    wxFlexGridSizer* m_fgsz_1;/**< FlexGrid Sizer */
    wxFlexGridSizer* m_fgsz_2;/**< FlexGrid Sizer */

    wxStaticText* m_keyInOut_Label_1;/**< Key In/Out Label 1 */
    wxStaticText* m_keyInOut_Label_2;/**< Key In/Out Label 2 */
    wxStaticText* m_keyInOut_Label_3;/**< Key In/Out Label 3 */
    wxStaticText* m_keyInOut_Label_4;/**< Key In/Out Label 4 */
    wxStaticText* m_keyInOut_Label_5;/**< Key In/Out Label 5 */
    wxStaticText* m_keyInOut_Label_6;/**< Key In/Out Label 6 */
    wxStaticText* m_keyInOut_Label_7;/**< Key In/Out Label 7 */
    wxStaticText* m_keyInOut_Label_8;/**< Key In/Out Label 8 */
    wxStaticText* m_keyInOut_Label_9;/**< Key In/Out Label 9 */
    wxStaticText* m_keyInOut_Label_10;/**< Key In/Out Label 10 */

    wxStaticText* m_percent_Label_1;/**< percent Label 1 */
    wxStaticText* m_percent_Label_2;/**< percent Label 2 */
    wxStaticText* m_percent_Label_3;/**< percent Label 3 */
    wxStaticText* m_percent_Label_4;/**< percent Label 4 */
    wxStaticText* m_percent_Label_5;/**< percent Label 5 */
    wxStaticText* m_percent_Label_6;/**< percent Label 6 */
    wxStaticText* m_percent_Label_7;/**< percent Label 7 */
    wxStaticText* m_percent_Label_8;/**< percent Label 8 */
    wxStaticText* m_percent_Label_9;/**< percent Label 9 */
    wxStaticText* m_percent_Label_10;/**< percent Label 10 */

    wxTextCtrl* m_keyIn_tc_1;/**< Key In Setting Value 1 */
    wxTextCtrl* m_keyOut_tc_1;/**< Key Out Setting Value 1 */
    wxTextCtrl* m_percent_tc_1;/**< Key In Out percent 1 */

    wxTextCtrl* m_keyIn_tc_2;/**< Key In Setting Value 2 */
    wxTextCtrl* m_keyOut_tc_2;/**< Key Out Setting Value 2 */
    wxTextCtrl* m_percent_tc_2;/**< Key In Out percent 2 */

    wxTextCtrl* m_keyIn_tc_3;/**< Key In Setting Value 3 */
    wxTextCtrl* m_keyOut_tc_3;/**< Key Out Setting Value 3 */
    wxTextCtrl* m_percent_tc_3;/**< Key In Out percent 3 */

    wxTextCtrl* m_keyIn_tc_4;/**< Key In Setting Value 4 */
    wxTextCtrl* m_keyOut_tc_4;/**< Key Out Setting Value 4 */
    wxTextCtrl* m_percent_tc_4;/**< Key In Out percent 4 */

    wxTextCtrl* m_keyIn_tc_5;/**< Key In Setting Value 5 */
    wxTextCtrl* m_keyOut_tc_5;/**< Key Out Setting Value 5 */
    wxTextCtrl* m_percent_tc_5;/**< Key In Out percent 5 */

    wxTextCtrl* m_keyIn_tc_6;/**< Key In Setting Value 6 */
    wxTextCtrl* m_keyOut_tc_6;/**< Key Out Setting Value 6 */
    wxTextCtrl* m_percent_tc_6;/**< Key In Out percent 6 */

    wxTextCtrl* m_keyIn_tc_7;/**< Key In Setting Value 7 */
    wxTextCtrl* m_keyOut_tc_7;/**< Key Out Setting Value 7 */
    wxTextCtrl* m_percent_tc_7;/**< Key In Out percent 7 */

    wxTextCtrl* m_keyIn_tc_8;/**< Key In Setting Value 8 */
    wxTextCtrl* m_keyOut_tc_8;/**< Key Out Setting Value 8 */
    wxTextCtrl* m_percent_tc_8;/**< Key In Out percent 8 */

    wxTextCtrl* m_keyIn_tc_9;/**< Key In Setting Value 9 */
    wxTextCtrl* m_keyOut_tc_9;/**< Key Out Setting Value 9 */
    wxTextCtrl* m_percent_tc_9;/**< Key In Out percent 9 */

    wxTextCtrl* m_keyIn_tc_10;/**< Key In Setting Value 10 */
    wxTextCtrl* m_keyOut_tc_10;/**< Key Out Setting Value 10 */
    wxTextCtrl* m_percent_tc_10;/**< Key In Out percent 10 */

	/**
	 * @brief Constructor.
	 */
	KeyInOutPanel(wxPanel* parent,wxString title);
};

#endif /* KEYINOUTPANEL_H_ */
