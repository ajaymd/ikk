class LinkedListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return str(self.val)

    def __cmp__(self, other):
        return self.val - other.val


class LinkedList(object):
    def __init__(self, head=None):
        self.head = head

    def __iter__(self):
        curr = self.head
        while curr:
            yield curr
            curr = curr.next

    def __str__(self):
        return str([x.val for x in self])

    def __len__(self):
        return len([x for x in self])


if __name__ == '__main__':
    n1 = LinkedListNode(1)
    n2 = LinkedListNode(2)
    n3 = LinkedListNode(3)

    n1.next = n2
    n2.next = n3

    ll = LinkedList(n1)

    for n in ll:
        print n.val

    print ll
