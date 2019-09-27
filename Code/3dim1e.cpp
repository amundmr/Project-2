#include <armadillo>
#include <cmath>
#include <iostream>

using namespace std;
using namespace arma;

mat Jacobi_method(mat A, int N);
tuple<mat,int> d_initialize();

int main() {
  auto init_values = initialize();
  mat A = get<0>(init_values);
  int N =get<1>(init_values);

  cout << A << endl;
  mat C;

  C = Jacobi_method(A,N);

  cout << C << endl;

  return 0;
}
