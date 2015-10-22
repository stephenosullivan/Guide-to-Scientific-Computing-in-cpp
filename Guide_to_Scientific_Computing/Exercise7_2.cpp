//
//  Exercise7_2.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/21/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <iostream>


class AbstractPerson {
    
public:
    virtual void Print() = 0;//{
//        std::cerr << "Never instantiate\n";
//    }
};



class Mother: public AbstractPerson {
public:
    virtual void Print(){
        std::cout << "Mother\n";
    }
};

class Daughter: public Mother {
public:
    virtual void Print(){
        std::cout << "Daughter\n";
    }
};


int main(){
    AbstractPerson* p_mother = new Mother;
    AbstractPerson* p_daughter = new Daughter;
    //AbstractPerson* p_abstract = new AbstractPerson;
    p_mother->Print();
    p_daughter->Print();
    //p_abstract->Print();
    delete p_mother;
    delete p_daughter;
    //delete p_abstract;
    return 0;
}