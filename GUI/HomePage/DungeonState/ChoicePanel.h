/*
 * ChoicePanel.h
 *
 *  Created on: May 1, 2021
 *      Author: patrick
 */

#ifndef GUI_HOMEPAGE_DUNGEONSTATE_CHOICEPANEL_H_
#define GUI_HOMEPAGE_DUNGEONSTATE_CHOICEPANEL_H_

#include <wx/wx.h>
#include <wx/notebook.h>
#include "../../../Game/DungeonIdle.h"
#include "../../ActionID.h"

class ChoicePanel: public wxPanel {
public:
	ChoicePanel(wxPanel *parent, DungeonIdle* game): wxPanel(parent, wxID_ANY), game(game)
    {
        init();
    };
	virtual ~ChoicePanel() {}
	void on_one(wxCommandEvent& event);
	void on_two(wxCommandEvent& event);
	void on_zero(wxCommandEvent& event);

private:
	DungeonIdle *game;
	std::vector<room_type> choices;
	play_state curr_state;
	wxButton *choice_button[3];
	wxStaticText *status_text;
	void init();
	void handle_choice(int choice);
	void handle_buttonUI();
};

#endif /* GUI_HOMEPAGE_DUNGEONSTATE_CHOICEPANEL_H_ */
