/*
 * PlayerStatPanel.h
 *
 *  Created on: May 7, 2021
 *      Author: patrick
 */

#ifndef GUI_PlayerSTATPAGE_PlayerSTATPAGE_H_
#define GUI_PlayerSTATPAGE_PlayerSTATPAGE_H_

#include "EquipmentInfoPanel.h"
#include "../GameStatPage/GameStatPage.h"

class PlayerStatPage: public wxPanel{
public:
	PlayerStatPage(wxNotebook *parent, DungeonIdle *parent_char): wxPanel(parent, wxID_ANY),
		game(parent_char)
	{
		main = game->getPlayer();
		init();
	};
	virtual ~PlayerStatPage() {}
	void update()
	{
		armor->update(main->getSet().first);
		weapon->update(main->getSet().second);
		gamestats->update();
	}
private:
	void init();
	DungeonIdle *game;
	Player *main;
	GameStatPage *gamestats;
	EquipmentInfoPanel *armor;
	EquipmentInfoPanel *weapon;
};


#endif /* GUI_PlayerSTATPAGE_ STATPAGE_H_ */
