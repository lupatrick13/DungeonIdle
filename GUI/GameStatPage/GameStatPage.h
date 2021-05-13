/*
 * GameStatPanel.h
 *
 *  Created on: May 7, 2021
 *      Author: patrick
 */

#ifndef GUI_GAMESTATPAGE_GAMESTATPAGE_H_
#define GUI_GAMESTATPAGE_GAMESTATPAGE_H_

#include <wx/wx.h>
#include "../../Game/DungeonIdle.h"

class GameStatPage: public wxPanel{
public:
	GameStatPage(wxPanel *parent, DungeonIdle *game): wxPanel(parent, wxID_ANY), game(game)
	{
		init();
	};
	virtual ~GameStatPage() {}
	void update();
private:
	void init();
	DungeonIdle *game;
	wxStaticText *current_room, *rooms_cleared,
		*bosses_defeated, *shop_chance;
};
#endif /* GUI_GAMESTATPAGE_GAMESTATPAGE_H_ */
