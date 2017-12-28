"""
Linked List
"""


class LLNode(object):

    def __init__(self, val):
        self.val = val
        self.next = None


class LinkedList(object):

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def append(self, val):
        node = LLNode(val)
        if self.tail is None:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            self.tail = node
        self.size += 1

    def prepend(self, val):
        node = LLNode(val)
        if self.head is None:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node
        self.size += 1

    def pop_head(self):
        if self.empty():
            return None

        to_return = self.head
        self.head = to_return.next
        if self.head is None:
            self.tail = None
        self.size -= 1

        return to_return.val

    def empty(self):
        return self.size == 0
