/**
 * @file scramble_renderer.hpp
 * @author dj1vs 
 * @brief 
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "scramble_manager.hpp"
#include "puzzle.hpp"

class ScrambleComponentBase : public ftxui::ComponentBase
{
public:
    ScrambleComponentBase();

    void load_scramble();

    void set_puzzle(puzzle::PuzzleType puzzle);

    puzzle::PuzzleType get_puzzle() const {return m_puzzle;};

public:
    bool OnEvent(ftxui::Event) override;
    ftxui::Element Render() override;    
private:
    bool is_available() const;    
private:
    std::atomic_bool is_empty;
    ScrambleManager scramble_manager;

    puzzle::PuzzleType m_puzzle = puzzle::PuzzleType::_3x3;
    std::string m_scramble;

friend class ApplicationComponentBase;
};

using ScrambleComponent = std::shared_ptr<ScrambleComponentBase>;