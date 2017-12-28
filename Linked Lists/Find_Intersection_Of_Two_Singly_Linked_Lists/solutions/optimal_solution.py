#!/bin/python3

import sys
import os

class LinkedListNode:
    def __init__(self, node_value):
        self.val = node_value
        self.next = None

def _insert_node_into_singlylinkedlist(head, tail, val):
    if head == None:
        head = LinkedListNode(val)
        tail = head
    else:
        node = LinkedListNode(val)
        tail.next = node
        tail = tail.next
    return tail

# Complete the function below.

#For your reference:
#LinkedListNode {
#    int val
#    LinkedListNode next
#}

'''
    ----START----
'''

def get_size(head):
    N = 0
    while (head != None):
        N += 1
        head = head.next
    return N

def find_intersection(l1, l2):
    N1 = get_size(l1)                   # Size of first linked list
    N2 = get_size(l2)                   # Size of second linked list
    while (N1 > N2):
        l1 = l1.next
        N1 -= 1
    while (N2 > N1):
        l2 = l2.next
        N2 -= 1
    while (l1 != None and l1 != l2):    # Comparing address 
        l1 = l1.next
        l2 = l2.next
    if (l1 == None):                    # If we have reached end 
        return -1
    return l1.val                       # Intersection at node pointed by current value of l1 


'''
    ----STOP----
'''

if __name__ == "__main__":
    f = open(os.environ['OUTPUT_PATH'], 'w')

    l1 = None
    l1_tail = None
    l1_size = int(input())
    l1_i = 0
    while l1_i < l1_size:
        l1_item = int(input())

        l1_tail = _insert_node_into_singlylinkedlist(l1, l1_tail, l1_item)
        if l1_i == 0:
            l1 = l1_tail
        l1_i += 1

    l2 = None
    l2_tail = None
    l2_size = int(input())
    l2_i = 0
    while l2_i < l2_size:
        l2_item = int(input())

        l2_tail = _insert_node_into_singlylinkedlist(l2, l2_tail, l2_item)
        if l2_i == 0:
            l2 = l2_tail
        l2_i += 1

    #--------
    merge_at = int(input())
    l1_temp = l1
    i = 0
    while i < merge_at:
        l1_temp = l1_temp.next
        i += 1
    if l2_tail == None:
        l2 = l1_temp
    else:
        l2_tail.next = l1_temp
    #--------
        
    res = find_intersection(l1, l2);
    f.write(str(res) + "\n")


    f.close()
