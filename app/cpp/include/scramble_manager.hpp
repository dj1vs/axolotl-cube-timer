/**
 * @file scramble_manager.hpp
 * @author Трифонов Д.А. (trifonov_da@nikiet.ru)
 * @brief 
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

class ScrambleManager
{
public:
    ScrambleManager();

    std::string get_scramble(const std::string &puzzle, uint8_t amount = 1);

    void set_tnoodle_path(const std::string &path);
private:
    void read_env_config();
private:
    std::string m_tnoodle_path = "tnoodle";
};