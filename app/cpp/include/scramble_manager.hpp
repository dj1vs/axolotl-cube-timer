/**
 * @file scramble_manager.hpp
 * @author dj1vs
 * @brief 
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "scramble_thread.hpp"
#include "puzzle.hpp"

class ScrambleManager
{
public:
    ScrambleManager();
    ~ScrambleManager();

    std::string get_scramble(puzzle::PuzzleType puzzle = puzzle::PuzzleType::_3x3);

    uint8_t availalbe_scrambles(puzzle::PuzzleType puzzle) const;

    void set_tnoodle_path(const std::string &path);
private:
    void read_env_config();
private:
    std::string m_tnoodle_path = "tnoodle";

    static constexpr const uint8_t BUF_SIZE = 20;

    std::map <puzzle::PuzzleType, uint8_t> buf_position;
    std::map<puzzle::PuzzleType, ScrambleThread*> buf_load_thread;

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
};