#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

vec Jacobi_method(mat A, int n);
vec arma_eig(mat A);

int main(){
	int n = 5;
	int k;
	int l;

	mat A(n,n, fill::zeros);
	A(0, 0) = A(n-1,n-1) = 2.0;
	A(0, 1) = A(n-1,n-2) = -1.0;
		for (int i = 1; i < n-1; i++){
			A(i, i-1) = A(i, i+1) = -1.0;
			A(i, i) = 2.0;
	}

	clock_t t0,t1;

	t0 = clock();
	vec arma_eigvals = arma_eig(A);
	t1 = clock();

	double t_arma = (double (t1 - t0))/CLOCKS_PER_SEC;

	t0 = clock();
	vec eigvals = Jacobi_method(A, n);
	t1 = clock();

	double t_jacobi = (double (t1- t0)) /CLOCKS_PER_SEC;

	cout << "Eigenvalues from arma solver: " << endl;
	cout << arma_eigvals << endl;
	cout << "Time spent on arma solver: " << t_arma << "s" << endl;
	cout << "Eigenvalues from our Jacobi solver: " << endl;
	cout << sort(eigvals) << endl;
	cout << "Time spent on our solver: " << t_jacobi << "s" << endl;
}