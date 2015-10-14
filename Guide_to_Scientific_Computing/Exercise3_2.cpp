//
//  Exercise3_2.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/13/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    std::ifstream read_file("x_and_y.data");
    if (!read_file.is_open()) {
        return 1;
    }
    int number_of_rows = 0.;
    
    while (!read_file.eof()) {
        double dummy1, dummy2, dummy3, dummy4;
        read_file >> dummy1 >> dummy2;
        read_file >> dummy3 >> dummy4;
        if (!read_file.fail())
            number_of_rows++;
    }
    
    std::cout << "Number of rows = " << number_of_rows << "\n";
    read_file.close();
    
    return 0;
}
