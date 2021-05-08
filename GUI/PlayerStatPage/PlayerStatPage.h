/*
 * PlayerStatPanel.h
 *
 *  Created on: May 7, 2021
 *      Author: patrick
 */

#ifndef GUI_PlayerSTATPAGE_PlayerSTATPAGE_H_
#define GUI_PlayerSTATPAGE_PlayerSTATPAGE_H_

#include "EquipmentInfoPanel.h"
#include "EquipmentInfoPanel.h"

class PlayerStatPage: public wxPanel{
public:
	PlayerStatPage(wxNotebook *parent, Player *parent_char): wxPanel(parent, wxID_ANY),
		main(parent_char)
	{
		init();
	};
	virtual ~PlayerStatPage() {}
	void update_armor(Equipment *neweqp){armor->update(neweqp); }
	void update_weapon(Equipment *neweqp){weapon->update(neweqp); }
private:
	void init();
	Player *main;
	EquipmentInfoPanel *armor;
	EquipmentInfoPanel *weapon;
};


#endif /* GUI_PlayerSTATPAGE_ STATPAGE_H_ */
