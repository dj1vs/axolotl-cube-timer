/**
 * @file app_component.cpp
 * @author dj1vs 
 * @brief 
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 */
#include "components/app_component.hpp"

ApplicationComponentBase::ApplicationComponentBase(ftxui::ScreenInteractive* screen)
: m_screen(screen)
{
    m_scramble_component = std::make_shared<ScrambleComponentBase>();
    m_timer_component = std::make_shared<TimerComponentBase>();
    m_puzzle_component = std::make_shared<PuzzleComponentBase>();

    timer_render_thread = std::thread([this]
    {
        while (this->timer_updating)
        {
            using namespace std::chrono_literals;

            if (this->m_timer_component->is_ticking())
            {
                this->m_timer_component->OnEvent(ftxui::Event::Custom);
            }

            std::this_thread::sleep_for(0.001s);
        }
    });

    scramble_update_thread = std::thread([this]
    {
        while (this->scramble_updating)
        {
            using namespace std::chrono_literals;

            if (this->m_scramble_component->is_empty.load())
            {
                this->m_scramble_component->load_scramble();
                this->m_scramble_component->Render();
            }
            
            std::this_thread::sleep_for(0.5s);
        }
    });

    std::string axolotl_str =
    R"##(
    ⠀⠀⠀⠀⠀⢠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡇⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠸⣿⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⡇⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⢀⣀⣠⡈⠻⣿⣷⡄⢲⣶⣦⣤⣤⣤⣀⡀⠀⠸⢿⡿⠁⠀⠀⢀⣀⠄⠀
    ⠀⠀⣈⣉⣉⣉⣛⠂⠈⠻⣿⠈⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣄⠀⢿⣿⠟⠋⠀⠀
    ⠀⢠⣌⠻⢿⣿⣿⣿⣦⡀⠉⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⣤⣤⠆⠀
    ⠀⢸⣿⣷⣦⣤⡌⠉⠙⠻⠆⢸⣿⣿⣿⠟⠻⣿⣿⣿⣿⣿⡿⠋⢙⣇⠘⠋⠀⠀
    ⠀⠸⠿⠛⢉⣠⣤⣶⣶⣦⠄⠈⢿⣿⣿⣦⣤⣼⣿⣿⣿⣿⣿⣶⣿⡟⠀⠀⠀⠀
    ⠀⠀⠀⠙⠛⠛⣉⣉⣉⡁⠀⠀⠀⠙⠻⠿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀
    ⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⡿⠖⠀⠀⠀⠀⠀⠀⠈⠉⠉⢀⣀⣤⣴⡀⠀⠀⠀⠀
    ⠀⠀⢰⣿⣿⣿⣿⣿⡿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠺⣿⣿⣿⣿⣷⠀⠀⠀⠀
    ⠀⠀⣼⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠼⠿⢿⣿⣿⣷⣄⠀⠀
    ⠀⠈⠉⠹⣿⠿⠋⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀
    ⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    )##";
    
    std::vector <ftxui::Element> axolotl_text_lines;
    std::stringstream ax_ss(axolotl_str);
    std::string text_line;
    while (getline(ax_ss, text_line, '\n'))
    {
        axolotl_text_lines.push_back(ftxui::text(text_line));
    }
    axolotl = ftxui::vbox(axolotl_text_lines);

}

ApplicationComponentBase::~ApplicationComponentBase()
{
    timer_updating = false;
    scramble_updating = false;

    timer_render_thread.join();
    scramble_update_thread.join();
}

bool ApplicationComponentBase::OnEvent(ftxui::Event event)
{
    using namespace ftxui;

    bool components_processed = false;
    bool puzzle_processed;
    
    components_processed |= m_scramble_component->OnEvent(event);
    components_processed |= m_timer_component->OnEvent(event);
    components_processed |= puzzle_processed = m_puzzle_component->OnEvent(event);

    if (puzzle_processed
     && m_puzzle_component->get_puzzle() != m_scramble_component->get_puzzle())
    {
        m_scramble_component->set_puzzle(m_puzzle_component->get_puzzle()); 
    }

    if (event == Event::Character(' '))
    {
        if (!m_timer_component->is_ticking())
        {
            m_scramble_component->load_scramble();
            return true;
        }
        return false;
    }
    else if (event == Event::Character('q'))
    {
        m_screen->ExitLoopClosure()();
        return true;
    }
    else if (event == Event::Custom)
    {
        return true;
    }

    return components_processed;
}

ftxui::Element ApplicationComponentBase::Render()
{
    using namespace ftxui;

    return vbox
        ({
            filler(),
            hbox({
                filler(),
                text("Axolotol Cube Timer"),
                filler(),
            }),
            filler(),
            hbox({
                filler(),
                axolotl,
                filler(),
            }),
            filler(),
            hbox({
                filler(),
                m_timer_component->Render(),
                filler(),
            }) | border,
            filler(),
            m_puzzle_component->Render(),
            m_scramble_component->Render()
        });
}

