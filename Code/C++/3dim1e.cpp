#include <armadillo>
#include <cmath>
#include <iostream>


using namespace std;
using namespace arma;

mat Jacobi_method(mat A, int N);

int main() {
  int i, N = 10;
  double Rho_0, Rho_N, h, d, a, V, Rho;   //Declaring all doubles

  Rho_0 = 0.0, Rho_N = 1e5;               //Defining start and stop. Rho_N = Rho_max which approximates infinity
  h =  (Rho_N-Rho_0)/ N;                  //Stepsize
  a = -1 / (h * h);                       //Value of nondiagonal element


  //Setting up matrix tridiagonal matrixA.
  mat A,C = mat(N,N, fill::zeros);

  for ( i = 0; i < N; i++ ) {             //Calculating the diagonal since it changes with Rho

    Rho = Rho_0 + i * h;
    V = Rho*Rho;
    d = 2 / (h * h) + V;                  //Value of diagonal element
    A(i,i) = d;
  }

  //Changing the nondiagnonal elements is easier this way
  A.diag(1)  += a;
  A.diag(-1) += a;

  cout << A << endl;

  C = Jacobi_method(A,N);

  cout << C << endl;

  return 0;
}
