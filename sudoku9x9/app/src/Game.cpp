#include "../headers/Game.h"
#include "SudokuSolver.h"

// Define to clear the screen and print the updated board and menu
#define RESET_SCREEN     std::cout << CLEAR; \
                            board.printBoard(); \
                            printIngameMenu(); \

// Run the Sudoku game loop
void Game::run(Sudoku9x9 &board) {
    int choose = 42;
    int row, col, num;
    bool check;

    // Display the initial state of the Sudoku board and in-game menu
    RESET_SCREEN

    // Main game loop
    while (choose != 4) {
        std::cout << "Enter key: ";
        getKey(choose);
        switch (choose) {
            case 0:
                // Reset the screen to display the updated board and menu
            RESET_SCREEN
                break;
            case 1:
                row = -1, col = -1, num = -1;
                std::cout << "Enter row column number: ";
                getKey(row, col, num);

                // Set the cell on the board and provide feedback
                if (!board.setCell(row, col, num)) {
                    // Reset the screen to display the updated board and menu
                    RESET_SCREEN
                    std::cout << "Unable to set num" << std::endl;
                }
                else {
                    // Reset the screen to display the updated board and menu
                    RESET_SCREEN
                    std::cout << "Number " << num << " is set on " << row << ":" << col << std::endl;
                }
                break;
            case 2:
                // Check if the board is solved and display the result
                check = board.checkIfSolved();
                RESET_SCREEN
                if (check) {
                    std::cout << "Board is solved!" << std::endl;
                } else {
                    std::cout << "Board is not solved" << std::endl;
                }
                break;
            case 3:
                // Clear the board, solve it, and display the result
                for (int i = 0; i < board.getRows(); i++)
                    for (int j = 0; j < board.getColumns(); ++j) {
                        if (board[i][j]) {
                            board[i][j] = 0;
                        }
                    }
                SudokuSolver::solveBoard(board);
                if (board.checkIfSolved()) {
                    RESET_SCREEN
                    std::cout << "Solved!" << std::endl;
                } else {
                    RESET_SCREEN
                    std::cout << "Unable to solve!" << std::endl;
                }
                break;
            case 4:
                break;
            default:
                // Reset the screen to display the updated board and menu
            RESET_SCREEN
                std::cout << "Wrong input" << std::endl;
        }
    }

    // Clear the screen before exiting the game loop
    std::cout << CLEAR;
}

// Print the in-game menu
void Game::printIngameMenu() {
    std::cout << "0. Print game menu" << std::endl
              << "1. Set Cell (row, column, number)" << std::endl
              << "2. Check if board solved" << std::endl
              << "3. Solve board" << std::endl
              << "4. Pause" << std::endl;
}
