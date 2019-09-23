// g++ *.cpp  -larmadillo -llapack -lblas -o unit

#include <armadillo>
#include <iostream>
#include <cmath>
// #include "functions/diagonalizer.cpp"
// #include "functions/Jacobi_method.cpp"
// #include "functions/Jacobi_rotate.cpp"
// #include "functions/off.cpp"

using namespace std;
using namespace arma;

//mat diagonalizer(mat A);
mat Jacobi_method(mat A, int N);

int main(){
  //Constants
  double Rstart = 0.0; double Rfin = 1.0; //Start and stop values
  int N = 10;                             //Number of iterations or points
  double h = (Rfin-Rstart)/N;             //Spacing
  double d = 2 / (h * h);                 //Diagonal element
  double a = -1 / (h * h);                //Nondiagonal element

  //Setting up matrix A.
  mat A = mat(N,N, fill::zeros);

  //Changing the diagonal + non diagnonal(above/below diag) elements
  A.diag()   += d;
  A.diag(1)  += a;
  A.diag(-1) += a;

  //Defining matrix C to have eigenvalues of A on its diagonal, by using Jacobi's method
  //mat B = diagonalizer(A);
  mat C = Jacobi_method(A,N);
  cout << "this is C:" << C << endl;

  for (int i = 0;i < N-1;i++){
    int lambda = d + 2 * a * cos (i * M_PI /(N + 1));
    //cout << lambda << endl;
  }
}
