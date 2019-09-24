#include<iostream>
#include<armadillo>
#include<vector>

using namespace std;
using namespace arma;


int main(){
  double n = 10;

  mat a = zeros<mat>(n,n);
  cout <<"a:"<< a <<endl;
  vec r(n);
  cout<<"r:"<< r <<endl;
}
