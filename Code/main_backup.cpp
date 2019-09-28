#include <armadillo>
#include <cmath>
#include <iostream>

using namespace std;
using namespace arma;

mat init(double Rho_N, int N);        //Takes Rho_N (approx infty) and integrations points N, returns tridiag mat.
mat Jacobi_method(mat A, int N);      //Takes matrix to find eigvals and N, returns vector with eigvals.
vec arma_eig(mat A);                  //Armadillos function for finding Eigenvalues, returns vector with eigvals.


int main() {



  double Rho_N = 10.0;                //Defining the approximation of infinity
  int N = 300;                        //Defining number of integration points

  mat A = init(Rho_N, N);             //Defining tridiagonal matrix



  //Timing armadillo's eigenvalue solver
  clock_t t0, t1;
  t0 = clock();
  vec arma_eigvals = arma_eig(A);     //Defining armadillos eigenvalues
  t1 = clock();
  double t_arma = (double (t1 - t0))/CLOCKS_PER_SEC;

  //Timing jacobi's eigenvalue solver
  t0 = clock();
  vec eigvals = Jacobi_method(A,N);   //Defining jacobi's eigenvalues
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
