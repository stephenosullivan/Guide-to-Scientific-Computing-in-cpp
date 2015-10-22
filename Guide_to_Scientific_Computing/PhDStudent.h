//
//  PhDStudent.h
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#ifndef __Guide_to_Scientific_Computing__PhDStudent__
#define __Guide_to_Scientific_Computing__PhDStudent__

#include <stdio.h>
#include "Grad_student.h"

class PhDStudent: public gradStudent {
    
public:
    double money_owed();
};

#endif /* defined(__Guide_to_Scientific_Computing__PhDStudent__) */
