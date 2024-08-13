/**
 * @file scramble_manager.hpp
 * @author dj1vs
 * @brief 
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "puzzle.hpp"

class ScrambleManager
{
public:
    ScrambleManager();

    std::string get_scramble(puzzle::PuzzleType puzzle = puzzle::PuzzleType::_3x3, uint8_t amount = 1);

    void set_tnoodle_path(const std::string &path);
private:
    void read_env_config();
private:
    std::string m_tnoodle_path = "tnoodle";

    static constexpr const uint8_t BUF_SIZE = 20; 
    std::map <puzzle::PuzzleType, std::array <std::string, BUF_SIZE>> buf_scrambles;
    std::map <puzzle::PuzzleType, uint8_t> buf_position;
    std::map <puzzle::PuzzleType, bool> buf_loaded;
    std::map <puzzle::PuzzleType, std::thread*> buf_load_thread;
};