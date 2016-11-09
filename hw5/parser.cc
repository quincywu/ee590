#include "parser.hh"
# include <cmath>

Parser::Parser ( std::string str ) : tok(str) {
}

Object * Parser::array ( void ) {

  Array * a = new Array();

  tok.eat_punctuation('[');
  int i = 0;

  while ( !tok.current().matches(']') ) {
    a->set(i++,object());
    if ( tok.current().matches(',')) {
      tok.eat_punctuation(',');
      if ( tok.current().matches(']') ) {
        throw ParserException("Unexpected end of array");
      }
    }
  }

  tok.eat_punctuation(']');

  return a;

}

Object * Parser::hash ( void ) {

  Hash * h = new Hash();

  tok.eat_punctuation('{');

  while ( !tok.current().matches('}') ) {

    if ( tok.current().is_string() ) {

      std::string key = tok.current().string_val();
      tok.eat();
      tok.eat_punctuation(':');
      h->set(key,object());

      if ( tok.current().matches(',')) {
        tok.eat_punctuation(',');
        if ( tok.current().matches('}') ) {
          throw ParserException("Unexpected end of hash");
        }
      }

    } else {

      throw ParserException("Expected string");

    }

  }

  tok.eat_punctuation('}');

  return h;

}

Number * Parser::expression(void) {
	Number * result = term();

    while (tok.current().matches('+') || tok.current().matches('-') ) {
        if (tok.current().matches('+')){
            tok.eat();
            Number * temp = term();
            *result = (*result + *temp);
        }
		if (tok.current().matches('-')){
            tok.eat();
            Number * temp = term();
            *result = (*result - *temp);

        }
    }

	return result;
}

Number * Parser::term(void) {
    Number * result = factor();

    while (tok.current().matches('*') || tok.current().matches('/') || tok.current().matches('%') ) {
        if (tok.current().matches('*')){
            tok.eat();
            Number * temp = term();
            *result = ((*result) * (*temp) );
        }else if (tok.current().matches('/')){
            tok.eat();
			Number * temp = term();
            *result = ((*result) / (*temp) );
        } else if  (tok.current().matches('%')){
            tok.eat();
			Number * temp = term();
            if( result->is_integer() && temp->is_integer() )
                *result = ((*result) % (*temp) );
            else{
                std::string err("Trying to do modulo with decimal number '");
                err += result->stringify();
                err += "' and '";
                err += temp->stringify();
                err += "' not acceptable in current implementation.";
                throw ParserException(err.c_str());
            }

        }
    }

	return result;
}

Number * Parser::factor(void) {

	Number * result;

    if (tok.current().is_number()) {
        result = new Number ( tok.current().number_val() );
        //std::cout << "this is " << result->get() << " is_integer = "<< result->is_integer() << std::endl;
        tok.eat();
    } else if (tok.current().is_number_int()) {
        result = new Number ( (int)tok.current().number_val_int() );
        //std::cout << "this is " << result->get() << " is_integer = "<< result->is_integer() << std::endl;
        tok.eat();
    } else if (tok.current().matches('(')) {
		tok.eat_punctuation('(');
        result = expression();
        tok.eat_punctuation(')'); // expect(rparen);

    } else if (tok.current().matches('-')) {
		tok.eat_punctuation('-');
        if ( tok.current().is_number() ){
            result = new Number ( -1 * tok.current().number_val() );
            tok.eat();
        } else if ( tok.current().is_number_int() ){
            result = new Number ( -1 * (int)tok.current().number_val_int() );
            tok.eat();
        } else if ( tok.current().matches('(') ) {
            tok.eat_punctuation('(');
            result = expression();
            *result = *result * -1;
            tok.eat_punctuation(')');
        } else {
            std::string err("Factor: syntax error '");
            err += tok.current().to_s();
            err += "' .";
            throw ParserException(err.c_str());

            tok.eat();
        }

    } else {
		throw ParserException("Factor: syntax error");
        tok.eat();
    }

	return result;
}


Object * Parser::number ( void ) {

  return expression();

}

Object * Parser::null ( void ) {
  tok.eat();
  return new Null;
}

Object * Parser::boolean ( void ) {
  Boolean * b = new Boolean(tok.current().bool_val());
  tok.eat();
  return b;
}

Object * Parser::string ( void ) {
  String * s = new String(tok.current().string_val());
  tok.eat();
  return s;
}

Object * Parser::object ( void ) {

  if ( tok.current().matches('{') ) {
    return hash();
  } else if ( tok.current().matches('[') ) {
    return array();
} else if ( tok.current().is_number() || tok.current().is_number_int() || tok.current().matches('(') || tok.current().matches('-') ) {
    return number();
  } else if ( tok.current().is_null() ) {
    return null();
  } else if ( tok.current().is_bool() ) {
    return boolean();
  } else if ( tok.current().is_string() ) {
    return string();
  } else {
    std::string s("Unexpected token ");
    s += tok.current().to_s();
    throw ParserException(s.c_str());
  }

}
