#include <iostream>
#include <math.h>
#include "fraction.hh"

fraction private_reduce_fraction () {
	
	for (int i = num * den; i > 1; i--) {
		if( (num % i == 0) && (den % i == 0) ){
			num /= i;
			den /= i;
		}
	}
	
	return *this;
	
}

fraction reduce_fraction ( const fraction &f ) const {
	
	fraction result = f;
	
	return result.private_reduce_fraction();
	
}

fraction add ( const fraction &f ) const{

	fraction result;
	
	result.num = ( num * f.den ) + ( f.num * den );
	result.den = ( den * f.den );
	
	return result.private_reduce_fraction();
	
}

fraction subtract ( const fraction &f ) const{

	fraction result;
	
	result.num = ( num * f.den ) - ( f.num * den );
	result.den = ( den * f.den );
	
	return result.private_reduce_fraction();
	
}

fraction mult ( const fraction &f ) const{

	fraction result;
	
	result.num = ( num * f.num );
	result.den = ( den * f.den );
	
	return result.private_reduce_fraction();
	
}

fraction divide ( const fraction &f ) const{

	fraction result;
	
	result.num = ( num * f.den );
	result.den = ( den * f.num );
	
	return result.private_reduce_fraction();
	
}

