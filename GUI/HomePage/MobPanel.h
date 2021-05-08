/*
 * MobPanel.h
 *
 *  Created on: May 8, 2021
 *      Author: patrick
 */

#ifndef GUI_HOMEPAGE_MOBPANEL_H_
#define GUI_HOMEPAGE_MOBPANEL_H_

#include <wx/wx.h>
#include "../../Game/DungeonIdle.h"
class MobPanel: public wxPanel {
public:
	MobPanel(wxPanel *parent, Mob *guy):
		wxPanel(parent, wxID_ANY, wxDefaultPosition),
		guy(guy)
	{
		init();
	}
	virtual ~MobPanel() {}
	void update();


private:
	void init();
	Mob *guy;
};
#endif /* GUI_HOMEPAGE_MOBPANEL_H_ */
