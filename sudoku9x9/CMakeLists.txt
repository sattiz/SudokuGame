cmake_minimum_required(VERSION 3.27)
project(sudoku9x9)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SUDOKU_SRCS sudoku_engine/src/*.cpp)
file(GLOB APP_SRC app/src/*.cpp)

add_executable(MatrixTest)
file(GLOB MATRIX_TEST_SRCS tests/MatrixTest/*.cpp)
target_include_directories(MatrixTest PUBLIC
        sudoku_engine/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/MatrixTest
)
target_sources(MatrixTest PUBLIC
        ${SUDOKU_SRCS}
        ${MATRIX_TEST_SRCS}
)


add_executable(Sudoku9x9Test)
file(GLOB SUDOKU9X9_TEST_SRC tests/Sudoku9x9Test/*.cpp)
target_include_directories(Sudoku9x9Test PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sudoku_engine/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/Sudoku9x9Test
)
target_sources(Sudoku9x9Test PUBLIC
        ${SUDOKU_SRCS}
        ${SUDOKU9X9_TEST_SRC}
)

add_executable(SudokuSolverTest)
file(GLOB SUDOKUSOLVER_TEST_SRC tests/SudokuSolverTest/*.cpp)
target_include_directories(SudokuSolverTest PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sudoku_engine/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/SudokuSolverTest
)
target_sources(SudokuSolverTest PUBLIC
        ${SUDOKU_SRCS}
        ${SUDOKUSOLVER_TEST_SRC}
)

add_executable(sudoku.run)
target_include_directories(sudoku.run PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/app/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/sudoku_engine/headers
)
target_sources(sudoku.run PUBLIC
        main.cpp
        ${SUDOKU_SRCS}
        ${APP_SRC}
)

