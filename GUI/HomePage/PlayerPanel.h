/*
 * PlayerPanel.h
 *
 *  Created on: May 8, 2021
 *      Author: patrick
 */

#ifndef GUI_HOMEPAGE_PlayerPANEL_H_
#define GUI_HOMEPAGE_PlayerPANEL_H_

#include <wx/wx.h>
#include "../../Game/DungeonIdle.h"
class PlayerPanel: public wxPanel {
public:
	PlayerPanel(wxPanel *parent, Player *guy):
		wxPanel(parent, wxID_ANY, wxDefaultPosition),
		guy(guy)
	{
		init();
	}
	virtual ~PlayerPanel() {}
	void update();


private:
	void init();
	Player *guy;
};

#endif /* GUI_HOMEPAGE_PlayerPANEL_H_ */
