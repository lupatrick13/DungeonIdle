/*
 * HomePage.h
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#ifndef GUI_HOMEPAGE_HOMEPAGE_H_
#define GUI_HOMEPAGE_HOMEPAGE_H_

#include "DungeonState/AllStates.h"

class HomePage: public wxPanel{
public:
	HomePage(wxNotebook *parent, DungeonIdle *game): wxPanel(parent, wxID_ANY), game(game)
    {
        init();
    };
	virtual ~HomePage() {}
private:
	void init();
	DungeonIdle *game;
	DungeonPanel *dungeon;
	ChoicePanel *choice;
};

#endif /* GUI_HOMEPAGE_HOMEPAGE_H_ */
