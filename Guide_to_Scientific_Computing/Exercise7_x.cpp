//
//  Exercise7_x.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <stdio.h>
#include <iostream>

double f(double x){
    return x*x;
}

double g(double x){
    return x*x*x;
}



int main(){
    double (*ptr)(double x);
    ptr = &f;
    std::cout << ptr(10) << "\n";
    ptr = &g;
    std::cout << ptr(10) << "\n";
    return 0;
}