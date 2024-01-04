#include "SudokuSolver.h"

// Function to generate a Sudoku board with a specified number of numbers to drop
void SudokuSolver::generateBoard(Sudoku9x9 &board, int nums_to_drop) {
    // Array of vectors to hold the initial 3x3 grids
    std::vector<std::vector<int>> grids[SUBGRID_SIZE];
    for (int i = 0; i < SUBGRID_SIZE; i++) {
        grids[i] = std::vector<std::vector<int>>(SUBGRID_SIZE, std::vector<int>(SUBGRID_SIZE));
    }

    // Random device and engine for shuffling
    std::random_device rd;
    std::mt19937 g(rd());

    // Fill each of the 3x3 grids with shuffled numbers
    for (auto &grid: grids) {
        fillGrid(grid, g);
    }

    // Vectors to shuffle the order in which the 3x3 grids are filled
    std::vector<int> grid_x = {1, 2, 3};
    std::vector<int> grid_y = {1, 2, 3};

    // Shuffle the order in which the 3x3 grids are filled
    std::shuffle(grid_x.begin(), grid_x.end(), g);
    std::shuffle(grid_y.begin(), grid_y.end(), g);

    // Place the filled 3x3 grids onto the Sudoku board
    for (int k = 0; k < 3; ++k) {
        int grid_number = (grid_x[k] - 1) * SUBGRID_SIZE + grid_y[k];
        auto grid = grids[k];

        putGrid(grid, board, grid_number);
    }

    // Solve the initial board to create a solvable puzzle
    solveBoard(board);

    // Drop a specified number of numbers from the board to create the puzzle
    dropNums(board, nums_to_drop, g);

    // Switch the modification status of all non-empty cells
    for (int i = 0; i < PUZZLE_SIZE; ++i) {
        for (int j = 0; j < PUZZLE_SIZE; ++j) {
            if (int(board[i][j]) != 0)
                board[i][j].switchMod();
        }
    }
}

// Function to solve the Sudoku board using backtracking
bool SudokuSolver::solveBoard(Sudoku9x9 &board) {
    return solveBoardHelper(board, 0, 0);
}

// Function to fill a 3x3 grid with shuffled numbers
void SudokuSolver::fillGrid(std::vector<std::vector<int>> &grid, std::mt19937 &g) {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Shuffle the numbers randomly
    std::shuffle(numbers.begin(), numbers.end(), g);

    // Fill the 3x3 grid with the shuffled numbers
    int k = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = numbers[k++];
        }
    }
}

// Function to place a 3x3 grid onto the Sudoku board
void SudokuSolver::putGrid(std::vector<std::vector<int>> &grid, Sudoku9x9 &board, int grid_number) {
    grid_number--;
    const int subgridRow = grid_number / SUBGRID_SIZE * SUBGRID_SIZE;
    const int subgridCol = grid_number * SUBGRID_SIZE % PUZZLE_SIZE;
    for (int i = 0; i < SUBGRID_SIZE; i++)
        for (int j = 0; j < SUBGRID_SIZE; j++) {
            int cell_x_idx = subgridRow + i;
            int cell_y_idx = subgridCol + j;
            board[cell_x_idx][cell_y_idx] = grid[i][j];
        }
}

// Function to drop a specified number of numbers from the board
void SudokuSolver::dropNums(Sudoku9x9 &board, int k, std::mt19937 &g) {
    std::uniform_int_distribution<int> distribution(0, PUZZLE_SIZE - 1);
    for (int i = 0; i < k; ++i) {
        int randomRow = distribution(g);
        int randomCol = distribution(g);

        // Ensure that the selected element is not already 0
        while (board[randomRow][randomCol] == 0) {
            randomRow = distribution(g);
            randomCol = distribution(g);
        }
        board[randomRow][randomCol] = 0;
    }
}

// Function to check if it's safe to place a number in a specific cell
bool SudokuSolver::isSafe(Sudoku9x9 &board, int row_idx, int col_idx, int num) {
    // Check that 'num' is not present in the current row, column, and subgrid
    int sg_idx = (row_idx / SUBGRID_SIZE) * SUBGRID_SIZE + (col_idx / SUBGRID_SIZE);
    bool resInRow = board.isInRow(row_idx, num);
    bool resInCol = board.isInColumn(col_idx, num);
    bool resInSubgrid = board.isInSubgrid(sg_idx, num);
    bool res = !resInRow && !resInCol && !resInSubgrid;
    return res;
}

// Helper function for backtracking to solve the Sudoku board
bool SudokuSolver::solveBoardHelper(Sudoku9x9 &board, int row, int col) {
    // Check if we have reached the end of the board
    if (row == PUZZLE_SIZE - 1 && col == PUZZLE_SIZE)
        return true;

    // Move to the next row when reaching the end of a column
    if (col == PUZZLE_SIZE) {
        row++;
        col = 0;
    }

    // Skip already filled cells, move to the next column
    if (int(board[row][col]) > 0)
        return solveBoardHelper(board, row, col + 1);

    // Try placing numbers from 1 to PUZZLE_SIZE in the current cell
    for (int num = 1; num <= PUZZLE_SIZE; num++) {
        // Check if the current number is safe to place in the cell
        bool check = isSafe(board, row, col, num);
        if (check) {
            // Place the number in the cell
            board[row][col] = num;

            // Recursively try to solve the board starting from the next column
            if (solveBoardHelper(board, row, col + 1))
                return true;
        }

        // If placing the current number doesn't lead to a solution, backtrack
        board[row][col] = 0;
    }

    // If no number can be placed in the current cell, backtrack
    return false;
}

