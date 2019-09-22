// #include <armadillo>
// #include <iostream>
// #include <cmath>


// using namespace std;
// using namespace arma;


void Jacobi_rotate(mat A, mat B, int k, int l, int n){
    double sin;
    double cos;

    if (A(k,l) != 0.0){                                 //If A(k,l) is 0, don't rotate
        double tan;
        double tau;
        double t;
        tau = (A(l,l)-A(k,k))/(2.0*A(k,l));
        if (tau >= 0){
            tan = 1.0/(tau + sqrt(1.0+pow(tau,2)));
        }
        else{
            t = -1.0/(-tau +sqrt(1.0 + tau*tau));
        }

        cos = 1/(sqrt(1.0+pow(tan,2)));
        sin = cos*tan;
    }
    else{
        cos = 1.0;
        sin = 0.0;
    }

    //Rotating element (k,k) and (l,l) of matrix A in to matrix B
    B(k,k) = pow(cos,2)*A(k,k) - 2.0*cos*sin*A(k,l) + pow(sin,2)*A(l,l);
    B(l,l) = pow(sin,2)*A(k,k) + 2.0*cos*sin*A(k,l) + pow(cos,2)*A(l,l);
    B(k,l) = 0.0;
    B(l,k) = 0.0;

    //Rotating all off-diagonal elements from A into B
    for (int i=0; i<n; i++){
        if (i != k && i != 1){
            B(i,k) = cos*A(i,k) - sin*A(i,l);
            B(k,i) = B(i,k);
            B(i,l) = cos*A(i,l) + sin*A(i,k);
            B(l,i) = B(i,l);
        }

    }
    return;
}
