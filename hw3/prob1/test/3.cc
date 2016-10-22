#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // OPERATION TEST
  // This test check for the comparision relations. ==, !=, <, >, <=, >=

  fraction A ( 4, 5 ),
           B ( 4, 5 ),
           C ( 3, 4 );

  ASSERT ( A == B );


  A.set( 3, 4 );
  B.set( 4, 5 );
  ASSERT ( A != B );


  ASSERT ( A < B );
  ASSERT ( B > A );
  ASSERT ( A >= C && B >= C );
  ASSERT ( A <= C && C <= B );


}
