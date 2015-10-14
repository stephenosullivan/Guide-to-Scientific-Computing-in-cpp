//
//  Exercise2_4.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>

void print_vector(double vector[], int size){
    std::cout << "[";
    for (int i = 0; i < size; ++i){
        std::cout << vector[i];
        if (i != size-1)
            std::cout << ", ";
    }
    std::cout  << "]";
}

void print_matrix(double matrix[][3], int size){
    std::cout << "\n[";
    for (int i = 0; i < size; ++i){
        std::cout << "[";
        for (int j = 0; j < size; ++j){
            std::cout << matrix[i][j];
            if (j != size-1)
                std::cout << ", ";
        }
        if (i != size-1)
            std::cout  << "],\n";
    }
    std::cout  << "]]\n";
}




int main(){
    double u[3] = {1.0, 2.0, 3.0};
    double v[3] = {6.0, 5.0, 4.0};
    double A[3][3]  = { {1., 5., 0.},
        {7., 1., 2.},
        {0., 0., 1.}};
    double B[3][3] = {{-2., 0., 1.},
        {1., 0., 0.},
        {4., 1., 0.}};
    double w[3];
    
    for (int i=0; i<3; ++i)
        w[i] = u[i] - 3.*v[i];
    
    
    double x[3], y[3], z[3];
    double C[3][3], D[3][3];
    
    for (int i = 0; i < 3; ++i) {
        x[i] = u[i] - v[i];
    }
    
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            y[i] += A[i][j] * u[j];
    
    for (int i = 0; i < 3; ++i)
        z[i] = y[i] - v[i];
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            C[i][j] = 4. * A[i][j] - 3. * B[i][j];
        }
    }
    
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                D[i][j] += A[i][k] * B[k][j];
    
    std::cout << "Vector x: ";
    print_vector(x, 3);
    std::cout << "\n";
    
    std::cout << "Vector y: ";
    print_vector(y, 3);
    std::cout << "\n";
    
    std::cout << "Vector z: ";
    print_vector(z, 3);
    std::cout << "\n";
    
    std::cout << "Matrix C: ";
    print_matrix(C, 3);
    std::cout << "\n";
    
    std::cout << "Matrix D: ";
    print_matrix(D, 3);
    std::cout << "\n";
    
    return 0;
}
