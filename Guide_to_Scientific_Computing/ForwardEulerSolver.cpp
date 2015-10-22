//
//  ForwardEulerSolver.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include "ForwardEulerSolver.h"
#include <iostream>

double ForwardEulerSolver::RightHandSide(double y, double t){
    return 1. + t;
}

double* ForwardEulerSolver::SolveEquation(){
    double* output = new double[GetIterationNumber()];
    double y = GetInitialValue();
    output[0] = y;
    
    for (int i = 1; i < GetIterationNumber(); ++i) {
        output[i] = y + GetStepSize()*RightHandSide(y, GetInitialTime() + i*GetStepSize());
        y = output[i];
    }
    return output;
}

inline double test(double t){
    return 3.5 + t + t*t/2.;
}

ForwardEulerSolver::ForwardEulerSolver(int N, double startTime, double endTime, double initialValue){
    if (endTime > startTime){
        if (N > 1){
            SetIterationNumber(N);
            SetInitialValue(initialValue);
            SetTimeInterval(startTime, endTime);
            SetStepSize((endTime - startTime)/(N - 1));
            double* output = SolveEquation();
            for (int i = 0; i < GetIterationNumber(); ++i) {
                std::cout << output[i] << " " << GetInitialTime() + i*GetStepSize() << " " << test(GetInitialTime() + i*GetStepSize())<< "\n";
            }
        }
        else{
            std::cerr << "The number of iterations needs to be > 1!!\n";
        }
    }
    else{
        std::cerr << "Final time needs to be after initial!!\n";
    }
}