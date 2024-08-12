/**
 * @file timer_component.hpp
 * @author dj1vs 
 * @brief 
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

class TimerComponentBase : public ftxui::ComponentBase
{
public:
    TimerComponentBase();

    void start();
    void stop();
    void play_pause();

    bool is_ticking() const {return m_ticking;}
public:
    ftxui::Element Render() override;
    bool OnEvent(ftxui::Event) override;
private:
    bool m_ticking = false;
    std::string m_status = "0";
    std::chrono::steady_clock::time_point m_start;
};

using TimerComponent = std::shared_ptr<TimerComponentBase>;