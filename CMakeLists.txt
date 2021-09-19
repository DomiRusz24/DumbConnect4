cmake_minimum_required(VERSION 3.20)
project(Connect4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp console/ConsoleGame.cpp connect4/Connect4Game.h console/ConsoleGame.h widgetapp/WidgetGame.cpp widgetapp/WidgetGame.h widgetapp/WidgetApp.cpp widgetapp/WidgetApp.h widgetapp/cMain.cpp widgetapp/cMain.h connect4/Connect4Game.cpp)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(Connect4 ${SOURCE_FILES})

target_link_libraries(Connect4 ${wxWidgets_LIBRARIES})