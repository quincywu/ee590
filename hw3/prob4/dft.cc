#include <iostream>
#include "dft.hh"
#include <math.h>

// DFT

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
    complex w ( cos(-2*M_PI / n), sin(-2 * M_PI / n) );
    w = w.e_power();
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


    matrix<complex> X = *dft_matrix * x;// nx1 matrix

    return X;
}
