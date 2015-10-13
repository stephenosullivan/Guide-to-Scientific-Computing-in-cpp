//
//  keyboard_input.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::string name;
    std::cout << "Enter your name then hit RETURN!\n" ;
    std::getline(std::cin, name);
    std::cout << "Your name is: " << name << std::endl;
}
