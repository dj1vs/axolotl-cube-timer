/**
 * @file app_component.hpp
 * @author dj1vs 
 * @brief 
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "scramble_component.hpp"
#include "timer_component.hpp"
#include "puzzle_component.hpp"

class ApplicationComponentBase : public ftxui::ComponentBase
{
public:
    ApplicationComponentBase(ftxui::ScreenInteractive* screen);
    ~ApplicationComponentBase();
public:
    bool OnEvent(ftxui::Event) override;
    ftxui::Element Render() override;    
private:
    ftxui::ScreenInteractive* m_screen;

    ScrambleComponent m_scramble_component;
    TimerComponent m_timer_component;
    PuzzleComponent m_puzzle_component;

    ftxui::Element axolotl;

    bool screen_updating = true;
    std::thread screen_update_thread;
};

using ApplicationComponent = std::shared_ptr<ApplicationComponentBase>;