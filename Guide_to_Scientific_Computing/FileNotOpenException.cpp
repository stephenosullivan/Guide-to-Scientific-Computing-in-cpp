//
//  FileNotOpenException.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/22/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include "FileNotOpenException.h"

FileNotOpenException::FileNotOpenException(std::string probString): Exception("File not open", probString){
    
}