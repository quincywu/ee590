let jnet = require('./json_net');

let server = new jnet.JSONServer();

server.clients = {}; //object

server.on('json_connection', function(jsocket) {

    var responses = {
      ee590: function (object){
        console.log("handshake with " + jsocket.remoteAddress);
        server.clients[jsocket.remoteAddress] = {};
        jsocket.jwrite({ "result": "ok"});
      },

      put: function (object) {
        if(!server.clients[jsocket.remoteAddress]){
            jsocket.error("not yet acquainted");
            return;
        }
        if( object && typeof object.key === 'string' && (typeof object.value === 'string' || typeof object.value === 'number' || typeof object.value === 'boolean') && typeof object.timestamp === 'number' && object.timestamp >= 0  ) {

            server.clients[jsocket.remoteAddress][object.key] = {
                "value": object.value,
                "timestamp": object.timestamp,
                "received": Math.floor(new Date() / 1000)
            };

        }else{
            jsocket.error("Input is incorrect");
            return;
        }

        jsocket.jwrite({ result: "ok"});
      },

      get: function (object) {
          if(!server.clients[jsocket.remoteAddress]){
              jsocket.error("not yet acquainted");
              return;
          }
        if (object) {
            if(typeof object.key === 'string' && typeof object.host === 'string'){
                // { "value": STRING|NUMBER|BOOLEAN, "timestamp": UNIXTIME, "received": UNIXTIME }
                if ( server.clients[object.host] && server.clients[object.host][object.key] )
                    jsocket.jwrite({ value: server.clients[object.host][object.key] });
                else
                    jsocket.error( object.host + " or " + object.key + " does not exist." );

            }else if(typeof object.key == 'string') {
                // { "value": STRING|NUMBER|BOOLEAN, "timestamp": UNIXTIME, "received": UNIXTIME }
                if ( server.clients[jsocket.remoteAddress] && server.clients[jsocket.remoteAddress][object.key] )
                    jsocket.jwrite ({ value: server.clients[jsocket.remoteAddress][object.key] });
                else {
                    jsocket.error( object.key + " does not exist." );;
                }
            }else{
                // { "result": CLIENTS_HASH }
                jsocket.jwrite ({ value: server.clients });

            }

        } else {
            jsocket.error("Object is not defined");
            return ;
        }
      },

      end: function(object,socket) {
        console.log( jsocket.remoteAddress + " disconnected." );
        jsocket.end();
      }

    }

    jsocket.on('json', function(object) {

      if ( responses[object.command] ) {
        responses[object.command](object);
      } else {
        jsocket.error("Unknown command '" + object.command + "'");
      }

      console.log(server.clients);

    });

});

server.on('error', (err) => {
  throw err;
});

server.listen(8080, () => {
  console.log('server bound');
});
