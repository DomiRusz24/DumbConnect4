//
// Created by pawel on 18.09.2021.
//

#include "WidgetApp.h"
#include "WidgetGame.h"

WidgetApp::WidgetApp() : wxApp() {
}

bool WidgetApp::OnInit() {
    main_game = new WidgetGame();
    return true;
}

WidgetApp::~WidgetApp() {

}
