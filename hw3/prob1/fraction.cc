#include <iostream>
#include "fraction.hh"

/*fraction::fraction ( int top, int bottom = 1 ) : num(top), den(bottom) {
	if ( bottom == 0 ){
			throw fraction_exception("Attempted to initialize a fraction with 0 in the denominator");
		}
}*/

fraction::~fraction() {
	//not needed for primitive type
}

//copy constructor
fraction::fraction (const fraction &f) {
	num = f.num;
	den = d.den;
}

fraction fraction::operator=(int top){
	num = top;
	den = 1;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const fraction &f) {

  os << f.num << "/" << f.den << std::endl;

  return os;

}