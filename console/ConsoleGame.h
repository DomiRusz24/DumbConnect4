//
// Created by pawel on 18.09.2021.
//

#ifndef CONNECT4_CONSOLEGAME_H
#define CONNECT4_CONSOLEGAME_H

#include <string>
#include <iostream>

#include "../connect4/Connect4Game.h"

using namespace std;

static void clear_screen() {
    string s;
    for (int i = 0; i < 20; i++) s.append("\n");
    cout << s;
}

static int get_input(Box turn) {
    cout << box_to_name(turn) + ": Choose row!" << std::endl;
    string in;
    cin >> in;
    if (is_number(in)) {
        int row = std::stoi(in) - 1;
        if (row > -1 && row < 20) {
            return row;
        } else {
            cout << box_to_name(turn) + ": Please select row from 1 to 20!" << endl;
        }
    } else {
        cout << box_to_name(turn) + ": Please input a correct number!" << endl;
    }
    return -1;
}

class ConsoleGame: public Connect4Game{
public:
    ConsoleGame();

    void display() override;

    void win(Box player) override;

    void _changePlayer(Box player) override;

private:
    bool loop();
};

#endif //CONNECT4_CONSOLEGAME_H
