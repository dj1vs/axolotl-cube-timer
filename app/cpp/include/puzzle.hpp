/**
 * @file puzzle.hpp
 * @author Трифонов Д.А. (trifonov_da@nikiet.ru)
 * @brief 
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

namespace puzzle
{
    enum class PuzzleType
    {
        _2x2, _3x3, _4x4, _5x5, _6x6, _7x7,
        Pyraminx, Square1, Megaminx, Clock, Skewb
    };

    static const std::map <PuzzleType, std::string> tnoodle_puzzle_str = 
    {
        {PuzzleType::_2x2,     "two"},
        {PuzzleType::_3x3,     "three"},
        {PuzzleType::_4x4,     "four"},
        {PuzzleType::_5x5,     "five"},
        {PuzzleType::_6x6,     "six"},
        {PuzzleType::_7x7,     "seven"},
        {PuzzleType::Pyraminx, "pyra"},
        {PuzzleType::Square1,  "sq1"},
        {PuzzleType::Megaminx, "mega"},
        {PuzzleType::Clock,    "clock"},
        {PuzzleType::Skewb,    "skewb"}
    };

    static const std::map <PuzzleType, std::string> readable_puzzle_str =
    {
        {PuzzleType::_2x2,     "2x2"},
        {PuzzleType::_3x3,     "3x3"},
        {PuzzleType::_4x4,     "4x4"},
        {PuzzleType::_5x5,     "5x5"},
        {PuzzleType::_6x6,     "6x6"},
        {PuzzleType::_7x7,     "7x7"},
        {PuzzleType::Pyraminx, "Pyraminx"},
        {PuzzleType::Square1,  "Square-1"},
        {PuzzleType::Megaminx, "Megaminx"},
        {PuzzleType::Clock,    "Clock"},
        {PuzzleType::Skewb,    "Skewb"}
    };
}