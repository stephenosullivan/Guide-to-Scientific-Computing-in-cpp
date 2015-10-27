//
//  Exercise10_3.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/26/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include "LinearSystem.hpp"
#include "PosDefSymmLinearSystem.h"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Exception.h"
#include <cstdlib>

void fillWithRandom(Matrix& A){
    int rows = A.GetNumberOfRows();
    int cols = A.GetNumberOfColumns();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            A[i][j] = rand() % 10;
        }
    }
}

void fillWithRandom(Vector& v){
    int size = v.GetSize();
    for(int i = 0; i < size; ++i){
        v[i] = rand() % 10;
    }
}

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Need one argument parameter to set the matrix size\n";
        exit(0);
    }
    srand(0);
    int size = atoi(argv[1]);
    Matrix A(size, size);
    Vector b(size);
    fillWithRandom(A);
    fillWithRandom(b);
    
    for (int i = 0; i < A.GetNumberOfRows(); ++i) {
        for (int j = 0; j < A.GetNumberOfColumns(); ++j) {
            A[i][j] = 1;
        }
    }
    
    b[0] = 5;
    b[1] = 2;
    A[1][0] = 0;
    A[0][1] = 0;
    
    std::cout << "Matrix A is:\n";
    std::cout << A;
    
    std::cout << "Vector b is:\n";
    std::cout << b;
    
    LinearSystem solution(A, b);
    Vector x = solution.Solve();
    
    std::cout << "Vector x is:\n";
    std::cout << x;
    
    std::cout << "Test Answer:\n";
    std::cout << A*x;
    
    std::cout << "Try solving via conjugate gradient\n";
    PosDefSymmLinearSystem conj_solution(A, b, 0.001);
    Vector x0 = conj_solution.Solve();
    std::cout << "Vector x is:\n";
    std::cout << x0;
    
    
    return 0;
}
