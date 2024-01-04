#include "Sudoku9x9.h"

// Function to set the value of a cell in the Sudoku grid
bool Sudoku9x9::setCell(int row, int column, int val) {
    // Check if the provided row and column indices are within valid bounds
    if ((row > PUZZLE_SIZE || row < 1) || (column > PUZZLE_SIZE || column < 1))
        return false;

    // Check if the provided value is within the valid range (1 to 9)
    if (val < 0 || val > PUZZLE_SIZE)
        return false;

    // Access the cell at the specified row and column indices
    auto &cell = (*this)[row - 1][column - 1];

    // Check if the cell is not empty (non-zero)
    if (not cell)
        return false;

    // Set the value of the cell and return success
    cell = val;
    return true;
}

// Function to load a Sudoku board from a string of numbers
void Sudoku9x9::loadBoard(const std::string &string_of_nums) {
    std::istringstream src(string_of_nums);
    for (int i = 0; i < PUZZLE_SIZE; ++i)
        for (int j = 0; j < PUZZLE_SIZE; ++j)
            src >> (*this)[i][j];
}

// Function to dump the Sudoku board to a string
std::string Sudoku9x9::dumpBoard() {
    std::ostringstream res("");
    for (int i = 0; i < PUZZLE_SIZE; ++i)
        for (int j = 0; j < PUZZLE_SIZE; ++j)
            res << (*this)[i][j];
    return res.str();
}

// Function to check for conflicts in a row
std::pair<int, int> Sudoku9x9::checkRow(int index) {
    // Adjust the 1-based index to a 0-based index
    index--;

    // Hash map to store cell values and their indices in the row
    std::unordered_map<int, int> items{}; // cell_value - key, index_in_row - value

    // Iterate over the row
    for (int i = 0; i < PUZZLE_SIZE; i++) {
        int cell_val = static_cast<int>((*this)[index][i]);
        int cell_idx = i;

        // Check if the cell value is zero
        if (not cell_val)
            return {i + 1, -1}; // If zero, return the index of '0' value and -1

        // Check if the cell value is already in the hash map
        auto it = items.find(cell_val);
        if (it == items.end()) {
            items[cell_val] = cell_idx; // If not, add it to the hash map
        } else {
            return {i + 1, it->second + 1}; // If in the hash map, return indexes of conflicting values
        }
    }
    return {-1, -1};
}

// Function to check for conflicts in a column
std::pair<int, int> Sudoku9x9::checkColumn(int index) {
    // Adjust the 1-based index to a 0-based index
    index--;

    // Hash map to store cell values and their indices in the column
    std::unordered_map<int, int> items{}; // cell_value - key, index_in_column - value

    // Iterate over the column
    for (int i = 0; i < PUZZLE_SIZE; i++) {
        int cell_val = static_cast<int>((*this)[i][index]);
        int cell_idx = i;

        // Check if the cell value is zero
        if (not cell_val)
            return {cell_idx + 1, -1}; // If zero, return the index of '0' value and -1

        // Check if the cell value is already in the hash map
        auto it = items.find(cell_val);
        if (it == items.end()) {
            items[cell_val] = cell_idx; // If not, add it to the hash map
        } else {
            return {cell_idx + 1, it->second + 1}; // If in the hash map, return indexes of conflicting values
        }
    }
    return {-1, -1};
}

// Function to check for conflicts in a subgrid
std::tuple<int, int, int, int> Sudoku9x9::checkSubgrid(int index) {
    // Adjust the 1-based index to a 0-based index
    index--;

    // Calculate the starting indices of the subgrid
    const int subgridRow = index / SUBGRID_SIZE * SUBGRID_SIZE;
    const int subgridCol = index * SUBGRID_SIZE % PUZZLE_SIZE;

    // Hash map to store cell values and their indices in the subgrid
    std::unordered_map<int, std::pair<int, int>> items{}; // cell_value - key, index_in_subgrid - value

    // Iterate over the subgrid
    for (int i = 0; i < SUBGRID_SIZE; i++) {
        for (int j = 0; j < SUBGRID_SIZE; j++) {
            int cell_x_idx = subgridRow + i;
            int cell_y_idx = subgridCol + j;
            int cell_val = static_cast<int>((*this)[cell_x_idx][cell_y_idx]);

            // Check if the cell value is zero
            if (not cell_val)
                return {cell_x_idx + 1, cell_y_idx + 1, -1, -1}; // If zero, return the indices of '0' value and -1

            // Check if the cell value is already in the hash map
            auto it = items.find(cell_val);
            if (it == items.end()) {
                items[cell_val] = {cell_x_idx, cell_y_idx}; // If not, add it to the hash map
            } else {
                return {cell_x_idx + 1, cell_y_idx + 1, it->second.first + 1, it->second.second + 1}; // If in the hash map, return indexes of conflicting values
            }
        }
    }
    return {-1, -1, -1, -1};
}

// Function to check if the Sudoku board is solved
bool Sudoku9x9::checkIfSolved() {
    // Check for conflicts in each row, column, and subgrid
    for (int i = 1; i <= PUZZLE_SIZE; i++) {
        auto checkRes = this->checkRow(i);
        if (checkRes.first != -1 || checkRes.second != -1) {
            return false;
        }
        checkRes = this->checkColumn(i);
        if (checkRes.first != -1 || checkRes.second != -1) {
            return false;
        }
        auto checkSg = this->checkSubgrid(i);
        if (checkRes.first != -1 || checkRes.second != -1) {
            return false;
        }
    }
    return true;
}

// Function to check if a number is present in a row
bool Sudoku9x9::isInRow(int row, int num) {
    return !rowContains(row, num).empty();
}

// Function to check if a number is present in a column
bool Sudoku9x9::isInColumn(int col, int num) {
    return !columnContains(col,num).empty();
}

// Function to check if a number is present in a subgrid
bool Sudoku9x9::isInSubgrid(int sg_idx, int num) {
    // Calculate the starting indices of the subgrid
    const int subgridRow = sg_idx / SUBGRID_SIZE * SUBGRID_SIZE;
    const int subgridCol = sg_idx * SUBGRID_SIZE % PUZZLE_SIZE;

    // Iterate over the subgrid
    for (int i = 0; i < SUBGRID_SIZE; i++) {
        for (int j = 0; j < SUBGRID_SIZE; ++j) {
            int cell_x_idx = subgridRow + i;
            int cell_y_idx = subgridCol + j;
            if (int((*this)[cell_x_idx][cell_y_idx]) == num)
                return true;
        }
    }
    return false;
}

// Function to print the Sudoku board
void Sudoku9x9::printBoard() {
    this->print();
}
