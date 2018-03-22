import Foundation

class TreeNode {
    var val: Int
    var left_ptr: TreeNode?
    var right_ptr: TreeNode?
    init(val: Int) {
        self.val = val
    }
}

// ------------------------------ START ------------------------------

func build_balanced_bst_helper(l: Int, r: Int, a: [Int]) -> TreeNode {				
	var m = Int(l + (r - l) / 2)
	var temp = TreeNode(val: a[m])		
    if l <= m - 1 {
        temp.left_ptr = build_balanced_bst_helper(l: l, r: m - 1, a: a)						
    }
	if m + 1 <= r {
        temp.right_ptr = build_balanced_bst_helper(l: m + 1, r: r, a: a)						    
    }
	return temp
}

func build_balanced_bst(a: [Int]) -> TreeNode {
    /*
     * Write your code here.
     */
    return build_balanced_bst_helper(l: 0, r: a.count - 1, a: a)
}

// ------------------------------ STOP ------------------------------

func check_balanced_bst(root: TreeNode?, l: Int, r: Int, a: [Int]) -> Bool {
    if l > r && root == nil                              
    {
        return true
    }
    else if l > r && root != nil                         
    {
        return false
    }
    if root == nil                                      
    {
        return false;
    }
    
    let mid1 = Int(l + (r - l) / 2)
    let mid2 = Int(l + (r - l + 1) / 2)
    
    let valid1 = (root!.val == a[mid1] && check_balanced_bst(root: root!.left_ptr, l: l, r: mid1 - 1,
    a: a) && check_balanced_bst(root: root!.right_ptr, l: mid1 + 1, r: r, a: a))
    if valid1                                            
    {
        return true        
    }
    if mid1 == mid2                                       
    {
        return false        
    }
    return (root!.val == a[mid2] && check_balanced_bst(root: root!.left_ptr, l: l, r: mid2 - 1, a: a) && check_balanced_bst(root: root!.right_ptr, l: mid2 + 1, r: r, a: a))  
}

let fileName = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: fileName, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: fileName)!

guard let aCount = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

let a: [Int] = AnyIterator{ readLine() }.prefix(aCount).map {
    if let aItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
        return aItem
    } else { fatalError("Bad input") }
}

guard a.count == aCount else { fatalError("Bad input") }

let root = build_balanced_bst(a: a)
if check_balanced_bst(root: root, l: 0, r: a.count - 1, a: a){
    fileHandle.write("Valid Balanced BST".data(using: .utf8)!)
} else {
    fileHandle.write("Invalid Balanced BST".data(using: .utf8)!)
}
fileHandle.write("\n".data(using: .utf8)!)

