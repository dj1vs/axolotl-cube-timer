/**
 * @file scramble_manager.hpp
 * @author dj1vs
 * @brief 
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "scramble_thread.hpp"
#include "puzzle.hpp"

/**
 * @brief Класс для управления скрамблами разных типов головоломок
 * 
 * @details Через внешнюю утилиту tnoodle загружает и кеширует скрамблы разных типов головоломок.
 * Поддерживает предзагрузку, распараллеливание и фоновую загрузку в дочернем треде. 
 */
class ScrambleManager
{
public:
    /**
     * @brief Конструктор
     * 
     * Читает переменные среды и запускает первую предзагрузку скрамблов 
     */
    ScrambleManager();

    /**
     * @brief Деструктор
     * 
     * Закрывает все дочерние потоки по предзагрузке скрамблов
     */
    ~ScrambleManager();

    /**
     * @brief Получение строки со скрамблом
     * 
     * Обращается к tnoodle и генерирует скрамбл для выбранной головоломки в формате WCA
     * 
     * @param puzzle Тип головоломки
     * @return Строковое представление скрамбла
     */
    std::string get_scramble(puzzle::PuzzleType puzzle = puzzle::PuzzleType::_3x3);

    /**
     * @brief Получение количества предзагруженных скрамблов
     * 
     * Возвращает количество скрамблов, доступных без загрузки из tnoodle
     * 
     * @param puzzle Тип головоломки
     * @return Количество доступных скрамблов
     */
    uint8_t availalbe_scrambles(puzzle::PuzzleType puzzle) const;

    /**
     * @brief Устанавливает путь до tnoodle
     * 
     * Обновляет сохранённое значение пути до исполняемого файла  
     * 
     * @param path Новый путь до tnoodle с Unix-style escape
     */    
    void set_tnoodle_path(const std::string &path);
private:

    /**
     * @brief Читает настройки из ENV
     * 
     * Читает настройки из определённых переменных среды и обновляет настройки
     */
    void read_env_config();
private:
    std::string m_tnoodle_path = "tnoodle"; ///< Путь до исполняемого файла tnoodle

    static constexpr const uint8_t BUF_SIZE = 20; ///< Количество сохраняемых в буфере скрамблов

    std::map <puzzle::PuzzleType, uint8_t> buf_position; ///< Указатель на текущий взятый скрамбл из буфера по типу головоломки
    std::map<puzzle::PuzzleType, ScrambleThread*> buf_load_thread; ///< Поток загрузки скрамблов по типу головоломки

    const std::vector <puzzle::PuzzleType> puzzles = 
    {
        puzzle::PuzzleType::_2x2,
        puzzle::PuzzleType::_3x3,
        puzzle::PuzzleType::_4x4,
        puzzle::PuzzleType::_5x5,
        puzzle::PuzzleType::_6x6,
        puzzle::PuzzleType::_7x7,
        puzzle::PuzzleType::Pyraminx,
        puzzle::PuzzleType::Square1,
        puzzle::PuzzleType::Megaminx,
        puzzle::PuzzleType::Clock,
        puzzle::PuzzleType::Skewb
    }; ///< список поддерживаемых типов головоломок
};