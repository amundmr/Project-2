#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

double off(mat A, int N, int &k, int &l){    //double* means it will be recieving a double POINTER. to get this value use *max
   // finding the maximum of the off-diagonal elements.
   double max = 0;
   for ( int i=0 ; i<N ; i++ ){
       for ( int j=0 ; j<N ; j++ ){
         if ( i!=j && (fabs(A(i,j)) > max) ){                    //If the element is greater than any previous element
            max = fabs(A(i,j));  k = i; l = j;        //Then we want to store its index and its value
          }
       }
   }

   return max;
}