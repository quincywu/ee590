#include "number.hh"

Number Number::divide ( const Number &n ) const {
    if ( is_int and n.is_int ){
        if( !(int)n.value )
            throw NumberException ("Invalid number: division by 0.");
        return Number((int)value / (int)n.value);
    }else {
        return Number(value / n.value);
    }

}

Number Number::mod ( const Number &n ) const {
    if ( is_int and n.is_int )
        return Number( (int)value % (int)n.value);
    else
        return fmod(value, n.value);
}

std::string Number::stringify() {
  if ( value - (int) value == 0 ) {
    return std::to_string((int)value);
  } else {
    return std::to_string(value);
  }
}
