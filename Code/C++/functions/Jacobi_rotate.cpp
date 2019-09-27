#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

mat Jacobi_rotate(mat A, int k, int l, int N){
    double s, c;

    // finding the cos and sin values
    if (A(k,l) == 0.0){                                 //If A(k,l) is 0, don't rotate
        s = 0.0;
        c = 1.0;
    } else {
        double t, tau;
        tau = (A(l,l)-A(k,k))/(2*A(k,l));
        if (tau >= 0){
            t = 1.0/(tau + sqrt(1.0 + tau*tau));
        }
        else{
            t = -1.0/(-tau + sqrt(1.0 + tau*tau));
        }

        c = 1.0/(sqrt(1.0 + t*t));
        s = t * c;
    }

    mat B = A;
    //Rotating element (k,k) and (l,l) of matrix A in to matrix B
    B(0,0)=A(0,0);
    B(k,k) = A(k,k)*pow(c,2) - 2.0*A(k,l)*c*s + A(l,l)*pow(s,2);
    B(l,l) = A(l,l)*pow(c,2) + 2.0*c*s*A(k,l) + A(k,k)*pow(s,2);
    B(k,l) = 0.0;
    B(l,k) = 0.0;

    //Rotating all off-diagonal elements from A into B
    for (int i = 0; i < N; i++){
        if (i != k && i != 1){
            B(i,i) = A(i,i);
            B(i,k) = A(i,k)*c - A(i,l)*s;
            B(i,l) = A(i,l)*c + A(i,k)*s;
            B(k,i) = B(i,k);
            B(l,i) = B(i,l);
        }
    }

    return B;
}