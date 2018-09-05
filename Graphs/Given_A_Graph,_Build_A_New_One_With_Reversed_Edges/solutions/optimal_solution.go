package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

type Node struct {
    val int32
    neighbours []*Node
}



// ----------------------------- START ---------------------------------

var reversed_graph = make(map[int32]*Node)

func dfs(node *Node) {
    // First create new node. 
    temp_node := &Node {
        val: node.val,
        neighbours: make([]*Node, 0),
    }
    reversed_graph[node.val] = temp_node        
    n := len(node.neighbours)
    // Visit all the neighbours.
    for i := 0; i < n; i++ {
        // If node is not visited then first visit it.
        _, ok := reversed_graph[node.neighbours[i].val]
        if ! ok {
            dfs(node.neighbours[i])
        }
        // Add the reverse edge. 
        reversed_graph[node.neighbours[i].val].neighbours = append(reversed_graph[node.neighbours[i].val].neighbours, reversed_graph[node.val])
    }
}

func build_other_graph(node *Node) *Node {
    // Build the graph.
    dfs(node)
    // Return any node of the new graph.
    return reversed_graph[1]
}

// ------------------------------- STOP ---------------------------------



var reversed = make(map[int32]*Node)

func helper_dfs(reversed_node *Node) {
    reversed[reversed_node.val] = reversed_node        
    n := len(reversed_node.neighbours)
    for i := 0; i < n; i++ {
        _, ok := reversed[reversed_node.neighbours[i].val]
        if ! ok {
            helper_dfs(reversed_node.neighbours[i])
        }
    }
}

func helper_get_all_addresses_in_reversed_graph(reversed_node *Node) map[int32]*Node {
    helper_dfs(reversed_node)
    return reversed
}

func helper(graph_nodes int32, graph_from []int32, graph_to []int32) string {
    MAX_NODES := 315
    
    original := make(map[int32]*Node)
    for i := 1; i <= int(graph_nodes); i++ {
        node := &Node {
            val: int32(i),
            neighbours: make([]*Node, 0),
        }
        original[int32(i)] = node
    }
    
    edges := make(map[int32]bool)
    
    graph_edges := len(graph_from)
    for i := 0; i < graph_edges; i++ {
        original[graph_from[i]].neighbours = append(original[graph_from[i]].neighbours, original[graph_to[i]])
        edges[int32(MAX_NODES) * (graph_from[i] - 1) + graph_to[i] - 1] = true
    }

    reversed = helper_get_all_addresses_in_reversed_graph(build_other_graph(original[1]))
    if (int32(len(reversed)) != graph_nodes) {
        return "Wrong Answer!"
    }

    for val, node := range reversed {
        if 1 > val || val > graph_nodes {
            return "Wrong Answer!"
        }
        if original[val] == reversed[val] {
            return "Wrong Answer!"
        }
        n := len(node.neighbours)
        for i := 0; i < n; i++ {
            _val := node.neighbours[i].val
            
            temp := int32(MAX_NODES) * (_val - 1) + val - 1
            _, ok := edges[temp]
            if ! ok {
                return "Wrong Answer!"
            }
            delete(edges, temp)
        }
    }
    
    if len(edges) > 0 {
        return "Wrong Answer!"
    }
    return "Correct Answer!"

}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    writer := bufio.NewWriterSize(os.Stdout, 16 * 1024 * 1024)

    graphNodesEdges := strings.Split(readLine(reader), " ")

    graphNodes, err := strconv.ParseInt(graphNodesEdges[0], 10, 64)
    checkError(err)

    graphEdges, err := strconv.ParseInt(graphNodesEdges[1], 10, 64)
    checkError(err)

    var graphFrom, graphTo []int32

    for i := 0; i < int(graphEdges); i++ {
        edgeFromToWeight := strings.Split(readLine(reader), " ")

        edgeFrom, err := strconv.ParseInt(edgeFromToWeight[0], 10, 64)
        checkError(err)

        edgeTo, err := strconv.ParseInt(edgeFromToWeight[1], 10, 64)
        checkError(err)

        graphFrom = append(graphFrom, int32(edgeFrom))
        graphTo = append(graphTo, int32(edgeTo))
    }

    res := helper(int32(graphNodes), graphFrom, graphTo)

    fmt.Fprintf(writer, "%s\n", res)

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
