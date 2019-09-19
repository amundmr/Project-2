#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

int main(){
  //vonstants
  double h = 0.1;
  int N = 10;
  double d = 2/h*h;
  double a = -1/h*h;

  mat A = mat(N,N);
  //changing the diagonal elements
  A.diag()   += d;
  A.diag(1)  += a;
  A.diag(-1) += a;

//set a matrix
//change diagonal elements to 2/h^2 and  and non diag to -1/h^2

  //return diagonalize(A);
  cout << A << endl;  // generate a symmetric matrix
  //cout << B << endl;

}

//preserved ortogonality
//at least two tests!!
