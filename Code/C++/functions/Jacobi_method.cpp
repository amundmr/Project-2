int off(mat A, int n, double max_off);

void Jacobi_rotate(mat A, mat B, int k, int l, int n);

mat Jacobi_method(mat A, int n){
    double epsilon = 1.0e-8;
    int max_iterations = 1e5;
    int i = 0;
    double max_off = 0.0;
    mat B;
    
    while (max_off > epsilon && i <= max_iterations){
        B = A;
        int k,l = off(A, n, max_off);
        Jacobi_rotate(A,B,k,l,n);
        A=B;
        i++;
    }
}