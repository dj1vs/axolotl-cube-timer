/**
 * @file puzzle_component.hpp
 * @author dj1vs
 * @brief 
 * @date 2024-08-12
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "puzzle.hpp"

class PuzzleComponentBase : ftxui::ComponentBase
{
public:
    PuzzleComponentBase();

    puzzle::PuzzleType get_puzzle() const {return puzzles[selected];}
public:
    bool OnEvent(ftxui::Event) override;
    ftxui::Element Render() override;
private:
    ftxui::Component m_dropdown;
    const std::vector <puzzle::PuzzleType> puzzles = 
    {
        puzzle::PuzzleType::_2x2,
        puzzle::PuzzleType::_3x3,
        puzzle::PuzzleType::_4x4,
        puzzle::PuzzleType::_5x5,
        puzzle::PuzzleType::_6x6,
        puzzle::PuzzleType::_7x7,
        puzzle::PuzzleType::Pyraminx,
        puzzle::PuzzleType::Square1,
        puzzle::PuzzleType::Megaminx,
        puzzle::PuzzleType::Clock,
        puzzle::PuzzleType::Skewb
    };
    
    int selected = 1;
};

using PuzzleComponent = std::shared_ptr<PuzzleComponentBase>;