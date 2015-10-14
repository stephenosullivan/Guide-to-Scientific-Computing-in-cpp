//
//  Exercise4_4.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/14/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include <cstdlib>

double** matrix_build(int size){
    double** matrix = new double*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new double[size];
    }
    return matrix;
}

void matrix_delete(double** matrix, int size){
    for (int i = 0; i < size; ++i) {
        delete [] matrix[i];
    }
    delete[] matrix;
}

void print_matrix(double** matrix, int size){
    std::cout.setf(std::ios::scientific);
    std::cout.precision(3);
    
    for (int i = 0; i < size; ++i){
        std::cout << "|";
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j];
            if (j != size-1)
                std::cout << " ";
        }
    std::cout << "|\n";
    }
}

int main(){
    srand(0);
    
    for(int i = 0; i < 1e9; ++i){
        double **A = matrix_build(2);
        double **B = matrix_build(2);
        double **C = matrix_build(2);
        
        
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j) {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
            }
        
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                C[i][j] = A[i][j] + B[i][j];
        
        print_matrix(C, 2);
        
        matrix_delete(A, 2);
        matrix_delete(B, 2);
        matrix_delete(C, 2);
    }
    return 0;
}
