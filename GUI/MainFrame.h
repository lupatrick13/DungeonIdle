/*
 * MainFrame.h
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#ifndef GUI_MAINFRAME_H_
#define GUI_MAINFRAME_H_

#include "HomePage/HomePage.h"
#include "SettingsPage/SettingsPage.h"

class MainFrame: public wxFrame {
public:
	MainFrame(const wxString& title,
            const wxPoint& pos, const wxSize& size);
	virtual ~MainFrame() {}
private:
	DungeonIdle* game;
	HomePage *home;
	SettingsPage *settings;

    wxNotebook *m_bookCtrl;
};

#endif /* GUI_MAINFRAME_H_ */
