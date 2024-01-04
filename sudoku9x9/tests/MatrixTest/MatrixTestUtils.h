//
// Created by vladimir on 26.12.23.
//

#pragma once

#include "Matrix.h"

// fill matrix with "i * j + i" values
auto init_matrix(int row_num, int column_num) {
    Matrix matrix(row_num, column_num);

    for (int i = 0; i < row_num; i++)
        for (int j = 0; j < column_num; j++)
            matrix[i][j] = i * j + i;

    return matrix;
}


// makes all each cell of matrix immutable
auto init_matrix2(int row_num, int column_num) {
    Matrix matrix(row_num, column_num);

    for (int i = 0; i < row_num; i++)
        for (int j = 0; j < column_num; j++) {
            matrix[i][j] = (i * j + i) % 10;
            if (int(matrix[i][j]) % 2) {
                matrix[i][j].switchMod();
            }
        }

    return matrix;
}

