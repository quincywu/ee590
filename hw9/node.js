var Node = function( name ){
    this.edge_list = {};
    this.name = name;
}

Node.prototype.addEdge = function( end, edge_name = "" ) {
    if ( edge_name ) {
        this.edge_list[String(edge_name)] = end;
    } else {
        this.edge_list[""] = end;
    }

}

module.exports = Node;
