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

}

std::string ScrambleManager::get_scramble(puzzle::PuzzleType puzzle, uint8_t amount)
{
    if (!amount) return std::string();

    std::string cmd = m_tnoodle_path + " scramble -p " + puzzle::tnoodle_puzzle_str.at(puzzle);
    if (amount > 1) cmd += " -c " + std::to_string(amount);

    return cli::exec(cmd.c_str());
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
