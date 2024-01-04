#pragma once

#include <sstream>
#include <unordered_map>
#include "Matrix.h"

#define SUBGRID_SIZE 3
#define PUZZLE_SIZE (SUBGRID_SIZE*SUBGRID_SIZE)

struct Sudoku9x9 : public Matrix {
    Sudoku9x9() : Matrix(PUZZLE_SIZE, PUZZLE_SIZE) {}

    /**
     * @brief Checks if the Sudoku puzzle is solved.
     *
     * @return true if the puzzle is solved, false otherwise.
     */
    bool checkIfSolved();

    /**
     * @brief Sets the value of a cell in the Sudoku grid.
     *
     * @param row The row index of the cell (1 to 9).
     * @param column The column index of the cell (1 to 9).
     * @param val The value to set in the cell.
     * @return true if the cell was set successfully, false if there is a collision.
     */
    bool setCell(int row, int column, int val);

    /**
     * @brief Loads a Sudoku puzzle board from a string of numbers.
     *
     * The string should contain 81 characters representing the puzzle grid, with '0' for empty cells.
     *
     * @param string_of_nums A string representing the puzzle grid.
     */
    void loadBoard(const std::string &string_of_nums);

    /**
     * @brief Dumps the current state of the Sudoku puzzle board as a string.
     *
     * @return A string representation of the puzzle grid.
     */
    std::string dumpBoard();

    /**
     * @brief Checks if a given number is present in the specified row of the Sudoku board.
     *
     * @param row The row index to check (0 to 8).
     * @param num The number to check for presence (1 to 9).
     * @return true if the number is not present in the row, false if it is present.
     */
    bool isInRow(int row, int num);

    /**
     * @brief Checks if a given number is present in the specified column of the Sudoku board.
     *
     * @param col The column index to check (0 to 8).
     * @param num The number to check for presence (1 to 9).
     * @return true if the number is not present in the column, false if it is present.
     */
    bool isInColumn(int col, int num);

    /**
     * @brief Checks if a given number is present in the specified subgrid of the Sudoku board.
     *
     * @param sg_idx The index of the subgrid to check (0 to 8).
     * @param num The number to check for presence (1 to 9).
     * @return true if the number is not present in the subgrid, false if it is present.
     */
    bool isInSubgrid(int sg_idx, int num);

    /**
     * @brief Prints the current state of the Sudoku board to the console.
     *
     * This function prints the entire Sudoku board, displaying the numbers in each cell.
     */
    void printBoard();

protected:

    /**
     * @brief Checks for collisions in the specified row.
     *
     * Indexes are formatted with an offset of 1 (from 1 to 9 instead of 0 to 8).
     * Returns {-1, -1} if the row has no collisions.
     * Returns {i, -1} if the row has '0' on index 'i'.
     * Returns {i, j} if the row has a collision between indexes 'i' and 'j' (row[i-1] == row[j-1]).
     *
     * @param index The index of the row to check (1 to 9).
     * @return std::pair<int, int> Result of the collision check.
     */
    std::pair<int, int> checkRow(int index);

    /**
     * @brief Checks for collisions in the specified column.
     *
     * Indexes are formatted with an offset of 1 (from 1 to 9 instead of 0 to 8).
     * Returns {-1, -1} if the column has no collisions.
     * Returns {i, -1} if the column has '0' on index 'i'.
     * Returns {i, j} if the column has a collision between indexes 'i' and 'j' (column[i-1] == column[j-1]).
     *
     * @param index The index of the column to check (1 to 9).
     * @return std::pair<int, int> Result of the collision check.
     */
    std::pair<int, int> checkColumn(int index);

    /**
     * @brief Checks for collisions in the specified subgrid.
     *
     * Indexes are formatted with an offset of 1 (from 1 to 9 instead of 0 to 8).
     * Returns {-1, -1, -1, -1} if the subgrid has no collisions.
     * Returns {i_x, i_y, -1, -1} if the subgrid element 'i' is zero.
     * Returns {i_x, i_y, j_x, j_y} if the subgrid has a collision between elements 'i' and 'j'.
     *
     * @param index The index of the subgrid to check (1 to 9).
     * @return std::pair<int, int> Result of the collision check.
     */
    std::tuple<int, int, int, int> checkSubgrid(int index);
};


