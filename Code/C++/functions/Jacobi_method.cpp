#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

mat Jacobi_rotate(mat A, int k, int l, int N);
void off(mat A, int N, double* max, int* k, int* l);

mat Jacobi_method(mat A, int N){
    double epsilon = 1.0e-8;                          //Defining maximum deviation from 0 for the off diagonal elements
    int max_iterations = 3;                         //Setting a number of max iterations if the tolerance epsilon is not yet met
    int i = 0;
    double max = epsilon * 2;                         //Introducing variable for storing max off-diagonal value
    //mat B = mat(N,N, fill::zeros);
    int k = 0; int l = 0;
    while (max > epsilon && i < max_iterations){     //Run this loop until max deviation is less than eps or max iterations is met

        off(A, N, &max, &k, &l);                      //Finding the maximum value and returning its indices k, l

        A = Jacobi_rotate(A,k,l,N);                     //Rotating by means of k, l.
        //cout << "Rotated: " << A << endl;

        i++;
    }
    return A;
}
