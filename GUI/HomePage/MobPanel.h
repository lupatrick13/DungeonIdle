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
	void update(Mob *newGuy);


private:
	void init();
	wxStaticText *level, *HP_t, *EXP_t, *gold_t,*armor_t, *title_label, *stats_t[6];
	wxGauge *HP_G;
	Mob *guy;
};
#endif /* GUI_HOMEPAGE_MOBPANEL_H_ */
