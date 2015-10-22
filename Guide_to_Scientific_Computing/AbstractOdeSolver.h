//
//  AbstractOdeSolver.h
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#ifndef __Guide_to_Scientific_Computing__AbstractOdeSolver__
#define __Guide_to_Scientific_Computing__AbstractOdeSolver__

class AbstractOdeSolver{
    int iterationNumber;
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;
public:
    void SetIterationNumber(int iterationNumber);
    void SetStepSize(double h);
    void SetTimeInterval(double t0, double t1);
    void SetInitialValue(double y0);
    
    int GetIterationNumber();
    double GetStepSize();
    double GetInitialTime();
    double GetFinalTime();
    double GetInitialValue();
    
    virtual double RightHandSide(double y, double t) = 0;
    virtual double* SolveEquation() = 0;
};


#endif /* defined(__Guide_to_Scientific_Computing__AbstractOdeSolver__) */
