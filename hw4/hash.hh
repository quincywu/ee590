#ifndef _HASH_H_
#define _HASH_H_

#include "object.hh"
#include "array.hh"
#include "string.hh"


typedef struct _Bucket {
  std::string key;
  Object * value;
  _Bucket * next;
} Bucket;

class Hash : public Object {

public:

  Hash();
  Hash ( const Hash &hash );
  ~Hash();

  Hash * clone() { return new Hash(*this); }
  void set ( std::string key, Object &value);
  Object * get ( std::string key ) const;
  Object * get ( std::string key );
  std::string stringify();

  Array getkeys() const;

private:

  int hash ( std::string s ) const;
  static const int num_shelves = 256;
  Bucket * shelves[num_shelves];

};

#endif
