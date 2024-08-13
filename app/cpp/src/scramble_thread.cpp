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

ScrambleThread::ScrambleThread()
{
    m_thread = std::thread([&]
    {
        std::string cmd = m_tnoodle_path + " scramble -p " + puzzle::tnoodle_puzzle_str.at(puzzle_type);
        if (m_target_amount > 1) cmd += " -c " + std::to_string(m_target_amount);

        std::string result = cli::exec(cmd.c_str());

        m_destination->clear();
        m_destination->reserve(m_target_amount);

        std::stringstream ss;
        std::string scramble;
        while (getline(ss, scramble, '\n'))
        {
            m_destination->push_back(scramble);
        }        
    });
}

ScrambleThread::~ScrambleThread()
{

}
