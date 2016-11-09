#include <iostream>
#include <stdexcept>
#include "object.hh"
#include "math.h"

class NumberException : public std::runtime_error {
public:
  NumberException(const char msg[]) : std::runtime_error(msg) {}
};

class Number : public Object {

public:

  Number(double d) : value(d), is_int(false) {};
  Number(int i) : value((double)i), is_int(true) {};
  Number ( const Number &number ) { value = number.value; is_int = number.is_int; }

  Number * clone() { return new Number(*this); }
  inline void set(double d) { value = d; }
  inline double get(void) { return value; }
  std::string stringify();

  inline bool is_integer () { return ( is_int && !(value - (int) value) ); }

  inline Number add ( const Number &n ) const { return (is_int && n.is_int)?Number((int)value + (int)n.value):Number(value + n.value); }
  inline Number mult ( const Number &n ) const { return (is_int && n.is_int)?Number((int)value * (int)n.value):Number(value * n.value); }
  Number divide ( const Number &n ) const;
  Number mod ( const Number &n ) const;

  inline Number operator+(const Number &n) { return add(n); }
  inline Number operator-(const Number &n) { Number result = n; result.value *= -1; return add(result); }
  inline Number operator*(const Number &n) { return mult(n); }
  inline Number operator/(const Number &n) { return divide(n); }
  inline Number operator%(const Number &n) { return mod(n); }

private:

  bool is_int;
  double value;

};
