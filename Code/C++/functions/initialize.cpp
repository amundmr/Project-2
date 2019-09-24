#include <armadillo>
#include <iostream>

using namespace arma;
using namespace std;

tuple<mat,int> initialize(){
    int N;
    double Rstart, Rfin, h, d, a;
    Rstart = 0.0, Rfin = 1.0, N = 10;
    h =  Rfin/ N;                //stepsize
    d = 2 / (h * h);                   //value diagonal element
    a = -1 / (h * h);                  //value of nondiagonal element

    //Setting up matrix tridiagonal matrixA.
    mat A = mat(N,N, fill::zeros);

    //Changingdiagonal + nondiagnonal elements
    A.diag()   += d;
    A.diag(1)  += a;
    A.diag(-1) += a;

    return make_tuple(A,N);
}
