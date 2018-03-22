import Foundation

class TreeNode {
    // To find height of tree, value stored in nodes does not matter. So in input also we are not given this field. 
    // var val: Int
    var children: Array<TreeNode>
    
    init() {
        self.children = Array<TreeNode>()
    }
}

// --------------------------------- START -----------------------------------

func find_height( root: TreeNode) -> Int {
    if root.children.count == 0	{
		return 0
	}
	var h = 0
    for i in 0...root.children.count - 1{
		// Find height of each children and store the maximum height of children. 
		h = max(h, find_height(root:root.children[i]))
	}
	return h + 1
}

// --------------------------------- STOP -----------------------------------

var address = [Int: TreeNode]()

func build_tree(N: Int, from: [Int], to: [Int]) -> TreeNode {
    for i in 1...N {
        address[i] = TreeNode()
    }
    if N - 2 >= 0 {
        for i in 0...N - 2 {
            address[from[i]]!.children.append(address[to[i]]!)
        }
    }
	return address[1]!
}


let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!
setbuf(__stdoutp, nil)

guard let k = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let treeFromCount = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

let treeFrom: [Int] = AnyIterator{ readLine() }.prefix(treeFromCount).map {
    if let aItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
        return aItem
    } else { fatalError("Bad input") }
}

guard treeFrom.count == treeFromCount else { fatalError("Bad input") }

guard let treeToCount = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

let treeTo: [Int] = AnyIterator{ readLine() }.prefix(treeToCount).map {
    if let aItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
        return aItem
    } else { fatalError("Bad input") }
}

guard treeTo.count == treeToCount else { fatalError("Bad input") }

let root = build_tree(N: treeFrom.count + 1, from: treeFrom, to: treeTo)
let res = find_height(root: root)

fileHandle.write(String(res).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)
