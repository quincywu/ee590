#ifndef _STRING_H_
#define _STRING_H_

#include "object.hh"

class String : public Object {

public:

  String(std::string s);
  String ( const String &s );
  ~String() {};

  String * clone() { return new String(*this); }
  void set(std::string s);
  std::string print () { return str; };
  std::string stringify();

private:

  std::string str;

};

#endif
