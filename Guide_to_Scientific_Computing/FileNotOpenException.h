//
//  FileNotOpenException.h
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/22/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#ifndef __Guide_to_Scientific_Computing__FileNotOpenException__
#define __Guide_to_Scientific_Computing__FileNotOpenException__

#include "Exception.h"

class FileNotOpenException: public Exception {
public:
    FileNotOpenException(std::string probString);
};

#endif /* defined(__Guide_to_Scientific_Computing__FileNotOpenException__) */
