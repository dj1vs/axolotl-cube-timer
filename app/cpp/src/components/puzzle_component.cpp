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
    static std::vector <std::string> puzzles_strings;
    for (const auto& puzzle : puzzles)
    {
        puzzles_strings.push_back(puzzle::readable_puzzle_str.at(puzzle));
    }

    m_dropdown = ftxui::Dropdown(ftxui::ConstStringListRef(&puzzles_strings), &selected);
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
