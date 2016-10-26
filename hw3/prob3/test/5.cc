#include "test.hh"
#include "matrix.hh"
#include "complex.hh"

#define epsilson_complex complex(0.0001)

int main ( int argc, char * argv[] ) {

    // testing all constructors and method of matrix of type complex
    std::cout << std::boolalpha;
    //CONSTRUCTORS TEST
    std::cout << "---constructor test---" << std::endl;
    matrix<complex> A(3,3);
    std::cout << "A = " << std::endl << A;
    ASSERT ( A.rows() == 3 && A.columns() == 3 );

    matrix<complex> I = matrix<complex>::identity(4);
    for ( int i=0; i<4; i++ ) {
      for ( int j=0; j<4; j++ ) {
        ASSERT ( ( i == j && I.get(i,j) == 1 ) || ( i!=j && I.get(i,j) == 0 ) );
      }
    }
    std::cout << "I(4) = " << std::endl << I;

    // Check that a matrix of ones is a matrix of ones.
    matrix<complex> O = matrix<complex>::ones(5,6);
    for ( int i=0; i<5; i++ ) {
      for ( int j=0; j<6; j++ ) {
        ASSERT ( O.get(i,j) == 1 );
      }
    }
    std::cout << "Ones(5,6) = " << std::endl << O;

    std::cout << "Test constructor, successful"  << std::endl;

    // check the copy constructor
    std::cout << "---copy constructor---"  << std::endl;

    A.set(0, 0, complex(2.3,3)); A.set(0, 1, complex(2)); A.set(0, 2, complex(2.5,-5));
    A.set(1, 0, -complex(3.2,0)); A.set(1, 1, complex(1.2,-2.4)); A.set(1, 2, complex(3.5,2));
    A.set(2, 0, complex(2.0,1)); A.set(2, 1, complex(-1)); A.set(2, 2, complex(-1.5));

    matrix<complex> B = A;
    std::cout << "A = " << std::endl << A;
    std::cout << "B = " << std::endl << B;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( B.get(i,j) == A.get(i,j) );
      }
    }

    std::cout << "Test copy constructor, successful"  << std::endl;

    //check scaling
    std::cout << "---scaling---" << std::endl;
    matrix<complex> C = A * 2;
    std::cout << "A = " << std::endl << A;
    std::cout << "C = " << std::endl << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == (A.get(i,j) * complex(2) ) );
      }
    }

    C = A;
    C.scale(-2.0);
    std::cout << "A = " << std::endl << A;
    std::cout << "C = " << std::endl << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == (A.get(i,j) * complex(-2.0)) );
      }
    }

    std::cout << "Test scaling, successful"  << std::endl;

    //check addition
    std::cout << "---addition---" << std::endl;
    C = A.add(B);
    std::cout << "C = " << std::endl << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == A.get(i,j) + B.get(i,j) );
      }
    }

    C = A + B;
    std::cout << "C = " << std::endl << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == A.get(i,j) + B.get(i,j) );
      }
    }
    std::cout << "C = " << std::endl << C;

    try {
        matrix<complex> D(3,4), E(4,5);
		std::cout << "Adding matrix of different size should fail at 1.cc line 11;" << std::endl;
        A = D.add(E);
        FAIL;
    } catch ( matrix_exception &e ) {
        std::cout << "successfully catch error of adding matrix of 2 different size," << std::endl;
    }

    std::cout << "Test addition, successful"  << std::endl;

    //check subtraction
    std::cout << "---subtraction---" << std::endl;

    matrix<complex> Z = A - B;
    std::cout << "Z = " << std::endl << Z;

    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
         // std::cout << "Z.get(i,j) = " << i << j << " " << Z.get(i,j) - EPSILSON << std::endl;
         ASSERT ( Z.get(i,j) == complex(0) );
      }
    }

    Z = A - C;
    std::cout << "Z = " << std::endl << Z;

    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
          //std::cout << "Z.get(i,j) = " << i << j << Z.get(i,j) - EPSILSON << std::endl;
          ASSERT ( Z.get(i,j) == -B.get(i,j) );
      }
    }

    std::cout << "Test subtraction, successful"  << std::endl;

    // check multiplication
    std::cout << "---multiplication---" << std::endl;
    A.set(0, 0, complex(-1,4)); A.set(0, 1, complex(4,6)); A.set(0, 2, complex(23,9));
    A.set(1, 0, complex(-5,7)); A.set(1, 1, complex(-14,-7)); A.set(1, 2, complex(-4,7));
    A.set(2, 0, complex(1,6)); A.set(2, 1, complex(4,4)); A.set(2, 2, complex(8,9));

    B = A;
    C.set(0, 0, complex(-108,137)); C.set(0, 1, complex(14,26)); C.set(0, 2, complex(-14,366));
    C.set(1, 0, complex(50,-107)); C.set(1, 1, complex(41,206)); C.set(1, 2, complex(-168,66));
    C.set(2, 0, complex(-119,63)); C.set(2, 1, complex(-64,14)); C.set(2, 2, complex(-92,303));

    Z = A * B;
    std::cout << "A = " << std::endl << A;
    std::cout << "B = " << std::endl << B;
    std::cout << "C = " << std::endl << C;
    std::cout << "Z = " << std::endl << Z;

    matrix<complex> eps_3(3,3);
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        eps_3.set(i,j, epsilson_complex );
      }
    }

    ASSERT(Z - eps_3 <= C && Z >= C - eps_3);

    std::cout.precision(17);
    matrix<complex> twobytwo1(2,2);
    twobytwo1.set(0, 0, complex( -14.220, -7.760));     twobytwo1.set(0, 1, complex(-4.25,7));
    twobytwo1.set(1, 0, complex( 4.300,4.400));          twobytwo1.set(1, 1, complex(8.75,9.5));

    matrix<complex> twobytwo_result = twobytwo1 * twobytwo1;
    matrix<complex> twobytwo_answer(2,2);
    twobytwo_answer.set(0, 0, complex(92.9158,232.0944)); twobytwo_answer.set(0, 1, complex(11.0675,-45.685));
    twobytwo_answer.set(1, 0, complex(-31.177,-16.586)); twobytwo_answer.set(1, 1, complex(-62.7625,177.65));

    std::cout << "twobytwo1 = " << std::endl << twobytwo1;
    std::cout << "twobytwo_result = " << std::endl << twobytwo_result;
    matrix<complex> eps_2(2,2);
    for ( int i=0; i<2; i++ ) {
      for ( int j=0; j<2; j++ ) {
        eps_2.set(i,j, epsilson_complex );
      }
    }
    for ( int i=0; i<2; i++ ) {
      for ( int j=0; j<2; j++ ) {
          std::cout << "ij = " << i << j << std::endl;
          std::cout << "ij = " << twobytwo_answer.get(i,j) << std::endl;
          std::cout << "ij = " << twobytwo_result.get(i,j) << std::endl;
          std::cout << "ij = " << twobytwo_answer.get(i,j) - twobytwo_result.get(i,j) << std::endl;
          std::cout << "ij = " << twobytwo_result.get(i,j) - twobytwo_result.get(i,j) << std::endl;
          std::cout << "ij = " << (bool)( twobytwo_answer.get(i,j) - twobytwo_result.get(i,j) <= epsilson_complex ) << std::endl;
          std::cout << "ij = " << (bool)( twobytwo_result.get(i,j) - twobytwo_result.get(i,j) <= epsilson_complex ) << std::endl;
        ASSERT ( twobytwo_answer.get(i,j) - twobytwo_result.get(i,j) <= epsilson_complex );
        ASSERT ( twobytwo_result.get(i,j) - twobytwo_result.get(i,j) <= epsilson_complex );
      }
    }
    ASSERT(twobytwo_result - eps_2 <= twobytwo_answer && twobytwo_result >= twobytwo_answer - eps_2);




    std::cout << "Test multiplication, successful"  << std::endl;

    // check equals, less than and greater than
	std::cout << "---Test operator, equals, less than and greater than ---"  << std::endl;
    ASSERT(Z == C);
    std::cout << "A = " << std::endl << A;
    std::cout << "B = " << std::endl << B;
    C = matrix<complex>::ones(3,3);
    C.scale(100);
    std::cout << "C = " << std::endl << C;
    ASSERT ( A.equals(B) );
    ASSERT ( A == B );
    ASSERT ( A != C );
    ASSERT ( A >= B );
    ASSERT ( C >= B );
    ASSERT ( C > B );
    ASSERT ( A <= B );
    ASSERT ( B <= C );
    ASSERT ( A < C );
    std::cout << "Test operator, successful"  << std::endl;

    std::cout << "All test passed successful"  << std::endl;

    SUCCEED;

}
