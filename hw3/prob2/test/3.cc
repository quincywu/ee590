#include "test.hh"
#include "complex.hh"
#include <math.h>

#define EPSILSON 0.0001

int main ( int argc, char * argv[] ) {

  // CONJUGATE TEST, MAGNITUDE TEST, ANGLE TEST

  // CONJUGATE TEST
  complex A(3.5, 4.5),
          B;
  B = A.conjugate();
  std::cout << "A = " << A;
  std::cout << "B = " << B;
  ASSERT ( B.getReal() == B.getReal() && A.getImg() == - B.getImg() );

  // MAGNITUDE TEST
  std::cout << "A.magnitude = " << A.magnitude() << std::endl;
  std::cout << "B.magnitude = " << B.magnitude() << std::endl;
  ASSERT ( A.magnitude() == B.magnitude() && fabs(A.magnitude() - 5.70088) < EPSILSON);

  // ANGLE TEST
  std::cout << "A.angle = " << A.angle() << std::endl;
  std::cout << "B.angle = " << B.angle() << std::endl;
  ASSERT ( fabs( A.angle() - (52.125 * M_PI/180) ) < EPSILSON );
  ASSERT ( fabs( B.angle() - (-52.125 * M_PI/180) ) < EPSILSON );

  SUCCEED;

}
