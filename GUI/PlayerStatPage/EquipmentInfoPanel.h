/*
 * EquipmentInfoPanel.h
 *
 *  Created on: May 7, 2021
 *      Author: patrick
 */

#ifndef GUI_PLAYERSTATPAGE_EQUIPMENTINFOPANEL_H_
#define GUI_PLAYERSTATPAGE_EQUIPMENTINFOPANEL_H_

#include <wx/wx.h>
#include <wx/notebook.h>
#include "../../Game/DungeonIdle.h"

class EquipmentInfoPanel: public wxPanel {
public:
	EquipmentInfoPanel(wxPanel *parent, Equipment *eqp):
		wxPanel(parent, wxID_ANY, wxDefaultPosition),
		equip(eqp)
	{
		init();
	}
	virtual ~EquipmentInfoPanel() {}
	wxStaticText *eqp_name;
	wxStaticText *value;
	wxStaticText *main_stat;
	wxStaticText *additional_stat[6];

private:
	void init();
	Equipment *equip;
};

#endif /* GUI_PLAYERSTATPAGE_EQUIPMENTINFOPANEL_H_ */
