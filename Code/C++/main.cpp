// g++ *.cpp  -larmadillo -llapack -lblas -o unit

#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

mat diagonalizer(mat A);
vec Jacobi_method(mat A, int N, int &k, int &l);
tuple<mat,int> initialize();

int main(){
  //auto init_values = initialize();
  //mat A = get<0>(init_values);
  //int N =get<1>(init_values);

  int N = 3;
  int k;
  int l;

	// Set up the matrix as a tridiagonal matrix
	mat A(N,N, fill::zeros);
	A(0, 0) = A(N-1,N-1) = 2.0;
	A(0, 1) = A(N-1,N-2) = -1.0;
		for (int i = 1; i < N-1; i++){
			A(i, i-1) = A(i, i+1) = -1.0;
			A(i, i) = 2.0;
	}

  cout << "The starting matrix:" << endl << A << endl;

  // Matrix B is the diagonalized version of A, using armadillos function
  vec arma_eig = diagonalizer(A).diag();
  // Matrix C is the diagonalized version of A, using our Jacobi method
  //mat C = Jacobi_rotate(A,5,6,N);
  vec Jacobi_eig = Jacobi_method(A,N,k,l);
  //double epsilon = 1.0e-8;
  //C = Jacobi_example(N,epsilon,A);
  cout << "Eigenvalues found with arma:" << endl << arma_eig << endl;
  cout << "Eigenvalues found with Jacobi method:" << endl << Jacobi_eig << endl;
}
