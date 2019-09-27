#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

mat Jacobi_rotate(mat A, int k, int l, int N);
double off(mat A, int N, int &k, int &l);

vec Jacobi_method(mat A, int N, int &k, int &l){
    k = 0;
    l = 0;
    double epsilon = 10e-8;                          //Defining maximum deviation from 0 for the off diagonal elements
    double max_iterations = pow(N, 3);                         //Setting a number of max iterations if the tolerance epsilon is not yet met
    double max = off(A,N,k,l);                           //Introducing variable for storing max off-diagonal value
    
    double i = 0;
    while (i < max_iterations && max > epsilon){      //Run this loop until max deviation is less than eps or max iterations is met
        A = Jacobi_rotate(A,k,l,N);                   //Rotating by means of k, l.
        max = off(A, N, k, l);                  //Finding the maximum value and returning its indices k, l
        i++;
    }

    cout << "The diagonalized matrix found with the Jacobi method:" << A << endl;
    cout << "Max: " << max << endl;
    cout << "Number of rotations: " << i << endl;
    return A.diag();
}