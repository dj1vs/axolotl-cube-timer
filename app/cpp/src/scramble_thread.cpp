/**
 * @file scramble_thread.cpp
 * @author dj1vs
 * @brief 
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 */
#include "scramble_thread.hpp"

#include "cli.hpp"
#include "puzzle.hpp"

ScrambleThread::ScrambleThread (const ThreadConfig &t_conf)
: m_scrambles_amount(t_conf.scrambles_amount), m_tnoodle_path(t_conf.tnoodle_path), m_puzzle_type(t_conf.puzzle_type)
{
    m_running.store(true);

    m_thread = std::thread([&]
    {
        std::string cmd = m_tnoodle_path + " scramble -p " + puzzle::tnoodle_puzzle_str.at(m_puzzle_type);
        if (m_scrambles_amount > 1) cmd += " -c " + std::to_string(m_scrambles_amount);

        m_scrambles.reserve(m_scrambles_amount);

        std::string result = cli::exec(cmd.c_str());

        std::stringstream ss(result);
        std::string scramble;

        while (getline(ss, scramble, '\n'))
        {
            m_scrambles.push_back(scramble);
        }

        m_running.store(false);
    });

}

ScrambleThread::~ScrambleThread()
{
    m_thread.join();
}