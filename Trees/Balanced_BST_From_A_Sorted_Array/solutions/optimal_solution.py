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


def build_balanced_bst(a):
    # build tree using values (a[left], a[left+1], ..., a[right]).
    # indices are inclusive
    def _build_balanced_bst(left, right):
        if left > right:
            return

        # to build balanced tree we need to choose the middle element as the root
        mid = int((left + right) / 2)
        node = TreeNode(a[mid])
        # recursively create subtrees and add them as left and right children
        node.left_ptr = _build_balanced_bst(left, mid - 1)
        node.right_ptr = _build_balanced_bst(mid + 1, right)
        return node

    # build balanced BST
    return _build_balanced_bst(0, len(a) - 1)

'''
    -----------------------------------STOP----------------------------------------
'''


def check_balanced_bst(root, l, r, a):
    # If no value in [l, r] and tree is also empty.
    if (l > r and root == None):                              
        return True
    # If no value in [l, r] but tree contains something. 
    elif (l > r and root != None):                         
        return False
    # If some values in [l, r] but tree is empty.
    if (root == None):                                       
        return False

    mid1 = l + (r - l) / 2
    mid2 = l + (r - l + 1) / 2
    mid1 = int(mid1)
    mid2 = int(mid2)

    valid1 = (root.val == a[mid1] and check_balanced_bst(root.left_ptr, l, mid1 - 1, a) and 
        check_balanced_bst(root.right_ptr, mid1 + 1, r, a))
    # actually we are doing valid1 || valid2 but when valid1 is true then no need to find valid2
    if (valid1):                                             
        return True        
    '''
    when odd no of elements in [l, r] then mid1 = mid2 so valid1 = valid2 and no need to find 
    valid2.  
    '''
    if (mid1 == mid2):                                       
        return False        
    return (root.val == a[mid2] and check_balanced_bst(root.left_ptr, l, mid2 - 1, a) and 
        check_balanced_bst(root.right_ptr, mid2 + 1, r, a))

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
