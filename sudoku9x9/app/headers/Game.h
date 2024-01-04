#pragma once

#include <limits>
#include "Sudoku9x9.h"
#define CLEAR "\033[2J\033[1;1H"

/*!
 * \brief The Game struct provides functionality for running a Sudoku game.
 */
struct Game {
    /*!
     * \brief Run the Sudoku game.
     *
     * \param board Reference to a Sudoku9x9 object representing the game board.
     */
    static void run(Sudoku9x9 &board);

private:
    /*!
     * \brief Print the in-game menu.
     */
    static void printIngameMenu();

    /*!
     * \brief Implementation of getting a single value from input.
     *
     * \tparam T Type of the value to be read.
     * \param arg Reference to the variable where the read value will be stored.
     */
    template<typename T>
    static void getKeyImpl(T &arg) {
        std::cin >> arg;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    /*!
     * \brief Implementation of getting multiple values from input using recursion.
     *
     * \tparam T Type of the first value to be read.
     * \tparam Args Types of the remaining values to be read.
     * \param first Reference to the variable where the first read value will be stored.
     * \param rest References to the variables where the remaining read values will be stored.
     */
    template<typename T, typename... Args>
    static void getKeyImpl(T &first, Args &... rest) {
        std::cin >> first;
        getKeyImpl(rest...);
    }

    /*!
     * \brief Get multiple values from input using recursion.
     *
     * \tparam Args Types of the values to be read.
     * \param args References to the variables where the read values will be stored.
     */
    template<typename... Args>
    static void getKey(Args &... args) {
        getKeyImpl(args...);
    }
};
