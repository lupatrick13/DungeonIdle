/*
 * ChoicePanel.cpp
 *
 *  Created on: May 1, 2021
 *      Author: patrick
 */

#include "ChoicePanel.h"

void ChoicePanel::init()
{
	curr_state = play_state::DONE;
	wxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);

	game->generate_choice();
	choices = game->get_choice();

	wxPanel *button_panel  =new wxPanel(this, wxID_ANY, wxDefaultPosition);
	wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 wxT("Choose:"));
	choice_button[0] = new wxButton(button_panel, actionID::roomc0, wxString(GET_ROOM(choices[0])));
	choice_button[0]->SetBackgroundColour(wxColor(128,128,128));
	choice_button[1] = new wxButton(button_panel, actionID::roomc1, wxString(GET_ROOM(choices[1])));
	choice_button[1]->SetBackgroundColour(wxColor(128,128,128));
	choice_button[2] = new wxButton(button_panel, actionID::roomc2, wxString(GET_ROOM(choices[2])));
	choice_button[2]->SetBackgroundColour(wxColor(128,128,128));
//
//    choice_button[0]->Bind(wxEVT_BUTTON, &ChoicePanel::on_zero, this);
//    choice_button[1]->Bind(wxEVT_BUTTON, &ChoicePanel::on_one, this);
//    choice_button[2]->Bind(wxEVT_BUTTON, &ChoicePanel::on_two, this);

    choose_text->SetFont(choose_text->GetFont().Larger());
    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(choice_button[0], 0 ,0 ,0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(choice_button[1], 0 ,0 ,0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(choice_button[2], 0 ,0 ,0);
    button_sizer->AddSpacer(5);
    button_panel->SetSizer(button_sizer);
    button_panel->SetBackgroundColour(wxColor(169,169,169));
	button_panel->SetForegroundColour(*wxBLACK);
	button_panel->SetWindowStyle(wxBORDER_RAISED);

	status_text = new wxStaticText(this, wxID_ANY, "Delving deep in to the dungeon...",
			wxDefaultPosition,wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL| wxST_NO_AUTORESIZE);

	main_sizer->Add(status_text, 0, wxALIGN_CENTER,0);
	main_sizer->AddSpacer(10);
	main_sizer->Add(button_panel, 0, 0, 0);
	SetSizer(main_sizer);
}

void ChoicePanel::handle_choice(int choice)
{
	if(curr_state == play_state::DONE)
	{
		game->generate_room(choice);
	    curr_state = game->play();
	}
	else if(curr_state == play_state::CONTINUE)
	{
		curr_state = game->play();
	}
	else if(curr_state == play_state::LOOT)
	{
		curr_state = game->play(choice+1);
	}
	else if(curr_state == play_state::OFFER)
	{
		curr_state = game->play(choice+1);
	}
	handle_buttonUI();
	GetSizer()->Layout();
}

void ChoicePanel::handle_buttonUI()
{

	if(curr_state == play_state::DONE)
	{
		game->generate_choice();
		choices = game->get_choice();
	    for(int i = 0; i < 3; i++)
	    {
	    	choice_button[i]->SetLabel(wxString(GET_ROOM(choices[i])));
	    	choice_button[i]->Show(true);
	    }
	    status_text->SetLabel("Where does this room take us?");
	}
	else if(curr_state == play_state::CONTINUE)
	{
		choice_button[0]->Show(true);
		choice_button[1]->Show(false);
		choice_button[2]->Show(false);
		choice_button[0]->SetLabel("Continue!");
		status_text->SetLabel("Delving deep into the dungeon...");
	}
	else if(curr_state == play_state::LOOT)
	{
		choice_button[0]->Show(true);
		choice_button[1]->Show(true);
		choice_button[2]->Show(false);
		choice_button[0]->SetLabel("Take");
		choice_button[1]->SetLabel("Leave");
		map<string, string> loot = game->get_loot();
		status_text->SetLabel(loot["loot"]);
	}
	else if(curr_state == play_state::OFFER)
	{
		choice_button[0]->Show(true);
		choice_button[1]->Show(true);
		choice_button[2]->Show(true);
		choice_button[0]->SetLabel("Heal!");
		choice_button[1]->SetLabel("Boost!");
		choice_button[2]->SetLabel("Equip!");
		map<string, string> loot = game->get_loot();
		status_text->SetLabel(loot["Heal"] + " " + loot["Boost"]);
	}
}
