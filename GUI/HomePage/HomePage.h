/*
 * HomePage.h
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#ifndef GUI_HOMEPAGE_HOMEPAGE_H_
#define GUI_HOMEPAGE_HOMEPAGE_H_

#include "ChoicePanel.h"

class HomePage: public wxPanel{
public:
	HomePage(wxNotebook *parent, DungeonIdle *game): wxPanel(parent, wxID_ANY), game(game)
    {
        init();
    };
	virtual ~HomePage() {}
	void handle_choice(int choice2) { choice->handle_choice(choice2);}
	ChoicePanel *choice;
private:
	void init();
	DungeonIdle *game;
};

#endif /* GUI_HOMEPAGE_HOMEPAGE_H_ */
