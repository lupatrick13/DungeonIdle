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

	game_stats =new GameStatPage(m_bookCtrl, game);
	m_bookCtrl->AddPage(game_stats, wxString("Game Stats"), false);

	player_stats = new PlayerStatPage(m_bookCtrl, game->getPlayer());
	m_bookCtrl->AddPage(player_stats, wxString("Player Stats"), false);


	home->choice->choice_button[0]->Bind(wxEVT_BUTTON, &MainFrame::on_zero, this);
	home->choice->choice_button[1]->Bind(wxEVT_BUTTON, &MainFrame::on_one, this);
	home->choice->choice_button[2]->Bind(wxEVT_BUTTON, &MainFrame::on_two, this);

}

void MainFrame::on_one(wxCommandEvent& event)
{
	home->handle_choice(1);
	game_stats->update();
}
void MainFrame::on_zero(wxCommandEvent& event)
{
	home->handle_choice(0);
	game_stats->update();
}
void MainFrame::on_two(wxCommandEvent& event)
{
	home->handle_choice(2);
	game_stats->update();
}
