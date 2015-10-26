//
//  Exception.h
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/22/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#ifndef __Guide_to_Scientific_Computing__Exception__
#define __Guide_to_Scientific_Computing__Exception__

#include <stdio.h>
#include <string>

class Exception{
    std::string mTag, mProblem;
public:
    Exception(std::string tagString, std::string probString);
    void PrintDebug() const;
};

#endif /* defined(__Guide_to_Scientific_Computing__Exception__) */
