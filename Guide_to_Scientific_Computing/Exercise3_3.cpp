//
//  Exercise3_3.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/13/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

// Implement the implicit Euler method to solve the initial value ODE
//              dy/dx = -y,     y(0) = 1

#include <iostream>
#include <cassert>
#include <fstream>
#include <cmath>

int main(int argc, char* argv[]){
    int number_of_grid_points = atoi(argv[1]);
    assert(number_of_grid_points > 0);
    
    double y = 1.;
    double x = 0.;
    double stepsize = 1./(number_of_grid_points-1);
    
    std::ofstream write_file("xy.dat");
    assert(write_file.is_open());
    
    
    write_file << x << " " << y << " " << exp(-x) << "\n";
    for (int i = 0; i < number_of_grid_points - 1; ++i){
        write_file << (x += stepsize) << " " << (y *= (1./(1. + stepsize))) << " " << exp(-x) << "\n";
    }
    write_file.close();
    
    return 0;
}
