/*
 * HomePage.h
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#ifndef GUI_HOMEPAGE_HOMEPAGE_H_
#define GUI_HOMEPAGE_HOMEPAGE_H_

#include "ChoicePanel.h"
#include "PlayerPanel.h"
#include "MobPanel.h"
#include "../PlayerStatPage/EquipmentInfoPanel.h"

class HomePage: public wxPanel{
public:
	HomePage(wxNotebook *parent, DungeonIdle *game): wxPanel(parent, wxID_ANY), game(game)
    {
        init();
    };
	virtual ~HomePage() {}
	play_state handle_choice(int choice2);

	ChoicePanel *choice;

private:
	void init();
	void update_boss_counter();
	wxStaticText *boss_cd, *status_t[3];
	DungeonIdle *game;
	PlayerPanel *player;
	MobPanel *mob;
	EquipmentInfoPanel *drop;
};

#endif /* GUI_HOMEPAGE_HOMEPAGE_H_ */
