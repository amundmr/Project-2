// g++ *.cpp  -larmadillo -llapack -lblas -o unit

#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

mat diagonalizer(mat A);
mat Jacobi_method(mat A, int N);
tuple<mat,int> initialize();

int main(){
  auto init_values = initialize();
  mat A = get<0>(init_values);
  int N =get<1>(init_values);
  cout << A << endl;

  //Defining matrix C to have eigenvalues of A on its diagonal, by using Jacobi's method
  mat C = mat(N,N, fill::zeros);

  //mat B = diagonalizer(A);
  //cout << "B diag:" << B << endl;
  C = Jacobi_method(A,N);
  cout << "this is C:" << C << endl;
  cout << "program ran" << endl;
  //for (int i = 0;i < N-1;i++){
  //  int lambda = d + 2 * a * cos (i * M_PI /(N + 1));
    //cout << lambda << endl;
}
