//
//  Exercise2_6.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/13/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include<iostream>
#include<cmath>

double test_fn(double x){
    return exp(x) + pow(x,3) - 5.;
}

double test_fn_derivative(double x){
    return exp(x) + 3.*pow(x,2);
}

int main(){
    double epsilon = 1.e-6;
    double x = 0.;
    double diff;
    
    for (int i = 0; i < 100; ++i){
        diff = test_fn(x)/test_fn_derivative(x);
        std::cout << (x -= diff) <<  "\n";
        if (std::abs(diff/x) < 1.e-10){
            std::cout << "Tolerance reached: " << std::abs(diff/x) << "\n";
            break;
        }
    }
    return 0;
}
