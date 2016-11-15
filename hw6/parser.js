tokfile = require('./tokenizer.js');
Tokenizer = tokfile.Tokenizer;
UserException = tokfile.UserException;

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
      .add(/((\d+(\.\d*)?)|(\d*\.\d+))([eE][\+\-]\d*)?/)
      .add(/\s/); // Add tokens here

}

Parser.prototype.factor = function() {
    var result;

    if (this.tokenizer.float_val()){ //is_number
        result = this.tokenizer.float_val();
        this.tokenizer.eat();

        if(this.tokenizer.float_val()){
            var ex = new UserException();
            ex.name = "ParserException Factor";
            ex.message = "Wrong syntax of a number follwing another number";
            var pos = 0;
            for (var i = 0; i < this.tokenizer.tok_index; i ++){
                pos += this.tokenizer.tokens[i].length;
            }
            ex.position = pos;
            throw ex;
        }
    }else if (this.tokenizer.current() == '(' ) {
        this.tokenizer.eat_punctuation('(');
        result = this.exr();
        this.tokenizer.eat_punctuation(')');
    }else if (this.tokenizer.current() == '-'){
        this.tokenizer.eat_punctuation('-');
        result = -1 * this.factor();
    }else {
        var ex = new UserException();
        ex.name = "ParserException Factor";
        ex.message = "Unexpected token \"" + this.tokenizer.current() + "\"";
        var pos = 0;
        for (var i = 0; i < this.tokenizer.tok_index; i ++){
            pos += this.tokenizer.tokens[i].length;
        }
        ex.position = pos;
        throw ex;
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
  if(!this.str){
    var ex = new UserException();
    ex.name = "ParserException Parse";
    ex.message = "Parseing empty input string";
    var pos = 0;
    ex.position = pos;
    throw ex;
  }

  this.tokenizer.tokenize(this.str);
  console.log(this.tokenizer.tokens);

  return this.exr();
}

module.exports = Parser;
