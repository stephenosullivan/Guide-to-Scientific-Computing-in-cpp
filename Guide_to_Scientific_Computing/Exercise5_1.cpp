//
//  Exercise5_1.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/14/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

// Send the address of an int to a func that prints out the value of that int

#include <iostream>

void print_value(int* i){
    std::cout << *i << "\n";
}

int main(){
    int i = 5;
    print_value(&i);
    return 0;
}
