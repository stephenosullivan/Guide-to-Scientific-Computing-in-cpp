//
//  assert_test.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cassert>

int main(int argc, char* argv[]){
    double testnum;
    while (true) {
        std::cout << "Enter a non-negative number\n";
        std::cin >> testnum;
        assert(testnum >= 0.);
        std::cout << "The sqrt of " << testnum << " is " << sqrt(testnum) << "\n";
    }
    return 0;
}
