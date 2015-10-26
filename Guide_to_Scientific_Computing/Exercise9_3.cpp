//
//  Exercise9_3.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/23/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "OutOfRangeException.h"
#include "Exception.h"

double test_fn1(double y, double t){
    return 1. + t;
}

double test_fn2(double y, double t){
    return -100. * y;
}



class linearSolverEuler{
    double* solution;
    int iterations;
    double t0;
    double tN;
    double y0;
    
    double tolerance = 1e-4;
    double (*test_func)(double y, double t);

    double stepsize(){
        return (tN - t0)/(iterations-1.);
    }
    
public:
    linearSolverEuler(double initial_y, double initial_t, double final_t, int N, double (*fn)(double y, double t)):iterations(N), t0(initial_t), tN(final_t), y0(initial_y){
        solution = new double[iterations];
        test_func = fn;
        
        int attempts = 0;
        int max_attempts = 4;
        bool success = false;
        try{
            while (!success) {
                try {
                    load_values();
                    success = true;
                } catch (Exception& error) {
                    error.PrintDebug();
                    attempts++;
                    delete [] solution;
                    iterations *= 2;
                    solution = new double[iterations];
                }
                if(attempts == max_attempts){
                    throw Exception("Failure", "Made " + std::to_string(max_attempts) +  " attempts!");
                }
            }
        }
        catch(Exception& error){
            error.PrintDebug();
            EXIT_FAILURE;
        }
        delete [] solution;
    }
    
    
    void load_values(){
        double y = y0;
        solution[0] = y0;
        std::cout << "Using " << iterations << " iterations\n";
        
        for (int i = 1; i < iterations; ++i) {
            solution[i] = y + stepsize() * test_func(y, t0 + i*stepsize());
            if (solution[i] >=0. && solution[i] <= 1.){
                
            }
            else if(solution[i] > -tolerance && solution[i]<0){
                std::cout << "Small adjustment needed for element " << i << "\n";
                solution[i] = 0;
            }
            else if (solution[i] > 1. && solution[i] < 1. + tolerance){
                std::cout << "Small adjustment needed to bring element " << i << " to below 1\n";
            }
            else{
                throw OutOfRangeException("Need an exception for solution[" + std::to_string(i) + "] with value " + std::to_string(solution[i]));
            }
            y = solution[i];
            
        }
        
    }
    
    void print(){
        for (int i = 0; i < 100; i += 1) {
            std::cout << solution[i] << " ";
        }
        std::cout << "\n";
    }
};

int main(){
    linearSolverEuler EulerTest(0.8, 0, 100, 1000, &test_fn2);
    EulerTest.print();
    return 0;
}
