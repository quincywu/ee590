#include <iostream>
#include "complex.hh"
#include <math.h>

complex::~complex() {
	//not needed for primitive type
}

//copy constructor
complex::complex (const complex &c) {
	real = c.real;
	img = c.img;
}

complex &complex::operator=(double left){
	real = left;
	img = 0;
	return *this;
}

void complex::set( double left, double right) {

	real = left;
	img = right;

}

double complex::magnitude () const{

	return (double) sqrt( pow(real, 2) + pow(img, 2) );

}

double complex::angle () const{

	double angle = 0;
	if ( real != 0 ) {
		angle = atan( img / real );
	}

	if ( real < 0 ){
		if ( img >= 0 )
			angle += M_PI;
		else
			angle -= M_PI;
	}

	if ( real == 0 && img > 0 ){
		angle = M_PI / 2;
	}

	if ( real == 0 && img < 0 ){
		angle = - M_PI / 2;
	}

	return angle;

}

std::ostream& operator<<(std::ostream& os, const complex &c) {

  if ( c.getImg() >= 0 )
  	os << c.getReal() << "+" << fabs(c.getImg()) << "i";
  else
    os << c.getReal() << "" << c.getImg() << "i";

  return os;

}
