
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
    ---START---
'''

import math

def find_first_big(ptr):
    if (ptr.val < ptr.next.val):
        return ptr.next
    cur = ptr.next
    while (cur != ptr):
        if (cur.val < cur.next.val):
            return cur.next
        cur = cur.next
    return None

def is_non_decreasing(head):
    cur = head
    while (cur.next != head):
        if (cur.val > cur.next.val):
            return False
        cur = cur.next
    return True

def find_first_small(ptr):
    if (ptr.val > ptr.next.val):
        return ptr.next
    cur = ptr.next
    while (cur != ptr):
        if (cur.val > cur.next.val):
            return cur.next
        cur = cur.next
    return None

# Finds size of the linked list                        
def find_size(ptr):                                         
    N = 1
    cur = ptr.next
    while (cur != ptr):
        N += 1
        cur = cur.next
    return N

def find_median(ptr):
    '''
        Linked list will be one of these 3 types
        1) (2 -> 2 -> 2 -> 2 -> 2 -> 2)
        2) (2 -> 2 -> 4 -> 6 -> 8 -> 8)
        3) (8 -> 8 -> 4 -> 6 -> 2 -> 2)
        Now first case is trivial.
        In 2nd case if we can find first smallest element (call it head) then finding median will
        be trivial. Just find middle element/elements.
        // (2 -> 2 -> 4 -> 6 -> 8 -> 8) then head will be ([2]head -> 2 -> 4 -> 6 -> 8 -> 8)
    
        In 3rd case if we can find first largest element (call it head) then finding median will 
        be trivial. Just find middle element/elements.
        // (8 -> 8 -> 4 -> 6 -> 2 -> 2) then head will be ([8]head -> 8 -> 4 -> 6 -> 2 -> 2)
    '''
    N = find_size(ptr)
    '''
    We do not know if given linked list is non-increasing or non-decreasing. If it is 
    non_decreasing (2->4->6->8) then there will be <= 1 pair big->small (8->2). If it is 
    non_increasing (8->6->4->2) then there will be many pair big->small (8->6, 6->4, 4->2). When 
    both non-increasing and non-decreasing (2->2->2) then there will be no small->big. This 
    function returns pointer to small. For non-decreasing case it will be unique. For 
    (2 -> 2 -> 2) it will be NULL. For non-increasing it will be any one of the valid pairs.
    '''
    first_small = find_first_small(ptr)                       
    # When all elements are same (2->2->2) then return any element.
    if (first_small == None):                                                   
        return ptr.val
    head = None
    '''
    Take pointer to small that we got previously, as head and check if linked list is 
    non-decreasing or not.       
    '''
    if (is_non_decreasing(first_small)):              
        # If it is non-decreasing then we have found our head
        head = first_small                                                      
    else:                                                                       
        # Non-increasing  
        head = find_first_big(ptr)                                              

    # Till now we have found our head. 

    i = 0
    # Exact middle element in case of odd N and middle left element in case of even N.
    while i < int(math.floor((N - 1) / 2)):                                                      
        i += 1
        head = head.next
    if ((N % 2) == 1):
        return head.val
    return int(math.floor((head.val + head.next.val) / 2))


'''
    ---STOP---
'''

if __name__ == "__main__":
    f = open(os.environ['OUTPUT_PATH'], 'w')

    ptr = None
    ptr_tail = None
    ptr_size = int(input())
    ptr_i = 0
    while ptr_i < ptr_size:
        ptr_item = int(input())

        ptr_tail = _insert_node_into_singlylinkedlist(ptr, ptr_tail, ptr_item)
        if ptr_i == 0:
            ptr = ptr_tail
        ptr_i += 1

    #----added manually----
    ptr_tail.next = ptr
    arbitrary_shift = int(input())
    while (arbitrary_shift > 0):
        arbitrary_shift -= 1
        ptr = ptr.next
    #--------
        
    res = find_median(ptr)
    f.write(str(res) + "\n")


    f.close()
