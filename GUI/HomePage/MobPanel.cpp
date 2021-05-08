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

	wxPanel *statepanel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
	wxSizer *state_sizer = new wxBoxSizer(wxVERTICAL);
;

	SetSizer(main_sizer);
}
