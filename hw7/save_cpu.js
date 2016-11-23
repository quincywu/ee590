let jnet  = require('./json_net');

let client = jnet.JSONSocket();

let counter = 0;

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




  }, 2000 );

}

function getsend(){
    t = setTimeout(function() {

        if ( counter % 3 == 0 )
          client.jwrite({ command: "get"}, getsend);

        if ( counter % 3 == 1 )
          client.jwrite({ command: "get", key:'cpu load'}, getsend);

        if ( counter % 3 == 2 )
          client.jwrite({ command: "get", "key":'cpu load', "host":'::ffff:127.0.0.1'}, getsend);

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

client.connect(8080, 'localhost');
