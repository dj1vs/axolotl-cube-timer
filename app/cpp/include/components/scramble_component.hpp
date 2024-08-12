/**
 * @file scramble_renderer.hpp
 * @author dj1vs 
 * @brief 
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

class ScrambleComponentBase : public ftxui::ComponentBase
{
public:
    ScrambleComponentBase();

    void load_scramble();

    void set_puzzle(const std::string &puzzle);

    std::string get_puzzle() const {return m_puzzle;};
public:
    bool OnEvent(ftxui::Event) override;
    ftxui::Element Render() override;    
private:
    std::string m_puzzle = "three";
    std::string m_scramble;
};

using ScrambleComponent = std::shared_ptr<ScrambleComponentBase>;