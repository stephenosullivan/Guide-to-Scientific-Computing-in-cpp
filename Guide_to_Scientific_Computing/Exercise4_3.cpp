//
//  Exercise4_3.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/14/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include <cstdlib>

void print_vector(double* vector, int size){
    std::cout << "[";
    for (int i = 0; i < size; ++i){
        std::cout << vector[i];
        if (i != size - 1)
            std::cout << " ";
    }
    std::cout << "]\n";
}


double* weird_product(double* v1, double* v2, int size){
    double* output_vec = new double[size];
    for (int i = 0; i < size; ++i) {
        output_vec[i] = v1[i]*v2[i];
    }
    return output_vec;
}

double* scalar_product(double* v1, double* v2, int size){
    double* sum = new double;
    for (int i = 0; i < size; ++i) {
        *sum += v1[i] * v2[i];
    }
    return sum;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout << "Enter length as first argument\n";
        exit(0);
    }
    srand(0);
    int size = atoi(argv[1]);
    double* vector1 = new double[size];
    double* vector2 = new double[size];
    
    for(int i = 0; i < size; ++i){
        vector1[i] = rand()%10;
        vector2[i] = rand()%10;
    }
    std::cout << "vector1\n";
    print_vector(vector1, size);
    std::cout << "vector2\n";
    print_vector(vector2, size);
    
    std::cout << "Scalar product of vector1 and vector2\n";
    std::cout << *scalar_product(vector1, vector2, size) << "\n";
    
    std::cout << "Weird product of vector1 and vector2\n";
    print_vector(weird_product(vector1, vector2, size), size);
    
    delete [] vector1;
    delete [] vector2;
    return 0;
}
