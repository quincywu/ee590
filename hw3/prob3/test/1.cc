#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

    // testing all constructors and method of matrix of type double

    //CONSTRUCTORS TEST
    std::cout << "---constructor test---" << std::endl;
    matrix<double> A(3,3);
    std::cout << "A = " << A;
    ASSERT ( A.rows() == 3 && A.columns() == 3 );

    matrix<double> I = matrix<double>::identity(4);
    for ( int i=0; i<4; i++ ) {
      for ( int j=0; j<4; j++ ) {
        ASSERT ( ( i == j && I.get(i,j) == 1 ) || ( i!=j && I.get(i,j) == 0 ) );
      }
    }
    std::cout << "I(4) = " << I;

    // Check that a matrix of ones is a matrix of ones.
    matrix<double> O = matrix<double>::ones(5,6);
    for ( int i=0; i<5; i++ ) {
      for ( int j=0; j<6; j++ ) {
        ASSERT ( O.get(i,j) == 1 );
      }
    }
    std::cout << "Ones(5,6) = " << O;

    // check the copy constructor
    std::cout << "---copy constructor---"  << std::endl;
    matrix<double> B(3,3);
    A.set(0, 0, 2.3); A.set(0, 1, 2); A.set(0, 2, 2.5);
    A.set(1, 0, -3.2); A.set(1, 1, 1.2); A.set(1, 2, 3.5);
    A.set(2, 0, 2); A.set(2, 1, -1); A.set(2, 2, -1.5);

    B = A;
    std::cout << "A = " << A;
    std::cout << "B = " << B;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( B.get(i,j) == A.get(i,j) );
      }
    }



    matrix<double> C(3,3);
    C.matrix(A);
    std::cout << "A = " << A;
    std::cout << "C = " << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == A.get(i,j) );
      }
    }

    //check scaling
    std::cout << "---scaling---" << std::endl;
    C = 2 * A * 2;
    std::cout << "A = " << A;
    std::cout << "C = " << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == 4*(A.get(i,j)) );
      }
    }

    C = A.scale(-2);
    std::cout << "A = " << A;
    std::cout << "C = " << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == -2*(A.get(i,j)) );
      }
    }


    //check addition
    std::cout << "---addition---" << std::endl;
    C = A.add(B);
    std::cout << "C = " << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == A.get(i,j) + B.get(i,j) );
      }
    }

    C = A + B;
    std::cout << "C = " << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( C.get(i,j) == A.get(i,j) + B.get(i,j) );
      }
    }
    std::cout << "C = " << C;

    try {
        matrix<double> D(3,4), E(4,5);
        A = D.add(E);
        std::cout << "Adding matrix of different size fail at 1.cc line 11;" << std::endl;
        FAIL;
    } catch ( matrix_exception &e ) {
        std::cout << "successfully catch erro of adding matrix of 2 different size,"
        ASSERT ( e );
    }


    //check subtraction
    std::cout << "---subtraction---" << std::endl;
    matrix<double> Z(3,3);
    Z = A - B;
    std::cout << "C = " << C;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( Z.get(i,j) == 0 );
      }
    }

    // check multiplication
    std::cout << "---multiplication---" << std::endl;
    C.set(0, 0, 3.89); C.set(0, 1, 4.5); C.set(0, 2, 9);
    C.set(1, 0, -4.2); C.set(1, 1, -8.46); C.set(1, 2, -9.05);
    C.set(2, 0, 4.8); C.set(2, 1, 4.3); C.set(2, 2, 3.75.5);
    Z = A * B;
    for ( int i=0; i<3; i++ ) {
      for ( int j=0; j<3; j++ ) {
        ASSERT ( Z.get(i,j) == C.get(i,j) );
      }
    }

    // check equals, less than and greater than
    ASSERT ( A.equals(B) );
    ASSERT ( A == B );
    ASSERT ( A != C );
    ASSERT ( A >= B );
    ASSERT ( C >= B );
    ASSERT ( A <= B );
    ASSERT ( B <= C );

    // check minor
    matrix<double> Y = A.m_minor(0,0);
    ASSERT ( Y.get(0,0) == 1.2 && Y.get(0,1) == 3.5 && Y.get(1,0) == -1 && Y.get(1,1) == -1.5 );

    // check inverse
    B = A * (A.inverse()); // B = A * A^-1 = I
    matrix<double> K = A.identity(3),
                   eps = matrix::ones(4,4);

    eps.scale (0.0001); //accepted error margin

    ASSERT ( I - eps <= B && M <= I + eps );

    // check determinant
    




    SUCCEED;

}
