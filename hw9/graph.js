let Node = require('./node');

Array.prototype.contains = function(name) {
    var i = this.length;
    while (i--) {
        if (this[i].name === name) {
            return true;
        }
    }
    return false;
}

var Graph = function() {
    this.node_list = [];
}

Graph.prototype.addEdge = function ( start, end, relationship = "") {
    var first = this.node_list.contains(start);
    var second = this.node_list.contains(end);
    if(first){
        //get start node
        var i = this.node_list.length;
        while (i--) {
            if (this.node_list[i].name === start) {
                this.node_list[i].addEdge(end, relationship);
                break;
            }
        }
    }
    if(second){
        //get end node
        var i = this.node_list.length;
        while (i--) {
            if (this.node_list[i].name === end) {
                this.node_list[i].addEdge(start, relationship);
                break;
            }
        }
    }

    if( (!first) || (!second) ){
        if( !first ){
            var node = new Node(start);
            node.addEdge(end, relationship);
            this.node_list.push(node);
        }
        if( !second ){
            var node = new Node(end);
            node.addEdge(start);
            this.node_list.push(node);
        }
    }
}

Graph.prototype.addMultEdge = function(){

}

Graph.prototype.printNodes = function (){
    for(var i = 0;i < this.node_list.length;i++){
        console.log(this.node_list[i].name +":");
        console.log(this.node_list[i].edge_list);
    }
}

module.exports = Graph;
