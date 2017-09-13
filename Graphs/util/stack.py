"""
LIFO Stack
"""
from linked_list import LinkedList


class Stack(object):

    def __init__(self):
        self.list = LinkedList()

    def push(self, val):
        self.list.prepend(val)

    def pop(self):
        return self.list.pop_head()

    def empty(self):
        return self.list.empty()

    def size(self):
        return self.list.size
