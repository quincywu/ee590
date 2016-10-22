#include <iostream>
#include <math.h>
#include "fraction.hh"

fraction fraction::reduce_fraction () const {

	fraction result = *this;
	for (int i = result.num * result.den; i > 1; i--) {
		if( (result.num % i == 0) && (result.den % i == 0) ){
			result.num /= i;
			result.den /= i;
		}
	}

	return result;

}

fraction fraction::add ( const fraction &f ) const{

	fraction result;

	result.num = ( num * f.den ) + ( f.num * den );
	result.den = ( den * f.den );

	return result.reduce_fraction();

}

fraction fraction::mult ( const fraction &f ) const{

	fraction result;

	result.num = ( num * f.num );
	result.den = ( den * f.den );

	return result.reduce_fraction();

}

fraction fraction::divide ( const fraction &f ) const{

	fraction result;

	result.num = ( num * f.den );
	result.den = ( den * f.num );

	return result.reduce_fraction();

}

fraction fraction::power ( int power ){

	fraction result = 1;
	if ( power != 0 ) {
		for ( int i = 0; i < std::abs(power); i ++){
			result = mult( result );
		}
	}
	if ( power < 0 ) {
		int temp = result.num;
		result.num = result.den;
		result.den = temp;
	}

	return result.reduce_fraction();
}
