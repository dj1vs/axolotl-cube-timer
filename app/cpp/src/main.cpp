/**
 * @file main.cpp
 * @author dj1vs 
 * @brief Entry point for axolotl-cube-timer
 * @date 2024-08-10
 * 
 * abandon hope all ye who enter here
 * 
 * @copyright Copyright (c) 2024
*/
#include "components/app_component.hpp"

int main()
{
    using namespace ftxui;

    auto screen = ScreenInteractive::TerminalOutput();
    
    ftxui::Screen::Cursor cursor;
    cursor.shape = ftxui::Screen::Cursor::Hidden;

    screen.SetCursor(cursor);

    ApplicationComponent app_component = std::make_shared<ApplicationComponentBase>(&screen);

    screen.Loop(app_component);
}