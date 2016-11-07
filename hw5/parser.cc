#include "parser.hh"
#include <math.h>

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

void Parser::expression(void) {
    if (tok.current().matches('+') || tok.current().matches('-') )
        tok.eat();
    term();
    while (tok.current().matches('+') || tok.current().matches('-') ) {
        tok.eat();
        term();
    }
}

void Parser::term(void) {
    factor();
    while (tok.current().matches('*') || tok.current().matches('/') ) {
        tok.eat();
        factor();
    }
}

void Parser::factor(void) {
    if (accept(ident)) {
        ;
    } else if (tok.current().is_number()) {
        ;
    } else if (tok.current().matches('(')) {
        expression();
        expect(rparen);
    } else {
        error("factor: syntax error");
        nextsym();
    }
}


Object * Parser::number ( void ) {

  Number * n;
  int result;




  while ( tok.curent().is_number() ){
      result = tok.current().number_val();
      n = new Number( result );
      tok.eat();
      switch (tok.current()) {
          case '+':
            tok.eat_punctuation('+');
            result += tok.current().number_val();
            break;
          case '-':
            tok.eat_punctuation('-');
            result -= tok.current().number_val();
            break;

      }
      if ( tok.current().matches( '+' ) || tok.current().matches( '-' ) || tok.current().matches( '*' ) || tok.current().matches( '/' ) || tok.current().matches( '%' ) ) {

          char kkk = tok.current().to_s().at(0);
          result = result

      }
  }

  if ( tok.current().matches( '(' ) ) {
    tok.eat_punctuation('(');
    number();
    while ( !tok.current().matches(')') ) {

    }
    tok.eat_punctuation(')');
  }


  return n;
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
  } else if ( tok.current().is_number() || tok.current().matches('(') ) {
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
