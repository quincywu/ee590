#include <iostream>
#include <stdexcept>
#include "matrix.hh"
#include "complex.hh"
// DFT header

class dft_exception : public std::runtime_error {
public:
  dft_exception(const char msg[]) : std::runtime_error(msg) { }
};


class dft {

public:

    // Constructors and destructors
	dft( int num_pts );
	~dft();

    // The copy constructor
    dft& operator=(const dft &other);

    void transform (); // return nxn DFT matrix for transform, W

    matrix<complex> compute_uni ( matrix<complex> x ); // returns the nxn unitary transform (the DFT matrix scaled by sqrt(n))

    matrix<complex> inverse_transform ( const matrix &m ); // return inverse of transform

    matrix<complex> compute_dft ( matrix<complex> x ); // input n x 1 matrix, return X

    //matrix compute_inverse_dft ( matrix x ); // input n x 1 matrix

private:
    int n; // N
    static int dft_count;
    static int uni_count;
    matrix<complex>* uni_matrix;
    matrix<complex>* dft_matrix;
    //static matrix& inverse_matrix;

};

// Interface with ostreams
//std::ostream& operator<<(std::ostream& os, const matrix &m);
