//
//  Exercise2_5.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cassert>

void print_matrix(double matrix[][2]){
    
    for (int i = 0; i < 2; ++i){
        std::cout << "|";
        for (int j = 0; j < 2; ++j){
            std::cout << matrix[i][j];
            if(j != 1)
                std::cout << " ";
        }
        std::cout << "|\n";
    }
}

int main(){
    double A[2][2] = {{4., 10.}, {1., 1.}};
    double inverseA[2][2];
    
    double determinant = A[1][1]*A[0][0] - A[1][0]*A[0][1];
    assert(determinant != 0);
    
    double inverse_det = pow(determinant, -1);
    
    inverseA[0][0] =  inverse_det * A[1][1];
    inverseA[1][0] = - inverse_det * A[1][0];
    inverseA[1][1] =  inverse_det * A[0][0];
    inverseA[0][1] = - inverse_det * A[0][1];
    
    
    std::cout << "Matrix A:\n";
    print_matrix(A);
    std::cout << "Inverse A:\n";
    print_matrix(inverseA);
    return 0;
}

