#include "test.hh"
#include "complex.hh"
#include <math.h>

#define EPSILSON 0.0001

int main ( int argc, char * argv[] ) {

  // OPERATION TEST, ADD, SUBTRACT, MULT, DIVIDE, POWER
  // This test check the mathamatica operations include add, subtract, multiplication,
  // division, and power of complex.
  // This test check on all operator overloaded, +, -, *, /,
  // and '-' will negate a complex number.

  complex A(2.25, 56),
          B(1.25, -10),
          C;

  std::cout << "-----" << std::endl;

  //addition A = 2.25 + 56 i, B = 1.25 - 10 i, A+B = 3.5 + 46 i
  std::cout << "A = " << A ;
  std::cout << "B = " << B ;
  C = A + B;
  std::cout << "A + B = " << C << std::endl;
  ASSERT ( C.getReal() == 3.5 && C.getImg() == 46 && A.getReal() == 2.25 && A.getImg() == 56 && B.getReal() == 1.25 && B.getImg() == -10  );


  std::cout << std::endl;
  std::cout << "-----" << std::endl;

  //subtraction A - B = 1 + 66 i
  C = A - B;
  std::cout << "A - B = " << C << std::endl;
  ASSERT ( C.getReal() == 1 && C.getImg() == 66 );


  std::cout << std::endl;
  std::cout << "-----" << std::endl;

  //multiplication A =  multiply B = (3.2 + 2.2i) * (4.1 + 3.3i) = (5.86 + 19.58i)
  A.set(3.2, 2.2);
  B.set(4.1, 3.3);
  C = A * B;
  std::cout << "multiplication C = " << C ;
  ASSERT ( fabs( C.getReal() - 5.86 ) < EPSILSON && fabs( C.getImg() - 19.58 ) < EPSILSON );

  C = A * 6.6;
  std::cout << "6.6 * A = " << C ;
  ASSERT ( fabs( C.getReal() - 21.12 ) < EPSILSON && fabs( C.getImg() - 14.52 ) < EPSILSON );


  std::cout << std::endl;
  std::cout << "-----" << std::endl;

  //division A / B = 0.73574... - 0.055595...i
  C = A / B;
  std::cout << "division C = " << C ;
  ASSERT ( fabs( C.getReal() - 0.73574 ) < EPSILSON && fabs( C.getImg() - (-0.05559) ) < EPSILSON );


  std::cout << std::endl;
  std::cout << "-----" << std::endl;


  //power
  A.set(3, 4);
  B = A.power(0);
  std::cout << "B = " << B ;
  ASSERT ( B.getReal() == 1 && B.getImg() == 0 );

  B = A.power(1);
  std::cout << "B = " << B ;
  ASSERT ( B.getReal() == 3 && B.getImg() == 4 );

  B = A.power(-1);
  std::cout << "B = " << B ;
  ASSERT ( fabs( B.getReal() - 0.12 ) < EPSILSON && fabs( B.getImg() - (-0.16) ) < EPSILSON );

  A.set(0, 1);
  B = A.power(2);
  std::cout << "B = " << B ;
  ASSERT ( B.getReal() == -1 && B.getImg() == 0 );

  A.set(4.5, 5);
  B = A.power(-2);
  std::cout << "B = " << B ;
  ASSERT ( fabs( B.getReal() - (-0.00231) ) < EPSILSON && fabs( B.getImg() - (-0.02197) ) < EPSILSON );
  std::cout << std::endl;
  std::cout << "-----" << std::endl;

  A.set(0, M_PI);
  A.e_power(A);

  std::cout << "A = " << A ;
  ASSERT ( fabs( A.getReal() - (-1) ) < EPSILSON && fabs( A.getImg() - (0) ) < EPSILSON );
  std::cout << std::endl;
  std::cout << "-----" << std::endl;

  //negate a complex
  A.set(1.1,-2.2);
  A = -A;
  std::cout << "A = " << A ;
  ASSERT ( fabs( A.getReal() - (-1.1) ) < EPSILSON && fabs( A.getImg() - 2.2 ) < EPSILSON );


  SUCCEED;
}
