/*
 * MainFrame.h
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#ifndef GUI_MAINFRAME_H_
#define GUI_MAINFRAME_H_

#include "HomePage/HomePage.h"
#include "PlayerStatPage/PlayerStatPage.h"

class MainFrame: public wxFrame {
public:
	MainFrame(const wxString& title,
            const wxPoint& pos, const wxSize& size);
	virtual ~MainFrame() {}
	void on_one(wxCommandEvent& event);
	void on_zero(wxCommandEvent& event);
	void on_two(wxCommandEvent& event);
private:
	DungeonIdle* game;
	HomePage *home;
	PlayerStatPage *player_stats;

    wxNotebook *m_bookCtrl;
};

#endif /* GUI_MAINFRAME_H_ */
