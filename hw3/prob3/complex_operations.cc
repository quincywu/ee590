#include <iostream>
#include <math.h>
#include "complex.hh"

complex complex::add ( const complex &c ) const{

	complex result;

	result.real = real  + c.real;
	result.img = img + c.img;

	return result;

}

complex complex::mult ( const complex &c ) const{

	complex result;

	result.real = ( real * c.real ) - ( img  * c.img);
	result.img = ( img * c.real ) + ( real * c.img );

	return result;

}

complex complex::divide ( const complex &c ) const{

	complex result;

	result.real = ( (real * c.real) + (img * c.img) ) / ( pow(c.real, 2)  + pow(c.img, 2) );
	result.img = ( (img * c.real) - (real * c.img) ) / ( pow(c.real, 2)  + pow(c.img, 2) );

	return result;

}

complex complex::power ( int power ){

	complex result = *this;
	if ( power != 0 ) {
		for ( int i = 1; i < abs(power); i ++){
			result = mult( result );
		}
	}

	if ( power < 0 ) {
		double temp_real =  result.real / ( pow(result.real, 2) + pow(result.img, 2) );
		result.img = - result.img / ( pow(result.real, 2) + pow(result.img, 2) );
		result.real = temp_real;
	}

	if ( power == 0 ) {
		result.real = 1;
		result.img = 0;
	}



	return result;
}

complex complex::e_power (){

	complex result;
	result.real = exp(real) * cos ( img );
	result.img = sin (img);

	return result;
}
