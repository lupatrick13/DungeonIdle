/*
 * MainApp.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#include "MainApp.h"

using namespace std;

bool MainApp::OnInit()
{
    cout << "OnInit: Initializing Idle app!" << endl;

    MainFrame *frame = new MainFrame("RPS",
                                                 wxPoint(50, 50),
                                                 wxSize(400, 300) );
    frame->Show(true);
    return true;
}

//wxIMPLEMENT_APP(MainApp);
