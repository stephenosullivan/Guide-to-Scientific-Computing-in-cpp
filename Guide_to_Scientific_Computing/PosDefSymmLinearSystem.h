//
//  PosDefSymmLinearSystem.h
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/26/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#ifndef __Guide_to_Scientific_Computing__PosDefSymmLinearSystem__
#define __Guide_to_Scientific_Computing__PosDefSymmLinearSystem__

#include <iostream>
#include "LinearSystem.hpp"

class PosDefSymmLinearSystem: public LinearSystem {
private:
    double Tolerance;
    int mSize; // size of linear system
    Matrix* mpA;  // matrix for linear system
    Vector* mpb;  // vector for linear system
public:
    PosDefSymmLinearSystem(const Matrix& matrix, const Vector& vector, double Tolerance);
    virtual Vector Solve();
};

#endif /* defined(__Guide_to_Scientific_Computing__PosDefSymmLinearSystem__) */
