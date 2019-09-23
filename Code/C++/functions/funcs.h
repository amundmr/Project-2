#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <armadillo>
using namespace std;
using namespace arma;
mat Jacobi_method(mat, int);
void off(mat, int, double, int, int);
void Jacobi_rotate(mat, mat, int, int, int);

#endif
