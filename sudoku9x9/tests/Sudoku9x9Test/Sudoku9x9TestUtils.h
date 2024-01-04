#pragma once

#include "Sudoku9x9.h"

struct Sudoku9x9TestWrapper : public Sudoku9x9 {
    Sudoku9x9TestWrapper() : Sudoku9x9() {}

    std::pair<int, int> checkRowT(int index) {
        return this->checkRow(index);
    }

    std::pair<int, int> checkColumnT(int index) {
        return this->checkColumn(index);
    }

    std::tuple<int, int, int, int> checkSubgridT(int index) {
        return this->checkSubgrid(index);
    }

    Sudoku9x9TestWrapper& operator=(Sudoku9x9 &item) {
        this->loadBoard(item.dumpBoard());
        return *this;
    }

    Sudoku9x9TestWrapper& operator=(Sudoku9x9TestWrapper item) {
        this->loadBoard(item.dumpBoard());
        return *this;
    }

};
