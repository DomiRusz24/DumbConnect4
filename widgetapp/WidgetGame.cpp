//
// Created by pawel on 18.09.2021.
//

#include "WidgetGame.h"
#include "cMain.h"


WidgetGame::WidgetGame() : Connect4Game() {
    m_frame1 = new cMain(this);
    m_frame1->Show();
}

WidgetGame::~WidgetGame() {

}

void WidgetGame::display() {
    m_frame1->display();
}

void WidgetGame::win(Box player) {
    m_frame1->win(player);
}

void WidgetGame::_changePlayer(Box player) {
    m_frame1->changePlayer(player);
}
