//
//  Exercise4_1.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/13/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>

int main(){
    int i = 5;
    int* p_j = &i;
    *p_j *= 5;
    
    int* p_k = new int;
    *p_k = i;
    
    std::cout << i << " " << *p_j << " " << *p_k << "\n";
    
    i = 20;
    
    std::cout << i << " " << *p_j << " " << *p_k << "\n";
    return 0;
}
