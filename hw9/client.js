let Database = require('./db');
let Graph = require('./graph');

var graph = new Graph();
graph.addEdge("start","end");
graph.addEdge("start","dest");
graph.addEdge("start","finish", "100");
graph.addEdge("here","there", "dont");
graph.addEdge("up","down", "yes");

graph.printNodes();

var db = new Database('graphDB');
console.log('abc');
db.saveGraph(graph);
db.closeDb();
