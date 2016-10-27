#include <iostream>
#include "dft.hh"
#include <math.h>

// DFT
int dft::dft_count = 1;

dft::dft ( int num_pts ) {

    if ( num_pts <= 0 ) {
      throw dft_exception("Attempted to initialize a dft matrix with non-positive number of points");
    }
    std::cout << "calling constructor" << std::endl;
	n = num_pts;

    //dft::transform();

    dft::transform();
}


dft::~dft() {
	//delete uni_matrix;
    //delete &dft_matrix;
    //delete inverse_matrix;
}


matrix<complex>& dft::transform () { //static method
    complex w ( 0, -2 * M_PI / n );
    w.e_power(w);
    std::cout << "w = " << w << std::endl;

    matrix<complex> temp (n);

    for ( int i=0; i<n; i++ ) {
      for ( int j=0; j<n; j++ ) {
        temp.set(i,j, w.power( (i * j)%n ) );
      }
    }
    std::cout << temp;
    dft_matrix = &temp;

    return *dft_matrix;
}


matrix<complex>  dft::compute_dft ( matrix<complex> x ){
    //make sure x is N x 1 matrix
    if ( x.rows() != n ) {
      throw dft_exception("Attempted to get dft of incorrect data points");
    }

    if(dft_count > 1) return *dft_matrix;

    matrix<complex> X(n,1);

    std::cout << "x.rows = " << x.rows() << std::endl;

    std::cout << "hereererere = " << std::endl;
    std::cout << (matrix<complex>)*dft_matrix;
    std::cout << "x " << x << std::endl;

    X = ((matrix<complex>)*dft_matrix) * x;// nx1 matrix

    return X;
}
