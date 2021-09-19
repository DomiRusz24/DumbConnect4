
#include <string>
#include <iostream>

#include "../connect4/Connect4Game.h"
#include "ConsoleGame.h"

using namespace std;

#ifdef _WIN32
#include <windows.h>
void sleep(unsigned milliseconds)
{
    Sleep(milliseconds);
}
#else
#include <unistd.h>

    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000);
    }
#endif

ConsoleGame::ConsoleGame() : Connect4Game() {
    display();
    while (true) {
        if (!loop()) {
            sleep(3000);
            break;
        }
    }
}

bool ConsoleGame::loop() {
    if (get_turn() == empty_box) {
        return false;
    }
    int col = -1;
    while (col == -1) {
        col = get_input(get_turn());
    }
    progress(col);
    return true;
}

void ConsoleGame::win(Box player) {
    cout << box_to_name(player) + " has won!" << endl;
}

void ConsoleGame::display() {
    clear_screen();
    string s = "+----------- " + box_to_name(get_turn()) + "'s turn -----------+";
    s.append("\n");
    for (auto &slot : slots) {
        for (auto &e: slot) {
            s.append("|" + box_to_char(e));
        }
        s.append("|\n");
    }
    s.append("+---------------------------------------+");
    s.append("\n");
    cout << s;
}

void ConsoleGame::_changePlayer(Box player) {}
