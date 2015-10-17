//
//  Exercise5_4.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/14/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdlib>

// Function to calculate the mean and standard deviation of an array of double precision floating point numbers

double mean_or_sigma(double* x, int size, bool sigma=true){
    double* sum = new double;
    double* mean = new double;
    
    for (int i = 0; i < size; ++i){
        *sum += x[i];
    }
    *mean = *sum/size;
    
    if (!sigma){
        return *mean;
    }
    else{
        *sum = 0;
        for(int i = 0; i < size; ++i){
            *sum += pow(x[i] - *mean, 2);
        }
        return sqrt(*sum/(size - 1));
    }
}

int main(int argc, char* argv[]){
    srand(0);
    int* length = new int;
    
    if(argc==2){
        *length = atoi(argv[1]);
    }
    else{
        *length = 10;
    }
    
    double* x = new double[*length];
    for (int i = 0; i < *length; ++i){
        x[i] = rand() % 10;
    }
    
    std::cout << "The mean is: " << mean_or_sigma(x, *length, false) << "\n";
    std::cout << "The standard dev is: " << mean_or_sigma(x, *length) << "\n";
    
    delete length;
    delete [] x;
    
    return 0;
}

