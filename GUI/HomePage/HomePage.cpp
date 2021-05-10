/*
 * HomePage.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#include "HomePage.h"

void HomePage::init()
{
	wxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *statepanel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
	wxSizer *state_sizer = new wxBoxSizer(wxVERTICAL);
	choice = new ChoicePanel(statepanel, game);
	state_sizer->Add(choice, 0, wxALIGN_CENTRE_HORIZONTAL, 0);
	statepanel->SetSizer(state_sizer);


	wxPanel *step_counter_panel = new wxPanel(this,wxID_ANY);
	wxSizer *step_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *step_label = new wxStaticText(step_counter_panel, wxID_ANY,wxString( "Steps til boss: "),
		wxPoint(-10, 0),wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL| wxST_NO_AUTORESIZE);


	step_label->SetFont(step_label->GetFont().Bold());
	boss_cd = new wxStaticText(step_counter_panel, wxID_ANY, wxString(to_string(game->getBossCd()) + " "));
	boss_cd->SetFont(step_label->GetFont());
	step_sizer->Add(step_label, 0, wxALIGN_RIGHT, 0);
	step_sizer->Add(boss_cd, 0, wxALIGN_LEFT,0);
	step_counter_panel->SetSizer(step_sizer);


	wxPanel *info_panel = new wxPanel(this,wxID_ANY);
	wxSizer *info_sizer = new wxBoxSizer(wxHORIZONTAL);
	player = new PlayerPanel(info_panel, new Player());
	mob = new MobPanel(info_panel, nullptr);
	drop = new EquipmentInfoPanel(info_panel, nullptr);
	info_sizer->Add(player,0 ,0, 0);
	info_sizer->Add(drop,0, 0,0);
	info_sizer->Add(mob,0, 0, 0);
	info_panel->SetSizer(info_sizer);


	main_sizer->Add(step_counter_panel, 0, wxALIGN_CENTER, 0);
	main_sizer->Add(statepanel,0, wxALIGN_CENTER, 0);
	main_sizer->Add(info_panel,0, wxALIGN_CENTER, 0);

	SetSizer(main_sizer);
}


void HomePage::update_boss_counter()
{
	int count = game->getBossCd();
	count = count == 10 ? 0 : count;
	boss_cd->SetLabel(wxString(to_string(count) + " "));
}

void HomePage::handle_choice(int choice2)
{
	choice->handle_choice(choice2);
	update_boss_counter();
}
