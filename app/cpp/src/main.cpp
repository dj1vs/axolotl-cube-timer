/**
 * @mainpage Консольный таймер для спидкубинга axolotl-cube-timer.
 * 
 * **abandon hope all ye who enter here**
 *
 * FTXUI CLI-приложение с использованием tnoodle для генерации скрамблов
 * 
 * @copyright dj1vs
 * @author Трифнов Д.А.
 * @date 23.09.2025
 * 
 * \par Использует классы:
 * - @ref ScrambleManager
 * - @ref ScrambleThread
 * - @ref ApplicationComponentBase
 * - @ref PuzzleComponentBase
 * - @ref ScrambleComponentBase
 * - @ref TimerComponentBase
 * 
 * \par Содержит файлы:
 * - @ref cli.hpp
 * - @ref pch.hpp
 * - @ref puzzle.hpp
 * - @ref scramble_manager.hpp
 * - @ref scramble_thread.hpp
 * - @ref app_component.hpp
 * - @ref puzzle_component.hpp
 * - @ref scramble_component.hpp
 * - @ref timer_component.hpp
 * - @ref app_component.cpp
 * - @ref puzzle_component.cpp
 * - @ref scramble_component.cpp
 * - @ref timer_component.cpp
 * - @ref main.cpp
 * - @ref scramble_manager.cpp
 * - @ref scramble_thread.cpp
 */

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