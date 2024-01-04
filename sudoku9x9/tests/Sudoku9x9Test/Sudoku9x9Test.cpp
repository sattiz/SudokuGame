#define BOOST_TEST_MODULE Sudoku9x9Tests

#include "Sudoku9x9TestUtils.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Sudoku9x9_load_dump_Test) {
    std::string dumps[] = {"2+5+4+2+0+7+1+4+9+"
                           "9+9-4-0+5+3-6-3+6+"
                           "2-2-6-1-9+7+9-0+6+"
                           "2+4-2+2-5-6+6-4-2+"
                           "9+3-7-9+6+4+6-5+4-"
                           "4-7-3-3+9-0+7-6+3-"
                           "2+2+3-0+2-7-9-9+2-"
                           "6+5-3-1-9+9+5+3-3+"
                           "0+6-1+6-4+4+2-2+3-",

                           "2+5+4+2+0+7+1+4+9+"
                           "9+9+4+0+5+3+6+3+6+"
                           "2+2+6+1+9+7+9+0+6+"
                           "2+4+2+2+5+6+6+4+2+"
                           "9+3+7+9+6+4+6+5+4+"
                           "4+7+3+3+9+0+7+6+3+"
                           "2+2+3+0+2+7+9+9+2+"
                           "6+5+3+1+9+9+5+3+3+"
                           "0+6+1+6+4+4+2+2+3+",

                           "2-5-4-2-0+7-1-4-9-"
                           "9-9-4-0+5-3-6-3-6-"
                           "2-2-6-1-9-7-9-0+6-"
                           "2-4-2-2-5-6-6-4-2-"
                           "9-3-7-9-6-4-6-5-4-"
                           "4-7-3-3-9-0+7-6-3-"
                           "2-2-3-0+2-7-9-9-2-"
                           "6-5-3-1-9-9-5-3-3-"
                           "0+6-1-6-4-4-2-2-3-",

                           "0+0+0+0+0+0+0+0+0+"
                           "0+0+0+0+0+0+0+0+0+"
                           "0+0+0+0+0+0+0+0+0+"
                           "0+0+0+0+0+0+0+0+0+"
                           "0+0+0+0+0+0+0+0+0+"
                           "0+0+0+0+0+0+0+0+0+"
                           "0+0+0+0+0+0+0+0+0+"
                           "0+0+0+0+0+0+0+0+0+"
                           "0+0+0+0+0+0+0+0+0+",

                           "1-3-6+8-1-6-7+1+2-"
                           "3+3-3-9-3-2+1+1+5-"
                           "2+1+8-6-3+2-1-6+2+"
                           "5-6-1-7+6+2+5+9-8+"
                           "3+2+3+6+9-5-6-2+2+"
                           "7+7-7-7-1+9+4+4-4-"
                           "4+7-4+8+2+1+6-4+8-"
                           "3+1+4+7+7-2+3-2-6-"
                           "9+9+4+4+2-8-2-6+6+",

                           "1+3+6+8+1+6+7+1+2+"
                           "3+3+3+9+3+2+1+1+5+"
                           "2+1+8+6+3+2+1+6+2+"
                           "5+6+1+7+6+2+5+9+8+"
                           "3+2+3+6+9+5+6+2+2+"
                           "7+7+7+7+1+9+4+4+4+"
                           "4+7+4+8+2+1+6+4+8+"
                           "3+1+4+7+7+2+3+2+6+"
                           "9+9+4+4+2+8+2+6+6+",

                           "1-3-6-8-1-6-7-1-2-"
                           "3-3-3-9-3-2-1-1-5-"
                           "2-1-8-6-3-2-1-6-2-"
                           "5-6-1-7-6-2-5-9-8-"
                           "3-2-3-6-9-5-6-2-2-"
                           "7-7-7-7-1-9-4-4-4-"
                           "4-7-4-8-2-1-6-4-8-"
                           "3-1-4-7-7-2-3-2-6-"
                           "9-9-4-4-2-8-2-6-6-"
    };

    for (const auto &dump: dumps) {
        Sudoku9x9TestWrapper board;
        board.loadBoard(dump);
        auto new_dump = board.dumpBoard();
        BOOST_CHECK_EQUAL(dump, new_dump);
    }
}

