/**
 * @file puzzle_component.cpp
 * @author dj1vs 
 * @brief 
 * @date 2024-08-12
 * 
 * @copyright Copyright (c) 2024
 */
#include "components/puzzle_component.hpp"

PuzzleComponentBase::PuzzleComponentBase()
{
    m_dropdown = ftxui::Dropdown(ftxui::ConstStringListRef(&puzzles), &selected);
}

bool PuzzleComponentBase::OnEvent(ftxui::Event e)
{
    if (e == ftxui::Event::Character(' '))
    {
        return false;
    }

    return m_dropdown->OnEvent(e);
}

ftxui::Element PuzzleComponentBase::Render()
{
    return m_dropdown->Render();
}
