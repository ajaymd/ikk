#!/bin/python3

import sys
import os

sys.setrecursionlimit(101000)

class Node:
    def __init__(self):
        self.val = 0
        self.neighbours = []

# ---- START ----

'''
In constraints we are given that each node contains distinct values, so we can keep track of node 
address using that value. {value : node}.
'''
reversed_graph = {}

def dfs(node):    
    # First create new node. 
    temp_node = Node()
    temp_node.val = node.val
    reversed_graph[node.val] = temp_node        
    n = len(node.neighbours)
    # Visit all the neighbours.
    for i in range(0, n):
        # If node is not visited then first visit it.
        if not node.neighbours[i].val in reversed_graph:
            dfs(node.neighbours[i])
        # Add the reverse edge. 
        reversed_graph[node.neighbours[i].val].neighbours.append(reversed_graph[node.val])

def build_other_graph(node):
    # Build the graph.
    dfs(node)
    # Return any node of the new graph.
    return reversed_graph[1]

# ---- STOP ----

reversed = {}

def helper_dfs(reversed_node):
    reversed[reversed_node.val] = reversed_node        
    n = len(reversed_node.neighbours)
    for i in range(0, n):
        if not reversed_node.neighbours[i].val in reversed:
            helper_dfs(reversed_node.neighbours[i])

def helper_get_all_addresses_in_reversed_graph(reversed_node):
    helper_dfs(reversed_node)
    return reversed

def helper(graph_nodes, graph_from, graph_to):

    # ----
    MAX_NODES = 315
    # ----
    
    original = {}
    for i in range(1, graph_nodes + 1):
        node = Node()
        node.val = i;
        original[i] = node
    edges = {}
    
    graph_edges = len(graph_from)
    for i in range(0, graph_edges):
        original[graph_from[i]].neighbours.append(original[graph_to[i]])
        edges[MAX_NODES * (graph_from[i] - 1) + graph_to[i] - 1] = True

    # Student will return only one node. Do a dfs and get all the nodes.
    reversed = helper_get_all_addresses_in_reversed_graph(build_other_graph(original[1]))
    if (len(reversed) != graph_nodes):
        return "Wrong Answer!"

    for val in reversed.keys():
        node = reversed[val]
        if 1 > val or val > graph_nodes:
            return "Wrong Answer!"
        # New graph should not contain node from original graph. 
        if original[val] == reversed[val]:
            return "Wrong Answer!"
        n = len(node.neighbours)
        for i in range(0, n):
            _val = node.neighbours[i].val
            temp = MAX_NODES * (_val - 1) + val - 1
            if not temp in edges:
                return "Wrong Answer!"
            del edges[temp]
    # All the edges should be present in the new graph. 
    if len(edges) > 0:
        return "Wrong Answer!"
    return "Correct Answer!"

if __name__ == "__main__":
    f = open(os.environ['OUTPUT_PATH'], 'w')

    graph_nodes, graph_edges = map(int, input().split())

    graph_from = [0] * graph_edges
    graph_to = [0] * graph_edges

    for graph_i in range(graph_edges):
        graph_from[graph_i], graph_to[graph_i] = map(int, input().split())

    res = helper(graph_nodes, graph_from, graph_to)
    f.write(res + "\n")


    f.close()
