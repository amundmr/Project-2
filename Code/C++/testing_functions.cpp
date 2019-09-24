#include "catch.hpp"
#include "jacobi.h" //må få riktig navn her

using namespace std;


TEST_CASE("Test max a(i,j"){
  int n = 3;
  double pmin = 0, pmax = 10, h = (pmax-pmin)/(double(n));
  mat a = zeros<mat>(n,n);
  mat v = zeros<mat>(n,n);
  vec r(n);
  initialize(n,h,a,r,v,0,0);
  int p = 0;
  int q = 0;
  double apq = 0;
  find_max(a,p,q,apq,n);

  REQUIRE(p==2);
  REQUIRE(q==1);
  REQUIRE(apq == Approx(-0.09));

}
