/**
 * @file puzzle_component.hpp
 * @author dj1vs
 * @brief 
 * @date 2024-08-12
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "puzzle.hpp"

/**
 * @class PuzzleComponentBase
 * @brief Класс по отображению текущей головоломки - наследование от ftxui::ComponentBase
 * 
 * @details Drop-down список с выбором головоломки и отображением выбранной
 */
class PuzzleComponentBase : ftxui::ComponentBase
{
public:
    /**
     * @brief Конструктор по умолчанию
     * 
     * Заполняет dropdown типами головоломок и формирует ui-компонент
     */
    PuzzleComponentBase();

    /**
     * @brief Возвращает головоломку
     * 
     * Возвращает текущую выбранную головоломку
     * 
     * @returns выбранный пользователем тип головоломки
     */
    puzzle::PuzzleType get_puzzle() const {return puzzles[selected];}
public:
    /**
     * @brief Отнаследованный хендлер ui-событий
     */
    bool OnEvent(ftxui::Event) override;

    /**
     * @brief Отнаследованный метод рендеринга
     * 
     * Отвечает за рендеринг ui-компонента
     */
    ftxui::Element Render() override;
private:
    ftxui::Component m_dropdown; ///< ui-компонент дропдауна

    /// @brief Список поддерживаемых головоломок
    const std::vector <puzzle::PuzzleType> puzzles = 
    {
        puzzle::PuzzleType::_2x2, /**< 2x2 */
        puzzle::PuzzleType::_3x3, /**< 3x3 */
        puzzle::PuzzleType::_4x4, /**< 4x4 */
        puzzle::PuzzleType::_5x5, /**< 5x5 */
        puzzle::PuzzleType::_6x6, /**< 6x6 */
        puzzle::PuzzleType::_7x7, /**< 7x7 */
        puzzle::PuzzleType::Pyraminx, /**< Pyraminx */
        puzzle::PuzzleType::Square1, /**< Square-1 */
        puzzle::PuzzleType::Megaminx, /**< Megaminx */
        puzzle::PuzzleType::Clock, /**< Clock */
        puzzle::PuzzleType::Skewb /**< Skewb */
    };
    
    int selected = 1; ///< Номер выбранной пользователем головоломки
};

using PuzzleComponent = std::shared_ptr<PuzzleComponentBase>;