/**
 * @file scramble_component.cpp
 * @author dj1vs 
 * @brief 
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 */
#include "components/scramble_component.hpp"

ScrambleComponentBase::ScrambleComponentBase()
{
    load_scramble();
}

ftxui::Element ScrambleComponentBase::Render()
{
    return ftxui::text(m_scramble);
}

void ScrambleComponentBase::load_scramble()
{
    m_scramble = scramble_manager.get_scramble(m_puzzle);
}

void ScrambleComponentBase::set_puzzle(const std::string &puzzle)
{
    m_puzzle = puzzle;

    load_scramble();
}

bool ScrambleComponentBase::OnEvent(ftxui::Event e)
{
    if (e == ftxui::Event::Character('n'))
    {
        load_scramble();
        return true;
    }
    return false;
}
