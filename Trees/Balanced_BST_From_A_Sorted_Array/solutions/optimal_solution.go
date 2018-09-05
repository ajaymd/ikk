package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

type TreeNode struct {
    val int32
    left_ptr *TreeNode
    right_ptr *TreeNode
}



// ------------------------------ START ------------------------------

// build tree using values (a[l], a[l+1], ..., a[r]).
func build_balanced_bst_helper(l int32, r int32, a []int32) *TreeNode {
    if l > r {  
        return nil
    }
    m := l + (r - l + 1) / 2
    // to build balanced tree we need to choose the middle element as the root 
    temp_tree_node := &TreeNode {
        left_ptr: nil,
        right_ptr: nil,
        val: a[m],
    }
    println(a[m])
    // recursively create subtree and add it as left child    
    temp_tree_node.left_ptr = build_balanced_bst_helper(l, m - 1, a)    
    // recursively create subtree and add it as right child 
    temp_tree_node.right_ptr = build_balanced_bst_helper(m + 1, r, a)   
    return temp_tree_node
}

// Complete the build_balanced_bst function below.
func build_balanced_bst(a []int32) *TreeNode {
    N := len(a)
    // build balanced BST
    return build_balanced_bst_helper(0, int32(N - 1), a) 
}

// ------------------------------ STOP ------------------------------



func check_balanced_bst(root *TreeNode, l int32, r int32, a []int32) bool {
    if l > r && root == nil {                              // If no value in [l, r] and tree is also empty.
        return true
    } else if l > r && root != nil {                         // If no value in [l, r] but tree contains something. 
        return false
    }
    if root == nil {                                        // If some values in [l, r] but tree is empty.
        return false
    }

    mid1 := l + (r - l) / 2
    mid2 := l + (r - l + 1) / 2

    valid1 := (root.val == a[mid1] && check_balanced_bst(root.left_ptr, l, mid1 - 1, a) && check_balanced_bst(root.right_ptr, mid1 + 1, r, a))
    if valid1 {                                             // actually we are doing valid1 || valid2 but when valid1 is true then no need to find valid2
        return true
    }
    if mid1 == mid2 {                                       // when odd no of elements in [l, r] then mid1 = mid2 so valid1 = valid2 and no need to find valid2.  
        return false
    }
    return (root.val == a[mid2] && check_balanced_bst(root.left_ptr, l, mid2 - 1, a) && check_balanced_bst(root.right_ptr, mid2 + 1, r, a))
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    writer := bufio.NewWriterSize(os.Stdout, 16 * 1024 * 1024)

    aCount, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)

    var a []int32

    for i := 0; i < int(aCount); i++ {
        aItemTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
        checkError(err)
        aItem := int32(aItemTemp)
        a = append(a, aItem)
    }

    root := build_balanced_bst(a)
    if check_balanced_bst(root, 0, int32(aCount - 1), a) {
        fmt.Fprintf(writer, "Valid Balanced BST\n")
    } else {
        fmt.Fprintf(writer, "Invalid Balanced BST\n")
    }

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
