//
//  Exercise5_3.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/14/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

// Swap two numbers using pointers and references

#include <iostream>

void swap_with_pointers(int *i1, int *i2){
    int *tmp = new int;
    *tmp = *i1;
    *i1 = *i2;
    *i2 = *tmp;
}

void swap_with_references(int &i1, int &i2){
    int tmp;
    tmp = i1;
    i1 = i2;
    i2 = tmp;
}

int main(){
    int i = 10;
    int j = 20;
    
    std::cout << i << " " << j << "\n";
    swap_with_pointers(&i, &j);
    std::cout << i << " " << j << "\n";
    swap_with_references(i,j);
    std::cout << i << " " << j << "\n";
    return 0;
}