/*
 * HomePage.h
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#ifndef GUI_HOMEPAGE_HOMEPAGE_H_
#define GUI_HOMEPAGE_HOMEPAGE_H_

#include <wx/wx.h>
#include <wx/notebook.h>

class HomePage: public wxPanel{
public:
	HomePage(wxNotebook *parent): wxPanel(parent, wxID_ANY)
    {
        init();
    };
	virtual ~HomePage() {}
private:
	void init();
};

#endif /* GUI_HOMEPAGE_HOMEPAGE_H_ */
