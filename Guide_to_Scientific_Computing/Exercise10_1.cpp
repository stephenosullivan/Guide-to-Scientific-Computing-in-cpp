//
//  Exercise10_1.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/25/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include "Vector.cpp"
#include "Exception.h"


int main(){
    int size = 10;
    Vector v1(size);
    for (int i = 0; i < size; ++i) {
        v1[i] = i;
    }
    std::cout << v1[2] << "\n";
    std::cout << v1(3) << "\n";
    std::cout << v1.Read(2) << "\n";
    std::cout << v1;
    
    Vector v2(size-1);
    std::cout << v1 + v2;
    return 0;
}