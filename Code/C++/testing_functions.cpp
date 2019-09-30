#include "catch.hpp"
#include "jacobi.h" //må få riktig navn her

using namespace std;


TEST_CASE("Test max a(i,j"){
  int N = 3;
  double pmin = 0, pmax = 10, h = (pmax-pmin)/(double(N));
  mat a = zeros<mat>(n,n);
  mat v = zeros<mat>(n,n);
  vec r(n);
 //initialize and vecs
 initialize(n,h,a,r,0,0);
  int p = 0;
  int q = 0;
  double apq = 0;
  off(a,p,q,apq,n); //finding max and min

  REQUIRE(p==2);
  REQUIRE(q==1);
  REQUIRE(apq == Approx(-0.09));

}


TEST_CASE("Eigenvalues"){
  int N = 5, interact = 0;
  double conv = 0.001, wr =0.01, pmin = 0, pmax = 10, h = (pmax-min)/(double(N));
  N = N-1;
  mat a = zeros<mat>(n,n);
  mat v = zeros<mat>(n,n);
  vec r(n);

  initialize(variables);
  jacobi(variables)

  vector<double>eigenvalue=get_eigenvals(a,n);

  REQUIRE(eigenvalue[0] = approx())
  REQUIRE(eigenvalue[1] = approx())
  REQIORE(eigenvalye[2] = approx())

}
