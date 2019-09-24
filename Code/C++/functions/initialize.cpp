#include <armadillo>

using namespace arma;
using namespace std;

tuple<mat,int> initialize(){
    double Rstart = 0.0; double Rfin = 1.0; //Start and stop values
    int N = 10;                             //Number of iterations(integrationpoints)
    double h = (Rfin-Rstart)/N;             //Spacing/stepsize
    double d = 2 / (h * h);                 //Diagonal element
    double a = -1 / (h * h);                //Nondiagonal element

    //Setting up matrix A.
    mat A = mat(N,N, fill::zeros);

    //Changing the diagonal + non diagnonal(above/below diag) elements
    A.diag()   += d;
    A.diag(1)  += a;
    A.diag(-1) += a;

    return make_tuple(A,N);
}