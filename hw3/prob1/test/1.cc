#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // CONSTRUCTOR TESTS, SETTERS AND GETTERS cHECK, COPY CONSTRUCTOR TEST
  // This file tests all constructors by building a fraction with each and then
  // testing that the fraction is the right size and/or that values in the fraction,
  // using get, are what they should be.
  // also check for the reduce fraction to reduce to lowest term

  // TEST 1: check that a default constructor is made with 0/1
  fraction A;
  std::cout << "A = " << A;
  ASSERT ( A.getNum() == 0 && A.getDen() == 1 );

  // TEST 2: check a fraction has numerator and denominator
  fraction B(4),
           C(-2,5);
  std::cout << "B = " << B;
  std::cout << "C = " << C;
  ASSERT ( B.getNum() == 4 && B.getDen() == 1 );
  ASSERT ( C.getNum() == -2 && C.getDen() == 5 );

  A.set(2,3);
  std::cout << "A = " << A;
  ASSERT ( A.getNum() == 2 && A.getDen() == 3 );

  // test for the copy constructor
  fraction D = A;
  std::cout << "D = " << D;
  ASSERT ( D.getNum() == 2 && D.getDen() == 3 );

  // test for the overloaded operator =
  D = 6;
  std::cout << "D = " << D;
  ASSERT ( D.getNum() == 6 && D.getDen() == 1 );

  // check the reduce fraction function reduce to the lowest term
  A.set( 4, 6 );
  B = A.reduce_fraction();
  std::cout << "A = " << A ;
  std::cout << "B = " << B ;
  ASSERT ( A.getNum() == 4 && A.getDen() == 6 && B.getNum() == 2 && B.getDen() == 3 );

  SUCCEED;

}
