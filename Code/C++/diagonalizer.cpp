//Compile with: g++ matrixCreator.cpp -o matrixCreator -std=c++11 -larmadillo -lopenblas -llapack
// run with matrix dimension as argument
#include <iostream>
#include <fstream>
#include <armadillo>
#include <cmath>
#include <cstdlib>

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

  mat A("1 2 3 4; 5 6 7 8; 1 2 4 3; 1 4 3 1");
  mat  B = diagonalize(A);
  cout <<B<< endl;
}
