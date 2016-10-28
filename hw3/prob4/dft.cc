#include <iostream>
#include "dft.hh"
#include <math.h>

// DFT
int dft::dft_count = 1;
int dft::uni_count = 1;

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
	delete uni_matrix;
    delete dft_matrix;
    //delete inverse_matrix;
}


void dft::transform () { //static method
    complex w ( 0, -2 * M_PI / n );
    w.e_power(w);
    std::cout << "w = " << w << std::endl;

    dft_matrix  = new matrix<complex> (n);
    uni_matrix  = new matrix<complex> (n);

    for ( int i=0; i<n; i++ ) {
      for ( int j=0; j<n; j++ ) {
        dft_matrix->set(i,j, (w.power( (i * j)%n) ));
        uni_matrix->set(i,j, (w.power( (i * j)%n)/sqrt(n) ));
      }
    }



    std::cout << "hereererere = " << std::endl;
    std::cout << (matrix<complex>)*dft_matrix;

}

matrix<complex>  dft::compute_uni ( matrix<complex> x ){
    //make sure x is N x 1 matrix
    if ( x.rows() != n ) {
      throw dft_exception("Attempted to get dft of incorrect data points");
    }
    if(uni_count > 1) return *uni_matrix;

    matrix<complex> X = *uni_matrix * (x);// nx1 matrix
    uni_count ++;

    return X;
}

matrix<complex>  dft::compute_dft ( matrix<complex> x ){
    //make sure x is N x 1 matrix
    if ( x.rows() != n ) {
      throw dft_exception("Attempted to get dft of incorrect data points");
    }
    std::cout << "cccc" << std::endl;
    if(dft_count > 1) return *dft_matrix;

    std::cout << "x.rows = " << x.rows() << std::endl;
    std::cout << "dft rows = " << dft_matrix->rows() << std::endl;
    std::cout << "dft columns = " << dft_matrix->columns() << std::endl;
    std::cout << "bbbbbb = " << std::endl;
    std::cout << (matrix<complex>)*dft_matrix;

    std::cout << "x " << x << std::endl;
    matrix<complex> X = *dft_matrix * (x);// nx1 matrix
    dft_count ++;
    std::cout<< "dft_count = " << dft_count << std::endl;
    return X;
}
