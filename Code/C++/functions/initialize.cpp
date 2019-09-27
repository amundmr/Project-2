#include <armadillo>
#include <iostream>

using namespace arma;
using namespace std;

tuple<mat,int> initialize(){
    int N;
    double Rstart, Rfin, h, d, a;
    Rstart = 0.0, Rfin = 1.0, N = 3;
    h =  Rfin/ N;                //stepsize
    //d = 2 / (h * h);                   //value diagonal element
    //a = -1 / (h * h);                  //value of nondiagonal element

    //Setting up matrix tridiagonal matrixA.
    mat A(N,N, fill::zeros);
	A(0, 0) = A(N-1,N-1) = 2.0;
	A(0, 1) = A(N-1,N-2) = -1.0;
		for (int i = 1; i < N-1; i++){
			A(i, i-1) = A(i, i+1) = -1.0;
			A(i, i) = 2.0;
	}

    return make_tuple(A,N);
}
