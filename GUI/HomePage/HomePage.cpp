/*
 * HomePage.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#include "HomePage.h"

void HomePage::init()
{
	vector<string> *status = game->get_status();
	wxPanel *status_texts = new wxPanel(this, wxID_ANY);
	wxSizer *status_texts_3=  new wxBoxSizer(wxHORIZONTAL);

	for(int i=0;i<3;i++)
	{
		wxPanel *status_panel = new wxPanel(status_texts, wxID_ANY,wxDefaultPosition, wxSize(200,50));
		status_t[i] = new wxStaticText(status_panel, wxID_ANY, wxString(status->at(i)));
		status_texts_3->Add(status_panel);
		status_panel->SetWindowStyle(wxBORDER_RAISED);
		status_panel->SetBackgroundColour(wxColor(169,169,169));
	}

	status_texts->SetSizer(status_texts_3);

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
	player = new PlayerPanel(info_panel, game->getPlayer());
	mob = new MobPanel(info_panel, game->getMob());
	drop = new EquipmentInfoPanel(info_panel, nullptr, StatType::ARMOR);
	info_sizer->Add(player,0 ,0, 0);
	info_sizer->Add(drop,0, 0,0);
	info_sizer->Add(mob,0, 0, 0);
	info_panel->SetSizer(info_sizer);

//	mob->Show(false);
//	drop->Show(false);


	main_sizer->Add(step_counter_panel, 0, wxALIGN_CENTER, 0);
	main_sizer->Add(statepanel,0, wxALIGN_CENTER, 0);
	main_sizer->Add(status_texts,0,wxALIGN_CENTER,0);
	main_sizer->Add(info_panel,0, wxALIGN_CENTER, 0);

	SetSizer(main_sizer);
}


void HomePage::update_boss_counter()
{
	int count = game->getBossCd();
	count = count == 10 ? 0 : count;
	boss_cd->SetLabel(wxString(to_string(count) + " "));
}

play_state HomePage::handle_choice(int choice2)
{
	vector<string> *status = game->get_status();
	play_state prev = choice->handle_choice(choice2);
	mob->update(game->getMob());

	if(prev == play_state::OFFER || prev == play_state::LOOT)
	{
		Equipment *item = game->getEqp();
		int type = StatType::AGI;
		if(item!= nullptr)
			type = item->get_base_stat().first;
		drop->update(item, type);
	}
	if(prev == play_state::DONE)
	{
		mob->update(nullptr);
		update_boss_counter();
		drop->update(nullptr, 4);
	}
	for(string stat : *status)
	{
		cout << stat << endl;
	}
	for(int i=0;i<3;i++)
		status_t[i]->SetLabel(wxString(status->at(i)));
	player->update();

	return prev;
}
