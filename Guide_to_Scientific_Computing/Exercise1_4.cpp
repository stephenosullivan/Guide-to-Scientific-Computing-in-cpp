//
//  Exercise1_4.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <stdlib.h>
#include <iostream>

void print_Matrix(double matrix[][2]){
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    // Initialize random generator
    srand(0);
    double A[2][2] = {{0, 0}, {0, 0}};
    double B[2][2] = {{0, 0}, {0, 0}};
    double C[2][2] = {{0, 0}, {0, 0}};
    double D[2][2] = {{0, 0}, {0, 0}};
    
    
    
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j){
            A[i][j] = rand()%10;
        }
    
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            B[i][j] = rand()%10;
    
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            C[i][j] = A[i][j] + B[i][j];
    
    
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                D[i][j] += A[i][k] * B[k][j];
    
    std::cout << "Matrix A is \n";
    print_Matrix(A);
    
    std::cout << "Matrix B is \n";
    print_Matrix(B);
    
    std::cout << "Matrix C is \n";
    print_Matrix(C);
    
    std::cout << "Matrix D is \n";
    print_Matrix(D);
    
    return 0;
}
