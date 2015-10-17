//
//  Exercise5_8.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/15/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

// Calculate the determinant of a square matrix

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>

double** buildmatrix(int size){
    double** matrix = new double*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new double[size];
    }
    return matrix;
}

double* buildvector(int size){
    double* vector = new double[size];
    return vector;
}

void delete_matrix(double** matrix, int size){
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void delete_matrix(double* vector, int size){
    delete[] vector;
}

void print_matrix(double** matrix, int size){
    for (int i = 0; i < size; ++i){
        std::cout << "|" ;
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j];
            if (j != size-1){
                std::cout << " ";
            }
        }
        std::cout << "|\n" ;
    }
}

void print_matrix(double* vector, int size){
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << vector[i];
        if (i != size-1){
            std::cout << " ";
        }
    }
    std::cout << "]\n";
}

void fill_matrix_with_random(double** matrix, int size, int N){
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % N;
        }
    }
}

void fill_matrix_with_random(double* vector, int size, int N){
    for (int i = 0; i < size; ++i){
            vector[i] = rand() % N;
    }
}


double determinant(double** matrix, int size){
    if (size == 1){
        return matrix[0][0];
    }
    else{
        double* sum = new double;
        *sum = 0;
        
        for (int i = 0; i < size; ++i) {
            double** submatrix = new double* [size-1];
            for (int j = 0; j < size-1; ++j){
                submatrix[j] = new double[size-1];
            }
            
            for (int j = 0; j < size-1; ++j) {
                for (int k = 0; k < i; ++k) {
                    submatrix[j][k] = matrix[j+1][k];
                }
            }

            for (int j = 0; j < size-1; ++j) {
                for (int k = i+1; k < size; ++k) {
                    submatrix[j][k-1] = matrix[j+1][k];
                }
            }
            
            *sum += pow(-1,i) * matrix[0][i] * determinant(submatrix, size-1);
           
        }
        return *sum;
    }
}

double** matrix_X_matrix(double** matrixA, double** matrixB, int size){
    double** matrix_out = buildmatrix(size);
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                matrix_out[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return matrix_out;
}

void swap_matrix_row(double** matrix, double* vector, int size, int swapA, int swapB){
//    double** swap_matrix = buildmatrix(size);
//    for (int i = 0; i < size; ++i){
//        if (i != swapA or i != swapB){
//            swap_matrix[i][i] = 1.;
//        }
//    }
//    swap_matrix[swapA][swapB] = 1.;
//    swap_matrix[swapB][swapA] = 1.;
    double* tmp_vec = new double[size];
    
    for(int i = 0; i < size; ++i){
        tmp_vec[i] = matrix[swapA][i];
    }
    for (int i = 0; i< size; ++i) {
        matrix[swapA][i] = matrix[swapB][i];
        matrix[swapB][i] = tmp_vec[i];
    }
    
    int* tmp_int = new int;
    *tmp_int = vector[swapA];
    vector[swapA] = vector[swapB];
    vector[swapB] = *tmp_int;
    
    delete [] tmp_vec;
    delete tmp_int;
 }


double* matrix_X_vector(double** matrix, double* vector, int size){
    double* output_vector = new double[size];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            output_vector[i] += matrix[i][j] * vector[j];
        }
    }
    return output_vector;
}

double** replace_col(double** matrix, double* vector, int size, int col){
    double** outputmatrix = new double* [size];
    for (int i = 0; i < size; ++i) {
        outputmatrix[i] = new double[size];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j==col){
                outputmatrix[i][j] = vector[i];
            }
            else{
                outputmatrix[i][j] = matrix[i][j];
            }
        }
    }
    return outputmatrix;
}

// Solve linear system using Cramers' rule
double* linear_solver(double** matrix, double* vector, int size){
    double* output_vector = new double[size];
    double det_matrix = determinant(matrix, size);
    
    // make new matrix by replacing column i from the old one with b and find its determinant
    for (int i = 0; i < size; ++i){
        double** matrix_i = replace_col(matrix, vector, size, i);
        //print_matrix(matrix_i, size);
        output_vector[i] = determinant(matrix_i, size)/det_matrix;
        delete_matrix(matrix_i, size);
    }
    return output_vector;
}

double* gaussian_linear_solver(double** matrix, double* vector, int size){
    double* output_vector = buildvector(size);
    for (int i = 0; i < size; ++i){
        if (matrix[i][i] == 0){
            std::cout << "Cannot eliminate on zero!!\n";
            exit(0);
        }
        else if (i < size-1){
            int* maxrow = new int;
            *maxrow = i;
            for (int j = i; j < size; ++j) {
                if (std::abs(matrix[j][i]) > std::abs(matrix[*maxrow][i])){
                    *maxrow = j;
                }
            }
            swap_matrix_row(matrix, vector, size, i, *maxrow);
        }
        
        // Gaussian elimination
        double* divisor = new double;
        
        for (int j = i + 1; j < size; ++j) {
            *divisor = matrix[j][i]/matrix[i][i];
            for (int k = i; k < size; ++k) {
                matrix[j][k] -= *divisor * matrix[i][k];
            }
            vector[j] -= *divisor * vector[i];
        }
    }
    
    //std::cout << "Upper triangular transformation leads to:\n";
    //print_matrix(matrix, size);
    
    for (int j = size - 1; j > -1; --j) {
        double remainder_Sum = 0;
        for(int k = j+1; k < size; ++k){
            remainder_Sum += matrix[j][k] * output_vector[k];
        }
        output_vector[j] = (vector[j] - remainder_Sum)/matrix[j][j];
    }
    
    return output_vector;
}

int main(){
    std::cout << "Enter size of matrix:\n";
    int size = 0;
    std::cin >> size;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;

    int N = 0;
    std::cout << "Enter range of random values:\n";
    std::cin >> N;
    
    double **matrix = buildmatrix(size);
    fill_matrix_with_random(matrix, size, N);
    std::cout << "The matrix \'A\' is:\n";
    print_matrix(matrix, size);
    std::cout << "The determinant is: " << determinant(matrix, size) << "\n";
    
    double* vector = buildvector(size);
    fill_matrix_with_random(vector, size, N);
    std::cout << "The vector \'b\' is:\n";
    print_matrix(vector, size);
    
    
    std::cout << "The solution \'x\' to \'Ax = b\' is:\n";
    start = std::chrono::system_clock::now();
    double* answer = linear_solver(matrix, vector, size);
    end = std::chrono::system_clock::now();
    print_matrix(answer, size);
    
    std::cout << "Let\'s check the answer\n";
    print_matrix(matrix_X_vector(matrix, answer, size), size);
    std::cout << "should be equal to:\n";
    print_matrix(vector, size);
    elapsed_seconds = end - start;
    std::cout << "And it took " << elapsed_seconds.count() << " seconds to calculate\n";

    std::cout << "The solution \'x\' to \'Ax = b\' using Gaussian elimination is:\n";
    start = std::chrono::system_clock::now();
    answer = gaussian_linear_solver(matrix, vector, size);
    end = std::chrono::system_clock::now();
    print_matrix(answer, size);
    
    std::cout << "Let\'s check the answer\n";
    print_matrix(matrix_X_vector(matrix, answer, size), size);
    std::cout << "should be equal to:\n";
    print_matrix(vector, size);
    elapsed_seconds = end - start;
    std::cout << "And it took " << elapsed_seconds.count() << " seconds to calculate\n";

    
    delete_matrix(matrix, size);
    delete_matrix(vector, size);
    delete_matrix(answer, size);
    
    return 0;
}
