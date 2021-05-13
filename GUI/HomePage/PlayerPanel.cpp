/*
 * PlayerPanel.cpp
 *
 *  Created on: May 8, 2021
 *      Author: patrick
 */

#include "PlayerPanel.h"

void PlayerPanel::init()
{
	wxSizer *main1_sizer = new wxBoxSizer(wxVERTICAL);


	wxPanel *title_panel = new wxPanel(this, wxID_ANY);
	wxSizer *title_sizer = new wxGridSizer(2,2,1);
	string title =guy->getName() + " ";
	wxStaticText *title_label = new wxStaticText(title_panel, wxID_ANY, wxString(title));
	level = new wxStaticText(title_panel, wxID_ANY, wxString(to_string(guy->getLevel())));
	title_sizer->Add(new wxStaticText(title_panel, wxID_ANY, wxString("Name: ")));
	title_sizer->Add(title_label);
	title_sizer->Add(new wxStaticText(title_panel, wxID_ANY, wxString("Lvl. ")));
	title_sizer->Add(level);
	title_panel->SetSizer(title_sizer);


	wxPanel *gauge_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
	wxSizer *gauge_sizer = new wxBoxSizer(wxVERTICAL);

	pair<float, float> HP = make_pair(guy->getCurrentHP(), guy->getMaxHP());
	pair<int,int> EXP = make_pair(guy->getEXP(), guy->getLevelUpExp());

	EXP_G = new wxGauge(gauge_panel, wxID_ANY, EXP.second, wxDefaultPosition,
			wxSize(125,10), wxGA_SMOOTH);
	EXP_G->SetValue(EXP.first);
	HP_G = new wxGauge(gauge_panel, wxID_ANY, HP.second, wxDefaultPosition,
			wxSize(125,10), wxGA_SMOOTH);
	HP_G->SetValue(HP.first);

	string HPlabel = "HP: " + to_string((int)HP.first) + "/" + to_string((int)HP.second) + " ";
	string EXPlabel ="EXP: " + to_string(EXP.first) + "/" + to_string(EXP.second) + " ";

	HP_t = new wxStaticText(gauge_panel, wxID_ANY, wxString(HPlabel), wxDefaultPosition,
			wxDefaultSize);
	EXP_t = new wxStaticText(gauge_panel, wxID_ANY, wxString(EXPlabel), wxDefaultPosition,
			wxDefaultSize);
	gauge_sizer->Add(HP_t);
	gauge_sizer->AddSpacer(5);
	gauge_sizer->Add(HP_G);
	gauge_sizer->AddSpacer(5);
	gauge_sizer->Add(EXP_t);
	gauge_sizer->AddSpacer(5);
	gauge_sizer->Add(EXP_G);
	gauge_panel->SetSizer(gauge_sizer);


	wxPanel *stats_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
	wxSizer *stats_sizer = new wxGridSizer(2, 2, 1);
	map<int, int> stats=  guy->getStats();
	string armor_reduc = to_string(guy->getArmorReduc());
	string gold = to_string(guy->getGold());
	armor_reduc = armor_reduc.substr(0, armor_reduc.length()-4);

	wxStaticText *gold_label = new wxStaticText(stats_panel, wxID_ANY, wxString("Gold: "));
	gold_t = new wxStaticText(stats_panel, wxID_ANY, wxString(gold + "g "));
	stats_sizer->Add(gold_label);
	stats_sizer->Add(gold_t);
	for(int i = 0; i < 6; i++)
	{
		wxStaticText *label = new wxStaticText(stats_panel, wxID_ANY, wxString(GET_TYPE(i) + ": "));
		stats_t[i] = new wxStaticText(stats_panel, wxID_ANY, wxString(to_string(stats[i]) + " "));
		stats_sizer->Add(label);
		stats_sizer->Add(stats_t[i]);
	}
	wxStaticText *label = new wxStaticText(stats_panel, wxID_ANY, wxString("ArmRed: "));
	armor_t = new wxStaticText(stats_panel, wxID_ANY, wxString(armor_reduc + "% "));
	stats_sizer->Add(label);
	stats_sizer->Add(armor_t);

	stats_panel->SetSizer(stats_sizer);

	main1_sizer->Add(title_panel);
	main1_sizer->Add(gauge_panel);
	main1_sizer->Add(stats_panel);

	SetWindowStyle(wxBORDER_RAISED);
	SetBackgroundColour(wxColor(169,169,169));
	SetSizer(main1_sizer);
}

void PlayerPanel::update(){
	pair<float, float> HP = make_pair(guy->getCurrentHP(), guy->getMaxHP());
	pair<int,int> EXP = make_pair(guy->getEXP(), guy->getLevelUpExp());
	map<int, int> stats=  guy->getStats();
	string armor_reduc = to_string(guy->getArmorReduc());
	string gold = to_string(guy->getGold());
	armor_reduc = armor_reduc.substr(0, armor_reduc.length()-4);
	string HPlabel = "HP: " + to_string((int)HP.first) + "/" + to_string((int)HP.second) + " ";
	string EXPlabel ="EXP: " + to_string(EXP.first) + "/" + to_string(EXP.second) + " ";

	level->SetLabel(to_string(guy->getLevel()) + " ");
	HP_G->SetValue(HP.first);
	EXP_G->SetValue(EXP.first);
	HP_G->SetRange(HP.second);
	EXP_G->SetRange(EXP.second);
	armor_t->SetLabel(wxString(armor_reduc + "% "));
	gold_t->SetLabel(wxString(gold + "g "));
	HP_t->SetLabel(wxString(HPlabel));
	EXP_t->SetLabel(wxString(EXPlabel));
	for(int i = 0; i < 6; i++)
	{
		stats_t[i]->SetLabel(wxString(to_string(stats[i]) + " "));
	}
}
