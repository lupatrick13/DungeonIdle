/*
 * GameStatPanel.h
 *
 *  Created on: May 7, 2021
 *      Author: patrick
 */

#ifndef GUI_GAMESTATPAGE_GAMESTATPAGE_H_
#define GUI_GAMESTATPAGE_GAMESTATPAGE_H_

#include <wx/wx.h>
#include <wx/notebook.h>
#include "../../Game/DungeonIdle.h"

class GameStatPage: public wxPanel{
public:
	GameStatPage(wxNotebook *parent, DungeonIdle *game): wxPanel(parent, wxID_ANY), game(game)
	{
		init();
	};
	virtual ~GameStatPage() {}
private:
	void init();
	DungeonIdle *game;
};
#endif /* GUI_GAMESTATPAGE_GAMESTATPAGE_H_ */
