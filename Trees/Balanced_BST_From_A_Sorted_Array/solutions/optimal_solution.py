#!/bin/python

import sys
import os

class TreeNode:
    def __init__(self, node_value):
        self.val = node_value
        self.left_ptr = None
        self.right_ptr = None

'''
    -----------------------------------START----------------------------------------
'''

# complete this function

'''
    For your reference:
    
    class TreeNode:
    def __init__(self, node_value):
        self.val = node_value
        self.left_ptr = None
        self.right_ptr = None
'''

def build_balanced_bst_helper(l, r, a):                         # build tree using values (a[l], a[l+1], ..., a[r]).
    if (l > r):  
        return None
    m = l + (r - l + 1) / 2
    m = int(m)
    temp_tree_node = TreeNode(a[m])                                         # to build balanced tree we need to choose the middle element as the root 
    temp_tree_node.left_ptr = build_balanced_bst_helper(l, m - 1, a)    # recursively create subtree and add it as left child
    temp_tree_node.right_ptr = build_balanced_bst_helper(m + 1, r, a)   # recursively create subtree and add it as right child 
    return temp_tree_node

def build_balanced_bst(a): 
    N = len(a)
    return build_balanced_bst_helper(0, N - 1, a)               # build balanced BST

'''
    -----------------------------------STOP----------------------------------------
'''


def check_balanced_bst(root, l, r, a):
    if (l > r and root == None):                              # If no value in [l, r] and tree is also empty.
        return True
    elif (l > r and root != None):                         # If no value in [l, r] but tree contains something. 
        return False
    if (root == None):                                       # If some values in [l, r] but tree is empty.
        return False

    mid1 = l + (r - l) / 2
    mid2 = l + (r - l + 1) / 2
    mid1 = int(mid1)
    mid2 = int(mid2)

    valid1 = (root.val == a[mid1] and check_balanced_bst(root.left_ptr, l, mid1 - 1, a) and check_balanced_bst(root.right_ptr, mid1 + 1, r, a))
    if (valid1):                                             # actually we are doing valid1 || valid2 but when valid1 is true then no need to find valid2
        return True        
    if (mid1 == mid2):                                       # when odd no of elements in [l, r] then mid1 = mid2 so valid1 = valid2 and no need to find valid2.  
        return False        
    return (root.val == a[mid2] and check_balanced_bst(root.left_ptr, l, mid2 - 1, a) and check_balanced_bst(root.right_ptr, mid2 + 1, r, a))

if __name__ == "__main__":
    f = open(os.environ['OUTPUT_PATH'], 'w')
    a_cnt = 0
    a_cnt = int(input())
    a_i = 0
    a = []
    while a_i < a_cnt:
        a_item = int(input())
        a.append(a_item)
        a_i += 1


    root = build_balanced_bst(a)
    if (check_balanced_bst(root, 0, a_cnt - 1, a)):
        f.write("Valid Balanced BST\n")
    else:
        f.write("Invalid Balanced BST\n")
    
    f.close()
