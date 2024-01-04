#pragma once

#include <vector>
#include "Cell.h"

/**
 * @struct Matrix
 * @brief Represents a matrix of cells, commonly used for Sudoku boards.
 */
struct Matrix {
    /**
     * @brief Parameterized constructor for Matrix.
     *
     * @param rows_num The number of rows in the matrix.
     * @param cols_num The number of columns in the matrix.
     */
    Matrix(int rows_num, int cols_num);

    /**
     * @brief Returns a vector of indices in the specified row that contain the given value.
     *
     * @param index The index of the row to search.
     * @param val The value to search for.
     * @return Vector of indices containing the given value in the specified row.
     */
    std::vector<int> rowContains(size_t index, int val);

    /**
     * @brief Returns a vector of indices in the specified column that contain the given value.
     *
     * @param index The index of the column to search.
     * @param val The value to search for.
     * @return Vector of indices containing the given value in the specified column.
     */
    std::vector<int> columnContains(size_t index, int val);

    /**
     * @brief Returns the number of rows in the matrix.
     *
     * @return The number of rows.
     */
    size_t getRows();

    /**
     * @brief Returns the number of columns in the matrix.
     *
     * @return The number of columns.
     */
    size_t getColumns();

    /**
     * @brief Overloaded subscript operator to access a specific row in the matrix.
     *
     * @param index The index of the row to access.
     * @return Reference to the specified row.
     */
    std::vector<Cell> &operator[](int index);

    /**
     * @brief Prints the matrix to the console.
     */
    void print();

private:
    std::vector<
            std::vector<
                    Cell
            >> values;  ///< The 2D vector storing the matrix of cells.
};
