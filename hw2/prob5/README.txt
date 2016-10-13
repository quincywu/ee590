IGNORE THIS FOLDER GO TO PROB 6 !!!!
























This is prob 5.
Copy the ee590/lec2 code into your prob5 directory, make and then run ./example. Implement the following methods to the matrix library.

int matrix_equal ( Matrix * A, Matrix * B );      /* return 1 if A == B (element wise) and 0 otherwise */
Matrix * matrix_identity ( int n );               /* return the nxn identity matrix */
Matrix * matrix_scale ( Matrix * M, double s );   /* return s * M, multiplying each element of M by s */
Matrix * matrix_transpose ( Matrix * M );         /* return the transpose of M */
Matrix * matrix_mult ( Matrix * A, Matrix * B );  /* return A*B using matrix multiplication */
Matrix * matrix_power ( Matrix * M, int n );      /* return M^n = M * M * ... * M (n times ) */


Test your code using random matrices or example matrices that you read in. We have added a matrix input method that expects files that look something like the following:

3,3
1.0,  2.3, -0.5
1.0,  0.0,  0.0
4.0, -1.5,  5.6

The first two numbers are the dimensions (rows, columns) and the remaining entries are the elements of the matrix separated by commas or newlines. Whitespace is ignored.

We will grade this problem by overwriting example.c with our own example.c code and recompiling. It will read matrices that we add to your data directory (see the current example.c) and transpose them, multiply them, raise them to various powers, and check the results.

Although we will not try to break your code by using negative dimensions or other incorrect calls, your code should sanity check the arguments to each method.
