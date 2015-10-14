//
//  Exercise2_3.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>

int main(){
    std::cout << "Enter some numbers:\n";
    int sum = 0;
    int current = 0, i = 0;
    while (i < 100) {
        std::cin >> current;
        if (current == -1){
            std::cout << "Their sum is " << sum << "\n";
            return 0;
        }
        else if (current == -2){
            std::cout << "Resetting sum\n";
            sum = 0;
            i = 0;
        }
        else
            sum += current;
    }
    std::cout << "Reached 100 entries\n";
    std::cout << "Their sum is " << sum << "\n";
    return 0;
}
