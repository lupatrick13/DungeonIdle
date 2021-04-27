/*
 * SettingsPage.h
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#ifndef GUI_SETTINGSPAGE_SETTINGSPAGE_H_
#define GUI_SETTINGSPAGE_SETTINGSPAGE_H_

#include <wx/wx.h>
#include <wx/notebook.h>

class SettingsPage: public wxPanel{
public:
	SettingsPage(wxNotebook *parent): wxPanel(parent, wxID_ANY)
    {
        init();
    };
	virtual ~SettingsPage() {}
private:
	void init();
};

#endif /* GUI_SETTINGSPAGE_SETTINGSPAGE_H_ */
