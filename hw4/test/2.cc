#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Hash h;
  Number n(1);
  Number k(2);

  h.set("first", n);
  h.set("second", h);

  std::cout << h.stringify() << std::endl;
  std::cout << h.get("first")->stringify() << std::endl;
  std::cout << h.get("second")->stringify() << std::endl;

  //testing on the same shelves
  h.set("firru", k);
  std::cout << h.stringify() << std::endl;

  h.set("first", k);
  std::cout << h.get("first")->stringify() << std::endl;
  std::cout << h.stringify() << std::endl;

  std::cout << "this is a extended test for hash within hash" << std::endl;
  h.set("third", h);
  std::cout << h.stringify() << std::endl;

  // next line will fail until the copy constructor for Hash is implemented
  std::cout << h.get("second")->get("first")->stringify() << std::endl;
  std::cout << h.get("third")->get("second")->get("first")->stringify() << std::endl;

  return 0;

}
