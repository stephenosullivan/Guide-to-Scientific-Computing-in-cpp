//
//  Example11_5.cpp
//  Guide to Scientific Computing
//
//  Created by Stephen O'Sullivan on 10/27/15.
//  Copyright (c) 2015 Stephen O'Sullivan. All rights reserved.
//

#include <mpi.h>
#include <cmath>
#include <iostream>

int main(int argc, char* argv[]){
    int max_n = 1000;
    double sum = 0;
    MPI::Init(argc, argv);
    
    int num_procs = MPI::COMM_WORLD.Get_size();
    int rank = MPI::COMM_WORLD.Get_rank();
    std::cout << "Rank: " << rank << "\n";
    for(int n = rank; n < max_n; n+= num_procs){
        double temp = 1.0/(2. * ((double)(n)) + 1.);
        if (n%2 == 0) {
            sum += temp;
        }
        else{
            sum -= temp;
        }
    }
    double global_sum;
    MPI::COMM_WORLD.Reduce(&sum, &global_sum, 1, MPI::DOUBLE, MPI::SUM, 0);
    
    if (rank == 0){
        std::cout << "Pi is about " << 4.*global_sum << " with error " << 4.*global_sum - M_PI << "\n";
    }
    MPI::Finalize();
    return 0;
}
