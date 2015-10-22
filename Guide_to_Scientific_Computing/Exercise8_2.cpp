//
//  Exercise8_2.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/22/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>


template <class T>
T abs(T num) {
    if (num < 0) {
        return -num;
    }
    else{
        return num;
    }
}

int main(){
    srand(10);
    int size = 10;
    int* p_int = new int[size];
    double* p_double = new double[size];
    
    for (int i = 0; i < size; ++i) {
        p_int[i] = (rand() %10) - 5;
        p_double[i] = ((double)(p_int[i] % 10) / (11.)) - 5. ;
    }
    
    for (int i = 0; i < size; ++i) {
        std::cout << abs<int>(p_int[i]) << "\n";
    }
    
    std::cout << "\n";
    
    for (int i = 0; i < size; ++i) {
        std::cout << abs<double>(p_double[i]) << "\n";
    }
    return 0;
}
