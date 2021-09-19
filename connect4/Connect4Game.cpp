//
// Created by pawel on 18.09.2021.
//

#include "Connect4Game.h"

Connect4Game::Connect4Game() {
    turn = player1;
    for (auto &slot: slots) {
        for (auto &e: slot) {
            e = empty_box;
        }
    }
}

bool Connect4Game::check_win(int row) {
    int i = get_empty_space(row);
    if (i == -1) return false;
    slots[i][row] = turn;
    if (is_combo(i, row, turn)) {
        return true;
    }
    return false;
}

void Connect4Game::progress(int row) {
    if (turn == empty_box) {
        return;
    }
    if (check_win(row)) {
        display();
        win(turn);
        turn = empty_box;
    } else {
        display();
        togglePlayer();
    }
}

Box Connect4Game::get_turn() {
    return turn;
}

void Connect4Game::togglePlayer() {
    if (turn == player1) turn = player2;
    else turn = player1;
    _changePlayer(turn);
}

bool Connect4Game::is_combo(int column, int row, Box box) {
    int combo;
    for (int i = 0; i < 17; i++) {
        combo = 0;
        for (int e = 0; e <= 4; e++) {
            if (e + i <= 19) {
                if (slots[column][i + e] == box) {
                    combo++;
                    if (combo == 4) {
                        return true;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < 17; i++) {
        combo = 0;
        for (int e = 0; e <= 4; e++) {
            if (e + i <= 19) {
                if (slots[i + e][row] == box) {
                    combo++;
                    if (combo == 4) {
                        return true;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    vector2 vec = get_corner_column_and_row(column, row);
    column = vec.column;
    row = vec.row;

    for (int i = 0; i < 17; i++) {
        combo = 0;
        for (int e = 0; e <= 4; e++) {
            if (column - i - e > -1 && row + i + e <= 19) {
                if (slots[column - i - e][row + i + e] == box) {
                    combo++;
                    if (combo == 4) {
                        return true;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    return false;
}

int Connect4Game::get_empty_space(int row) {
    if (row > -1 && row < 20) {
        for (int i = 19; i >= 0; i--) {
            if (slots[i][row] == empty_box) {
                return i;
            }
        }
    }
    return -1;
}

