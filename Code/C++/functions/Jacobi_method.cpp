#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

int off(mat A, int N, double max_off);
void Jacobi_rotate(mat A, mat B, int k, int l, int N);

mat Jacobi_method(mat A, int N){
    double epsilon = 1.0e-8;                          //Defining maximum deviation from 0 for the off diagonal elements
    int max_iterations = 1e5;                         //Setting a number of max iterations if the tolerance epsilon is not yet met
    int i = 0;
    double max = 0.0;                                 //Introducing variable for storing max off-diagonal value
    mat B;
    
    while (max > epsilon && i <= max_iterations){     //Run this loop until max deviation is less than eps or max iterations is met
        B = A;
        int k,l = off(A, N, max);                     //Finding the maximum value and returning its indices k, l
        Jacobi_rotate(A,B,k,l,N);                     //Rotating by means of k, l. B is the rotated matrix.
        A = B;                                        //Setting A=B ready for new loop iteration
        i++;
    }
}
