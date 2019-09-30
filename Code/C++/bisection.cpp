#include <iostream>
#include <math.h>   //fabs()
#include <armadillo>

using namespace std;
using namespace arma;

double f(double x); //declearing function
double f(double x)  //defining function
{
  double pi, diag = 2.0, nondiag = -1.0;
  double n = 10;
  vec p = zeros<vec>(n);

  p[1] = 1;
  p[0] = 0;

  for (int i = 2; i <= n ; ++i)
  {
  pi = (diag - x)*(p[i-1]) - (nondiag*nondiag*(p[i-2]));
  cout << "p[i]: "<< p[i]<<endl;
  }

  return pi;
}

double bisection(double a, double b)
{
  double c, epsilon = 1E-9, root;
  int i;
  double fa, fb, fc;

    //cout<<setw(12)<<"a"<<setw(18)<<"b"<<setw(18)<<"f(c)"<<setw(18)<<"|a-b|"<<endl;

    if ((fa * fb) > 0)         //root not in intervall
    {
      cout << "No roots in intervall [" <<a<< " , "<< b << "]"<<endl;
    }
    while (fabs(b - a) >= epsilon)
    {
      c = (a + b) /2.0;
      fc = f(c);
      fb = f(b);
      fa = f(a);
      cout <<"fa: " << fa <<endl;
      cout <<"fb: " << fb <<endl;
      //cout<<setw(18)<<a<<setw(18)<<b<<setw(18)<<fc_i<<setw(18)<<fabs(a-b)<<endl;

      if (fc == 0.0)
      {
        cout <<"Root is: " << c << endl;
        return 0;
      }

      if (fa*fc > 0)        //no root between a and c
      {
        a = c;
      }
      else              //Root lies here.
      {
        b = c;
      }
    }
    cout << "The root for f(c) " << f(c) << " is " << c << endl;
}


int main()
{
  double a = 0.0, b = 1.0;
  int n = 100;
  bisection(a,b);
}
