#pragma once

#include "Sudoku9x9.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

/**
 * @class SudokuSolver
 * @brief A class for generating and solving Sudoku boards.
 */
struct SudokuSolver {
    /**
     * @brief Generates a Sudoku board with a specified number of numbers dropped.
     *
     * @param board The Sudoku9x9 object to generate the board for.
     * @param nums_to_drop The number of numbers to drop from the generated board.
     */
    static void generateBoard(Sudoku9x9 &board, int nums_to_drop);

    /**
     * @brief Solves the provided Sudoku board.
     *
     * @param board The Sudoku9x9 object to solve.
     * @return true if the board is successfully solved, false otherwise.
     */
    static bool solveBoard(Sudoku9x9 &board);

protected:
    /**
     * @brief Fills a 3x3 grid with random numbers.
     *
     * @param grid The grid to fill.
     * @param g The random number generator.
     */
    static void fillGrid(std::vector<std::vector<int>> &grid, std::mt19937 &g);

    /**
     * @brief Places a filled grid onto the Sudoku board at a specified position.
     *
     * @param grid The filled grid to place.
     * @param board The Sudoku9x9 object to place the grid on.
     * @param grid_number The number identifying the position to place the grid.
     */
    static void putGrid(std::vector<std::vector<int>> &grid, Sudoku9x9 &board, int grid_number);

    /**
     * @brief Drops a specified number of random numbers from the Sudoku board.
     *
     * @param board The Sudoku9x9 object to drop numbers from.
     * @param k The number of random numbers to drop.
     * @param g The random number generator.
     */
    static void dropNums(Sudoku9x9 &board, int k, std::mt19937 &g);

    /**
     * @brief Checks if it is safe to place a number in a specific cell of the Sudoku board.
     *
     * @param board The Sudoku9x9 object.
     * @param row_idx The row index of the cell.
     * @param col_idx The column index of the cell.
     * @param num The number to check for safety.
     * @return true if it is safe to place the number, false otherwise.
     */
    static bool isSafe(Sudoku9x9 &board, int row_idx, int col_idx, int num);

    /**
     * @brief Solves the Sudoku board using a recursive backtracking algorithm.
     *
     * @param board The Sudoku9x9 object to solve.
     * @param row The current row during the solving process.
     * @param col The current column during the solving process.
     * @return true if the board is successfully solved, false otherwise.
     */
    static bool solveBoardHelper(Sudoku9x9 &board, int row, int col);
};
