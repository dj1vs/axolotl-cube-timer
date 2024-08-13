/**
 * @file scramble_thread.hpp
 * @author dj1vs
 * @brief 
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "puzzle.hpp"

class ScrambleThread
{
public:
    ScrambleThread();
private:
    std::thread m_thread;
    std::vector<std::string> *m_destination;
    uint8_t m_target_amount;
    std::string m_tnoodle_path = "tnoodle";
    
    puzzle::PuzzleType puzzle_type;
};