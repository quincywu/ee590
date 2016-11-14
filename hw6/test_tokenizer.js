Tokenizer = require('./tokenizer.js');

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


t = new Tokenizer();

t.add(/\+/)
.add(/\-/)
.add(/\*/)
.add(/\//)
.add(/\(/)
.add(/\)/)
.add(/%/)
.add(/(\d)?(\.\d)/)
.add(/\s/)
 .tokenize("0.5*(-1+2/3.0)+.1+2.2.2"); // ,'m'


  while ( !t.eof() ) {
    console.log(t.eat());
  }

console.log(t.tokens);
