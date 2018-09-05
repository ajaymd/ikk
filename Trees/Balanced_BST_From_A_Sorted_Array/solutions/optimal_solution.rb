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



# ------------------------------ START ------------------------------

# build tree using values (a[left], a[left+1], ..., a[right]).
# indices are inclusive
def _build_balanced_bst(left, right, a)
    if left > right
        return
    end
    # to build balanced tree we need to choose the middle element as the root
    mid = (left + right) / 2
    node = TreeNode.new a[mid]
    # recursively create subtrees and add them as left and right children
    node.left_ptr = _build_balanced_bst(left, mid - 1, a)
    node.right_ptr = _build_balanced_bst(mid + 1, right, a)
    return node
end

# Complete the build_balanced_bst function below.
def build_balanced_bst(a)
    # build balanced BST
    return _build_balanced_bst(0, a.length - 1, a)
end

# ------------------------------ STOP ------------------------------



def check_balanced_bst(root, l, r, a)
    if l > r and root == nil                            # If no value in [l, r] and tree is also empty.
        return true
    elsif l > r and root != nil                         # If no value in [l, r] but tree contains something. 
        return false
    end
    if root == nil                                      # If some values in [l, r] but tree is empty.
        return false
    end
    mid1 = l + (r - l) / 2
    mid2 = l + (r - l + 1) / 2

    valid1 = (root.val == a[mid1] and check_balanced_bst(root.left_ptr, l, mid1 - 1, a) and check_balanced_bst(root.right_ptr, mid1 + 1, r, a))
    if valid1                                             # actually we are doing valid1 || valid2 but when valid1 is true then no need to find valid2
        return true        
    end
    if mid1 == mid2                                       # when odd no of elements in [l, r] then mid1 = mid2 so valid1 = valid2 and no need to find valid2.  
        return false        
    end
    return (root.val == a[mid2] and check_balanced_bst(root.left_ptr, l, mid2 - 1, a) and check_balanced_bst(root.right_ptr, mid2 + 1, r, a))
end


fptr = $stdout.dup

a_count = gets.strip.to_i

a = Array.new(a_count)

a_count.times do |i|
    a_item = gets.strip.to_i
    a[i] = a_item
end

root = build_balanced_bst a
if check_balanced_bst(root, 0, a_count - 1, a)
    fptr.write "Valid Balanced BST\n"
else
    fptr.write "Invalid Balanced BST\n"
end

fptr.close()
