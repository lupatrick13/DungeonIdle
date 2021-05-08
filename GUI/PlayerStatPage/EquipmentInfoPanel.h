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
	void update(Equipment *neweqp);


private:
	void init();
	Equipment *equip;
	wxStaticText *value;
	wxStaticText *main_stat;
	wxStaticText *additional_stat[6];
	wxStaticText *modifiers;
	wxStaticText *name_of_eqp;
	wxStaticText *level_of_eqp;
};

#endif /* GUI_PLAYERSTATPAGE_EQUIPMENTINFOPANEL_H_ */
