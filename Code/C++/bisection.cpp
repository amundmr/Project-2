#include <iostream>
#include <math.h>   //fabs()
#include <armadillo>
#include <iomanip>

using namespace std;
using namespace arma;

vec f(double x); //declearing function
vec f(double x)  //defining function
{
  double pi, diag = 2.0, nondiag = -1.0;
  double n = 10;
  vec p = zeros<vec>(n);
  p[1] = 1;
  p[0] = 0;
  for (int i = 2; i <= n ; ++i)
  {
  p[i] = (diag - x) * (p[i-1]) - (nondiag * nondiag * (p[i-2]));
  }
  return p;
}

double bisection(double a, double b, int n)
{
  double c, epsilon = 1E-9, root, fa_i, fb_i, fc_i;
  int i;
  vec fa, fb, fc;

  for (int i = 2; i <= 4; i++)
  {
    c = (a + b) /2.0;
    fa = f(a);
    fa_i = fa[i];
    fb = f(b);
    fb_i = fb[i];
    fc = f(c);
    fc_i = fc[i];

    cout <<"fa: " << fa <<endl;
    cout <<"fai: " << fa_i <<endl;
    cout <<"fb: " << fb <<endl;
    cout <<"fbi: " << fb_i <<endl;

    if ((fa_i * fb_i) > 0)         //root not in intervall
    {
      cout << "No roots in intervall [" <<a<< " , "<< b << "]"<<endl;
    }
    while (fabs(b - a) >= epsilon)
    {
      //cout<<setw(18)<<a<<setw(18)<<b<<setw(18)<<fc<<setw(18)<<fabs(a-b)<<endl;

      if (fc_i == 0.0)
      {
        cout <<"Root is: " << c << endl;
        //return 0;
      }

      if (fa_i*fc_i > 0)        //no root between a and c
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
}



    //cout<<setw(12)<<"a"<<setw(18)<<"b"<<setw(18)<<"f(c)"<<setw(18)<<"|a-b|"<<endl;



int main()
{
  double a = 0.0, b = 1.0;
  int n = 10;
  bisection(a,b,n);
}
