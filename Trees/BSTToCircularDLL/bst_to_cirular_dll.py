# Reference - http://cslibrary.stanford.edu/109/TreeListRecursion.html


class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def inorder(node):
    if not node:
        return
    inorder(node.left)
    print node.val,
    inorder(node.right)


def join_nodes(a, b):
    # joins node a with b
    # a's next (right) goes to b
    # b's prev (left) goes to a
    a.right = b
    b.left = a


def append_dlls(a, b):
    # takes 2 dlls a and b; adds b to the end of a and returns the joined dll
    if not a:
        return b
    if not b:
        return a

    a_last = a.left
    b_last = b.left

    join_nodes(a_last, b)
    join_nodes(b_last, a)
    return a


def bst_to_dll(node):
    if not node:
        return
    # imagine a 3 node bst, if we have the dll of the left side
    # and dll of the right side and a one node dll of the root
    # then we can join the 3 dlls to make the complete dll

    a_list = bst_to_dll(node.left)
    b_list = bst_to_dll(node.right)

    # make a one node dll
    node.left = node
    node.right = node

    a_list = append_dlls(a_list, node)
    return append_dlls(a_list, b_list)


def print_dll(node):
    if not node:
        return

    curr = node
    while curr:
        print curr.val,
        curr = curr.right
        if curr is node:
            break



n1 = Node(6)
n2 = Node(2)
n3 = Node(7)
n4 = Node(1)
n5 = Node(3)
n6 = Node(8)

n1.left = n2
n1.right = n3
n2.left = n4
n2.right = n5
n3.right = n6


inorder(n1)
print '\n'
output = bst_to_dll(n1)
print_dll(output)