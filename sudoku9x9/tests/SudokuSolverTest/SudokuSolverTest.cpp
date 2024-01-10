#define BOOST_TEST_MODULE SudokuSolverTest

#include <boost/test/included/unit_test.hpp>

#include "SudokuSolver.h"  // Assuming this is the header file containing SudokuSolver class

BOOST_AUTO_TEST_CASE(testSudokuSolver_solveBoard) {
    // Create an instance of Sudoku9x9
    Sudoku9x9 board = Sudoku9x9();
    std::string dump = "0+0+0+4+1+7+0+0+0+"
                       "0+0+0+9+5+3+0+0+0+"
                       "0+0+0+2+8+6+0+0+0+"
                       "0+0+0+0+0+0+6+7+1+"
                       "0+0+0+0+0+0+5+2+8+"
                       "0+0+0+0+0+0+4+3+9+"
                       "9+6+5+0+0+0+0+0+0+"
                       "7+1+4+0+0+0+0+0+0+"
                       "2+3+8+0+0+0+0+0+0+";
    board.loadBoard(dump);

    // Test solving the generated Sudoku board
    BOOST_CHECK(SudokuSolver::solveBoard(board));
    board.printBoard();

}


BOOST_AUTO_TEST_CASE(testSudokuSolver_unitTest) {
    Sudoku9x9 board = Sudoku9x9();

    SudokuSolver::generateBoard(board, 45);  // Generate a board with 20 numbers dropped

    board.printBoard();

    SudokuSolver::solveBoard(board);
    board.printBoard();
}

