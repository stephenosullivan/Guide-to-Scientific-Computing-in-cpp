//
//  Exercise9_2.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/23/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <stdio.h>
#include <new>
#include <iostream>

int main(){
    double* p_x;
    try{
        p_x = new double[1000000000000];
    }
    catch(std::bad_alloc& alloc){
        std::cerr << "Alloc caught: " << alloc.what() << "\n";
    }
    delete p_x;
    std::cout << sizeof(double) << "\n";
    return 0;
}