const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of basic matrix multiply
   for (int i = 0; i < n; i++) { //loop n times, once for each row/element in final vector
        double temp = 0.0; //initialize our temp value used to calculate final vector elements
        for (int j = 0; j < n; j++) { // loop n times, because n columns for each row
            //i * n is all elements in all previous rows (row offset)
            //j is what column within that row
            //x[j], x is our vector, j is which row of x
            temp += A[i * n + j] * x[j]; 
        }
        y[i] = temp + y[i]; //add result of matrix multiplication for that row to y
    }
}
