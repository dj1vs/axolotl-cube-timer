/**
 * @file puzzle_component.hpp
 * @author dj1vs
 * @brief 
 * @date 2024-08-12
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

class PuzzleComponentBase : ftxui::ComponentBase
{
public:
    PuzzleComponentBase();

    std::string get_puzzle() const {return puzzles[selected];}
public:
    bool OnEvent(ftxui::Event) override;
    ftxui::Element Render() override;
private:
    ftxui::Component m_dropdown;
    const std::vector <std::string> puzzles = 
    {
        "two",
        "three",
        "four",
        "four_fast",
        "five",
        "six",
        "seven",
        "three_ni",
        "four_ni",
        "five_ni",
        "three_fm",
        "pyra",
        "sq1",
        "mega",
        "clock",
        "skewb"
    };
    int selected = 1;
};

using PuzzleComponent = std::shared_ptr<PuzzleComponentBase>;