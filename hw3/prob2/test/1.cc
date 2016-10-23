#include "test.hh"
#include "complex.hh"

int main ( int argc, char * argv[] ) {

  // CONSTRUCTOR TESTS, SETTERS AND GETTERS CHECK, COPY CONSTRUCTOR TEST
  // This file tests all constructors by building a complex number with each and then
  // testing that values in the complex number,
  // using get, are what they should be.

  // TEST 1: check that a default constructor is made with 0/0
  complex A;
  std::cout << "A = " << A;
  ASSERT ( A.getReal() == 0 && A.getImg() == 0 );

  // TEST 2: check a complex has real and imaginary part
  complex B(4.2),
           C(-2,-5.3);
  std::cout << "B = " << B;
  std::cout << "C = " << C;
  ASSERT ( B.getReal() == 4.2 && B.getImg() == 0 );
  ASSERT ( C.getReal() == -2 && C.getImg() == -5.3 );

  A.set(2.9,3.44);
  std::cout << "A = " << A;
  ASSERT ( A.getReal() == 2.9 && A.getImg() == 3.44 );

  // check the copy constructor
  complex D = A;
  std::cout << "D = " << D;
  ASSERT ( D.getReal() == 2.9 && D.getImg() == 3.44 );

  // check the overloaded operator = 
  D = 6.314;
  std::cout << "D = " << D;
  ASSERT ( D.getReal() == 6.314 && D.getImg() == 0 );

  SUCCEED;

}
