Tokenizer = require('./tokenizer.js')

function Parser(str) {

  this.str = str; // the string to be parsed

  this.tokenizer = new Tokenizer();

  this.tokenizer
      .add(/\+/)
      .add(/\-/)
      .add(/\*/)
      .add(/\//)
      .add(/\(/)
      .add(/\)/)
      .add(/%/)
      .add(/(\d)?(\.\d)?/)
      .add(/\s/); // Add tokens here

}

Parser.prototype.factor = function() {
    var result;

    if (this.tokenizer.float_val()){ //is_number
        result = this.tokenizer.float_val();
        this.tokenizer.eat();
    }else if (this.tokenizer.current() == '(' ) {
        this.tokenizer.eat_punctuation('(');
        result = this.exr();
        this.tokenizer.eat_punctuation(')');
    }else if (this.tokenizer.current() == '-'){
        this.tokenizer.eat_punctuation('-');
        result = -1 * this.factor();
    }else {
        throw {
            name: "Unexpected token \"" + this.tokenizer.current() + "\"",
            position: this.tokenizer.tok_index
        };
    }

    return result;
}

Parser.prototype.term = function() {
  var result = this.factor();

  while ( this.tokenizer.current() == '*' || this.tokenizer.current() == '/' || this.tokenizer.current() == '%' ){
      if( this.tokenizer.current() == '*' ){
          this.tokenizer.eat();
          result *= this.term();
      } else if (this.tokenizer.current() == '/') {
          this.tokenizer.eat();
          result /= this.term();
      } else if (this.tokenizer.current() == '%') {
          this.tokenizer.eat();
          result = result % this.term();
      }
  }

  return result;
}

Parser.prototype.exr = function() {
  var result = this.term();

  while ( this.tokenizer.current() == '+' || this.tokenizer.current() == '-' ){
      if( this.tokenizer.current() == '+' ){
          this.tokenizer.eat();
          result += this.term();
      } else if (this.tokenizer.current() == '-') {
          this.tokenizer.eat();
          result -= this.term();
      }
  }

  return result;

}

Parser.prototype.parse = function() {
  // TODO
debugger;
  if(!this.str)
    throw {
        name: "Parser empty input string",
        position: "0"
    };

  this.tokenizer.tokenize(this.str);

  return this.exr();
}

module.exports = Parser;
