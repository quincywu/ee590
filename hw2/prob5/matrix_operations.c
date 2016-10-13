#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix * matrix_add ( Matrix * A, Matrix * B ) {

  ASSERT ( A->rows == B->rows && A->columns == B->columns );

  Matrix * C = matrix_new ( A->rows, A->columns );

  for ( int i=0; i<A->rows; i++ ) {
    for ( int j=0; j<A->columns; j++ ) {
      matrix_set(C, i, j, matrix_get(A,i,j) + matrix_get(B,i,j) );
    }
  }

  return C;

}

Matrix * matrix_minor ( Matrix * M, int n ) {

  ASSERT ( 0 <= n && n < M->columns );

  Matrix * P = matrix_new ( M->rows - 1, M->columns - 1 );

  for ( int i=1; i<M->rows; i++ ) {
    for ( int j=0; j<n; j++ ) {
      matrix_set(P,i-1,j,matrix_get(M,i,j));
    }
  }

  for ( int i=1; i<M->rows; i++ ) {
    for ( int j=n+1; j<M->columns; j++ ) {
      matrix_set(P,i-1,j-1,matrix_get(M,i,j));
    }
  }

  return P;

}

double matrix_det ( Matrix * M ) {

  if ( M->rows == 1 && M->columns == 1 ) {

    return matrix_get(M,0,0);

  } else {

    double sign = 1,
           sum = 0;

    for ( int i=0; i<M->columns; i++ ) {
      Matrix * P = matrix_minor ( M, i );
      sum += sign * matrix_get(M,0,i) * matrix_det(P);
      sign *= -1;
      matrix_destroy ( P );
    }

    return sum;

  }

}

int matrix_equal ( Matrix * A, Matrix * B ){
    ASSERT ( A->rows == B->rows && A->columns == B->columns );

    for ( int i=0; i<A->rows; i++ ) {
        for ( int j=0; j<A->columns; j++ ) {

            if (  matrix_get(A,i,j) !=  matrix_get(B,i,j))
                return -1;
        }
    }

    return 0;
}

Matrix * matrix_identity ( int n ){
    ASSERT( n > 1 );

    Matrix * M = matrix_new ( n, n );
    for (int i = 0; i<M->rows; i++) {
        for ( int j=0; j<M->columns; j++ ) {
            if ( i == j )
                matrix_set ( M, i, j, 1 );
            else
                matrix_set ( M, i, j, 0 );
        }
    }

    return M;
}

Matrix * matrix_scale ( Matrix * M, double s ) {

    for ( int i=0; i<M->rows; i++ ) {
        for ( int j=0; j<M->columns; j++ ) {
                matrix_set(M, i, j, s * matrix_get(M,i,j) );
      }
    }

    return M;
}

Matrix * matrix_transpose ( Matrix * M ){

    Matrix * T= matrix_new ( M->rows, M->columns );

    for ( int i=0; i<M->rows; i++ ) {
        for ( int j=0; j<M->columns; j++ ) {
            matrix_set(T, i, j, matrix_get(M,j,i) );
        }
    }

    return T;
}

Matrix * matrix_mult ( Matrix * A, Matrix * B ){
    ASSERT( A->columns == B->rows);

    Matrix * M = matrix_new ( A->rows, B->columns ); // (m x n)(n x p) = m x p

    for ( int i=0; i<M->rows; i++ ) {
        for ( int j=0; j<M->columns; j++ ) {

            double num = 0;
            for(int k = 0; k < A->columns; k++){
                num += matrix_get(A,i,k) * matrix_get(B,k,j);
            }

            matrix_set(M, i, j, num);
        }
    }

    return M;
}

Matrix * matrix_power ( Matrix * M, int n ){
    ASSERT( n >= 0 && M->rows == M->columns);

    if(n == 0) return matrix_identity(M->rows);
    if(n == 1) return M;

    Matrix * P = matrix_new ( M->rows, M->columns );
    for ( int i=0; i<P->rows; i++ ) {
        for ( int j=0; j<P->columns; j++ ) {
            matrix_set(P, i, j, matrix_get(M,i,j) );
        }
    }

    for (int k = 1; k < n; k++){
        Matrix * TEMP = P;
        P = matrix_mult(P, M);
        matrix_destroy(TEMP);
    }

    return P;
}
