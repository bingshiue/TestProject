/*
 * TestProject.c
 *
 *  Created on: 2014/04/15
 *      Author: bingshiue
 */

#include "TestProject.h"
#include "simple.h"

IMPLEMENT_APP(Myapp)

bool Myapp::OnInit(){
	Simple* simple = new Simple(wxT("Simple"));
	simple->Show(true);

	return true;
}




