#include <armadillo>
#include <iostream>
#include <cmath>
#include "funcs.h"

using namespace std;
using namespace arma;


mat Jacobi_method(mat A, int N){
    double epsilon = 1.0e-8;                          //Defining maximum deviation from 0 for the off diagonal elements
    int max_iterations = 1e3;                         //Setting a number of max iterations if the tolerance epsilon is not yet met
    int i = 0;
    double max = epsilon * 2;                         //Introducing variable for storing max off-diagonal value
    mat B;
    int k = 0; int l = 0;
    while (max > epsilon && i <= max_iterations){     //Run this loop until max deviation is less than eps or max iterations is met
        B = A;
        off(A, N, max, k, l);                         //Finding the maximum value and returning its indices k, l
        cout << k << " | " << l << endl;
        Jacobi_rotate(A,B,k,l,N);                     //Rotating by means of k, l. B is the rotated matrix.
        A = B;                                        //Setting A=B ready for new loop iteration
        i++;
    }
}
