#include "test.hh"
#include "fraction.hh"

int main ( int argc, char * argv[] ) {

  // OPERATION TEST
  // This test check for the comparision relations. ==, !=, <, >, <=, >=

  fraction A ( 4, 5 ),
           B ( 40, 50 ),
           C ( 3, 4 ),
           D ( -32, 10 ),
           E (5 , 1),
           F (0 , 10),
           G (0 , -10),
           H (5 , -1);

  ASSERT ( A == B );


  A.set( 3, 4 );
  B.set( 4, 5 );
  ASSERT ( A != B );


  ASSERT ( A < B );
  ASSERT ( B > A );
  ASSERT ( A >= C && B >= C );
  ASSERT ( A <= C && C <= B );
  ASSERT ( D < E );
  ASSERT ( D <= E  );
  ASSERT ( F <= G  );
  ASSERT ( G <= E  );
  ASSERT ( G >= H  );
  ASSERT ( E >= H  );

  std::cout << "Passed all test" << std::endl;






}
