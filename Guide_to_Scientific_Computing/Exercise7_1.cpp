//
//  Exercise7_1.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include "Exercise7_1.h"
#include <iostream>
#include "Grad_student.h"
#include "PhDStudent.h"


student::student(){
    tuition_fees = 0.;
    library_fine = 0.;
}

student::student(double carry){
    tuition_fees = carry;
    library_fine = 0;
}

double student::money_owed(){
    return library_fine + tuition_fees;
}

void student::update_tuition_fees(double fee){
    if (tuition_fees + fee < 0){
        std::cout << "Invalid tuition update;";
    }
    else{
        tuition_fees += fee;
    }
}

void student::update_library_fine(double fee){
    library_fine += fee;
}

double student::get_library_fine(){
    return library_fine;
}

double student::get_tuition_fee(){
    return tuition_fees;
}




int main(){
    student Alice;
    student Bob(100);
    
    gradStudent Connor;
    
    PhDStudent David;
    
    Alice.update_library_fine(10);
    Alice.update_tuition_fees(20000);
    Bob.update_library_fine(20);
    Bob.update_tuition_fees(25000);
    Connor.update_library_fine(100);
    Connor.update_tuition_fees(10000);
    David.update_tuition_fees(5000);
    David.update_library_fine(25);
    
    
    std::cout << "Alice owes " << Alice.money_owed() << "\n";
    std::cout << "Bob owes " << Bob.money_owed() << "\n";
    std::cout << "Connor owes " << Connor.money_owed() << "\n";
    std::cout << "David owes " << David.money_owed() << "\n";
    return 0;
}