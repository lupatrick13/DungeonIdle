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

	gamestats = new GameStatPage(this, game);
	wxStaticText *title = new wxStaticText(this, wxID_ANY, "Player Stats", wxPoint(-10, 0),
    		wxSize(400,25), wxALIGN_CENTRE_HORIZONTAL| wxST_NO_AUTORESIZE);
	title->SetFont(title->GetFont().Larger());

	wxPanel *eqp_panel = new wxPanel(this, wxID_ANY);
	wxSizer *eqp_sizer = new wxBoxSizer(wxHORIZONTAL);

	pair<Equipment *, Equipment *> armorset = main->getSet();
	armor = new EquipmentInfoPanel(eqp_panel, armorset.first, StatType::ARMOR);
	weapon = new EquipmentInfoPanel(eqp_panel, armorset.second, StatType::DMG);
	eqp_sizer->Add(armor);
	eqp_sizer->Add(weapon);
	eqp_panel->SetSizer(eqp_sizer);

	main_sizer->Add(title);
	main_sizer->Add(gamestats);
	main_sizer->Add(eqp_panel);
	SetSizer(main_sizer);

}
