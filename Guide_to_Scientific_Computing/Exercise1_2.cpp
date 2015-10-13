//
//  Exercise1_2.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>

int main(int, char**){
    std::cout << "Enter two numbers\n";
    int first = 0, second = 0;
    std::cin >> first;
    std::cin >> second;
    std::cout << "The product of " << first << " and " << second << " is " << first*second << "\n";
}
