//
//  Exercise5_5.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/14/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

// Attempts to build function overloading but need to be more careful regarding vector - matrix multiplication

#include <iostream>
#include <cstdlib>

double** buildmatrix(int size){
    double** matrix = new double* [size];
    for (int i = 0; i < size; ++i)
    matrix[i] = new double[size];
    return matrix;
}

void deletematrix(double** matrix, int size){
    for (int i = 0; i < size; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
}

double* buildvector(int size){
    double* vector = new double[size];
    return vector;
}

double** matrixmultiply(double** matrixA, double** matrixB, int size){
    double** matrix = buildmatrix(size);
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                matrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return matrix;
}

double** matrixmultiply(double* vector, double** matrix, int size){
    double** output = buildmatrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; j++) {
            output[0][i] = matrix[j][i] * vector[j];
        }
    }
    return output;
}

double** matrixmultiply(double** matrix, double* vector, int size){
    double** output = buildmatrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; j++) {
            output[i][0] = matrix[i][j] * vector[j];
        }
    }
    return output;
}

double** matrixmultiply(double scalar, double** matrix, int size){
    double** output = buildmatrix(size);
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j) {
            output[i][j] = scalar * matrix[i][j];
        }
    }
    return output;
}

double** matrixmultiply(double** matrix, double scalar, int size){
    return matrixmultiply(scalar, matrix, size);
}

void printmatrix(double** matrix, int size){
    for (int i = 0; i < size; ++i){
        std::cout << "|";
        for (int j = 0; j < size; ++j){
            std::cout << matrix[i][j];
            if (j!=size-1){
                std::cout << " ";
            }
        }
        std::cout << "|\n";
    }
}

double** randommatrix(int size){
    double** matrix = buildmatrix(size);
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

double* randomvector(int size){
    double* vector = buildvector(size);
    for (int i = 0; i < size; ++i) {
        vector[i] = rand() % 10;
    }
    return vector;
}

int main(int argc, char* argv[]){
    srand(0);
    
    int size;
    if(argc > 1){
        size = atoi(argv[1]);
    }
    else{
        size = 2;
    }
    
    double** A = randommatrix(size);
    double** B = randommatrix(size);
    double** C = matrixmultiply(A, B, size);
    
    std::cout << "Matrix A\n";
    printmatrix(A, size);
    std::cout << "Matrix B\n";
    printmatrix(B, size);
    std::cout << "Matrix C = A x B\n";
    printmatrix(C, size);
    
    std::cout << "Vector x Matrix\n";
    double* randvector = randomvector(size);
    double* ptr;
    //printmatrix(randvector, size);
    printmatrix(matrixmultiply(randvector, C, size), size);
    
    deletematrix(A, size);
    deletematrix(B, size);
    deletematrix(C, size);
    
}