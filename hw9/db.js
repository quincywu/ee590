//let Graph = require('./graph');
var sqlite3 = require('sqlite3').verbose();
var db;
var tableName;

var Database = function ( name ){
    tableName = name;

    createDB();
}

function createDB() {
    var fs = require("fs");
    var file = "graph.db";
    var exists = fs.existsSync(file);

    if(!exists) {
        console.log("Creating DB file.");
        fs.openSync(file, "w");
    }

    console.log('createDB ' + file );
    db = new sqlite3.Database(file);

    createTable();
}

function createTable() {
    console.log("createTable " + tableName);
debugger;
    db.run("CREATE TABLE IF NOT EXISTS " + tableName + "_node ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, 'node' varchar(64) NOT NULL UNIQUE )");
    db.run("CREATE TABLE IF NOT EXISTS " + tableName + "_edge ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, 'node_one_id' int(11) NOT NULL, 'node_two_id' int(11) NOT NULL, 'relationship' varchar(64) NOT NULL )");

    db.serialize(function(){
        db.run("CREATE TABLE IF NOT EXISTS graph ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, 'name' varchar(64) NOT NULL )");
        insertMain();
    });


}

function insertMain() {
    console.log("Insert into graph database ");
    db.run("INSERT INTO graph VALUES (NULL, '" + tableName + "')");
    console.log("Finish into graph database ");
}

Database.prototype.saveGraph = function ( graph ){
    console.log("insertRows ");
debugger;
    db.serialize(function() {

        for(var i = 0; i < graph.node_list.length; i ++){
            if ( graph.node_list[i] ) {

                db.run("INSERT OR IGNORE INTO " + tableName + "_node (id, node) VALUES (NULL, '" + graph.node_list[i].name + "') ",  [], function(err, row) {
                    if(err) console.log(err);
                });
            }
        }

        for(var i = 0; i < graph.node_list.length; i ++){
            if ( graph.node_list[i] ) {
                db.run("INSERT INTO " + tableName + "_edge (id, node_one_id, node_two_id, relationship) VALUES (NULL, '0', '0', 'test')");

                for(var key in graph.node_list[i].edge_list){
                    if (key) {

                        for(var j = 0; j < graph.node_list[i].edge_list[key].length; j ++) {
                            let node1 = graph.node_list[i].name;
                            let node2 = key;
                            let relationship = graph.node_list[i].edge_list[key][j];
                            let query1 = "INSERT INTO " + tableName + "_edge (id, node_one_id, node_two_id, relationship) SELECT NULL, (SELECT id FROM " + tableName + "_node WHERE node like '" + node1 + "') AS id1, (SELECT id FROM " + tableName + "_node WHERE node like '" + node2 + "') AS id2, '" + relationship + "' FROM " + tableName + "_edge WHERE NOT EXISTS ( SELECT 1 FROM " + tableName + "_edge e inner join " + tableName + "_node n on n.id = e.node_one_id inner join " + tableName + "_node n2 on n2.id = e.node_two_id WHERE n.node like '" + node1 + "' and n2.node like '" + node2 + "' and e.relationship like '" + relationship + "' ) limit 1";
                            //console.log(query1);

                            db.run(query1, [],
                                function(err, row) {
                                    console.log("hihi");
                                    if(err) console.log(err);
                                }
                            );

                        }

                    }
                }

                db.run("DELETE FROM " + tableName + "_edge WHERE id = 0 and node_one_id = 0 and node_two_id = 0 and relationship like 'test'");

            }
        }

    });

    console.log("DONE ");
}

Database.prototype.deleteGraph = function() {
    
}

Database.prototype.closeDb = function(){
    console.log("closeDb");
    db.close();
}

module.exports = Database;
