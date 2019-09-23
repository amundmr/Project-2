#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

int off(mat A, int N, double max_off);
void Jacobi_rotate(mat A, mat B, int k, int l, int N);

mat Jacobi_method(mat A, int N){
    double epsilon = 1.0e-8; // could perhaps be even smaller?
    int max_iterations = 1e5; // tentative guess
    int i = 0;
    double max = 0.0;
    mat B;
    
    while (max > epsilon && i <= max_iterations){
        B = A;
        int k,l = off(A, N, max); // finding the maximum value and returning its indices k, l
        Jacobi_rotate(A,B,k,l,N); // rotating by means of k, l. B is the rotated matrix.
        A = B;
        i++;
    }
}