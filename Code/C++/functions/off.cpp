#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

int off(mat A, int N, double max){
   int k; int l;
   // finding the maximum of the off-diagonal elements.
   for (int i = 0; i < N; ++i){
       for ( int j = i+1; j < N; ++j){
           double aij = fabs(A(i,j));
           if ( aij > max){
              max = aij;  k = i; l = j;
              // storing the maximum value and returning its indices.
           }
       }
   }
   return k, l, max;
}
