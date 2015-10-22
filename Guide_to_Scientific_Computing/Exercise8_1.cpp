//
//  Exercise8_1.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/22/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

template <unsigned int N>
class probabilities {
    double* vector = new double[N];
    double error = 1e-6;
    
public:
    double& operator[](int i){
        return vector[i];
    }
    
    double operator()(int i){
        if (0 <= vector[i] && vector[i] <= 1){
            //std::cout << "Below 0: "<<(vector[i] < 0) << "\n";
            std::cout << "Between 0 and 1\n";
            return vector[i];
        }
        else if(-error <= vector[i] && vector[i] < 0){
            std::cout << "Close to zero\n";
            return 0.;
        }
        else if(1. < vector[i] && vector[i] <= 1. + error){
            std::cout << "Close to 1\n";
            return 1.;
        }
        else{
            std::cerr << "Invalid probability\n";
            return 0;
        }
    }
    
    void insert_randoms(){
        for (int i = 0; i < N; ++i) {
            vector[i] = (rand() % 100)/150.;
        }
    }
    
    friend std::ostream& operator<<(std::ostream& output, probabilities vector){
        for (int i = 0; i < N; ++i) {
            output << vector(i) << " ";
        }
        output << "\n";
        return output;
    }

    void test_bounds(){
        vector[0] = -error;
        vector[1] = 1+error;
        vector[2] = 2.;
    }
};

int main(){
    srand(10);
    probabilities<10> prob_vector;
    prob_vector.insert_randoms();
    std::cout << prob_vector << "\n";
    prob_vector.test_bounds();
    std::cout << prob_vector << "\n";
    return 0;
}