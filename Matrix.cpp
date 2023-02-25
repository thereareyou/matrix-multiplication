#include <iostream>
#include "Matrix.h"

Matrix::Matrix() : matrix(nullptr), matrix_size(int()) {}

Matrix::Matrix(int mtrx_size) : matrix_size(mtrx_size) {
    int matrix_element_count = matrix_size * matrix_size;
    matrix = new float[matrix_element_count];
    for(int i = 0; i < matrix_element_count; i++) {
        matrix[i] = getRandomFloatNumber();
    }
}

Matrix::Matrix(float* mtrx, int mtrx_size) :
    matrix(mtrx), matrix_size(mtrx_size) {}

Matrix::~Matrix() {
    delete [] matrix;
}


float* Matrix::getMatrix() {
    return matrix;
}

int Matrix::getMatrixSize() {
    return matrix_size;
}


float getRandomFloatNumber() {
    return (std::rand() % 1000) / 1000.0f;
}