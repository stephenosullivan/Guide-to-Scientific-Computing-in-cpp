//
//  Exercise4_2.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/13/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>


void swap(int *r, int *s){
    int* p_j = new int;
    
    *p_j = *r;
    *r = *s;
    *s = *p_j;
    
    return;
}

int main(){
    int i = 5, j = 10;
    swap(&i, &j);
    
    std::cout << i << " " << j << "\n";
    return 0;
}