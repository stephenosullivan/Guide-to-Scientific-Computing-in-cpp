//
//  PosDefSymmLinearSystem.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/26/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include "PosDefSymmLinearSystem.h"
#include "LinearSystem.hpp"
#include <cassert>
#include <cmath>

PosDefSymmLinearSystem::PosDefSymmLinearSystem(const Matrix& A, const Vector& b, double Tolerance):LinearSystem(A, b),Tolerance(Tolerance){
    
    int local_size = A.GetNumberOfRows();
    assert(A.GetNumberOfColumns() == local_size);
    assert(b.GetSize() == local_size);
    
    // set variables for linear system
    mSize = local_size;
    mpA = new Matrix(A);
    mpb = new Vector(b);
    
    //assert(matrix.GetNumberOfColumns() == matrix.GetNumberOfRows() && matrix.GetNumberOfRows() == vector.GetSize());
}

Vector PosDefSymmLinearSystem::Solve(){
    Vector x(mSize), residual(mSize), residual_old(mSize), p(mSize);

    
    // We introduce references to make the syntax readable
    Matrix& rA = *mpA;
    Vector& rb = *mpb;
    residual = rb - rA*x;
    int k = 0;
    double beta = 0;
    double alpha = 0;
    
    
    while (residual.CalculateNorm(2) >= Tolerance) {
        std::cout << "Iteration: " << k << "\n";
        std::cout << x ;
//        std::cout << " " << residual << " " << residual_old << " " << p << " " << alpha << " " << beta << "\n";
        if (k > 0){
            beta = residual.CalculateNorm(2) / residual_old.CalculateNorm(2);
        }
        p = residual + p*beta;
        alpha = residual.CalculateNorm(2) / ((p*rA)*p);
        x = x + p*alpha;
        residual_old = residual;
        residual = rb - rA*x;
        ++k;
    }
    
    return x;
}