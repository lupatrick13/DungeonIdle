/*
 * MobPanel.cpp
 *
 *  Created on: May 8, 2021
 *      Author: patrick
 */

#include "MobPanel.h"

void MobPanel::init()
{
	wxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *title_panel = new wxPanel(this, wxID_ANY);
	wxSizer *title_sizer = new wxGridSizer(2,2,1);
	string title =guy->getName() + " ";
	title_label = new wxStaticText(title_panel, wxID_ANY, wxString(title));
	level = new wxStaticText(title_panel, wxID_ANY, wxString(to_string(guy->getLevel())));
	title_sizer->Add(new wxStaticText(title_panel, wxID_ANY, wxString("Name: ")));
	title_sizer->Add(title_label);
	title_sizer->Add(new wxStaticText(title_panel, wxID_ANY, wxString("Lvl. ")));
	title_sizer->Add(level);
	title_panel->SetSizer(title_sizer);


	wxPanel *gauge_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
	wxSizer *gauge_sizer = new wxBoxSizer(wxVERTICAL);

	pair<float, float> HP = make_pair(guy->getCurrentHP(), guy->getMaxHP());
	string EXP = to_string(guy->getEXP());
	HP_G = new wxGauge(gauge_panel, wxID_ANY, HP.second, wxDefaultPosition,
			wxSize(125,10), wxGA_SMOOTH);
	HP_G->SetValue(HP.first);

	string HPlabel = "HP: " + to_string((int)HP.first) + "/" + to_string((int)HP.second) + " ";

	HP_t = new wxStaticText(gauge_panel, wxID_ANY, wxString(HPlabel), wxDefaultPosition,
			wxDefaultSize);
	gauge_sizer->Add(HP_t);
	gauge_sizer->AddSpacer(5);
	gauge_sizer->Add(HP_G);
	gauge_sizer->AddSpacer(5);
	gauge_panel->SetSizer(gauge_sizer);


	wxPanel *stats_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
	wxSizer *stats_sizer = new wxGridSizer(2, 2, 1);
	map<int, int> stats=  guy->getStats();
	string armor_reduc = to_string(guy->getArmorReduc());
	string gold = to_string(guy->getGold());
	armor_reduc = armor_reduc.substr(0, armor_reduc.length()-4);

	wxStaticText *exp_label = new wxStaticText(stats_panel, wxID_ANY, wxString("Exp Gained: "));
	EXP_t = new wxStaticText(stats_panel, wxID_ANY, wxString(EXP), wxDefaultPosition,
			wxDefaultSize);
	wxStaticText *gold_label = new wxStaticText(stats_panel, wxID_ANY, wxString("Drops Gold: "));
	gold_t = new wxStaticText(stats_panel, wxID_ANY, wxString(gold + "g "));
	stats_sizer->Add(exp_label);
	stats_sizer->Add(EXP_t);
	stats_sizer->Add(gold_label);
	stats_sizer->Add(gold_t);
	for(int i = 0; i < 6; i++)
	{
		wxStaticText *label = new wxStaticText(stats_panel, wxID_ANY, wxString(GET_TYPE(i) + ": "));
		stats_t[i] = new wxStaticText(stats_panel, wxID_ANY, wxString(to_string(stats[i])));
		stats_sizer->Add(label);
		stats_sizer->Add(stats_t[i]);
	}
	wxStaticText *label = new wxStaticText(stats_panel, wxID_ANY, wxString("ArmRed: "));
	armor_t = new wxStaticText(stats_panel, wxID_ANY, wxString(armor_reduc + "% "));
	stats_sizer->Add(label);
	stats_sizer->Add(armor_t);

	stats_panel->SetSizer(stats_sizer);

	main_sizer->Add(title_panel);
	main_sizer->Add(gauge_panel);
	main_sizer->Add(stats_panel);

	SetWindowStyle(wxBORDER_RAISED);
	SetBackgroundColour(wxColor(169,169,169));
	SetSizer(main_sizer);
//	Show(false);
}

void MobPanel::update(Mob *newGuy)
{
	guy = newGuy;
	if(guy == nullptr)
	{
		Show(false);
		return;
	}
	string title =guy->getName() + " ";
	pair<float, float> HP = make_pair(guy->getCurrentHP(), guy->getMaxHP());
	string EXP = to_string(guy->getEXP());
	map<int, int> stats=  guy->getStats();
	string armor_reduc = to_string(guy->getArmorReduc());
	string gold = to_string(guy->getGold());
	armor_reduc = armor_reduc.substr(0, armor_reduc.length()-4);
	int hp = HP.first < 0 ? 0 : HP.first;
	string HPlabel = "HP: " + to_string(hp) + "/" + to_string((int)HP.second) + " ";

	title_label->SetLabel(wxString(title));
	level->SetLabel(to_string(guy->getLevel()) + " ");
	HP_G->SetValue(HP.first);
	HP_G->SetRange(HP.second);
	armor_t->SetLabel(wxString(armor_reduc + "% "));
	gold_t->SetLabel(wxString(gold + "g "));
	HP_t->SetLabel(wxString(HPlabel));
	EXP_t->SetLabel(wxString(EXP));
	for(int i = 0; i < 6; i++)
	{
		stats_t[i]->SetLabel(wxString(to_string(stats[i]) + " "));
	}
	Show(true);
}
