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

func bst_insert(root *TreeNode, val int32) *TreeNode {
    if root == nil {
        return &TreeNode {
            left_ptr: nil,
            right_ptr: nil,
            val: val,
        }
    }
    root_copy := root
    for true {
        if val <= root.val && root.left_ptr != nil {
            root = root.left_ptr
        } else if val <= root.val {
            root.left_ptr = &TreeNode {
                left_ptr: nil,
                right_ptr: nil,
                val: val,
            }
            return root_copy
        } else if root.right_ptr != nil {
            root = root.right_ptr
        } else {
            root.right_ptr = &TreeNode {
                left_ptr: nil,
                right_ptr: nil,
                val: val,
            }
            return root_copy
        }
    }
    return root_copy
}


// ------------------------------- START ---------------------------------

var kth_element = int32(0)                                                
var counter = int32(0)

func get_k_th_element(root *TreeNode, k int32) {
    // either root is null or we have already found the answer.
    if root == nil || counter >= k {
        return
    }
    // first try to find from left subtree, because elements in left suubtree will be smaller than 
    // the root.
    get_k_th_element(root.left_ptr, k)                                  
    // if we have not found the answer till now. 
    if counter < k {
        counter += 1
        // if current node is the kth node.
        if counter == k {
            kth_element = root.val
            return
        }
        // we have explored left subtree and the root now explore right subtree. 
        get_k_th_element(root.right_ptr, k)
    }
}

// func inorder_traversal(root *TreeNode) {
//     if root == nil {
//         return
//     }
//     inorder_traversal(root.left_ptr)
//     print(root.val)
//     inorder_traversal(root.right_ptr)
// }

// Complete the kth_smallest_element function below.
func kth_smallest_element(root *TreeNode, k int32) int32 {
    // inorder_traversal(root)
    get_k_th_element(root, k)                               
    return kth_element
}

// ------------------------------- STOP ---------------------------------


func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    writer := bufio.NewWriterSize(os.Stdout, 16 * 1024 * 1024)

    var root *TreeNode

    N, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)

    for i := 0; i < int(N); i++ {
        dataTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
        checkError(err)
        data := int32(dataTemp)
        root = bst_insert(root, data)
    }

    kTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    k := int32(kTemp)

    res := kth_smallest_element(root, k)

    fmt.Fprintf(writer, "%d\n", res)

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
