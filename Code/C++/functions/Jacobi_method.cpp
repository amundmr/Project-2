int off(mat A, int n, double max_off);                      //Declaring off function

void Jacobi_rotate(mat A, mat B, int k, int l, int n);      //Declaring Jacobi_rotate function

mat Jacobi_method(mat A, int n){
    double epsilon = 1.0e-8;                                //Defining maximum deviation from 0 for the off diagonal elements
    int max_iterations = 1e5;                               //Setting a number of max iterations if the tolerance epsilon is not yet met
    int i = 0;
    double max_off = 0.0;                                   //Introducing variable for storing max off-diagonal value
    mat B;

    while (max_off > epsilon && i <= max_iterations){       //Run this loop until max deviation is less than eps or max iterations is met
        B = A;
        int k,l = off(A, n, max_off);                       //Gathers k,l(row & column of biggest off diagonal element)
        Jacobi_rotate(A,B,k,l,n);                           //Rotates matrix A around max element A(k,l), and returns it as B
        A=B;                                                //Setting A=B ready for new loop iteration
        i++;
    }
}
