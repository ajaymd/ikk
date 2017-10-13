#!/bin/python3

import sys
import os

sys.setrecursionlimit(101000)

class TreeNode:
    def __init__(self):
    	# self.val = 0 										# To find height of tree, value stored in nodes does not matter. So in input also we are not given this field. 
        self.children = []

'''
	--------------------------------START------------------------------------
'''

'''
    For your reference:
    
    class TreeNode:
        def __init__(self):
            self.children = []

'''

# Complete the function below.

def find_height(k, root):
    if (len(root.children) == 0):							# Handle base case when root is a leaf node.					
        return 0
    h = 0
    for i in range(0, len(root.children)):
        temp = root.children[i]
        h = max(h, find_height(k, temp))					# Find height of each children and store the maximum height of children. 
    return h + 1	

'''
	--------------------------------STOP------------------------------------
'''

address = {}

def build_tree(frm, to):
    N = len(frm) + 1
    address = {}											# Clear the global variable.
    for i in range(1, N + 1):
        address[i] = TreeNode()								# Create N nodes. 
    for i in range(0, N - 1):
        address[frm[i]].children.append(address[to[i]])		# Link the nodes. (Build the k-ary tree.)
    return address[1]	

if __name__ == "__main__":
    f = open(os.environ['OUTPUT_PATH'], 'w')

    k = int(input())

    from_cnt = 0
    from_cnt = int(input())
    from_i = 0
    frm = []
    while from_i < from_cnt:
        from_item = int(input())
        frm.append(from_item)
        from_i += 1


    to_cnt = 0
    to_cnt = int(input())
    to_i = 0
    to = []
    while to_i < to_cnt:
        to_item = int(input())
        to.append(to_item)
        to_i += 1

    root = build_tree(frm, to)

    res = find_height(k, root)
    f.write(str(res) + "\n")


    f.close()
