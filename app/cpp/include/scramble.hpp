/**
 * @file scramble.hpp
 * @author dj1vs 
 * @brief Scramble generator library
 * @date 2024-08-10
 * 
 * Uses tnoodle CLI
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "cli.hpp"

namespace scramble
{
    static std::string get_scramble(const std::string& puzzle, uint8_t amount = 1)
    {
        std::string cmd = "tnoodle scramble -p " + puzzle
                          + " -c " + std::to_string(amount);

        return cli::exec(cmd.c_str());
    }
};