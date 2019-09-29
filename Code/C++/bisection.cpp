#include <iostream>
#include <math.h>   //fabs()
#include <armadillo>

using namespace std;
using namespace arma;

double f(double x){
  double pi, diag = 2.0, nondiag = -1.0;
  int n = 10;
  vec p = zeros<vec>(n);
  p[1] = 1;
  p[0] = 0;
  for (int i = 2; i <= n ; ++i){
    pi = (diag - x) * (p[i-1]) - (nondiag * nondiag * (p[i-2]));
    p[i] = pi;
  }
  return pi;
}

void bisection(double a, double b){
  double c, epsilon = 1e-8, root, fa, fb, fc;
  if ((f(a) * f(b)) > 0){ // Root not in interval, don't do anything
  }
  else{
    while (fabs(b - a) >= epsilon){
      c = (a + b) /2.0;
      
      // If there's no root between a and c, set a=c
      if (f(a)*f(c) > 0){
        a = c;
      }
      // If there's a root between a and c, set a=b
      else{
        b = c;
      }
    }
    cout <<"Root found: " << c << endl;
  }
}

int main(){
  double start = -10;
  double end = 10;
  int N = 1000;
  double h = (end-start)/N;

  cout << "Searching for roots in interval: [" << start << "," << end << "]" << endl << endl;
  // Test for roots in small intervals from start to end
  for (int i = 0; i <= 200; i++){
    double a = h*i;
    double b = h*(i+1);
    bisection(a,b);
  }
}