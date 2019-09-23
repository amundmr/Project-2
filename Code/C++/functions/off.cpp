#include <armadillo>
#include <iostream>
#include <cmath>
#include "funcs.h"

using namespace std;
using namespace arma;

void off(mat A, int N, double max, int k, int l){
   // finding the maximum of the off-diagonal elements.
   for ( int i = 0 ; i < N ; i++ ){
       for ( int j = 0 ; j < N ; j++ ){

          if ( i != j ){                        //If i != j we are above or below
            double aij = fabs( A(i,j) );        //Looking at the element in the matrix

            if ( aij > max ){                   //If the element is greater than any previous element
              max = aij;  k = i; l = j;         //Then we want to store its index and its value

            }
          }
       }
   }
   cout << k << " off " << l << endl;
   return;
}
