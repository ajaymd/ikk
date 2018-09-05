#!/bin/ruby

require 'json'
require 'stringio'

class TreeNode
    attr_accessor :val, :left_ptr, :right_ptr

    def initialize node_val
        @val = node_val
        @left_ptr = nil
        @right_ptr = nil
    end
end


def bst_insert(root, val)
    if root == nil                        # destination.
        return TreeNode.new val
    end
    
    root_copy = root
    while true
        if val <= root.val and root.left_ptr != nil
            root = root.left_ptr
        elsif val <= root.val
            root.left_ptr = TreeNode.new val
            return root_copy
        elsif root.right_ptr != nil
            root = root.right_ptr
        else
            root.right_ptr = TreeNode.new val
            return root_copy
        end
    end
    return root_copy
end


# ------------------------------- START ---------------------------------

$kth_element = 0                                                
$counter = 0

def get_k_th_element(root, k)
    # either root is null or we have already found the answer.
    if root == nil or $counter >= k                               
        return
    end
    get_k_th_element(root.left_ptr, k)                                  
    # if we have not found the answer till now. 
    if $counter < k
        $counter += 1
        # if current node is the kth node.
        if $counter == k
            $kth_element = root.val
            return
        end
        # we have explored left subtree and the root now explore right subtree. 
        get_k_th_element(root.right_ptr, k)                             
    end
end

# def print_inorder(root)
#     if root == nil
#         return
#     end
#     print_inorder(root.left_ptr)
#     print(root.val)
#     print_inorder(root.right_ptr)
# end

def kth_smallest_element(root, k)
    # print_inorder(root)
    get_k_th_element(root, k)                               
    return $kth_element
end

# ------------------------------- STOP ---------------------------------


fptr = $stdout.dup

root = nil

N = gets.strip.to_i
N.times do |i|
    data = gets.strip.to_i
    root = bst_insert(root, data)
end

k = gets.strip.to_i

res = kth_smallest_element root, k

fptr.write res
fptr.write "\n"

fptr.close()
