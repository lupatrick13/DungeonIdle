/*
 * GameStatPanel.cpp
 *
 *  Created on: May 7, 2021
 *      Author: patrick
 */

#include "GameStatPage.h"

void GameStatPage::init()
{
	wxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *stat_panel = new wxPanel(this, wxID_ANY);
	wxSizer *stat_sizer = new wxGridSizer(2,2,0);
	string tot_rooms = to_string(game->getRoomsCleared()),
			tot_boss = to_string(game->getBosses_defeated()),
			cur_sh_ch = to_string(game->getShopChance()) + "% ",
			curr_r = GET_ROOM(game->getRoomType());

	wxStaticText *curr_room_label = new wxStaticText(stat_panel, wxID_ANY, wxString("Current Room Type : "));
	current_room = new wxStaticText(stat_panel, wxID_ANY, wxString(curr_r));

	wxStaticText *room_cleared_label = new wxStaticText(stat_panel, wxID_ANY, wxString("Total Rooms Cleared: "));
	rooms_cleared = new wxStaticText(stat_panel, wxID_ANY, wxString(tot_rooms));

	wxStaticText *tot_boss_label = new wxStaticText(stat_panel, wxID_ANY, wxString("Total Bosses Killed: "));
	bosses_defeated = new wxStaticText(stat_panel, wxID_ANY, wxString(tot_boss));

	wxStaticText *shop_ch_lab = new wxStaticText(stat_panel, wxID_ANY, wxString("Current shop chance: "));
	shop_chance = new wxStaticText(stat_panel, wxID_ANY, wxString(cur_sh_ch));

	stat_sizer->Add(curr_room_label);
	stat_sizer->Add(current_room);
	stat_sizer->Add(room_cleared_label);
	stat_sizer->Add(rooms_cleared);
	stat_sizer->Add(tot_boss_label);
	stat_sizer->Add(bosses_defeated);
	stat_sizer->Add(shop_ch_lab);
	stat_sizer->Add(shop_chance);
	stat_panel->SetSizer(stat_sizer);

	main_sizer->Add(stat_panel);

	SetSizer(main_sizer);
}

void GameStatPage::update()
{
	string tot_rooms = to_string(game->getRoomsCleared()) + " ",
			tot_boss = to_string(game->getBosses_defeated()) + " ",
			cur_sh_ch = to_string(game->getShopChance()) + "% ",
			curr_r = GET_ROOM(game->getRoomType()) + " ";

	current_room->SetLabel(curr_r);
	rooms_cleared->SetLabel(tot_rooms);
	bosses_defeated->SetLabel(tot_boss);
	shop_chance->SetLabel(cur_sh_ch);
}
