#!/bin/ruby

class Node
    attr_accessor :val, :neighbours

    def initialize node_val
        @val = node_val
        @neighbours = []
    end
end



# ------------------------------- START ---------------------------------

$reversed_graph = Hash.new

def dfs(node) 
    # First create new node. 
    temp_node = Node.new node.val
    $reversed_graph[node.val] = temp_node        
    n = node.neighbours.length
    # Visit all the neighbours.
    for i in 0...n
        # If node is not visited then first visit it.
        if ! $reversed_graph.key?(node.neighbours[i].val)
            dfs(node.neighbours[i])
        end
        # Add the reverse edge. 
        $reversed_graph[node.neighbours[i].val].neighbours.push($reversed_graph[node.val])
    end
end

def build_other_graph(node)
    # Build the graph.
    dfs(node)
    # Return any node of the new graph.
    return $reversed_graph[1]
end

# ------------------------------- STOP ---------------------------------



$reversed = Hash.new

def helper_dfs(reversed_node)
    $reversed[reversed_node.val] = reversed_node
    n = reversed_node.neighbours.length
    for i in 0...n
        if ! $reversed.key?(reversed_node.neighbours[i].val)
            helper_dfs(reversed_node.neighbours[i])
        end
    end
end

def helper_get_all_addresses_in_reversed_graph(reversed_node)
    helper_dfs(reversed_node)
    return $reversed
end

$MAX_NODES = 315

def helper(graph_nodes, graph_from, graph_to)
    original = Hash.new
    
    for i in 1..graph_nodes
        node = Node.new i
        original[i] = node
    end
    
    edges = Hash.new
    
    graph_edges = graph_from.length
    for i in 0...graph_edges
        original[graph_from[i]].neighbours.push(original[graph_to[i]])
        edges[$MAX_NODES * (graph_from[i] - 1) + graph_to[i] - 1] = true
    end

    reversed = helper_get_all_addresses_in_reversed_graph(build_other_graph(original[1]))
    if reversed.length != graph_nodes
        return "Wrong Answer!"
    end

    reversed.each_key do |val|
        node = reversed[val]
        if 1 > val || val > graph_nodes
            return "Wrong Answer!"
        end
        if original[val] == reversed[val]
            return "Wrong Answer!"
        end
        n = node.neighbours.length
        for i in 0...n
            _val = node.neighbours[i].val
            temp = $MAX_NODES * (_val - 1) + val - 1
            if !edges.key?(temp)
                return "Wrong Answer!"
            end
            edges.delete(temp)
        end
    end
    
    if edges.length > 0
        return "Wrong Answer!"
    end
    
    return "Correct Answer!"
end


fp = $stdout.dup

graph_nodes, graph_edges = gets.strip.split(' ').map(&:to_i)

graph_from = Array.new(graph_edges)
graph_to = Array.new(graph_edges)

(0..(graph_edges - 1)).each do |graph_i|
    graph_from[graph_i], graph_to[graph_i] = gets.strip.split(' ').map(&:to_i)
end


res = helper(graph_nodes, graph_from, graph_to);
fp.write res;
fp.write "\n"

fp.close()
