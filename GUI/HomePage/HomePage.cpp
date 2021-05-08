/*
 * HomePage.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#include "HomePage.h"

void HomePage::init()
{
	wxSizer *main_sizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *statepanel = new wxPanel(this, wxID_ANY, wxDefaultPosition);
	wxSizer *state_sizer = new wxBoxSizer(wxVERTICAL);
	choice = new ChoicePanel(statepanel, game);
	state_sizer->Add(choice, 0, wxALIGN_CENTRE_HORIZONTAL, 0);
	statepanel->SetSizer(state_sizer);



	wxStaticText *title = new wxStaticText(this, wxID_ANY, "Home", wxPoint(-10, 0),
    		wxSize(400,25), wxALIGN_CENTRE_HORIZONTAL| wxST_NO_AUTORESIZE);
	title->SetFont(title->GetFont().Larger().Larger());

	main_sizer->Add(title, 0, wxALIGN_CENTER, 0);
	main_sizer->Add(statepanel,0, wxALIGN_CENTER, 0);

	SetSizer(main_sizer);
}

