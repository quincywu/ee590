#include <stdio.h>
#include "matrix.h"

int main ( int argc, char * argv[] ) {

  Matrix * A = matrix_new ( 2, 2 ),
         * B = matrix_random ( 4, 4 ),
         * C,
         * D = matrix_new( 3, 4 ),
         * E = matrix_new( 4, 3 ),
         * F;

  matrix_set ( A, 0, 0, 1 ); matrix_set ( A, 0, 1, 2 );
  matrix_set ( A, 1, 0, 3 ); matrix_set ( A, 1, 1, 4 );

  matrix_set ( D, 0, 0, 2 ); matrix_set ( D, 0, 1, 2 );
  matrix_set ( D, 1, 0, 3 ); matrix_set ( D, 1, 1, 4 );

  C = matrix_add ( A, A );
  matrix_print ( C ); NL;
  matrix_destroy ( C );

  matrix_print ( B ); NL;
  C = matrix_minor ( B, 1 );
  matrix_print ( C ); NL;
  matrix_destroy ( C );

  printf ( "det = %lf\n", matrix_det ( B ) );

  C = matrix_from_file ( "data/m1.mat" );
  matrix_print(C); NL;
  printf ( "det = %lf\n", matrix_det ( C ) );

  matrix_destroy(C);

  //added
  matrix_set ( D, 0, 0, 1 ); matrix_set ( D, 0, 1, 2 ); matrix_set ( D, 0, 2, 3 ); matrix_set ( D, 0, 3, 4 );
  matrix_set ( D, 1, 0, 3 ); matrix_set ( D, 1, 1, 4 ); matrix_set ( D, 1, 2, 2 ); matrix_set ( D, 1, 3, 1 );
  matrix_set ( D, 2, 0, 3 ); matrix_set ( D, 2, 1, 3 ); matrix_set ( D, 2, 2, 3 ); matrix_set ( D, 2, 3, 3 );

  matrix_set ( E, 0, 0, 12 ); matrix_set ( E, 0, 1, 2 ); matrix_set ( E, 0, 2, 3 );
  matrix_set ( E, 1, 0, 3 ); matrix_set ( E, 1, 1, 4 ); matrix_set ( E, 1, 2, 2 );
  matrix_set ( E, 2, 0, 3 ); matrix_set ( E, 2, 1, 7 ); matrix_set ( E, 2, 2, 2 );
  matrix_set ( E, 3, 0, 3 ); matrix_set ( E, 3, 1, 3 ); matrix_set ( E, 3, 2, 3 );

  C = matrix_mult( D, E);

  F = matrix_power( C, 2 );
  matrix_print ( F ); NL;

  /*int a = matrix_equal ( A, A );
  printf ( "equal = %d\n", a );

  a = matrix_equal ( A, D );
  matrix_print ( A ); NL;
  matrix_print ( D ); NL;
  printf ( "equal = %d\n", a );*/

  return 0;

}
