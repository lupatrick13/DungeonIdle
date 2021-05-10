/*
 * SettingsPage.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#include "SettingsPage.h"

void SettingsPage::init()
{
	wxSizer *main_sizer = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText *title = new wxStaticText(this, wxID_ANY, "Settings", wxPoint(-10, 0),
    		wxSize(400,25), wxALIGN_CENTRE_HORIZONTAL| wxST_NO_AUTORESIZE);
	title->SetFont(title->GetFont().Larger().Larger());

	main_sizer->Add(title, 0, wxALIGN_CENTER, 0);

	SetSizer(main_sizer);
}

