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
    // To find height of tree, value stored in nodes does not matter. 
    // So in input also we are not given this field.
    // val int32
    children []*TreeNode
}


// ------------------------------ START --------------------------

// type TreeNode struct {
//     // To find height of tree, value stored in nodes does not matter. 
//     // So in input also we are not given this field.
//     // val int32
//     children []*TreeNode
// }

func Max(x int32, y int32) int32 {
    if x > y {
        return x
    }
    return y
}

// Complete the find_height function below.
func find_height(root *TreeNode) int32 {
    // Handle base case when root is a leaf node.                    
    if len(root.children) == 0 {                        
        return 0
    }
    h := int32(0)
    for i := 0; i < len(root.children); i++ {
        temp := root.children[i]
        // Find height of each children and store the maximum height of children. 
        h = Max(h, find_height(temp))   
    }
    return h + 1
}

// ------------------------------ STOP ---------------------------


func build_tree(from []int32, to []int32) *TreeNode {
    N := len(from) + 1
    address := make(map[int32]*TreeNode)
    for i := 1; i <= N; i++ {
        address[int32(i)] = &TreeNode{
            children: make([]*TreeNode, 0),
        }
    }
    for i := 0; i < N - 1; i++ {
        address[from[i]].children = append(address[from[i]].children, address[to[i]])
    }
    return address[1]
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    writer := bufio.NewWriterSize(os.Stdout, 16 * 1024 * 1024)

    kTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    k := int32(kTemp)
    _ = k

    fromCount, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)

    var from []int32

    for i := 0; i < int(fromCount); i++ {
        fromItemTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
        checkError(err)
        fromItem := int32(fromItemTemp)
        from = append(from, fromItem)
    }

    toCount, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)

    var to []int32

    for i := 0; i < int(toCount); i++ {
        toItemTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
        checkError(err)
        toItem := int32(toItemTemp)
        to = append(to, toItem)
    }

    root := build_tree(from, to)

    res := find_height(root)

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

