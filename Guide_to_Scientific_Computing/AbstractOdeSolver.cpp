//
//  AbstractOdeSolver.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include "AbstractOdeSolver.h"

void AbstractOdeSolver::SetStepSize(double h){
    stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1){
    initialTime = t0;
    finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue(double y0){
    initialValue = y0;
}

void AbstractOdeSolver::SetIterationNumber(int IterationNumber) {
    iterationNumber = IterationNumber;
}


int AbstractOdeSolver::GetIterationNumber(){
    return iterationNumber;
}

double AbstractOdeSolver::GetStepSize(){
    return stepSize;
}

double AbstractOdeSolver::GetInitialTime(){
    return initialTime;
}

double AbstractOdeSolver::GetFinalTime(){
    return finalTime;
}

double AbstractOdeSolver::GetInitialValue(){
    return initialValue;
}