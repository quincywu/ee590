#include <iostream>
#include "fraction.hh"


fraction::fraction (int top, int bottom){
	if ( bottom == 0 ){
		throw fraction_exception("Attempted to initialize a fraction with 0 in the denominator");
	}
	num = top;
	den = bottom;
}

fraction::~fraction() {
	//not needed for primitive type
}

//copy constructor
fraction::fraction (const fraction &f) {
	num = f.num;
	den = f.den;
}

fraction &fraction::operator=(int top){
	num = top;
	den = 1;
	return *this;
}

void fraction::set( int top, int bottom) {

	if ( bottom == 0 ){
		throw fraction_exception("Attempted to set a fraction with 0 in the denominator");
	}

	num = top;
	den = bottom;

}

std::ostream& operator<<(std::ostream& os, const fraction &f) {

  os << f.getNum() << "/" << f.getDen();

  return os;

}
