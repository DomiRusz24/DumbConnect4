//
// Created by pawel on 18.09.2021.
//

#ifndef CONNECT4_CMAIN_H
#define CONNECT4_CMAIN_H

#include "wx/wx.h"
#include "../connect4/Connect4Game.h"

class WidgetGame;

class cMain : public wxFrame {
public:
    cMain(WidgetGame* game);
    ~cMain();

    void display();

    void win(Box player);

private:

    wxBoxSizer *main_sizer;
    wxGridSizer *choose_slot;
    wxGridSizer *board;

    wxButton **choose_buttons;
    wxWindow **squares;

    Box current_turn;

    WidgetGame* game;

public:
    void changePlayer(Box player);
    void button_click(wxCommandEvent &evt);
    void button_hover(wxMouseEvent &evt);
    void button_not_hover(wxMouseEvent &evt);

    wxDECLARE_EVENT_TABLE();
};


#endif //CONNECT4_CMAIN_H
