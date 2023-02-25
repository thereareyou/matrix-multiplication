#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    float* matrix;
    int matrix_size;

    public:
        Matrix();
        Matrix(int size);
        Matrix(float* mtrx, int mtrx_size);
        ~Matrix();

        float* getMatrix();
        int getMatrixSize();
};

float getRandomFloatNumber();

#endif