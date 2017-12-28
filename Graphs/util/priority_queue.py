"""
Python implementation of a priority queue

The expected interface:
- insert(key, priority)
- set_priority(key, priority) / set_priority(new_key, priority)
- pop()
- size()
- empty()

Read the doc strings for more info
"""


class PriorityQueueElement(object):

    def __init__(self, key, priority):
        self.key = key
        self.priority = priority

    def __repr__(self):
        return '<%s: %s>' % (self.key, self.priority)


class PriorityQueue(object):
    """Base class with unimplemented comparator"""

    def __init__(self):
        self.arr = []
        self.positions = {}  # Mapping from values to their current indexes

    def _heapify(self, idx):
        """
        Makes sure the heap constraints are satisfied in the sub heap
        starting at idx
        """
        if idx >= len(self.arr)/2:
            return

        left = self._left(idx)
        right = self._right(idx)

        if left >= self.size():
            return
        if right >= self.size():
            replace_idx = left
        else:
            compare = self._comparator(self.arr[left], self.arr[right])
            replace_idx = left if compare >= 0 else right

        if self._comparator(self.arr[idx], self.arr[replace_idx]) < 0:
            self._swap(idx, replace_idx)
            self._heapify(replace_idx)

    def _bubble_up(self, idx):
        """
        Moves the element at i, as close to the root as it can get
        to satisfy the heap invariant.
        Refer to insert for usage.
        """
        while idx > 0:
            parent = self._parent(idx)
            if self._comparator(self.arr[parent], self.arr[idx]) < 0:
                self._swap(parent, idx)
                idx = parent
            else:
                break

    def _swap(self, i1, i2):
        """Swaps elements at i1 and i2 in the underlying array"""
        self.positions[self.arr[i1].key] = i2
        self.positions[self.arr[i2].key] = i1
        self.arr[i1], self.arr[i2] = self.arr[i2], self.arr[i1]

    def _comparator(self, a, b):
        """
        Returns -1, 0 or 1 based on how a compares to b
        Min and Max heaps / priority queues implement this differently
        """
        raise NotImplementedError

    def pop(self):
        """
        Removes the top most element, rearranges the heap to retain its
        properties and returns the removed element
        """
        self._swap(0, self.size()-1)
        ret = self.arr.pop()
        if self.size():
            self._heapify(0)
        return ret

    def insert(self, key, priority):
        """
        Inserts the given value in the heap and ensures heap is still valid
        """
        self.arr.append(PriorityQueueElement(key, priority))
        self.positions[key] = len(self.arr)-1
        self._bubble_up(len(self.arr)-1)

    def set_priority(self, key, priority):
        """
        Inserts the value with the given priority if it doesn't already exist
        Updates the priority if it does exist
        """
        if key not in self.positions:
            self.insert(key, priority)
        else:
            current_pos = self.positions[key]
            curr_element = self.arr[current_pos]
            self.arr[current_pos] = PriorityQueueElement(key, priority)

            if self._comparator(self.arr[current_pos], curr_element) >= 0:
                # If compares positively, we want to bubble it up
                # i.e. in MinPriorityQueue, new priority is lower than existing
                # and in MaxPriorityQueue, new priority is higher
                self._bubble_up(current_pos)
            else:
                # Otherwise, we want to bubble it down a.k.a. heapify
                self._heapify(current_pos)

    def _parent(self, idx):
        """Returns the parent index of the node at given index"""
        return (idx-1)/2

    def _left(self, idx):
        """Returns the left child index of the node at given index"""
        return 2*idx + 1

    def _right(self, idx):
        """Returns the right child index of the node at given index"""
        return 2*idx + 2

    def size(self):
        """Returns the size of the priority queue"""
        return len(self.arr)

    def empty(self):
        """Returns whether the priority queue is empty"""
        return self.size() == 0


class MinPriorityQueue(PriorityQueue):
    """PriorityQueue with least priority element at the top"""

    def _comparator(self, a, b):
        assert isinstance(a, PriorityQueueElement)
        assert isinstance(b, PriorityQueueElement)

        if a.priority < b.priority:
            return 1
        if a.priority == b.priority:
            return 0
        return -1


class MaxPriorityQueue(PriorityQueue):
    """PriorityQueue with highest priority element at the top"""

    def _comparator(self, a, b):
        assert isinstance(a, PriorityQueueElement)
        assert isinstance(b, PriorityQueueElement)

        if a.priority > b.priority:
            return 1
        if a.priority == b.priority:
            return 0
        return -1


if __name__ == '__main__':
    q = MinPriorityQueue()
    q.set_priority(1, 1000)
    q.insert(2, 2000)
    q.set_priority(3, 3000)
    q.insert(4, 4000)

    q.set_priority(3, 0)
    q.set_priority(4, 1)
    q.set_priority(2, 2)
    q.set_priority(1, 3)
    q.set_priority(3, 5)
    q.set_priority(4, 6)

    while not q.empty():
        print q.pop()

    q = MaxPriorityQueue()
    q.set_priority(1, 1000)
    q.insert(2, 2000)
    q.set_priority(3, 3000)
    q.insert(4, 4000)

    q.set_priority(3, 0)
    q.set_priority(4, 1)
    q.set_priority(2, 2)
    q.set_priority(1, 3)
    q.set_priority(3, 5)
    q.set_priority(4, 6)

    while not q.empty():
        print q.pop()

