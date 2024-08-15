/**
 * @file scramble_manager.cpp
 * @author dj1vs
 * @brief 
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 */
#include "scramble_manager.hpp"

#include "cli.hpp"

ScrambleManager::ScrambleManager()
{
    read_env_config();

    for (auto &puzzle : puzzles)
    {
        buf_position[puzzle] = 0;
        buf_load_thread[puzzle] = new ScrambleThread
        (
            {
                BUF_SIZE,
                m_tnoodle_path,
                puzzle
            }
        );
    }
}

ScrambleManager::~ScrambleManager()
{
    for (auto &puzzle : puzzles)
    {
        delete buf_load_thread[puzzle];
    }
}

std::string ScrambleManager::get_scramble(puzzle::PuzzleType puzzle)
{
    while (buf_load_thread[puzzle]->is_running())
    {
        std::this_thread::yield();
    }

    const auto buf_size = buf_load_thread[puzzle]->get_scrambles().size();

    if (buf_position[puzzle] < buf_size)
    {
        // we have enough pre-loaded scrambles
        return buf_load_thread[puzzle]->get_scrambles()[buf_position[puzzle]++];
    }

    // here we have to load new scrambles

    delete buf_load_thread[puzzle];
    buf_load_thread[puzzle] = new ScrambleThread
    (
        {
            BUF_SIZE,
            m_tnoodle_path,
            puzzle
        }
    );
    
    buf_position[puzzle] = 0;

    while (!buf_load_thread[puzzle]->is_running())
    {
        // wait until the scrambles are loaded
        std::this_thread::yield();
    }

    return buf_load_thread[puzzle]->get_scrambles()[buf_position[puzzle]++]; 
}

uint8_t ScrambleManager::availalbe_scrambles(puzzle::PuzzleType puzzle) const
{
    if (buf_load_thread.at(puzzle)->is_running())
    {
        return 0;
    }

    return buf_load_thread.at(puzzle)->get_scrambles().size() - buf_position.at(puzzle);
}

void ScrambleManager::set_tnoodle_path(const std::string &path)
{
    m_tnoodle_path = path;
}

void ScrambleManager::read_env_config()
{
    if (const char *tnoodle_path_p = std::getenv("TNOODLE_PATH"))
    {
        set_tnoodle_path(tnoodle_path_p);
    }
}
