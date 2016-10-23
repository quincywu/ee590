#include "test.hh"
#include "complex.hh"

int main ( int argc, char * argv[] ) {

  // OPERATION TEST
  // This test check for the comparision relations. ==, !=, <, >, <=, >=

  complex A ( 4.4321, 5.5321 ),
           B ( 4.4321, 5.5321 ),
           C ( 3, 4 );

  ASSERT ( A == B );
  ASSERT ( A <= B );
  ASSERT ( A >= B );
  ASSERT ( A > C && B > C);

  A.set( 3.2, 4.2 );
  B.set( 4.6, 5.8 );
  ASSERT ( A != B );


  ASSERT ( A < B );
  ASSERT ( B >= A );
  ASSERT ( A <= B );


}
