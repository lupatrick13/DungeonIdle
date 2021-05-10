/*
 * DungeonPanel.h
 *
 *  Created on: May 1, 2021
 *      Author: patrick
 */

#ifndef GUI_HOMEPAGE_DUNGEONSTATE_DUNGEONPANEL_H_
#define GUI_HOMEPAGE_DUNGEONSTATE_DUNGEONPANEL_H_

#include <wx/wx.h>
#include <wx/notebook.h>
#include "../../../Game/DungeonIdle.h"
#include "../../ActionID.h"

class DungeonPanel: public wxPanel {
public:
	DungeonPanel(wxPanel *parent, DungeonIdle* game): wxPanel(parent, wxID_ANY), game(game)
    {
        init();
    };
	virtual ~DungeonPanel() {}
	void on_click(wxCommandEvent& event);
private:
	DungeonIdle *game;
	wxButton *fight_button;
	void init();
};

#endif /* GUI_HOMEPAGE_DUNGEONSTATE_DUNGEONPANEL_H_ */
