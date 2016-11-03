#include "object.hh"

class Boolean : public Object {

public:

  Boolean(bool b);
  Boolean ( const Boolean &b );
  ~Boolean() {};

  Boolean * clone() { return new Boolean(*this); }
  void set(bool b);
  std::string stringify();

private:

  bool boo;

};
