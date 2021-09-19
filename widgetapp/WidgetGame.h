//
// Created by pawel on 18.09.2021.
//

#ifndef CONNECT4_WIDGETGAME_H
#define CONNECT4_WIDGETGAME_H

#include "../connect4/Connect4Game.h"

class cMain;

class WidgetGame: public Connect4Game {
private:
    cMain* m_frame1 = nullptr;
public:
    WidgetGame();

    ~WidgetGame();

    void display() override;

    void _changePlayer(Box player) override;

    void win(Box player) override;
};


#endif //CONNECT4_WIDGETGAME_H
