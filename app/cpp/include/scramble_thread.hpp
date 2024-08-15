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
    struct ThreadConfig
    {
        uint8_t scrambles_amount;
        std::string tnoodle_path;
        puzzle::PuzzleType puzzle_type;
    };

    ScrambleThread(const ThreadConfig &t_conf);
    ~ScrambleThread();

    std::vector <std::string> get_scrambles() const {return m_scrambles;}

    bool is_running() const {return m_running.load();}
private:
    std::vector<std::string> m_scrambles;

    volatile std::atomic_bool m_running;
    std::thread m_thread;
    uint8_t m_scrambles_amount;
    std::string m_tnoodle_path = "tnoodle";
    
    puzzle::PuzzleType m_puzzle_type;
};