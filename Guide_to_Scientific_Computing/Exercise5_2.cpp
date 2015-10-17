//
//  Exercise5_2.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/14/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

// Send the address of an int to a func that changes the value of the int

#include <iostream>

void times2(int* i){
    *i = 2 * (*i);
}

int main(){
    int i = 5;
    std::cout << i << "\n";
    times2(&i);
    std::cout << i << "\n";
    return 0;
}
