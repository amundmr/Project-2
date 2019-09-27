#include <armadillo>
#include <cmath>
#include <iostream>

using namespace std;
using namespace arma;

mat Jacobi_method(mat A, int N);
vec arma_eig(mat A);

int main() {
  //START of tridiagonal matrix implementation
  double Rho_0, Rho_N, h, d, a, V, Rho;   //Declaring all doubles

  int i, N = 5000;
  Rho_0 = 0.0, Rho_N = 1e10;               //Defining start and stop. Rho_N = Rho_max which approximates infinity

  h =  (Rho_N-Rho_0)/ N;                  //Stepsize
  a = -1 / (h * h);                       //Value of nondiagonal element


  //Setting up tridiagonal matrix A.
  mat A = mat(N,N, fill::zeros);
  for ( i = 0; i < N; i++ ) {             //Calculating the diagonal since it changes with Rho

    Rho = Rho_0 + i * h;
    V = Rho*Rho;
    d = 2 / (h * h) + V;                  //Value of diagonal element
    A(i,i) = d;
  }

  //Changing the nondiagnonal elements is easier this way
  A.diag(1)  += a;
  A.diag(-1) += a;

  //END of tridiagonal matrix implementation


  clock_t t0, t1;
  //Timing armadillo's eigenvalue solver
  t0 = clock();
  vec arma_eigvals = arma_eig(A);
  t1 = clock();
  double t_arma = (double (t1 - t0))/CLOCKS_PER_SEC;

  //Timing jacobi's eigenvalue solver
  t0 = clock();
  vec eigvals = Jacobi_method(A,N);
  t1 = clock();
  double t_jacobi = (double (t1 - t0))/CLOCKS_PER_SEC;


  cout << "Eigenvalues from arma solver: " << endl;
	cout << arma_eigvals << endl;
	cout << "Time spent on arma solver: " << t_arma << "s" << endl;
	cout << "Eigenvalues from our Jacobi solver: " << endl;
	cout << sort(eigvals) << endl;
	cout << "Time spent on our solver: " << t_jacobi << "s" << endl;

  return 0;
}
