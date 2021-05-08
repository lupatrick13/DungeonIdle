/*
 * MainFrame.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title,
        const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size), m_bookCtrl(new wxNotebook(this, wxID_ANY, wxDefaultPosition,
		wxDefaultSize, wxNB_BOTTOM))
{
	game = new DungeonIdle();
	home = new HomePage(m_bookCtrl, game);
	m_bookCtrl->AddPage(home, wxString("Home"), true);

	player_stats = new PlayerStatPage(m_bookCtrl, new Player());
	m_bookCtrl->AddPage(player_stats, wxString("Player Stats"), false);

	settings = new SettingsPage(m_bookCtrl);
	m_bookCtrl->AddPage(settings, wxString("Settings"), false);
}


