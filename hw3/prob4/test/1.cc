#include "test.hh"
#include "dft.hh"

#define EPSILSON 0.0001

int main ( int argc, char * argv[] ) {

    // testing all constructors and method of matrix of type double

    //CONSTRUCTORS TEST
    std::cout << "---constructor test---" << std::endl;
    matrix<double> A(3,3);
    std::cout << "A = " << std::endl << A;
    ASSERT ( A.rows() == 3 && A.columns() == 3 );

    dft a_dft(4);
    matrix<complex> x(4,1);
    matrix<complex> X = a_dft.compute_dft(x);
    X = a_dft.compute_dft(x);

    std::cout << "All test passed successful"  << std::endl;

    SUCCEED;

}
