#include <iostream>
#include <string>

#include "console/ConsoleGame.h"
#include "widgetapp/WidgetApp.h"

using namespace std;

ConsoleGame *main_game;
WidgetApp *widget_game;

int main(int argc, char **argv) {
    widget_game = new WidgetApp();
    wxApp::SetInstance(widget_game);
    wxEntry(argc, argv);
    main_game = new ConsoleGame();
    return 0;
}
