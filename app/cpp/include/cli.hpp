/**
 * @file cli.hpp
 * @author dj1vs 
 * @brief Library for executing terminal commands
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

namespace cli
{

static std::string exec(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, void(*)(FILE*)> pipe(popen(cmd, "r"),
    [](FILE * f) -> void
    {
        // wrapper to ignore the return value from pclose() is needed with newer versions of gnu g++
        std::ignore = pclose(f);
    });

    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    
    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }

    return result;
}

};