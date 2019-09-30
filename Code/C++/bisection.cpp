#include <iostream>
#include <math.h>   //fabs()
#include <armadillo>

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
<<<<<<< HEAD
  for (int i = 2; i <= n ; ++i)
  {
  p[i] = (diag - x) * (p[i-1]) - (nondiag * nondiag * (p[i-2]));
  }
  return p;
}

double bisection(double a, double b)
{
  double c, epsilon = 1E-9, root, fa_i, fb_i, fc_i;
  int i;
  vec fa, fb, fc;

  c = (a + b) /2.0;
  fc[0] = f(c);
  fb = f(b);
  fa = f(a);

  for (int i = 2; i <= 4; i++)
  {

    fa_i = fa[i];
    fb_i = fb[i];
    //fc_i = fc[i];

    cout <<"fa: [" << fa <<" ]"<<endl;
    cout <<"fai: " << fa_i <<endl;
    cout <<"fb: " << fb <<endl;
    cout <<"fbi: " << fb_i <<endl;

    cout<<setw(12)<<"a"<<setw(18)<<"b"<<setw(18)<<"f(c)"<<setw(18)<<"|a-b|"<<endl;

    if ((fa_i * fb_i) > 0)         //root not in intervall
    {
      cout << "No roots in intervall [" <<a<< " , "<< b << "]"<<endl;
    }
    while (fabs(b - a) >= epsilon)
    {
      //cout<<setw(18)<<a<<setw(18)<<b<<setw(18)<<fc_i<<setw(18)<<fabs(a-b)<<endl;

      if (fc == 0.0)
      {
        cout <<"Root is: " << c << endl;
        return 0;
      }

      if (fa_i*fc > 0)        //no root between a and c
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






int main()
{
  double a = 0.0, b = 1.0;
  int n = 100;
  bisection(a,b);
}
=======

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
  int N = 1000;
    double a = 0.0, b = 1.0;
    bisection(a,b);

}
>>>>>>> 5e88b130696d458ad37dc4c018da9ed1e25cc816
