#include "test.hh"
#include "fraction.hh"

#define MAXNUM 10000

int main ( int argc, char * argv[] ) {

  // OPERATION TEST, ADD, SUBTRACT, MULT, DIVIDE, POWER
  // This test check the mathamatica operations include add, subtract, multiplication,
  // division, and power of fraction. All operations return in lowest term.
  // This test check on all operator overloaded, +, -, *, /,
  // and '-' will negate a fraction.

  fraction A(2, 5),
           B(1, 10);

  int counter = 0;
  std::cout << "-----" << std::endl;

  //addition A = 4/10 takes 6 addition of B to make it 10/10 = 1/1
  std::cout << "A = " << A ;
  std::cout << "B = " << B ;
  while ( (A.getNum() != 1 || A.getDen() != 1) && counter < MAXNUM) {
      A = A + B;
      counter ++;
      std::cout << "A = " << A ;
  }

  ASSERT ( counter == 6 && A.getNum() == 1 && A.getDen() == 1 );
  std::cout << std::endl;
  std::cout << "-----" << std::endl;


  //subtraction A = 16/10 takes 6 subtraction of B to make it 10/10 = 1/1
  A.set(8, 5);
  counter = 0;
  std::cout << "A = " << A ;

  while ( (A.getNum() != 1 || A.getDen() != 1) && counter < MAXNUM) {
      A = A - B;
      counter ++;
      std::cout << "A = " << A ;
  }
  ASSERT ( counter == 6 && A.getNum() == 1 && A.getDen() == 1 );
  std::cout << std::endl;
  std::cout << "-----" << std::endl;


  //multiplication A = 2/3 multiply B = 6/2 to make it 2/1
  A.set(2, 3);
  B.set(6, 2);
  counter = 0;
  A = A * B;
  std::cout << "multiplication A = " << A ;
  ASSERT ( A.getNum() == 2 && A.getDen() == 1 );
  std::cout << std::endl;
  std::cout << "-----" << std::endl;


  //division A = 2/3 divide B = 2/6 to make it 2
  A.set(2, 3);
  B.set(2, 6);
  A = A / B;
  std::cout << "division A = " << A ;
  ASSERT ( A.getNum() == 2 && A.getDen() == 1 );
  std::cout << std::endl;
  std::cout << "-----" << std::endl;


  //power
  A.set(1, 2);
  B = A.power(0);
  std::cout << "B = " << B ;
  ASSERT ( B.getNum() == 1 && B.getDen() == 1 );

  B = A.power(1);
  std::cout << "B = " << B ;
  ASSERT ( B.getNum() == A.getNum() && B.getDen() == A.getDen() );

  B = A.power(-1);
  std::cout << "B = " << B ;
  ASSERT ( B.getNum() == A.getDen() && B.getDen() == A.getNum() );

  B = A.power(2);
  std::cout << "B = " << B ;
  ASSERT ( B.getNum() == 1 && B.getDen() == 4 );

  B = A.power(-2);
  std::cout << "B = " << B ;
  ASSERT ( B.getNum() == 4 && B.getDen() == 1 );
  std::cout << std::endl;
  std::cout << "-----" << std::endl;

  //negate a fraction
  A.set(1,2);
  A = -A;
  std::cout << "A = " << A ;
  ASSERT ( A.getNum() == -1 && A.getDen() == 2 );


  SUCCEED;
}
