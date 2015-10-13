//
//  Exercise1_3.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include <cmath>

double norm(double* vector){
    double square_mag = 0.;
    for (int i = 0; i<3; i++)
        square_mag += pow(vector[i], 2.);
    return sqrt(square_mag);
}

int main(){
    double vector1[3];
    double vector2[3];
    
    std::cout << "Enter three values of first vector\n";
    for (int i = 0; i < 3; ++i) {
        std::cin >> vector1[i];
    }
    
    std::cout << "Enter three values of second vector\n";
    for (int i = 0; i < 3; ++i) {
        std::cin >> vector2[i];
    }
    
    std::cout << "Vector1 is [" ;
    for (int i = 0; i < 3; ++i){
        std::cout << vector1[i];
        if (i != 2)
            std::cout << ", ";
    }
    std::cout << "]\n";
    
    std::cout << "Vector2 is [" ;
    for (int i = 0; i < 3; ++i){
        std::cout << vector2[i];
        if (i != 2)
            std::cout << ", ";
    }
    std::cout << "]\n";
    
    double scalar_product = 0.;
    for (int i = 0; i < 3; ++i)
        scalar_product += vector1[i]*vector2[i];
    
    std::cout << "The scalar product is " << scalar_product << "\n";

    std::cout << "The Euclidean norms are " << norm(vector1) << " and " << norm(vector2) << " respectively\n" ;
    return 0;
}
