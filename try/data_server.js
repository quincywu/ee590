let jnet = require('./json_net');

let server = new jnet.JSONServer();

server.clients = {}; //object

server.on('json_connection', function(jsocket) {

    var responses = {
      "hello ee590": function (object){
        jsocket.jwrite({ "result": "ok"});
      },

      put: function (object) {
        if(typeof object.key === 'string')
        server.clients[jsocket.address().address] = object;
        jsocket.jwrite({ result: "ok"});
      },


    }

});
