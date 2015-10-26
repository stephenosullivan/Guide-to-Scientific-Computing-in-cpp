//
//  Exception.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/22/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include "Exception.h"
#include <iostream>

Exception::Exception(std::string tagString, std::string probString){
    mTag = tagString;
    mProblem = probString;
}

void Exception::PrintDebug() const{
    std::cerr << "** Error ("<< mTag << ") **\n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}