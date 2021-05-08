/*
 * EquipStatPanel.cpp
 *
 *  Created on: May 7, 2021
 *      Author: patrick
 */

#include "PlayerStatPage.h"

void PlayerStatPage::init()
{
	wxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText *title = new wxStaticText(this, wxID_ANY, "Player Stats", wxPoint(-10, 0),
    		wxSize(400,25), wxALIGN_CENTRE_HORIZONTAL| wxST_NO_AUTORESIZE);
	title->SetFont(title->GetFont().Larger());

	wxPanel *eqp_panel = new wxPanel(this, wxID_ANY);
	wxSizer *eqp_sizer = new wxBoxSizer(wxHORIZONTAL);
	Equipment *sword = new Equipment(DMG, epic, "Excalibur", 10000, 200, 999);
	Equipment *shield = new Equipment(ARMOR, legendary, "Table", 21, 200, 3);

	sword = new Perfect(sword);
	shield = new Sharp(shield);
	armor = new EquipmentInfoPanel(eqp_panel, shield);
	weapon = new EquipmentInfoPanel(eqp_panel, sword);
	eqp_sizer->Add(armor);
	eqp_sizer->Add(weapon);
	eqp_panel->SetSizer(eqp_sizer);

	main_sizer->Add(title);
	main_sizer->Add(eqp_panel);
	SetSizer(main_sizer);

}
