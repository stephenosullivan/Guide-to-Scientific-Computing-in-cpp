//
//  RungeKuttaSolver.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include "RungeKuttaSolver.h"
#include <iostream>

double RungeKuttaSolver::RightHandSide(double y, double t){
    return 1. + t;
}

double* RungeKuttaSolver::SolveEquation(){
    double* output = new double[GetIterationNumber()];
    double y = GetInitialValue();
    output[0] = y;
    
    
    for (int i = 1; i < GetIterationNumber(); ++i) {
        double k1 = GetStepSize()*RightHandSide(y, GetInitialTime() + i*GetStepSize());
        double k2 = GetStepSize()*RightHandSide(y + k1/2., GetInitialTime() + i*GetStepSize() + GetStepSize()/2.);
        double k3 = GetStepSize()*RightHandSide(y + k2/2., GetInitialTime() + i*GetStepSize() + GetStepSize()/2.);
        double k4 = GetStepSize()*RightHandSide(y + k3, GetInitialTime() + i*GetStepSize() + GetStepSize());
        
        output[i] = y + (k1 + 2.*k2 + 2.*k3 + k4)/6.;
        y = output[i];
    }
    return output;
}

inline double test(double t){
    return 3.5 + t + t*t/2.;
}

RungeKuttaSolver::RungeKuttaSolver(int N, double startTime, double endTime, double initialValue){
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