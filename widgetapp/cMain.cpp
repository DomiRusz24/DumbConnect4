//
// Created by pawel on 18.09.2021.
//

#include "cMain.h"
#include "WidgetGame.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
wxEND_EVENT_TABLE()

static int box_to_color(Box box) {
    switch(box) {
        case player1:
            return 0xff0000;
        case player2:
            return 0x0059ff;
        case empty_box:
            return 8688555;
        default:
            return 8688555;
    }
}

static int box_to_light_color(Box box) {
    switch(box) {
        case player1:
            return 0xd98992;
        case player2:
            return 0x89a5d9;
        case empty_box:
            return 8688555;
        default:
            return 8688555;
    }
}

static std::string box_to_pl_name(Box box) {
    switch(box) {
        case player1:
            return "Niebieski";
        case player2:
            return "Czerwony";
        case empty_box:
            return "Nikt";
        default:
            return "Nikt";
    }
}

cMain::cMain(WidgetGame* game) : wxFrame(nullptr, wxID_ANY, "Connect4", wxPoint(30, 30), wxSize(1050, 1050)) {
    this->game = game;
    choose_slot = new wxGridSizer(1, 20, 0, 0);
    choose_buttons = new wxButton*[20];
    for (int i = 0; i < 20; i++) {
        choose_buttons[i] = new wxButton(this, 1000 + i);
        choose_slot->Add(choose_buttons[i], wxSizerFlags().Expand().Border(wxALL, 1));
        choose_buttons[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::button_click, this);
        choose_buttons[i]->Bind(wxEVT_ENTER_WINDOW, &cMain::button_hover, this);
        choose_buttons[i]->Bind(wxEVT_LEAVE_WINDOW, &cMain::button_not_hover, this);
    }

    squares = new wxWindow*[400];
    board = new wxGridSizer(20, 20, 0, 0);
    for (int i = 0; i < 20; i++) {
        for (int e = 0; e < 20; e++) {
            squares[i * 20 + e] = new wxWindow(this, wxID_ANY);
            squares[i * 20 + e]->SetBackgroundColour(wxColor(8688555));
            board->Add(squares[i * 20 + e], wxSizerFlags().Expand().Border(wxALL, 1));
        }
    }

    main_sizer = new wxBoxSizer(wxVERTICAL);

    main_sizer->Add(choose_slot, wxSizerFlags().Expand().Proportion(1).Border(wxALL, 1));
    main_sizer->Add(board, wxSizerFlags().Expand().Proportion(20).Border(wxALL, 1));

    this->SetSizer(main_sizer);

    changePlayer(player1);
    main_sizer->Layout();
}

void cMain::button_click(wxCommandEvent &evt) {
    int slot = evt.GetId() - 1000;
    game->progress(slot);
    evt.Skip();
}

void cMain::button_hover(wxMouseEvent &evt) {
    int row = evt.GetId() - 1000;
    choose_buttons[row]->SetBackgroundColour(box_to_color(current_turn));
    for (int i = 0; i < 20; i++) {
        if (game->slots[i][row] == empty_box) {
            squares[i * 20 + row]->SetBackgroundColour(box_to_light_color(current_turn));
            squares[i * 20 + row]->Refresh();
        }
    }
    evt.Skip();
}

void cMain::button_not_hover(wxMouseEvent &evt) {
    int row = evt.GetId() - 1000;
    for (int i = 0; i < 20; i++) {
        if (game->slots[i][row] == empty_box) {
            squares[i * 20 + row]->SetBackgroundColour(wxColor(8688555));
            squares[i * 20 + row]->Refresh();
        }
    }
    evt.Skip();
}

void cMain::display() {
    for (int i = 0; i < 20; i++) {
        for (int e = 0; e < 20; e++) {
            squares[i * 20 + e]->SetBackgroundColour(box_to_color(game->slots[i][e]));
            squares[i * 20 + e]->Refresh();
        }
    }
}

void cMain::win(Box player) {
    int answer = wxMessageBox("Wygral: " + box_to_pl_name(player) + "!", "Koniec gry!",
                              wxOK, this);
    if (answer == wxOK)
        this->Close();
}

cMain::~cMain() {
    delete[] squares;
    delete[] choose_buttons;
}

void cMain::changePlayer(Box player) {
    current_turn = player;
    int col = box_to_color(current_turn);
    for (int i = 0; i < 20; i++) {
        choose_buttons[i]->SetBackgroundColour(col);
    }
}
