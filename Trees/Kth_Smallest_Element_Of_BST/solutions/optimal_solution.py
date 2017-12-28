#!/bin/python

import sys
import os
sys.setrecursionlimit(7000)

class TreeNode:
    def __init__(self, node_value):
        self.val = node_value
        self.left_ptr = None
        self.right_ptr = None

def bst_insert(root, val):
    if (root == None):												# base case
        return TreeNode(val)
    root_copy = root
    while (1):
        if (val <= root.val and root.left_ptr != None):             # insert in left subtree
            root = root.left_ptr
        elif (val <= root.val):
            root.left_ptr = TreeNode(val)
            return root_copy
        elif (root.right_ptr != None):                              # insert in right subtree
            root = root.right_ptr
        else:
            root.right_ptr = TreeNode(val)
            return root_copy
    return root_copy


#-------------------------------START-----------------------------------

'''
    For your reference:
    
    class TreeNode:
    def __init__(self, node_value):
        self.val = node_value
        self.left_ptr = None
        self.right_ptr = None
'''

kth_element = 0                                                
counter = 0

def get_k_th_element(root, k):
    global counter                                                      # don't forget this
    global kth_element
    if (root == None or counter >= k):                                  # either root is null or we have already found the answer.                        
        return
    get_k_th_element(root.left_ptr, k)                                  # first try to find from left subtree, because elements in left suubtree will be smaller than the root.           
    if (counter < k):                                                   # if we have not found the answer till now. 
        counter += 1
        if (counter == k):                                              # if current node is the kth node.
            kth_element = root.val
            return
        get_k_th_element(root.right_ptr, k)                             # we have explored left subtree and the root now explore right subtree. 

def kth_smallest_element(root, k):
    get_k_th_element(root, k)                               
    return kth_element

#-------------------------------------STOP---------------------------------

if __name__ == "__main__":
    f = open(os.environ['OUTPUT_PATH'], 'w')
    
    N = int(input())

    root = None
    
    for i in range(0, N):
        data = int(input())
        root = bst_insert(root, data)
    k = int(input())
    
    ans = kth_smallest_element(root, k)
    f.write(str(ans) + "\n")

    f.close()