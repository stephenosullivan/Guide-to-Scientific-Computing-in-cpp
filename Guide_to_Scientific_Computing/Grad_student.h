//
//  Grad_student.h
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#ifndef __Guide_to_Scientific_Computing__Grad_student__
#define __Guide_to_Scientific_Computing__Grad_student__

#include <stdio.h>
#include "Exercise7_1.h"

class gradStudent: public student {
    
public:
    double money_owed();
    bool fulltime;
};

#endif /* defined(__Guide_to_Scientific_Computing__Grad_student__) */
