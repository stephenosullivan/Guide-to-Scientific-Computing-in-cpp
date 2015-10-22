//
//  Exercise7_1.h
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#ifndef __Guide_to_Scientific_Computing__Exercise7_1__
#define __Guide_to_Scientific_Computing__Exercise7_1__

#include <stdio.h>
#include <string>

class student {
    std::string name;
    double library_fine;
    double tuition_fees;
    
public:
    student();
    student(double);
    virtual double money_owed();
    void update_library_fine(double);
    void update_tuition_fees(double);
    double get_library_fine();
    double get_tuition_fee();
};

#endif /* defined(__Guide_to_Scientific_Computing__Exercise7_1__) */
