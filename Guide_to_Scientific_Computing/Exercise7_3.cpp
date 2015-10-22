//
//  Exercise7_3.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

//#include "ForwardEulerSolver.h"
#include "RungeKuttaSolver.h"

double func(double y, double t){
    return 1. + t;
}

int main(){
    //ForwardEulerSolver integratorA(40, 1, 2, 5);
    RungeKuttaSolver integratorB(40, 1, 2, 5);
    //integrator1->RightHandSide = &func;
    return 0;
}

