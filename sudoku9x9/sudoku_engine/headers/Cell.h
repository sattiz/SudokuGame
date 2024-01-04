#pragma once

#include <string>
#include <iostream>

/**
 * @struct Cell
 * @brief Represents a cell in a Sudoku board.
 */
struct Cell {
    /**
     * @brief Default constructor for Cell.
     */
    Cell() = default;

    /**
     * @brief Parameterized constructor for Cell.
     *
     * @param value The initial value of the cell.
     * @param modifiable Specifies if the cell is modifiable (default is true).
     */
    explicit Cell(int value, bool modifiable = true);

    /**
     * @brief Copy assignment operator for Cell.
     *
     * @param item The Cell object to copy from.
     * @return Reference to the assigned Cell.
     */
    Cell &operator=(Cell const &item) = default;

    /**
     * @brief Assignment operator to set the value of the cell.
     *
     * @param new_val The new value to assign to the cell.
     * @return Reference to the assigned Cell.
     */
    Cell &operator=(int new_val);

    /**
     * @brief Equality operator for Cell.
     *
     * @param right The Cell object to compare.
     * @return true if the cells are equal, false otherwise.
     */
    bool operator==(Cell &right) const;

    /**
     * @brief Equality operator for comparing with an integer.
     *
     * @param right The integer to compare.
     * @return true if the cell's value is equal to the integer, false otherwise.
     */
    bool operator==(int right) const;

    /**
     * @brief Conversion operator to int, allowing Cell to be used as an integer.
     *
     * @return The value of the cell.
     */
    explicit operator int() const;

    /**
     * @brief Conversion operator to bool, indicating whether the cell is non-zero.
     *
     * @return true if the cell's value is non-zero, false otherwise.
     */
    explicit operator bool() const;

    /**
     * @brief Overloaded stream insertion operator to print the cell.
     *
     * @param out The output stream.
     * @param item The Cell object to print.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, Cell &item);

    /**
     * @brief Overloaded stream extraction operator to read the cell from input.
     *
     * @param in The input stream.
     * @param item The Cell object to read into.
     * @return Reference to the input stream.
     */
    friend std::istream &operator>>(std::istream &in, Cell &item);

    /**
     * @brief Switches the modifiability of the cell (modifiable <-> non-modifiable).
     */
    void switchMod();

private:
    /**
     * @brief Converts the cell's value to a string.
     *
     * @return The string representation of the cell's value.
     */
    std::string toStr() const;

    int value{0};     ///< The value of the cell.
    bool modifiable{true};  ///< Specifies if the cell is modifiable.
};
