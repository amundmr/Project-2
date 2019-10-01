//compile as g++ bisection.cpp -larmadillo -lblas -llapack
#include <iostream>
#include <cmath>   //fabs()
#include <armadillo>

using namespace std;
using namespace arma;

<<<<<<< HEAD
 //declaring functions
vec Jacobi_method(mat A, int N);
double f(double x, int n);
void bisection(double a, double b, int n);
=======
vec Jacobi_method(mat A, int N);
>>>>>>> fcffc138f5735c99ca65c5b5c99cddf82271811a

double f(double x, int n)  //defining function for characteristic polynomial
{
  double f, diag = 2.0, nondiag = -1.0;
  vec p = zeros<vec>(n);

  p(0) = 1;
  p(1) = diag - x;

  for (int i=2; i<n; i++){
    p(i) = (diag-x)*p(i-1)-pow(nondiag,2)*p(i-2);
    f = p(i);
  }

  return f;
}
//Bisection method
void bisection(double a, double b, int n){
  double c, epsilon = 1e-15, root, fa, fb, fc;
  if ((f(a,n) * f(b,n)) > 0){ // Root not in interval, don't do anything
  }
  else{
    while (fabs(b - a) >= epsilon){
      c = (a + b) /2.0;

      // If there's no root between a and c, set a=c
      if (f(a,n)*f(c,n) > 0){
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
<<<<<<< HEAD

  int n = 20;
  int N = 10000;
  double start = 0.0, end = 1.00;
  double h = (end-start)/N;

  mat A(n,n, fill::zeros);
  A.diag() += 2;
  A.diag(-1) -= 1;
  A.diag(1) -= 1;

  vec Jacobi_method(mat A, int N);
  double f(double x, int n);
  void bisection(double a, double b, int n);



  //timing for comparason

  clock_t t0,t1;
=======
  int n = 200;
  int N = 1000;
  double start = -10.0, end = 10.0;
  double h = (end-start)/N;

  clock_t t0,t1;

>>>>>>> fcffc138f5735c99ca65c5b5c99cddf82271811a
  t0 = clock();
  for (int i=0; i<N; i++){
    double a = i*h;
    double b = h*(i+1);
    bisection(a,b,n);
  }
<<<<<<< HEAD
    t1 = clock();
    double t_bisec = (double (t1 - t0))/CLOCKS_PER_SEC; //tme spent on biesection solver.



/*timing to compare bisection with jacobi
  t0 = clock();
  vec eigvals = Jacobi_method(A, n);
  t1 = clock();
  double t_jacobi = (double (t1- t0)) /CLOCKS_PER_SEC;	// Time spent on our eigenvalue solver.


	cout << "------------------------------------" << endl;
	cout << "Time spent on our solver: " << t_jacobi << "s" << endl;

*/

  cout << "------------------------------------" << endl;
	cout << "Time spent on Bisection method: " << t_bisec << "s" << endl;
=======
  t1 = clock();

  double t_bisec = (double (t1 - t0))/CLOCKS_PER_SEC;

  mat A(n,n, fill::zeros);
  A.diag() += 2;
  A.diag(-1) -= 1;
  A.diag(1) -= 1;

  t0 = clock();
  vec eigvals = Jacobi_method(A, n);
  t1 = clock();

  double t_jacobi = (double (t1- t0)) /CLOCKS_PER_SEC;	// Time spent on Jacobi

  cout << "Time spent on bisection method: " << t_bisec << " s" << endl;
  cout << "Time spent on Jacobi method: " << t_jacobi << " s" << endl;
>>>>>>> fcffc138f5735c99ca65c5b5c99cddf82271811a
}
