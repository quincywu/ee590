#include <iostream>
#include <math.h>
#include "fraction.hh"

bool fraction::equals ( const fraction &f ) const {

	fraction result = reduce_fraction();
	fraction result2 = f.reduce_fraction();
	return result.getNum() == result2.getNum() && result.getDen() == result2.getDen();

}
bool fraction::less_than ( const fraction &f ) const {

	fraction result = reduce_fraction();
	fraction result2 = f.reduce_fraction();

	return (result.getNum() * result2.getDen()) < (result2.getNum() * result.getDen());

}

fraction fraction::reduce_fraction (void) const {
	int gcd, re = 0;
	int temp_top = num, temp_bot = den;

	while( temp_top != 0 ){
		re = temp_bot % temp_top;
		temp_bot = temp_top;
		temp_top = re;
	}

	gcd = temp_bot;
	if( (den / gcd) < 0){
		return fraction( - (num / gcd), - (den / gcd) );
	}else
		return fraction( num / gcd, den / gcd );

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
