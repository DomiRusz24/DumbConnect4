//
// Created by pawel on 18.09.2021.
//

#ifndef CONNECT4_WIDGETAPP_H
#define CONNECT4_WIDGETAPP_H

#include "WidgetGame.h"
#include "wx/wx.h"

class WidgetApp: public wxApp {
public:
    WidgetApp();
    ~WidgetApp();

public:
    virtual bool OnInit();

private:
    WidgetGame *main_game = nullptr;
};

#endif //CONNECT4_WIDGETAPP_H
