"""
FIFO Queue
"""
from linked_list import LinkedList


class Queue(object):

    def __init__(self):
        self.list = LinkedList()

    def enqueue(self, val):
        self.list.append(val)

    def dequeue(self):
        return self.list.pop_head()

    def size(self):
        return self.list.size

    def empty(self):
        return self.list.empty()


class ListQueue(object):
    """
    A list based implementation of Queue
    Highly inefficient dequeues since we pop from index 0
    """

    def __init__(self):
        self.arr = []

    def enqueue(self, val):
        self.arr.append(val)

    def dequeue(self):
        return self.arr.pop(0)

    def size(self):
        return len(self.arr)
