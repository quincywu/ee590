#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

    // testing all constructors and method of matrix of type int

    //CONSTRUCTORS TEST
    std::cout << "---constructor test---" << std::endl;
    matrix<int> A(3,3);
    std::cout << "A = " << std::endl << A;
    ASSERT ( A.rows() == 3 && A.columns() == 3 );

    matrix<int> I = matrix<int>::identity(4);
	std::cout << "I(4) = " << std::endl << I;
    for ( int i=0; i<4; i++ ) {
      for ( int j=0; j<4; j++ ) {
        ASSERT ( ( i == j && I.get(i,j) == 1 ) || ( i!=j && I.get(i,j) == 0 ) );
      }
    }

    // Check that a matrix of ones is a matrix of ones.
    matrix<int> O = matrix<int>::ones(5,6);
	std::cout << "Ones(5,6) = " << std::endl << O;
    for ( int i=0; i<5; i++ ) {
      for ( int j=0; j<6; j++ ) {
        ASSERT ( O.get(i,j) == 1 );
      }
    }

	std::cout << "Test constructor, successful"  << std::endl;

    // check the copy constructor
    std::cout << "---copy constructor---"  << std::endl;

    A.set(0, 0, 1); A.set(0, 1, 3); A.set(0, 2, 6);
    A.set(1, 0, 2); A.set(1, 1, -4); A.set(1, 2, 8);
    A.set(2, 0, -10); A.set(2, 1, 12); A.set(2, 2, 1);

    matrix<int> B = A;
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
    matrix<int> C = A * 2;
    std::cout << "A = " << std::endl << A;
    std::cout << "C = " << std::endl << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == 2*(A.get(i,j)) );
      }
    }

    C = A;
    C.scale(-2);
    std::cout << "A = " << std::endl << A;
    std::cout << "C = " << std::endl << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == -2*(A.get(i,j)) );
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
        matrix<int> D(3,4), E(4,5);
		std::cout << "Adding matrix of different size should fail at 1.cc line 11;" << std::endl;
        A = D.add(E);
        FAIL;
    } catch ( matrix_exception &e ) {
        std::cout << "successfully catch error of adding matrix of 2 different size," << std::endl;
    }

	std::cout << "Test addition, successful"  << std::endl;

    //check subtraction
    std::cout << "---subtraction---" << std::endl;
    matrix<int> Z = A - B;
    std::cout << "Z = " << std::endl << Z;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( Z.get(i,j) == 0 );
      }
    }

	std::cout << "Test subtraction, successful"  << std::endl;

    // check multiplication
    std::cout << "---multiplication---" << std::endl;
    C.set(0, 0, -53); C.set(0, 1, 63); C.set(0, 2, 36);
    C.set(1, 0, -86); C.set(1, 1, 118); C.set(1, 2, -12);
    C.set(2, 0, 4); C.set(2, 1, -66); C.set(2, 2, 37);

    Z = A * B;
    std::cout << "C = " << std::endl << C;
    std::cout << "Z = " << std::endl << Z;

    ASSERT ( Z == C	);

	std::cout << "Test multiplication, successful"  << std::endl;

    // check equals, less than and greater than
	std::cout << "---Test operator, equals, less than and greater than ---"  << std::endl;
    std::cout << "A = " << std::endl << A;
    std::cout << "B = " << std::endl << B;
    C = matrix<int>::ones(3,3);
    C.scale(13);
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

    // check minor
	std::cout << "---Minor test---"  << std::endl;
    matrix<int> Y = A.m_minor(0,0);
    ASSERT ( Y.get(0,0) == -4 && Y.get(0,1) == 8 && Y.get(1,0) == 12 && Y.get(1,1) == 1 );
    std::cout << "Test minor, successful"  << std::endl;


    // check inverse
	std::cout << "---test inverse ---"  << std::endl;
    A.set(0, 0, 1); A.set(0, 1, 2); A.set(0, 2, 3);
    A.set(1, 0, 0); A.set(1, 1, 1); A.set(1, 2, 4);
    A.set(2, 0, 5); A.set(2, 1, 6); A.set(2, 2, 0);

    B = A * (A.inverse()); // B = A * A^-1 = I
    std::cout << "A = " << std::endl << A;
    std::cout << "A^-1 = " << std::endl << A.inverse();
    matrix<int> K = matrix<int>::identity(3);
    std::cout << "B = " << std::endl << B;
    std::cout << "K = " << std::endl << K;
    ASSERT ( K == B );

    std::cout << "Test inverse, successful"  << std::endl;

    // check determinant
	std::cout << "---test determinant ---"  << std::endl;
    std::cout << "A = " << std::endl << A;
    std::cout << "det(A) = " << A.det() << std::endl;
    ASSERT ( A.det() == 1 );
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
