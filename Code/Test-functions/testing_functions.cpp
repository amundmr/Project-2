#include "catch.hpp"
#include <armadillo>
#include <cmath>
#include <iostream>

#include<fstream>
#include<math.h>
#include<iomanip>

#include<algorithm>
#include<vector>


//#include "jacobi_method.h" //må få riktig navn her
using namespace std;
using namespace arma;

mat Jacobi_rotate(mat A, int k, int l, int n);
double off(mat A, int &k, int &l, int n);
vec arma_eig(mat A);
vec Jacobi_method(mat A, int n);

TEST_CASE("Test max a(i,j)"){
  int n = 10;
  mat A(n,n, fill::zeros);
  A.diag() += 2;
  A.diag(-1) -= 1;
  A.diag(1) -= 1;


  double pmin = 0, pmax = 10, h = (pmax-pmin)/(n);
  mat a = zeros<mat>(n,n);
  mat v = zeros<mat>(n,n);
  vec r(n);

  int p = 0;
  int q = 0;
  double apq = 0;

  off(A, p, q, n); //finding max and min

  REQUIRE(p==0);
  REQUIRE(q==0);
  REQUIRE(apq == Approx(-0.09));

}


TEST_CASE("Eigenvalues"){
  int n = 10;
  mat A(n,n, fill::zeros);
  A.diag() += 2;
  A.diag(-1) -= 1;
  A.diag(1) -= 1;

  int interact = 0;
  double conv = 0.001, wr =0.01, pmin = 0, pmax = 10, h = (pmax-pmin)/(double(n));
  n = n-1;
  mat a = zeros<mat>(n,n);
  mat v = zeros<mat>(n,n);
  vec r(n);

  Jacobi_method(A,n);

  vec eigenvalue = arma_eig(A);

    double eig_1 = eigenvalue[0];
    double eig_2 = eigenvalue[1];
    double eig_3 = eigenvalue[2];

  REQUIRE( eig_1 = Approx( 0.0810 )..epsilon(0.00001));
  REQUIRE( eig_2 = Approx( 0.23175 ).epsilon(0.00001));
  REQUIRE( eig_3 = Approx( 0.06903 ).epsilon(0.00001));

}
