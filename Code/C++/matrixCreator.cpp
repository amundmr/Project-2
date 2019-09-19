//Compile with: g++ matrixCreator.cpp -o matrixCreator -std=c++11 -larmadillo -lopenblas -llapack
// run with matrix dimension as argument
#include <iostream>
#include <fstream>
#include <armadillo>
#include <cmath>
#include <cstdlib>

using namespace std;
using namespace arma;

int main(int argc, char* argv[]) { //Input parameter is matrix dimension
  int i, j, dim;
  dim = atoi(argv[1]);

  //Range and step length
  double h, RMin, RMax;
  RMin = 0.0; RMax = 1.0;
  h = ( RMax - RMin ) / dim;

  //Diagonal and non-diagonal elements
  double diag, nonDiag;
  diag = 2.0 / ( h * h );
  nonDiag = -1.0 / ( h * h );

  //Defining matrix with a_ij
  /*  a00   b01
      b10   a11   b12
            b21   a22   b23
                  b32   a33   b34
  */

  mat tridiagonal = zeros<mat>(dim, dim);
  //Placing elements on diagonal and above and below diagonal.
  for (i = 0; i < dim ; i++) {
    for (j = 0; j < dim ; j++) {

      if ( i == j ) {
        tridiagonal(i,j) = diag;
      } else if ( i == j - 1 ) {
        tridiagonal(i,j) = nonDiag;
      } else if ( i == j + 1 ) {
        tridiagonal(i,j) = nonDiag;
      }
    }
  }
  //Initializing storage for eigenvalues and vectors
  vec eigVal;
  mat eigVec;
  //Finding the eigenvalues
  eig_sym(eigVal, eigVec, tridiagonal);
  //Creating diagonal matrix
  mat diagonalized = diagmat(eigVal);
  
  cout << diagonalized << endl;
  return 0;

}
