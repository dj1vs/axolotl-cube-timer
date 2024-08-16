/**
 * @file scramble_component.cpp
 * @author dj1vs 
 * @brief 
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 */
#include "components/scramble_component.hpp"
#include "components/scramble_component.hpp"

ScrambleComponentBase::ScrambleComponentBase()
{
    is_empty.store(true);

    load_scramble();
}

ftxui::Element ScrambleComponentBase::Render()
{
    if (is_empty.load())
    {
        return ftxui::text("Loading...");
    }

    return ftxui::paragraph(m_scramble);
}

void ScrambleComponentBase::load_scramble()
{
    if (is_available())
    {
        is_empty.store(false);
        m_scramble = scramble_manager.get_scramble(m_puzzle);
        if (!m_scramble.length())
        {
            is_empty.store(true);
        }
    }
    else
    {
        is_empty.store(true);        
    }
}

void ScrambleComponentBase::set_puzzle(puzzle::PuzzleType puzzle)
{
    m_puzzle = puzzle;

    load_scramble();
}

bool ScrambleComponentBase::is_available() const
{    
    return scramble_manager.availalbe_scrambles(m_puzzle);
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
