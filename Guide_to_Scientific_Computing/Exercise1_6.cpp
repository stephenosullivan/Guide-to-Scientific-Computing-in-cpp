//
//  Exercise1_6.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/12/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>

double average(int *nums, int length){
    double sum = 0.;
    int cnt = 0;
    while (cnt < length){
        sum += (double)nums[cnt];
        cnt++;
    }
    return sum/cnt;
        
    }

int main(){
    int daily_cnt[5];
    int cnt = 0;
    std::cout << "Enter 5 numbers\n";
    while(cnt < 5){
        std::cin >> daily_cnt[cnt];
        cnt++;
    }
    std::cout << "The average is: " << average(daily_cnt, 5)<< "\n";
}
