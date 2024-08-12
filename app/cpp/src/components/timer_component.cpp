/**
 * @file timer_component.cpp
 * @author dj1vs 
 * @brief 
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 */
#include "components/timer_component.hpp"

TimerComponentBase::TimerComponentBase()
{
}
void TimerComponentBase::start()
{
    if (m_ticking)
    {
        return;
    }    

    m_ticking = true;
    m_status = "0";
    m_start = std::chrono::steady_clock::now();
}

void TimerComponentBase::stop()
{
    m_ticking = false;
}

void TimerComponentBase::play_pause()
{
    if (is_ticking())
    {
        stop();
    }
    else
    {
        start();
    }
}

ftxui::Element TimerComponentBase::Render()
{
    ftxui::Color text_color = ftxui::Color::Red;

    if (m_ticking)
    {
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>
        (
            std::chrono::steady_clock::now() - m_start
        );

        m_status = std::to_string(ms.count());

        text_color = ftxui::Color::Green;
    }

    
    return ftxui::text(m_status + "ms") | ftxui::color(text_color);
}

bool TimerComponentBase::OnEvent(ftxui::Event e)
{
    if (e == ftxui::Event::Character(' '))
    {
        play_pause();
        return true;
    }
    
    return false;
}