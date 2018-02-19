process.stdin.resume();
process.stdin.setEncoding('utf-8');

var __input_stdin = "";
var __input_stdin_array = "";
var __input_currentline = 0;

process.stdin.on('data', function(data) {
    __input_stdin += data;
});

function Node()
{
    this.val = 0;													
    this.neighbours = [];
}


const MAX_NODES = 315;



// ---- START ----

/*
In constraints we are given that each node contains distinct values, so we can keep track of node 
address using that value. {value : node}.
*/
var reversed_graph = new Map();

function dfs(node)
{        
    // First create new node.
    var temp_node = new Node;
    temp_node.val = node.val;
    reversed_graph.set(node.val, temp_node);        
    var n = node.neighbours.length;
    // Visit all the neighbours.
    for (var i = 0; i < n; i++)
    {
        // If node is not visited then first visit it.
        if (reversed_graph.has(node.neighbours[i].val) == false)
        {
            dfs(node.neighbours[i]);
        }
        // Add the reverse edge. 
        reversed_graph.get(node.neighbours[i].val).neighbours.push(reversed_graph.get(node.val));
    }
}

function build_other_graph(node)
{
    // Build the graph.
    dfs(node);
    // Return any node of the new graph. 
    return reversed_graph.get(1);
}

// ---- STOP ----

var reversed = new Map();

function helper_dfs(reversed_node)
{
    reversed.set(reversed_node.val, reversed_node);        
    var n = reversed_node.neighbours.length;
    for (var i = 0; i < n; i++)
    {
        if (reversed.has(reversed_node.neighbours[i].val) == false)
        {
            helper_dfs(reversed_node.neighbours[i]);
        }
    }
}

function helper_get_all_addresses_in_reversed_graph(reversed_node)
{
    helper_dfs(reversed_node);
    return reversed;
}

function helper(graph_nodes, graph_from, graph_to) {
    var original = new Map();
    for (var i = 1; i <= graph_nodes; i++)
    {
        var node = new Node();
        node.val = i;
        original.set(i, node);
    }
    var edges = new Map();
    
    var graph_edges = graph_from.length;
    for (var i = 0; i < graph_edges; i++)
    {
        original.get(graph_from[i]).neighbours.push(original.get(graph_to[i]));

        edges.set(MAX_NODES * (graph_from[i] - 1) + graph_to[i] - 1, true);
    }	 

    // Student will return only one node. Do a dfs and get all the nodes.
    var reversed = helper_get_all_addresses_in_reversed_graph(build_other_graph(original.get(1)));
    if (reversed.size != graph_nodes)
    {
        return "Wrong Answer!";
    }

    for (var[val, node] of reversed)
    {
        if (1 > val || val > graph_nodes)
        {
            return "Wrong Answer!";
        }
        // New graph should not contain node from original graph. 
        if (original.get(val) == reversed.get(val))
        {
            return "Wrong Answer!";
        }
        var n = node.neighbours.length;
        for (var i = 0; i < n; i++)
        {
            var _val = node.neighbours[i].val;
            var temp = MAX_NODES * (_val - 1) + val - 1;
            if (edges.has(temp) == false)
            {
                return "Wrong Answer!";
            }
            edges.delete(temp);
        }
    }
    // All the edges should be present in the new graph. 
    if (edges.size > 0)
    {
        return "Wrong Answer!";
    }
    return "Correct Answer!";
}



var fs = require('fs');
var wstream = fs.createWriteStream(process.env.OUTPUT_PATH);

process.stdin.on('end', function() {
    __input_stdin_array = __input_stdin.split("\n");
    var graph_nodesm = __input_stdin_array[__input_currentline].split(" ");
    var graph_nodes = parseInt(graph_nodesm[0]);
    var graph_edges = parseInt(graph_nodesm[1]);

    __input_currentline += 1;

    var graph_from = [];
    var graph_to = [];

    for (var graph_i = 0; graph_i < graph_edges; graph_i++) {
        var graph_fromv = __input_stdin_array[__input_currentline].split(" ");
        graph_from.push(parseInt(graph_fromv[0]));
        graph_to.push(parseInt(graph_fromv[1]));

        __input_currentline += 1;
    }


    res = helper(graph_nodes, graph_from, graph_to);
    wstream.write(res+"\n");

    wstream.end();
});
