//
//  Exercise8_3.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/22/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <stdio.h>
#include "ComplexNumber.hpp"
#include <vector>
#include <algorithm>

bool sort_on_real(ComplexNumber A, ComplexNumber B){
    return A.GetRealPart() > B.GetRealPart();
}

int main(){
    int size = 10;
    std::vector<ComplexNumber> complex_vector(size);
    for (int i = 0; i < size; ++i) {
        complex_vector[i] = ComplexNumber(rand()%10, rand()%10);
    }
    
    for (int i = 0; i < size; ++i) {
        std::cout << complex_vector[i] << " ";
    }
    std::cout << "\n";
    
    std::vector<ComplexNumber>::iterator it;
    sort(complex_vector.begin(), complex_vector.end(), sort_on_real);
    
    for (int i = 0; i < size; ++i) {
        std::cout << complex_vector[i] << " ";
    }
    std::cout << "\n";
    
    return 0;
}
