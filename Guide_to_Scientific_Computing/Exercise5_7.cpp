//
//  Exercise5_7.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/15/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

// Calculate the p-norm of a vector

#include <stdio.h>
#include <cmath>
#include <iostream>

double CalculateNorm(double* x, int vecSize, int p=2){
    double sum = 0.0;
    for (int i = 0; i < vecSize; i++) {
        double temp = fabs(x[i]);
        sum += pow(temp, p);
    }
    return pow(sum, 1./p);
}

int main(){
    srand(0);
    int size;
    int p = 0;
    
    std::cout << "Enter the length of the randomized vector:\n";
    std::cin >> size;
    double* vector = new double[size];
    
    for(int i = 0; i < size; ++i){
        vector[i] = rand() % 10;
    }
    
    std::cout << "Enter \'p\' for the p-norm:\n";
    while (p<=0) {
        std::cin >> p;
        std::cout << "Need a positive definite value for p\n";
    }
    
    
    std::cout << "The " << p << "-norm of [";
    for (int i = 0; i < size; ++i) {
        std::cout << vector[i];
        if (i != size-1){
            std::cout << " ";
        }
    }
    std::cout << "] is ";
    std::cout << CalculateNorm(vector, size, p) << "\n";
    return 0;
}