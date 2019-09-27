#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

mat Jacobi_rotate(mat A, int k, int l, int n);
double off(mat A, int &k, int &l, int n);

vec Jacobi_method(mat A, int n){
	int k = 0;
	int l = 0;
	double tol = 10e-8;
	double max_iterations = pow(n, 3);
	double max = off(A, k, l, n);

	double i = 0;
	while (i < max_iterations && max > tol){
		A = Jacobi_rotate(A, k, l, n);
		max = off(A, k, l, n);
		i++;
	}

	cout << "Max non-diagonal element after diagonalization: " << max << endl;
	cout << "Number of rotations: " << i << endl;
	return A.diag();
}