//
//  RungeKuttaSolver.h
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#ifndef __Guide_to_Scientific_Computing__RungeKuttaSolver__
#define __Guide_to_Scientific_Computing__RungeKuttaSolver__

#include <stdio.h>
#include "AbstractOdeSolver.h"
#include <iostream>

class RungeKuttaSolver: public AbstractOdeSolver{
public:
    RungeKuttaSolver(int N, double startTime, double endTime, double initialValue);
    double RightHandSide(double y, double t);
    double* SolveEquation();
    //  virtual double RightHandSide(double y, double t) = 0;
    //    virtual double SolveEquation() = 0;
    
};

#endif /* defined(__Guide_to_Scientific_Computing__RungeKuttaSolver__) */
