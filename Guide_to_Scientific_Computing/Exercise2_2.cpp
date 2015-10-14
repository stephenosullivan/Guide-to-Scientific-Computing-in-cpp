//
//  Exercise2_2.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>

int main(){
    double p=6., q=5, x=2, y=3;
    int j=2;
    
    //part(i)
    if (p >= q || j!=10) {
        x = 5.;
    }
    
    //part(ii)
    if (y >= q && j==20){
        x = 5.;
    }
    else{
        x = p;
    }
    
    
    //part(iii)
    if(p > q){
        x = 0;
    }
    else if(p <= q && j==10){
        x = 1.;
    }
    else{
        x = 2.;
    }
    std::cout << p << " " << q << " " << x << " " << y << "\n";
    
    return 0;
}