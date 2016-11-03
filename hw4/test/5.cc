#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {
    //test boolean class

  Boolean b(true);
  Array array;

  array.set(0,b);
  b.set(false);
  array.set(1,b);
  array.set(3,array);
  std::cout << array.length() << std::endl;

  std::cout << b.stringify() << std::endl;
  std::cout << array.stringify() << std::endl;

  std::cout << array.get(3)->stringify() << std::endl;

  return 0;

}
