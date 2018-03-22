import Foundation

class Node { 
    var val: Int
    var neighbours: Array<Node>
    
    init(_val: Int) {
        self.val = _val
        self.neighbours = Array<Node>()
    }
}

// --------------------------------- START -----------------------------------

var my_reversed = [Int: Node]()

func dfs(node: Node){	
	my_reversed[node.val] = Node(_val: node.val)
	let n = node.neighbours.count
	for i in 0..<n {
		if my_reversed[node.neighbours[i].val] == nil {
			dfs(node: node.neighbours[i])
		}
		my_reversed[node.neighbours[i].val]!.neighbours.append(my_reversed[node.val]!)
	}
}

func build_other_graph(node: Node) -> Node {
    dfs(node: node)
    return my_reversed[1]!
}

// --------------------------------- STOP -----------------------------------

var reversed = [Int: Node]()

func helper_dfs(reversed_node: Node) {
    
	reversed[reversed_node.val] = reversed_node
	let n = reversed_node.neighbours.count
    if n - 1 >= 0 {
        for i in 0...n - 1 {
            if reversed[reversed_node.neighbours[i].val] == nil {
                helper_dfs(reversed_node: reversed_node.neighbours[i])
            }
        }
    }
}

func helper_get_all_addresses_in_reversed_graph(reversed_node: Node){
	helper_dfs(reversed_node: reversed_node)
}

func helper(graph_nodes: Int, graph_from: [Int], graph_to: [Int]) -> String {
    var original = [Int: Node]()
    for i in 1...graph_nodes {
		original[i] = Node(_val: i)
	}
    
    var edges = [[Bool]]()
    for _ in 0...graph_nodes {
        var subArray = [Bool]()
        for _ in 0...graph_nodes {
            subArray.append(false)
        }
        edges.append(subArray)
    }
    
	let graph_edges = graph_from.count
    if graph_edges - 1 >= 0 {
       for i in 0...graph_edges - 1{
		  original[graph_from[i]]!.neighbours.append(original[graph_to[i]]!)
          print(i)
          edges[graph_from[i]][graph_to[i]] = true
	   }
    }
    
    helper_get_all_addresses_in_reversed_graph(reversed_node: build_other_graph(node: original[1]!))
	if reversed.count != graph_nodes{
		return "Wrong Answer!"
	}

    for (id, node) in reversed {
		if 1 > id || id > graph_nodes{
			return "Wrong Answer!"
		}
		if original[id] === reversed[id] {
			return "Wrong Answer!"
		}
		let n = node.neighbours.count
        if n - 1 >= 0 {
            for i in 0...n - 1 {
                let val = node.neighbours[i].val
                if edges[val][id] == false {
                    return "Wrong Answer!"
                }
                edges[val][id] = false
            }
        }
	}
    
    for i in 0...graph_nodes {
        for j in 0...graph_nodes {
            if edges[i][j] == true {
                return "Wrong Answer!"
            }
        }
    }
	return "Correct Answer!"
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!
setbuf(__stdoutp, nil)

let graphNodesEdges: [Int] = readLine()!.split(separator: " ").map {
    if let graphItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
        return graphItem
    } else { fatalError("Bad input") }
}

guard graphNodesEdges.count == 2 else { fatalError("Bad input") }

let graphNodes = graphNodesEdges[0]
let graphEdges = graphNodesEdges[1]

let graphFromTo: [[Int]] = AnyIterator{ readLine() }.prefix(graphEdges).map {
    let graphRow: [Int] = $0.split(separator: " ").map {
        if let graphItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
            return graphItem
        } else { fatalError("Bad input") }
    }

    guard graphRow.count == 2 else { fatalError("Bad input") }

    return graphRow
}

guard graphFromTo.count == graphEdges else { fatalError("Bad input") }

let graphFrom = graphFromTo.map{ $0[0] }
let graphTo = graphFromTo.map{ $0[1] }

let res = helper(graph_nodes: graphNodes, graph_from: graphFrom, graph_to: graphTo)

fileHandle.write(res.data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)

