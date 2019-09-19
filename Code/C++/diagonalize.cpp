#include <armadillo>
#include <iostream>
#include <cmath>


using namespace std;
using namespace arma;


mat diagonalize(mat A){
  vec eigVal;
  mat eigVec;
  //Finding the eigenvalues
  eig_sym(eigVal, eigVec, A);
  //Creating diagonal matrix
  mat diagonalized = diagmat(eigVal);
  return diagonalized;
}

int main(){
  //constants
  double h = 0.1;
  int N = 10;
  double d = 2 / (h * h);
  double a = -1 / (h * h);

//setting up matrix A.
  mat A = mat(N,N);
  //changing the diagonal + non diagnonal(above/below diag) elements
  A.diag()   += d;
  A.diag(1)  += a;
  A.diag(-1) += a;

  mat B;
  B =  diagonalize(A);
  cout<<B<<endl;

  for (int i = 0;i < N;i++){
    int lambda = d + 2 * a * cos (i * M_PI /(N + 1));
    cout <<lambda << endl;
  }
}
