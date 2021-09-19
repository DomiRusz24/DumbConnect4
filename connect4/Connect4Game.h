#ifndef CONNECT4_CONNECT4GAME_H
#define CONNECT4_CONNECT4GAME_H

#include <string>
#include <iostream>

enum Box{player1, player2, empty_box};

static std::string box_to_char(Box type) {
    switch(type) {
        case player1:
            return "X";
        case player2:
            return "O";
        case empty_box:
            return " ";
        default:
            return " ";
    }
}

static std::string box_to_name(Box type) {
    switch(type) {
        case player1:
            return "Player 1";
        case player2:
            return "Player 2";
        case empty_box:
            return "No one";
        default:
            return "No one";
    }
}

static bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

struct vector2 {
    int column;
    int row;
};

static vector2 get_corner_column_and_row(int column, int row) {
    vector2 vec = vector2();
    vec.column = column;
    vec.row = row;
    while (vec.column != 19 && vec.row != 0) {
        vec.column++;
        vec.row--;
    }
    return vec;
}

class Connect4Game {
public:

    Connect4Game();

    bool check_win(int row);
    int get_empty_space(int row);

    void progress(int row);

    Box get_turn();

    Box slots[20][20]{};

protected:
    virtual void display() = 0;
    virtual void _changePlayer(Box player) = 0;
    virtual void win(Box player) = 0;

private:
    Box turn;

    void togglePlayer();
    bool is_combo(int column, int row, Box box);
};


#endif //CONNECT4_CONNECT4GAME_H
