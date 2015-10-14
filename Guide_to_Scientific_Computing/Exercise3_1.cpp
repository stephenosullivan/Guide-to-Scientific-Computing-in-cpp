//
//  Exercise3_1.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/13/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cassert>


int main(int argc, char* argv[]){
    double x[4] = {0., 1., 1., 0.};
    double y[4] = {0., 0., 1., 1.};
    
    std::ofstream write_file("x_and_y.data");
    assert(write_file.is_open());
    
    write_file.setf(std::ios::scientific);
    write_file.precision(10);
    write_file.setf(std::ios::showpos);
    
    for (int i = 0; i < 4; ++i) {
        write_file << x[i] << " ";
    }
    write_file << "\n";
    
    write_file.flush();
    
    for (int i = 0; i < 4; ++i) {
        write_file << y[i] << " ";
    }
    write_file << "\n";
    return 0;
}
