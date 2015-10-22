//
//  Exercise6_1.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/16/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "ComplexNumber.hpp"
#include <cmath>

class ComplexMatrix{
public:
    ComplexMatrix(int size):mSize(size){
        matrix = new ComplexNumber*[mSize];
        for (int i = 0; i < mSize; ++i){
            matrix[i] = new ComplexNumber[mSize];
        }
    }
    
    ~ComplexMatrix(){
        for (int i = 0; i < mSize; ++i){
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
    void InsertRandomElements(int range){
        for (int i = 0; i < mSize; ++i){
            for (int j = 0; j < mSize; ++j) {
                matrix[i][j] = ComplexNumber( rand() % range, rand() % range);
            }
        }
    }
    
    
    // Calculate the exponential to a given tolerance on the first element of the matrix
    ComplexMatrix Exponential(double Tolerance) const{
        ComplexMatrix multiplier(mSize), output(mSize);
        for (int i = 0; i < mSize; ++i) {
            multiplier.matrix[i][i] = ComplexNumber(1,0);
        }
        
        int i = 1;
        ComplexNumber old;
        do{
            old = output.matrix[0][0];
            output += multiplier;
           // std::cout << "\n" << i << "\n";
           // std::cout << output << "\n";
            multiplier *= *this * (1./((double) i));
           // std::cout << multiplier;
            i++;
        }
        while ((std::abs((old.CalculateModulus() - output.matrix[0][0].CalculateModulus())/old.CalculateModulus())) > Tolerance );
    
        return output;
    }
    
    ComplexNumber get(const int i, const int j) const{
        return matrix[i][j];
    }
    
    ComplexNumber set(const int i, const int j, const ComplexNumber& complex) const{
        return matrix[i][j] = complex;
    }
    
    ComplexMatrix operator*(const double& scalar) const{
        //ComplexMatrix *w = new ComplexMatrix(mSize);
        ComplexMatrix w(mSize);
        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < mSize; ++j) {
                w.matrix[i][j] = matrix[i][j]*scalar;
            }
        }
        return w;
    }
    
    ComplexMatrix operator*(const ComplexMatrix& other){
        if (mSize == other.mSize){
            ComplexMatrix w (mSize);
            for (int i = 0; i < mSize; ++i) {
                for (int j = 0; j < mSize; ++j) {
                    for (int k = 0; k < mSize; ++k) {
                        w.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                    }
                }
            }
            return w;
        }
        else{
            std::cerr << "Need matrices of same size\n";
            exit(0);
        }
    }
    
    ComplexMatrix& operator*=(const ComplexMatrix& other){
        ComplexMatrix w(mSize);
        if (mSize == other.mSize){
            for (int i = 0; i < mSize; ++i) {
                for (int j = 0; j < mSize; ++j) {
                    for (int k = 0; k < mSize; ++k) {
                        w.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                    }
                }
            }
            *this = w;
        }
        else{
            std::cerr << "Need matrices of same size\n";
            exit(0);
        }
        return *this;
    }

    ComplexMatrix& operator=(const ComplexMatrix& other){
        if(mSize == other.mSize){
            for (int i = 0; i < mSize; ++i) {
                for (int j = 0; j < mSize; ++j) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        return *this;
    }
    
    ComplexMatrix& operator+=(const ComplexMatrix& other){
        if (mSize == other.mSize){
            for (int i = 0; i < mSize; ++i) {
                for (int j = 0; j < mSize; ++j) {
                    matrix[i][j] += other.matrix[i][j];
                }
            }
        }
        else{
            std::cerr << "Need matrices of same size\n";
            exit(0);
        }
        return *this;
    }
    
    ComplexNumber* operator[](int i){
        return matrix[i];
    }
    
    //std::ostream& operator<<(std::ostream& output, const ComplexNumber& z);
    friend std::ostream& operator<<(std::ostream& output, const ComplexMatrix& matrix){
        for (int i = 0; i < matrix.mSize; ++i) {
            output << "|";
            for (int j = 0; j < matrix.mSize; ++j) {
                output << matrix.get(i,j);
                if (j < matrix.mSize - 1 ){
                    output << " ";
                }
            }
            output << "|\n";
        }
        return output;
    }
private:
    int mSize;
    ComplexNumber** matrix;
};

int main(){
    ComplexNumber a(10, 20);
    ComplexNumber b(25, 50);
    
    std::cout << a + b << "\n";
    std::cout << a.GetRealPart() << " " << a.GetImaginaryPart() << "\n";
    std::cout << RealPart(a) << " " << ImaginaryPart(a) << "\n";
    
    ComplexNumber c(a);
    std::cout << c.GetRealPart() << " " << c.GetImaginaryPart() << "\n";

    
    std::cout << "Take it's complex conjugate\n";
    std::cout << c.CalculateConjugate() << "\n" ;
    c.SetConjugate();
    std::cout << c << "\n";
    
    double r = 55.;
    ComplexNumber d(r);
    std::cout << d << "\n";
    
    std::cout << "Making a complex Matrix\n";
    ComplexMatrix matrix(3);
    matrix.InsertRandomElements(10);
    std::cout << matrix << "\n";
    
    
    std::cout << "Exponentiating a matrix\n";
    std::cout << matrix.Exponential(0.000001) << "\n";
    
    std::cout << "Test access:\n";
    std::cout << matrix[0][0] << " " << matrix[1][1]  << "\n";
    matrix[0][0] = ComplexNumber(2,1);
    
    std::cout << "Output Matrix again:\n";
    std::cout << matrix ;
    
    
    return 0;
}
