tokfile = require('./tokenizer.js');
Tokenizer = tokfile.Tokenizer;
UserException = tokfile.UserException;

/*t = new Tokenizer();

t.add(/\[/)
 .add(/\d+/)
 .add(/\s/)
 .add(/,/)
 .add(/]/)
 .tokenize("[ 100,  200,300, ,,[][]]"); // ,'m'


  while ( !t.eof() ) {
    console.log(t.eat());
  }

console.log(t.tokens);*/

// test exception class

t = new Tokenizer();

t.add(/\+/)
.add(/\-/)
.add(/\*/)
.add(/\//)
.add(/\(/)
.add(/\)/)
.add(/%/)
.add(/((\d+(\.\d*)?)|(\d*\.\d+))([eE]\d*)?/)
.add(/\s/)
 .tokenize("q");
 //.tokenize("22.22.231 + .1e11 "); // ,'m'


  while ( !t.eof() ) {
      try{
          t.eat_punctuation("&");
      }catch(e){
          console.log(e.name + ": " + e.message + " at position " + e.position);
      }
    console.log(t.eat());
  }

console.log(t.tokens);
