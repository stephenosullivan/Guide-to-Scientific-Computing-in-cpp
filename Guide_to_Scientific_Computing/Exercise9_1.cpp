//
//  Exercise9_1.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/22/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include "Exception.h"
#include "FileNotOpenException.h"
#include "OutOfRangeException.h"
#include <iostream>
#include <fstream>


void ReadFile(const std::string& filename, double x[], double y[]){
    std::ifstream readfile(filename.c_str());
    
    if(readfile.is_open() == false){
        //throw Exception("FILE", "File can't be opened");
        throw FileNotOpenException("File can't be opened");
    }
    
    for (int i = 0; i < 6; ++i) {
        readfile >> x[i] >> y[i];
        if (readfile.eof()) {
            throw OutOfRangeException("Out of range issue");
        }
    }
    
    readfile.close();
    std::cout << filename << "read successfully\n";
}

int main(){
    double x[6], y[6];
    try{
        ReadFile("Output.dat", x, y);
    }
    catch (Exception& error){
        error.PrintDebug();
        std::cout << "Couldn't open Output.dat\n";
        std::cout << "Give alternative location\n";
        std::string filename;
        std::cin >> filename;
        ReadFile(filename, x, y);
    }
    return 0;
}
