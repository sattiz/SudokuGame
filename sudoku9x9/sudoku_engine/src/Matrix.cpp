#include "Matrix.h"

#include <iostream>

// Constructor to initialize a Matrix with the specified number of rows and columns
Matrix::Matrix(int rows_num, int cols_num) :
        values(rows_num, std::vector<Cell>(cols_num, Cell())) {}

// Function to find indices of cells in a row containing a specific value
std::vector<int> Matrix::rowContains(size_t index, int val) {
    std::vector<int> res{};
    for (int i = 0; i < values[0].size(); ++i)
        if (values[index][i] == val)
            res.push_back(i);

    return res;
}

// Function to find indices of cells in a column containing a specific value
std::vector<int> Matrix::columnContains(size_t index, int val) {
    std::vector<int> res{};
    for (int i = 0; i < values.size(); ++i)
        if (values[i][index] == val)
            res.push_back(i);
    return res;
}

// Function to get the number of rows in the matrix
size_t Matrix::getRows() {
    return values.size();
}

// Function to get the number of columns in the matrix
size_t Matrix::getColumns() {
    return values[0].size();
}

// Operator overloading to access a row in the matrix
std::vector<Cell> &Matrix::operator[](int index) {
    return values[index];
}

// Function to print the matrix in a visually formatted way
void Matrix::print() {
    std::cout << "      1       2       3       4       5       6       7       8       9" << '\n';
    std::cout << "  ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐" << "\n";
    for (int i = 0; i < this->getRows(); i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < this->getColumns(); j++) {
            std::cout << "│   " << int((*this)[i][j]) << "   ";
        }
        std::cout << "│" << "\n";
        std::cout << "  ";
        for (int j = 0; j < this->getColumns(); j++) {
            auto curr = (*this)[i][j];
            if(!curr) {
                std::cout << "│       ";
            } else {
                std::cout << "│   ─   ";
            }
        }
        std::cout << "│" << "\n";
        if (i < this->getRows() - 1)
            std::cout << "  ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤" << "\n";
    }
    std::cout << "  └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘" << "\n";
}
