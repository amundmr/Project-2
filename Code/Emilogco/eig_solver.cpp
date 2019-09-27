#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

mat Jacobi_rotate(mat A, int k, int l, int n);
double max_offdiag(mat A, int &k, int &l, int n);

// Find the eigenvalues for a given matrix
vec eig_solver(mat A, int n){
	// Set up our eigvec-matrix
	mat eigvec(n,n);

	// Setting initial values and tolerance
	int k = 0;
	int l = 0;
	double tol = 10e-8;
	double max_iterations = pow(n, 3);
	double max_element = max_offdiag(A, k, l, n);


	double iterations = 0;
	// Run the Jacobi rotation until we reach the max num of iterations or the max element is within our tolerance
	while (iterations < max_iterations && max_element > tol){
		// Rotate and change our matrix to the rotated one
		A = Jacobi_rotate(A, k, l, n);
		// Find the new max. offdiagonal element
		max_element = max_offdiag(A, k, l, n);
		iterations++;
	}


	cout << "Max: " << max_element << endl;
	cout << "Iterations run: " << iterations << endl;
	return A.diag();
}