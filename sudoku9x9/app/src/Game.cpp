#include "../headers/Game.h"
#include "SudokuSolver.h"

#define RESET_SCREEN     std::cout << CLEAR; \
                            board.printBoard(); \
                            printIngameMenu(); \


void Game::run(Sudoku9x9 &board) {
    int choose = 42;
    int row, col, num;
    bool check;

    RESET_SCREEN
    while (choose != 4) {
        std::cout << "Enter key: ";
        getKey(choose);
        switch (choose) {
            case 0:
            RESET_SCREEN
                break;
            case 1:
                row = -1, col = -1, num = -1;
                std::cout << "Enter row column number: ";
                getKey(row, col, num);
                
                if (!board.setCell(row, col, num)) {
                    RESET_SCREEN
                        std::cout << "Unable to set num" << std::endl;
                }
                else {
                    RESET_SCREEN
                    std::cout << "Number " << num << " is set on " << row << ":" << col << std::endl;
                }

                break;
            case 2:
                check = board.checkIfSolved();
                RESET_SCREEN
                if (check) {
                    std::cout << "Board is solved!" << std::endl;
                } else {
                    std::cout << "Board is not solved" << std::endl;
                }
                break;
            case 3:

                for (int i = 0; i < board.getRows(); i++)
                    for (int j = 0; j < board.getColumns(); ++j) {
                        if (board[i][j]) {
                            board[i][j] = 0;
                        }
                    }

                if (SudokuSolver::solveBoard(board)) {
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
            RESET_SCREEN
                std::cout << "Wrong input" << std::endl;
        }
    }
    std::cout << CLEAR;
}

void Game::printIngameMenu() {
    std::cout << "0. Print game menu" << std::endl
              << "1. Set Cell (row, column, number)" << std::endl
              << "2. Check if board solved" << std::endl
              << "3. Solve board" << std::endl
              << "4. Pause" << std::endl;
}