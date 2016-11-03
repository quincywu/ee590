#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {
    //test string class

  String s("is a string class");
  Array array;

  array.set(0,s);
  s.set("2nd times enter");
  array.set(1,s);
  array.set(3,array);
  std::cout << array.length() << std::endl;

  std::cout << s.stringify() << std::endl;
  std::cout << array.stringify() << std::endl;

  std::cout << array.get(3)->stringify() << std::endl;
  std::cout << array.get(3)->get(0)->stringify() << std::endl;

  return 0;

}
