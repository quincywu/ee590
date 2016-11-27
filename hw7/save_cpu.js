let jnet  = require('./json_net');

let client = jnet.JSONSocket();

let counter = 0;

let hostname = '';
let port = '';

function send() {

  setTimeout(function() {
      let user = 0;
      let tot = 0;
      for(var i = 0; i < require('os').cpus().length; i ++) {
          user += require('os').cpus()[i].times.user;
          tot += require('os').cpus()[i].times.sys;
          tot += require('os').cpus()[i].times.idle;
          tot += require('os').cpus()[i].times.irq;
      }
      user *= 100;

      client.jwrite({ command: "put", key: "cpu load", value:user/tot, timestamp: Math.floor(new Date() / 1000) }, getsend);





  }, 1000 );

}

function getsend(){
    t = setTimeout(function() {

        if ( counter % 3 == 0 )
          client.jwrite({ command: "get"}, getsend);

        if ( counter % 3 == 1 )
          client.jwrite({ command: "get", key:'cpu load'}, getsend);

        if ( counter % 3 == 2 )
          client.jwrite({ command: "get", "key":'cpu load', "host":'::ffff:24.18.241.4'}, getsend);

        counter ++;

    }, 1000);

    if ( counter > 2 ){
      clearTimeout(t);
      client.jwrite({ command: "end" });
    }
}

client.on('connect', function() {
  client.jwrite({ command: "ee590"} );
  send();
});

client.on('json', function(object) {
  console.log(object);
});

client.on('error', (err) => {
  throw err;
});

//client.connect(8080, '35.164.154.132');
process.argv.forEach(function (val, index, array) {

  if ( index == 2 ) {
      // hostname
      hostname = val;
  }
  if ( index == 3 ){
      // port
      port = val;

     try{
         client.connect(port, hostname);
     }  catch (e) {
         console.error('Cannot connect to server, ' + e);
     }
  }

});
