#include <iostream>
#include "fraction.hh"

fraction::fraction ( int top, int bottom = 1 ) : num(top), den(bottom) {
	
	
	
}

matrix::matrix ( int r, int c ) : num_rows(r), num_columns(c) {

  if ( r <= 0 || c <= 0 ) {
    throw matrix_exception("Attempted to initialize a matrix with non-positive number of rows and/or columns");
  }

  value = new double[r*c];

  for ( int i=0; i<r*c; i++ ) {
    value[i] = 0.0;
  }

}