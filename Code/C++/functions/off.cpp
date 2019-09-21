int off(mat A, int n, double max_off){
   double max;
   double sum = 0.0;
   int k; int l;
   for (int i = 0; i < n; ++i){
       for ( int j = i+1; j < n; ++j){
           double aij = fabs(A(i,j));
           sum+=aij;
           if ( aij > max){ 
              max = aij;  k = i; l = j;
           }
       }
   }
   max_off = sum;
   return k, l;
}