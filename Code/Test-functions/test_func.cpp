#include "catch.hpp"

#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

mat Jacobi_rotate(mat A, int k, int l, int n);
double off(mat A, int &k, int &l, int n);
vec arma_eig(mat A);
vec Jacobi_method(mat A, int n);

TEST_CASE("Test max a(i,j)"){
  //Initializing matrix A with 2 on diag. Max elem is on A(0,0)
  int n = 5;
  mat A(n,n, fill::zeros);
  A.diag() += 2;
  A.diag(-1) -= 1;
  A.diag(1) -= 1;
  cout << A << endl;


  //Declaring k and l in memory for off() to return max indexes to
  int k = 0;
  int l = 0;

  double apq = off(A, k, l, n); //finding max indexes, returning value

  //Require that both indexes are 0 since the largest element is for 0
  REQUIRE(k==0);
  REQUIRE(l==0);
  REQUIRE(apq == Approx(2));

}


TEST_CASE("Testing eigenvalues"){
  //Initializing matrix A with 2 on diag. Max elem is on A(0,0)
  int n = 5;
  mat A(n,n, fill::zeros);
  A.diag() += 2;
  A.diag(-1) -= 1;
  A.diag(1) -= 1;



  vec eigvec = Jacobi_method(A,n);

  double eps = 0.00001;

  REQUIRE( eigvec(0) == Approx( 0.26795  ).epsilon(eps));
  REQUIRE( eigvec(1) == Approx( 1.0      ).epsilon(eps));
  REQUIRE( eigvec(2) == Approx( 2.0      ).epsilon(eps));
  REQUIRE( eigvec(3) == Approx( 3.0      ).epsilon(eps));
  REQUIRE( eigvec(4) == Approx( 3.73205  ).epsilon(eps));

}
