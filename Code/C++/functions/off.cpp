#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

void off(mat A, int N, double * max_pointer, int * k_pointer, int * l_pointer){    //double* means it will be recieving a double POINTER. to get this value use *max
   // finding the maximum of the off-diagonal elements.
   for ( int i = 0 ; i < N-1 ; ++i ){
       for ( int j = i+1 ; j < N-1 ; ++j ){

         double aij = fabs( A(i,j) );          //Looking at the floating absolute of the element in the matrix

         if ( aij > *max_pointer ){                    //If the element is greater than any previous element
            *max_pointer = aij;  *k_pointer = i; *l_pointer = j;        //Then we want to store its index and its value
          }
       }
   }
   //cout << *k << " off " << *l << endl;
   return;
}