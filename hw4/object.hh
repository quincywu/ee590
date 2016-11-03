#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <stdexcept>
#include <string>

class object_exception : public std::runtime_error {
public:
  object_exception(const char msg[]) : std::runtime_error(msg) { }
};

class Object {

public:

  Object();
  Object ( const Object &m ) {}
  ~Object() {};

  virtual Object * clone() = 0;
  virtual std::string stringify() = 0;

  virtual Object * get() { throw object_exception ("Undefined getter: get()"); }
  virtual Object * get(std::string s) { throw object_exception ("Undefined getter: get(s)"); }
  virtual Object * get(int i) { throw object_exception ("Undefined getter: get(i)"); }
  //virtual Object * get(bool b) { throw object_exception ("Undefined getter: get(b)"); }

};

#define DEBUG(_msg_) { std::cout << _msg_ << std::endl; }

#endif
