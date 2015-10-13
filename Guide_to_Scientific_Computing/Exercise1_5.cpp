//
//  Exercise1_5.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>

int main(){
    std::string first, second;
    std::cout << "Enter your first name: ";
    std::getline(std::cin, first);
    std::cout << "Enter your surname: ";
    std::getline(std::cin, second);
    std::cout << "Your name is: " << first << " " << second << "\n";
    
    return 0;
}
