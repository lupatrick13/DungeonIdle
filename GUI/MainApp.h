/*
 * MainApp.h
 *
 *  Created on: Apr 26, 2021
 *      Author: patrick
 */

#ifndef GUI_MAINAPP_H_
#define GUI_MAINAPP_H_

#include <iostream>
#include <wx/wx.h>
#include "MainFrame.h"

using namespace std;

class MainApp: public wxApp
{
public:
    virtual bool OnInit() override;
    virtual ~MainApp(){};
};

#endif /* GUI_MAINAPP_H_ */
