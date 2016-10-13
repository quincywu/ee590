This is prob 6.
Implement the inverse of a matrix.

Matrix * matrix_inverse ( Matrix * M );          /* returns the inverse of M */

The easiest to understand method will be to use the "matrix of co-factors" method, described here. Make sure to check that the determinant is not zero and exit(-1) if it is zero.

We will grade this problem the same way we grade the previous problem, within a custom example.c file that we compile with your code. It will define a few matrices, multiply by their inverses and see if the result is the identity matrix.
