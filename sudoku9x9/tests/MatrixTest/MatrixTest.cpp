#define BOOST_TEST_MODULE MatrixTests

#include <boost/test/included/unit_test.hpp>

#include "MatrixTestUtils.h"

BOOST_AUTO_TEST_CASE(ConstructorTest) {
    Matrix matrix(9, 9);

    BOOST_CHECK_EQUAL(matrix.getRows(), 9);
    BOOST_CHECK_EQUAL(matrix.getColumns(), 9);

    for (size_t i = 0; i < matrix.getRows(); ++i) {
        for (size_t j = 0; j < matrix.getColumns(); ++j) {
            BOOST_CHECK_EQUAL(int(matrix[i][j]), 0);
        }
    }

    matrix.print();
}

BOOST_AUTO_TEST_CASE(PrintTest) {
    Matrix mtr = init_matrix2(9, 9);

    std::cout << "Matrix:" << std::endl;
    mtr.print();
    std::cout << std::endl;
}

BOOST_AUTO_TEST_CASE(RowContainsTest) {
    Matrix mtr = init_matrix(9, 9);

    std::cout << "Matrix:" << std::endl;
    mtr.print();
    std::cout << std::endl;

    bool check = mtr.rowContains(0, 0) ==
                 std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8};
    BOOST_CHECK(check);
    BOOST_CHECK(mtr.rowContains(0, 1).empty());  // Expected result: The vector is empty
    BOOST_CHECK(mtr.rowContains(0, 81).empty()); // Expected result: The vector is empty

    BOOST_CHECK(mtr.rowContains(1, 0).empty());  // Expected result: The vector is empty
    BOOST_CHECK(mtr.rowContains(1, 1) == std::vector<int>{0});
    BOOST_CHECK(mtr.rowContains(1, 2) == std::vector<int>{1});
    BOOST_CHECK(mtr.rowContains(1, 8) == std::vector<int>{7});
    BOOST_CHECK(mtr.rowContains(1, 9) == std::vector<int>{8});
    BOOST_CHECK(mtr.rowContains(1, 10).empty()); // Expected result: The vector is empty

    BOOST_CHECK(mtr.rowContains(3, 0).empty());  // Expected result: The vector is empty
    BOOST_CHECK(mtr.rowContains(3, 3) == std::vector<int>{0});
    BOOST_CHECK(mtr.rowContains(3, 6) == std::vector<int>{1});
    BOOST_CHECK(mtr.rowContains(3, 24) == std::vector<int>{7});
    BOOST_CHECK(mtr.rowContains(3, 7).empty());  // Expected result: The vector is empty

    BOOST_CHECK(mtr.rowContains(8, 0).empty());  // Expected result: The vector is empty
    BOOST_CHECK(mtr.rowContains(8, 8) == std::vector<int>{0});
    BOOST_CHECK(mtr.rowContains(8, 16) == std::vector<int>{1});
    BOOST_CHECK(mtr.rowContains(8, 24) == std::vector<int>{2});
    BOOST_CHECK(mtr.rowContains(8, 32) == std::vector<int>{3});
    BOOST_CHECK(mtr.rowContains(8, 1).empty());  // Expected result: The vector is empty
    BOOST_CHECK(mtr.rowContains(8, 8 * 9) == std::vector<int>{8});
    BOOST_CHECK(mtr.rowContains(8, 83).empty()); // Expected result: The vector is empty

}

BOOST_AUTO_TEST_CASE(ColumnContainsTest) {
    Matrix mtr = init_matrix(9, 9);

    std::cout << "Matrix:" << std::endl;
    mtr.print();
    std::cout << std::endl;

    BOOST_CHECK(mtr.columnContains(0, 0) == std::vector<int>{0});
    BOOST_CHECK(mtr.columnContains(0, 1) == std::vector<int>{1});
    BOOST_CHECK(mtr.columnContains(0, 81).empty());  // Expected result: The vector is empty

    BOOST_CHECK(mtr.columnContains(1, 0) == std::vector<int>{0});
    BOOST_CHECK(mtr.columnContains(1, 1).empty());    // Expected result: The vector is empty
    BOOST_CHECK(mtr.columnContains(1, 2) == std::vector<int>{1});
    BOOST_CHECK(mtr.columnContains(1, 8) == std::vector<int>{4});
    BOOST_CHECK(mtr.columnContains(1, 9).empty());    // Expected result: The vector is empty
    BOOST_CHECK(mtr.columnContains(1, 10) == std::vector<int>{5});

    BOOST_CHECK(mtr.columnContains(3, 0) == std::vector<int>{0});
    BOOST_CHECK(mtr.columnContains(3, 3).empty());    // Expected result: The vector is empty
    BOOST_CHECK(mtr.columnContains(3, 6).empty());    // Expected result: The vector is empty
    BOOST_CHECK(mtr.columnContains(3, 24) == std::vector<int>{6});
    BOOST_CHECK(mtr.columnContains(3, 7).empty());    // Expected result: The vector is empty

    BOOST_CHECK(mtr.columnContains(8, 0) == std::vector<int>{0});
    BOOST_CHECK(mtr.columnContains(8, 8).empty());    // Expected result: The vector is empty
    BOOST_CHECK(mtr.columnContains(8, 18) == std::vector<int>{2});
    BOOST_CHECK(mtr.columnContains(8, 27) == std::vector<int>{3});
    BOOST_CHECK(mtr.columnContains(8, 36) == std::vector<int>{4});
    BOOST_CHECK(mtr.columnContains(8, 1).empty());    // Expected result: The vector is empty
    BOOST_CHECK(mtr.columnContains(8, 72) == std::vector<int>{8});
    BOOST_CHECK(mtr.columnContains(8, 83).empty());   // Expected result: The vector is empty
}


