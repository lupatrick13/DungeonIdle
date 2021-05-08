/*
 * EquipmentInfoPanel.cpp
 *
 *  Created on: May 7, 2021
 *      Author: patrick
 */

#include "EquipmentInfoPanel.h"

void EquipmentInfoPanel::init()
{
	wxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);

	map<int, float> additional_stats = equip->get_additional();
	pair<int, float> base_stat = equip->get_base_stat();
	int level = equip->get_level();
	string eqp_value = to_string((int)equip->get_value());
	string name = equip->get_name() + " ";
	string mods = equip->description();
	Rarity rarity = equip->get_rarity();

	wxPanel *beginning_panel = new wxPanel(this, wxID_ANY);
	wxSizer *beg_sizer = new wxBoxSizer(wxVERTICAL);
	modifiers = new wxStaticText(beginning_panel, wxID_ANY, wxString(mods));
	name_of_eqp = new wxStaticText(beginning_panel, wxID_ANY, wxString(name),
			wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	level_of_eqp = new wxStaticText(beginning_panel, wxID_ANY, wxString("Lvl. " + to_string(level) + " "));

	name_of_eqp->SetForegroundColour(*RARITY_COLOUR(rarity));
	modifiers->SetForegroundColour(*RARITY_COLOUR(rarity));
	beg_sizer->Add(modifiers);
	beg_sizer->Add(name_of_eqp);
	beg_sizer->Add(level_of_eqp);
	beginning_panel->SetSizer(beg_sizer);

	wxStaticText *value_label = new wxStaticText(this, wxID_ANY, wxString("Value:"));
	value = new wxStaticText(this, wxID_ANY, wxString(eqp_value));
	wxSizer *base_sizer= new wxGridSizer(2,2,1);
	wxStaticText *base_stat_name = new wxStaticText(this, wxID_ANY,
			wxString(GET_TYPE(base_stat.first) + ":"));
	main_stat = new wxStaticText(this, wxID_ANY,
			wxString(to_string((int)base_stat.second)));

	base_sizer->Add(value_label);
	base_sizer->Add(value);
	base_sizer->Add(base_stat_name);
	base_sizer->Add(main_stat);

	wxStaticText *bonus_label = new wxStaticText(this, wxID_ANY, wxString("Bonus Stats!"));
	wxSizer *additional_stat_sizer = new wxGridSizer(2,2,1);
	wxStaticText *stat_label[6];
	for(int i = 0; i < 6; i++)
	{
		stat_label[i] = new wxStaticText(this, wxID_ANY, wxString(GET_TYPE(i) + ":"));
		additional_stat[i] = new wxStaticText(this, wxID_ANY,
			wxString(to_string((int)additional_stats[i])));
		additional_stat_sizer->Add(stat_label[i]);
		additional_stat_sizer->Add(additional_stat[i]);
	}

	main_sizer->Add(beginning_panel);
	main_sizer->AddSpacer(5);
	main_sizer->Add(base_sizer);
	main_sizer->AddSpacer(5);
	main_sizer->Add(bonus_label);
	main_sizer->Add(additional_stat_sizer);

	SetWindowStyle(wxBORDER_RAISED);
	SetBackgroundColour(wxColor(169,169,169));
	SetSizer(main_sizer);
}

void EquipmentInfoPanel::update(Equipment *neweqp)
{
	equip = neweqp;
	map<int, float> additional_stats = equip->get_additional();
	pair<int, float> base_stat = equip->get_base_stat();
	int level = equip->get_level();
	string eqp_value = to_string((int)equip->get_value());
	string name = equip->get_name() + " ";
	string mods = equip->description();
	Rarity rarity = equip->get_rarity();

	name_of_eqp->SetLabel(name);
	name_of_eqp->SetForegroundColour(*RARITY_COLOUR(rarity));
	modifiers->SetLabel(mods);
	modifiers->SetForegroundColour(*RARITY_COLOUR(rarity));
	value->SetLabel(eqp_value);
	main_stat->SetLabel(wxString(to_string((int)base_stat.second)));
	level_of_eqp->SetLabel(wxString(to_string(level)));

	for(int i = 0; i < 6; i++)
	{
		additional_stat[i]->SetLabel(wxString(to_string((int)additional_stats[i])));
	}

}