BOOST_AUTO_TEST_SUITE(Sudoku9x9_setCell)

    BOOST_AUTO_TEST_CASE(Test1) {
        Sudoku9x9TestWrapper board;
        std::string dump = "1-1-1+1-1-1-1+1+1-"
                           "1+1-1-1+1+1+1+1-1+"
                           "1+1-1-1+1+1+1-1+1-"
                           "1-1+1-1-1+1-1-1+1+"
                           "1+1+1+1-1-1+1+1-1-"
                           "1-1-1+1+1+1-1-1+1-"
                           "1+1+1+1+1-1+1-1+1+"
                           "1+1+1-1+1-1-1-1+1+"
                           "1+1-1-1-1+1+1+1+1-";
        board.loadBoard(dump);

        for (int i = 1; i < 10; i++)
            for (int j = 1; j < 10; ++j) {
                int cell_idx = (i - 1) * 18 + (j - 1) * 2;
                int state_idx = cell_idx + 1;
                if (dump[state_idx] == '+')
                    BOOST_CHECK(board.setCell(i, j, 5));
                else {
                    BOOST_CHECK(!board.setCell(i, j, 5));
                }
            }
        board.printBoard();
    }

    BOOST_AUTO_TEST_CASE(Test2) {
        Sudoku9x9TestWrapper board;
        std::string dump = "1+1+1+1+1+1+1+1+1+"
                           "1+1+1+1+1+1+1+1+1+"
                           "1+1+1+1+1+1+1+1+1+"
                           "1+1+1+1+1+1+1+1+1+"
                           "1+1+1+1+1+1+1+1+1+"
                           "1+1+1+1+1+1+1+1+1+"
                           "1+1+1+1+1+1+1+1+1+"
                           "1+1+1+1+1+1+1+1+1+"
                           "1+1+1+1+1+1+1+1+1+";
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++)
            for (int j = 1; j < 10; ++j) {
                int cell_idx = (i - 1) * 18 + (j - 1) * 2;
                int state_idx = cell_idx + 1;
                if (dump[state_idx] == '+')
                    BOOST_CHECK(board.setCell(i, j, 5));
                else {
                    BOOST_CHECK(!board.setCell(i, j, 5));
                }
            }
        board.printBoard();
    }

    BOOST_AUTO_TEST_CASE(Test3) {
        Sudoku9x9TestWrapper board;
        std::string dump = "1-1-1-1-1-1-1-1-1-"
                           "1-1-1-1-1-1-1-1-1-"
                           "1-1-1-1-1-1-1-1-1-"
                           "1-1-1-1-1-1-1-1-1-"
                           "1-1-1-1-1-1-1-1-1-"
                           "1-1-1-1-1-1-1-1-1-"
                           "1-1-1-1-1-1-1-1-1-"
                           "1-1-1-1-1-1-1-1-1-"
                           "1-1-1-1-1-1-1-1-1-";
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++)
            for (int j = 1; j < 10; ++j) {
                int cell_idx = (i - 1) * 18 + (j - 1) * 2;
                int state_idx = cell_idx + 1;
                if (dump[state_idx] == '+')
                    BOOST_CHECK(board.setCell(i, j, 5));
                else {
                    BOOST_CHECK(!board.setCell(i, j, 5));
                }
            }
        board.printBoard();
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Sudoku9x9_checkRow)

    BOOST_AUTO_TEST_CASE(Test1) {
        Sudoku9x9TestWrapper board;
        std::string dump;


        dump = ("1-1-1+1-1-1-1+1+1-"
                "1+1-1-1+1+1+1+1-1+"
                "1+1-1-1+1+1+1-1+1-"
                "1-1+1-1-1+1-1-1+1+"
                "1+1+1+1-1-1+1+1-1-"
                "1-1-1+1+1+1-1-1+1-"
                "1+1+1+1+1-1+1-1+1+"
                "1+1+1-1+1-1-1-1+1+"
                "1+1-1-1-1+1+1+1+1-");
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkRowT(i) == std::make_pair(2, 1));
        }


        dump = ("0+2+3+4+5+6+7+8+9+"
                "1+0+3+4+5+6+7+8+9+"
                "1+2+0+4+5+6+7+8+9+"
                "1+2+3+0+5+6+7+8+9+"
                "1+2+3+4+0+6+7+8+9+"
                "1+2+3+4+5+0+7+8+9+"
                "1+2+3+4+5+6+0+8+9+"
                "1+2+3+4+5+6+7+0+9+"
                "1+2+3+4+5+6+7+8+0-");
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkRowT(i) == std::make_pair(i, -1));
        }

        dump = ("1+2+3+4+5+6+7+8+8+"
                "1+2+3+4+5+6+7+8+8+"
                "1+2+3+4+5+6+7+8+8+"
                "1+2+3+4+5+6+7+8+8+"
                "1+2+3+4+5+6+7+8+8+"
                "1+2+3+4+5+6+7+8+8+"
                "1+2+3+4+5+6+7+8+8+"
                "1+2+3+4+5+6+7+8+8+"
                "1+2+3+4+5+6+7+8+8+");
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkRowT(i) == std::make_pair(9, 8));
        }


        dump = ("1+2+3+4+5+6+7+8+9+"
                "1+2+3+4+5+6+7+8+9+"
                "1+2+3+4+5+6+7+8+9+"
                "1+2+3+4+5+6+7+8+9+"
                "1+2+3+4+5+6+7+8+9+"
                "1+2+3+4+5+6+7+8+9+"
                "1+2+3+4+5+6+7+8+9+"
                "1+2+3+4+5+6+7+8+9+"
                "1+2+3+4+5+6+7+8+9+");
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkRowT(i) == std::make_pair(-1, -1));
        }

        dump = ("9+2+3+4+5+6+7+8+9+"
                "9+2+3+4+5+6+7+8+9+"
                "9+2+3+4+5+6+7+8+9+"
                "9+2+3+4+5+6+7+8+9+"
                "9+2+3+4+5+6+7+8+9+"
                "9+2+3+4+5+6+7+8+9+"
                "9+2+3+4+5+6+7+8+9+"
                "9+2+3+4+5+6+7+8+9+"
                "9+2+3+4+5+6+7+8+9+");
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkRowT(i) == std::make_pair(9, 1));
        }
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Sudoku9x9_checkColumn)

    BOOST_AUTO_TEST_CASE(Test1) {
        Sudoku9x9TestWrapper board;
        std::string dump;

        dump = ("1-1-1+1-1-1-1+1+1-"
                "1+1-1-1+1+1+1+1-1+"
                "1+1-1-1+1+1+1-1+1-"
                "1-1+1-1-1+1-1-1+1+"
                "1+1+1+1-1-1+1+1-1-"
                "1-1-1+1+1+1-1-1+1-"
                "1+1+1+1+1-1+1-1+1+"
                "1+1+1-1+1-1-1-1+1+"
                "1+1-1-1-1+1+1+1+1-");
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkColumnT(i) == std::make_pair(2, 1));
        }
    }

    BOOST_AUTO_TEST_CASE(Test2) {
        Sudoku9x9TestWrapper board;
        std::string dump;
        dump = "0+1+1-1+1+1+1+1+1-"
               "2+0+2+2+2+2+2+2-2+"
               "3-3-0+3+3-3-3-3+3+"
               "4-4+4+0-4+4-4-4-4+"
               "5-5+5-5+0-5-5+5+5+"
               "6+6-6+6+6+0-6-6-6-"
               "7+7-7-7+7-7+0+7+7+"
               "8-8-8-8+8-8+8+0+8-"
               "9-9-9+9+9-9+9-9-0-";
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkColumnT(i) == std::make_pair(i, -1));
        }
    }

    BOOST_AUTO_TEST_CASE(Test3) {
        Sudoku9x9TestWrapper board;
        std::string dump;
        dump = "1+1+1-1+1+1+1+1+1-"
               "2+2+2+2+2+2+2+2-2+"
               "3-3-3+3+3-3-3-3+3+"
               "4-4+4+4-4+4-4-4-4+"
               "5-5+5-5+5-5-5+5+5+"
               "6+6-6+6+6+6-6-6-6-"
               "7+7-7-7+7-7+7+7+7+"
               "8-8-8-8+8-8+8+8+8-"
               "8-8-8+8+8-8+8-8-8-";
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkColumnT(i) == std::make_pair(9, 8));
        }
    }

    BOOST_AUTO_TEST_CASE(Test4) {
        Sudoku9x9TestWrapper board;
        std::string dump;
        dump = "1+1+1-1+1+1+1+1+1-"
               "2+2+2+2+2+2+2+2-2+"
               "3-3-3+3+3-3-3-3+3+"
               "4-4+4+4-4+4-4-4-4+"
               "5-5+5-5+5-5-5+5+5+"
               "6+6-6+6+6+6-6-6-6-"
               "7+7-7-7+7-7+7+7+7+"
               "8-8-8-8+8-8+8+8+8-"
               "9-9-9+9+9-9+9-9-9-";
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkColumnT(i) == std::make_pair(-1, -1));
        }
    }

    BOOST_AUTO_TEST_CASE(Test5) {
        Sudoku9x9TestWrapper board;
        std::string dump;
        dump = "9+9+9-9+9+9+9+9+9-"
               "2+2+2+2+2+2+2+2-2+"
               "3-3-3+3+3-3-3-3+3+"
               "4-4+4+4-4+4-4-4-4+"
               "5-5+5-5+5-5-5+5+5+"
               "6+6-6+6+6+6-6-6-6-"
               "7+7-7-7+7-7+7+7+7+"
               "8-8-8-8+8-8+8+8+8-"
               "9-9-9+9+9-9+9-9-9-";
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            BOOST_CHECK(board.checkColumnT(i) == std::make_pair(9, 1));
        }
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Sudoku9x9_checkSubgrid)

    BOOST_AUTO_TEST_CASE(Test1) {
        Sudoku9x9TestWrapper board;
        std::string dump;

        dump = "1-1-1+1-1-1-1+1+1-"
               "1+1-1-1+1+1+1+1-1+"
               "1+1-1-1+1+1+1-1+1-"
               "1-1+1-1-1+1-1-1+1+"
               "1+1+1+1-1-1+1+1-1-"
               "1-1-1+1+1+1-1-1+1-"
               "1+1+1+1+1-1+1-1+1+"
               "1+1+1-1+1-1-1-1+1+"
               "1+1-1-1-1+1+1+1+1-";
        std::tuple<int, int, int, int> results[] = {
                std::make_tuple(1, 2, 1, 1),
                std::make_tuple(1, 5, 1, 4),
                std::make_tuple(1, 8, 1, 7),
                std::make_tuple(4, 2, 4, 1),
                std::make_tuple(4, 5, 4, 4),
                std::make_tuple(4, 8, 4, 7),
                std::make_tuple(7, 2, 7, 1),
                std::make_tuple(7, 5, 7, 4),
                std::make_tuple(7, 8, 7, 7)
        };
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            auto [cell1_x, cell1_y, cell2_x, cell2_y] = board.checkSubgridT(i);
            BOOST_CHECK(board.checkSubgridT(i) == results[i - 1]);
        }
    }

    BOOST_AUTO_TEST_CASE(Test2) {
        Sudoku9x9TestWrapper board;
        std::string dump;

        dump = "1-2+3-4+5-6+7-8+9+"
               "4-5+6-7+8-9+1-2+3+"
               "7-8+9-1+2-3+4-5+6+"
               "2-3+4-5+6-7+8-9+1+"
               "5-6+7-8+9-1+2-3+4+"
               "8-9+1-2+3-4+5-6+7+"
               "3-4+5-6+7-8+9-1+2+"
               "6-7+8-9+1-2+3-4+5+"
               "9-1+2-3+4-5+6-7+8+";
        std::tuple<int, int, int, int> results[] = {
                std::make_tuple(-1, -1, -1, -1),
                std::make_tuple(-1, -1, -1, -1),
                std::make_tuple(-1, -1, -1, -1),
                std::make_tuple(-1, -1, -1, -1),
                std::make_tuple(-1, -1, -1, -1),
                std::make_tuple(-1, -1, -1, -1),
                std::make_tuple(-1, -1, -1, -1),
                std::make_tuple(-1, -1, -1, -1),
                std::make_tuple(-1, -1, -1, -1)
        };
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            auto [cell1_x, cell1_y, cell2_x, cell2_y] = board.checkSubgridT(i);
            BOOST_CHECK(board.checkSubgridT(i) == results[i - 1]);
        }
    }

    BOOST_AUTO_TEST_CASE(Test3) {
        Sudoku9x9TestWrapper board;
        std::string dump;

        dump = "1-2+3-0+5-6+7-8+9+"
               "4-5+0-7+8-9+1-2+3+"
               "7-8+9-1+2-3+0-5+6+"
               "2-3+4-5+0-7+8-9+1+"
               "5-6+7-8+9-1+2-3+4+"
               "8-9+0-2+3-4+5-0+7+"
               "3-4+5-0+7-8+9-1+2+"
               "6-7+8-9+1-2+3-4+0+"
               "0-1+2-3+4-5+6-7+8+";
        std::tuple<int, int, int, int> results[] = {
                std::make_tuple(2, 3, -1, -1),
                std::make_tuple(1, 4, -1, -1),
                std::make_tuple(3, 7, -1, -1),
                std::make_tuple(6, 3, -1, -1),
                std::make_tuple(4, 5, -1, -1),
                std::make_tuple(6, 8, -1, -1),
                std::make_tuple(9, 1, -1, -1),
                std::make_tuple(7, 4, -1, -1),
                std::make_tuple(8, 9, -1, -1)
        };
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            auto [cell1_x, cell1_y, cell2_x, cell2_y] = board.checkSubgridT(i);
            BOOST_CHECK(board.checkSubgridT(i) == results[i - 1]);
        }
    }

    BOOST_AUTO_TEST_CASE(Test4) {
        Sudoku9x9TestWrapper board;
        std::string dump;

        dump = "0+0+0+0+0+0+0+0+0+"
               "0+0+0+0+0+0+0+0+0+"
               "0+0+0+0+0+0+0+0+0+"
               "0+0+0+0+0+0+0+0+0+"
               "0+0+0+0+0+0+0+0+0+"
               "0+0+0+0+0+0+0+0+0+"
               "0+0+0+0+0+0+0+0+0+"
               "0+0+0+0+0+0+0+0+0+"
               "0+0+0+0+0+0+0+0+0+";
        std::tuple<int, int, int, int> results[] = {
                std::make_tuple(1, 1, -1, -1),
                std::make_tuple(1, 4, -1, -1),
                std::make_tuple(1, 7, -1, -1),
                std::make_tuple(4, 1, -1, -1),
                std::make_tuple(4, 4, -1, -1),
                std::make_tuple(4, 7, -1, -1),
                std::make_tuple(7, 1, -1, -1),
                std::make_tuple(7, 4, -1, -1),
                std::make_tuple(7, 7, -1, -1)
        };
        board.loadBoard(dump);
        for (int i = 1; i < 10; i++) {
            auto [cell1_x, cell1_y, cell2_x, cell2_y] = board.checkSubgridT(i);
            std::cout << cell1_x << " " << cell1_y << " " << cell2_x << " " << cell2_y;
            BOOST_CHECK(board.checkSubgridT(i) == results[i - 1]);
        }
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Sudoku9x9_checkIfSolved)

    BOOST_AUTO_TEST_CASE(Test1) {
        Sudoku9x9TestWrapper board;
        std::string dump;

        dump = "1-2+3-4+5-6+7-8+9+"
               "4-5+6-7+8-9+1-2+3+"
               "7-8+9-1+2-3+4-5+6+"
               "2-3+4-5+6-7+8-9+1+"
               "5-6+7-8+9-1+2-3+4+"
               "8-9+1-2+3-4+5-6+7+"
               "3-4+5-6+7-8+9-1+2+"
               "6-7+8-9+1-2+3-4+5+"
               "9-1+2-3+4-5+6-7+8+";
        board.loadBoard(dump);
        BOOST_CHECK(board.checkIfSolved() == true);
    }

    BOOST_AUTO_TEST_CASE(Test2) {
        Sudoku9x9TestWrapper board;
        std::string dump;

        dump = "1-2+3-4+5-6+7-8+9+"
               "4-2+6-7+8-9+1-2+3+"
               "7-8+9-1+2-3+4-5+6+"
               "2-3+4-5+6-7+8-9+1+"
               "5-6+7-8+9-1+2-3+4+"
               "8-9+1-2+3-4+5-6+7+"
               "3-4+5-6+7-8+9-1+2+"
               "6-7+8-9+1-2+3-4+5+"
               "9-1+2-3+4-5+6-7+8+";
        board.loadBoard(dump);
        BOOST_CHECK(board.checkIfSolved() == false);
    }

BOOST_AUTO_TEST_SUITE_END()