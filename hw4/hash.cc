#include "hash.hh"
#include "null.hh"

Hash::Hash() {

  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

}

Hash::Hash ( const Hash &hash ) {

  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

  // TODO: method keys() that returns an Array of keys
  //           for ( k in keys() ) {
  //             set(k,hash.get(k))
  //          }

  Array arr = hash.getkeys();

  for ( int i = 0; i < arr.length(); i ++){
      if( arr.get(i) != NULL ){
          std::string k = arr.get(i)->stringify();
          set( k, *(hash.get(k)) );
      }

  }

}

Hash::~Hash() {
    for(int i = 0; i < num_shelves; i++){
        Bucket * ptr = shelves[i];
        while ( ptr ) {
            shelves[i] = shelves[i]->next;

            delete ptr->value;
            delete ptr;

            ptr = shelves[i];
        }

        shelves[i] = NULL;
    }

}

void Hash::set ( std::string key, Object &value ) {

  // TODO: Homework: Use delete if key exists to avoid duplicate keys
  //       or reset the value in place (make sure to delete old value!)

  int i = hash(key);
  Bucket * ptr = shelves[i];
  Bucket * before;

  while ( ptr && ptr->key != key ) {
      before = ptr;
      ptr = ptr->next;
  }

  if ( ptr ){
      Bucket * next = ptr->next;
      delete ptr->value;
      delete ptr;
      if ( before )
        before->next = next;
      else
        shelves[i] = NULL;
  }

  ptr = new Bucket;

  ptr->key = key;
  ptr->value = value.clone();
  ptr->next = shelves[i];
  shelves[i] = ptr;

}

Object * Hash::get ( std::string key ) const{

  int i = hash(key);
  Bucket * ptr = shelves[i];

  while ( ptr && ptr->key != key ) {
    ptr = ptr->next;
  }

  if ( ptr ) {
    return ptr->value;
  } else {
    throw "No value for key";
  }

}

Object * Hash::get ( std::string key ) {

  int i = hash(key);
  Bucket * ptr = shelves[i];

  while ( ptr && ptr->key != key ) {
    ptr = ptr->next;
  }

  if ( ptr ) {
    return ptr->value;
  } else {
    throw "No value for key";
  }

}

int Hash::hash ( std::string s ) const{

  int n = 0;

  for ( int i=0; i<s.length(); i++ ) {
    n += (int) s[i];
  }

  return n % num_shelves;

}

Array Hash::getkeys () const{
    Array arr;

    int k = 0;
    for (int i = 0 ; i<num_shelves; i++ ) {
      Bucket * ptr = shelves[i];
      while( ptr != NULL ){
          String ss((ptr->key)) ;
          arr.set( k++ , ss );
          ptr = ptr->next;
      }
    }

    return arr;

}

std::string Hash::stringify() {

  std::string s = "{";

  for ( int i=0; i<num_shelves; i++ ) {
    Bucket * ptr = shelves[i];
    while ( ptr != NULL ) {
      s += ptr->key + ":" + ptr->value->stringify() + ",";
      ptr = ptr->next;
    }
  }

  if ( s[s.length()-1] == ',' ) {
    s[s.length()-1] = '}';
  } else {
    s += "}";
  }

  return s;

}
