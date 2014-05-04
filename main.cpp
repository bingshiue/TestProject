/**
 * @file main.cpp
 *
 */

#include "main.h"
#include "mainFrame.h"

IMPLEMENT_APP(CrownTrain)

bool CrownTrain::OnInit(){
	MainFrame* mainFrame = new MainFrame(wxT("CrownTrain"));
	mainFrame->Show(true);

	return true;
}




