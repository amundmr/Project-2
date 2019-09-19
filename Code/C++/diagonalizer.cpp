//Compile with: g++ matrixCreator.cpp -o matrixCreator -std=c++11 -larmadillo -lopenblas -llapack
// run with matrix dimension as argument
#include <iostream>
#include <fstream>
#include <armadillo>
#include <cmath>
#include <cstdlib>

using namespace std;
using namespace arma;

void diagonalize(mat A){
  vec eigVal;
  mat eigVec;
  //Finding the eigenvalues
  eig_sym(eigVal, eigVec, A);
  //Creating diagonal matrix
  mat diagonalized = diagmat(eigVal);
  return diagonalized;
}
