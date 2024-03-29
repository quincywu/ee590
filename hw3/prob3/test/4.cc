#include "test.hh"
#include "matrix.hh"
#include "fraction.hh"

#define EPSILSON fraction(1,10000)
#define EPSILSON_DECIMAL 0.0001

int main ( int argc, char * argv[] ) {

    // testing all constructors and method of matrix of type fraction

    //CONSTRUCTORS TEST
    std::cout << "---constructor test---" << std::endl;
    matrix<fraction> A(3,3);
    std::cout << "A = " << std::endl << A;
    ASSERT ( A.rows() == 3 && A.columns() == 3 );

    matrix<fraction> I = matrix<fraction>::identity(4);
    for ( int i=0; i<4; i++ ) {
      for ( int j=0; j<4; j++ ) {
        ASSERT ( ( i == j && I.get(i,j) == fraction(1) ) || ( i!=j && I.get(i,j) == fraction(0) ) );
      }
    }
    std::cout << "I(4) = " << std::endl << I;

    // Check that a matrix of ones is a matrix of ones.
    matrix<fraction> O = matrix<fraction>::ones(5,6);
    for ( int i=0; i<5; i++ ) {
      for ( int j=0; j<6; j++ ) {
        ASSERT ( O.get(i,j) == 1 );
      }
    }
    std::cout << "Ones(5,6) = " << std::endl << O;

    std::cout << "Test constructor, successful"  << std::endl;

    // check the copy constructor
    std::cout << "---copy constructor---"  << std::endl;

    A.set(0, 0, fraction(23,10)); A.set(0, 1, fraction(2)); A.set(0, 2, fraction(25,10));
    A.set(1, 0, -fraction(32,10)); A.set(1, 1, fraction(12,10)); A.set(1, 2, fraction(35,10));
    A.set(2, 0, fraction(20,10)); A.set(2, 1, fraction(-1)); A.set(2, 2, fraction(-15,10));

    matrix<fraction> B = A;
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
    matrix<fraction> C = A * 2;
    std::cout << "A = " << std::endl << A;
    std::cout << "C = " << std::endl << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == (A.get(i,j) * fraction(2) ) );
      }
    }

    C = A;
    C.scale(-2.0);
    std::cout << "A = " << std::endl << A;
    std::cout << "C = " << std::endl << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == (A.get(i,j) * fraction(-2.0)) );
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
        matrix<fraction> D(3,4), E(4,5);
		std::cout << "Adding matrix of different size should fail at 1.cc line 11;" << std::endl;
        A = D.add(E);
        FAIL;
    } catch ( matrix_exception &e ) {
        std::cout << "successfully catch error of adding matrix of 2 different size," << std::endl;
    }


    //check subtraction
    std::cout << "---subtraction---" << std::endl;
    matrix<fraction> Z = A - B;
    std::cout << "Z = " << std::endl << Z;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
          std::cout << "Z.get(i,j) = " << i << j << Z.get(i,j) - EPSILSON << std::endl;
        ASSERT ( Z.get(i,j) == fraction(0) );
      }
    }

    // TODO add more test

    // check multiplication
    std::cout << "---multiplication---" << std::endl;
    C.set(0, 0, fraction(3890,1000)); C.set(0, 1, fraction(45,10)); C.set(0, 2, fraction(9));
    C.set(1, 0, -fraction(420,100)); C.set(1, 1, -fraction(846,100)); C.set(1, 2, -fraction(905,100));
    C.set(2, 0, fraction(480,100)); C.set(2, 1, fraction(43,10)); C.set(2, 2, fraction(375,100));

    Z = A * B;
    std::cout << "A = " << std::endl << A;
    std::cout << "B = " << std::endl << B;
    std::cout << "C = " << std::endl << C;
    std::cout << "Z = " << std::endl << Z;

    matrix<fraction> eps_3(3,3);
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        eps_3.set(i,j, EPSILSON );
      }
    }

    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( Z.get(i,j) == C.get(i,j).reduce_fraction() );
      }
    }


    // check equals, less than and greater than
	std::cout << "---Test operator, equals, less than and greater than ---"  << std::endl;
    std::cout << "A = " << std::endl << A;
    std::cout << "B = " << std::endl << B;
    C = matrix<fraction>::ones(3,3);
    C.scale(5);
    std::cout << "C = " << std::endl << C;
    ASSERT ( A.equals(B) );
    ASSERT ( A == B );
    ASSERT ( A != C );
    ASSERT ( A >= B );

    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
          std::cout << "Bij = " << i << j << " "<< B.get(i,j) << std::endl;
          std::cout << "C = "  << C.get(i,j) << std::endl;
        ASSERT ( C.get(i,j) >= B.get(i,j).reduce_fraction() );
      }
    }

    ASSERT ( C >= B );
    ASSERT ( C > B );
    ASSERT ( A <= B );
    ASSERT ( B <= C );
    ASSERT ( A < C );
    std::cout << "Test operator, successful"  << std::endl;

    // check minor
	std::cout << "---Minor test---"  << std::endl;
    matrix<fraction> Y = A.m_minor(0,0);
    ASSERT ( Y.get(0,0) == fraction(12,10) && Y.get(0,1) == fraction(35,10) && Y.get(1,0) == fraction(-1) && Y.get(1,1) == fraction(-15,10) );

    Y = A.m_minor(0,1);
    ASSERT ( Y.rows() == 2 && Y.columns() == 2 && Y.get(0,0) == fraction(-32,10) && Y.get(0,1) == fraction(35,10) && Y.get(1,0) == fraction(20,10) && Y.get(1,1) == fraction(-15,10) );

    Y = Y.m_minor(0,0); //A.m_minor(0,1).Y.m_minor(0,0)
    ASSERT ( Y.rows() == 1 && Y.columns() == 1 && Y.get(0,0) == fraction(-15,10) );
    std::cout << "Test minor, successful"  << std::endl;


    // check inverse
	std::cout << "---test inverse ---"  << std::endl;
    B = A * (A.inverse()); // B = A * A^-1 = I
    matrix<fraction> K = A.identity(3);

    ASSERT ( K == B && B == K);

    std::cout << "Test inverse, successful"  << std::endl;

    // check determinant
	std::cout << "---test determinant ---"  << std::endl;
    std::cout << "A = " << std::endl << A;
    std::cout << "det(A) = " << A.det() << std::endl;
    ASSERT ( A.det() - EPSILSON <= fraction(1031,100) && A.det() + EPSILSON >= fraction(1031,100) );
	ASSERT ( I.det() == 1 && K.det() == 1 );

	// A.det() == 0
	B.set(0, 0, 1); B.set(0, 1, 2); B.set(0, 2, 3);
    B.set(1, 0, 4); B.set(1, 1, 5); B.set(1, 2, 6);
    B.set(2, 0, 7); B.set(2, 1, 8); B.set(2, 2, 9);
	ASSERT( B.det() == 0 );

	try {
        std::cout << "Adding matrix of different size should fail at 1.cc line 11;" << std::endl;
		B.inverse();
        FAIL;
    } catch ( matrix_exception &e ) {
        std::cout << "successfully catch error of getting inverse of det(0), singlular matrix" << std::endl;
    }
    std::cout << "Test determinant, successful"  << std::endl;

    std::cout << "All test passed successful"  << std::endl;

    SUCCEED;

}
