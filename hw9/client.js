let Database = require('./db');
let Graph = require('./graph');

var graph = new Graph();
graph.addEdge("start","end");
graph.addEdge("start","dest");
graph.addEdge("start","finish", "100");
graph.addEdge("here","there", "dont");
graph.addEdge("up","down", "yes");

graph.printNodes();

var graph2 = new Graph();
graph2.addEdge("gar","cri","partnar");
graph2.addEdge("gar","qui","sameroom");
graph2.addEdge("cay","qui", "friend");
graph2.addEdge("ant","qui");
graph2.deleteNode("gar");

graph2.printNodes();

var db = new Database('graphDB');
db.saveGraph(graph);
db.saveGraph(graph2);

var returnvalue;
db.listAllRelationship("qui", function(rows) {
    returnvalue = rows; // rows = [{node2: related_node_name, relationship: relationship_with_input_node}, ]
    console.log("example = " + returnvalue[0].node2);
    for(var i = 0; i < returnvalue.length; i ++){
        for(var key in returnvalue[i]){
            console.log(key + ": " + returnvalue[i][key])
        }
    }

});


db.closeDb();
