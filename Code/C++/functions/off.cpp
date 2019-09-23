#include <armadillo>
#include <iostream>
#include <cmath>
#include "funcs.h"

using namespace std;
using namespace arma;

void off(mat A, int N, double* max, int* k, int* l){    //double* means it will be recieving a double POINTER. to get this value use *max
   // finding the maximum of the off-diagonal elements.
   for ( int i = 0 ; i < N ; i++ ){
       for ( int j = i+1 ; j < N ; j++ ){

          double aij = fabs( A(i,j) );        //Looking at the floating absolute of the element in the matrix

          if ( aij > *max ){                  //If the element is greater than any previous element
            *max = aij;  *k = i; *l = j;         //Then we want to store its index and its value

          }
       }
   }
   cout << *k << " off " << *l << endl;
   return;
}
