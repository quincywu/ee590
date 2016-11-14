function Tokenizer(regexps) {

  this.re_string = "";
  this.re;
  this.tokens = [];
  this.tok_index = 0;

  if ( regexps ) {
    for ( var i=0; i<regexps.length; i++ ) {
      this.add(regexps[i]);
    }
  }

}

Tokenizer.prototype.add = function(regexp) {
  if ( this.re_string == "" ) {
    this.re_string = regexp.source;
  } else {
    this.re_string += "|" + regexp.source;
  }
  this.re = RegExp(this.re_string,"g");
  return this;
}

Tokenizer.prototype.tokenize = function(str) {
  this.tokens = str.match(this.re);
  return this;
}

Tokenizer.prototype.current = function() {
  // TODO: Return current token

  if ( !this.tok_index ){
      this.whitespace();

      if ( this.eof() ){
          throw new Error("Tokenizer current: end of tokens");
      }
  }

  return this.tokens[this.tok_index];
}

Tokenizer.prototype.float_val = function() {
  // Possibly useful to return the current value as a float
  // or return NaN if it doesn't evaluate (using the built in
  // method parseFloat)
  return parseFloat(this.current());
}

Tokenizer.prototype.int_val = function() {
  return parseInt(this.current());
}

Tokenizer.prototype.next = function() {

    var ate = this.current();
    this.tok_index ++;

    this.whitespace();

/*    if ( this.eof() ){
        throw new Error("Tokenizer next: end of tokens");
    }
*/
    return ate;

}

Tokenizer.prototype.eat = function() {

  if ( !this.eof() ){
      return this.next();
  }
  return this.current();

}

Tokenizer.prototype.eat_punctuation = function(c) {

  if ( this.current() == c ){
      return this.eat();
  }else{
      throw new Error("Expect token " + c + " but encountered " + this.current() );
  }

}

Tokenizer.prototype.whitespace = function() {

    while ( this.tok_index < this.tokens.length && this.tok_index >= 0 && this.tokens[this.tok_index].match(/\s/) ){
        this.tok_index ++;
    }

}

Tokenizer.prototype.eof = function() {

    this.whitespace();
    return this.tok_index >= this.tokens.length;

}

module.exports = Tokenizer;
