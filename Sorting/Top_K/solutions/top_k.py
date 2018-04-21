from heapq import heappush, heappop


def topK(arr, k):
    heap = []
    if not arr:
        return heap
    # use a set to not have duplicates in the heap
    heap_set = set()
    for item in arr:
        if item in heap_set:
            continue
        if len(heap) < k:
            # push the first k items
            heappush(heap, item)
            heap_set.add(item)
        else:
            # then remove the smallest item and push another item if it's greater than the smallest
            # to maintain the invariant of the largest k being in the heap
            if item > heap[0]:
                out = heappop(heap)
                heap_set.remove(out)
                heappush(heap, item)
                heap_set.add(item)
    # at the end return the largest values uniquely
    return heap


a = [1, 5, 4, 4, 2]
k = 2
print topK(a, k)

a = [1, 5, 1, 5, 1]
k = 2
print topK(a, k)