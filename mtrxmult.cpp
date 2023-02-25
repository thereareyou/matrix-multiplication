#include <iostream>
#include "omp.h"
#include "Matrix.h"

float getMatrixCellValue(Matrix& mtrx1, int cell_row_index,
                         Matrix& mtrx2, int cell_column_index,
                         int matrix_vectors_length) {
    float cell_value = 0.0f;
    for(int i = 0; i < matrix_vectors_length; i++) {
        cell_value += mtrx1.getMatrix()[cell_row_index * matrix_vectors_length + i] *
            mtrx2.getMatrix()[i * matrix_vectors_length + cell_column_index];
    }
    return cell_value;
}

int main(int argc, char** argv) {
    int matrix_size = std::atoi(argv[1]);
    Matrix mtrx1(matrix_size);
    Matrix mtrx2(matrix_size);
    
    float* matricies_multiplication_result = new float[matrix_size * matrix_size];
    for(int i = 0; i < matrix_size; i++) {
        #pragma omp parallel for
        for(int j = 0; j < matrix_size; j++) {
            matricies_multiplication_result[i * matrix_size + j] = getMatrixCellValue(
                mtrx1, i, mtrx2, j, matrix_size);
        }
    }

    return 0;
}