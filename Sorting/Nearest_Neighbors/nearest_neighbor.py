from heapq import heappop, heappush


def get_distance(p1, p2):
    return pow(p1[0]-p2[0], 2) + pow(p1[1]-p2[1], 2)


def nearest_neighbors_heap(a, point, k):
    # make a max heap, populate it with k points
    # for the next point that comes up, if it's smaller than the max then remove the max and put this one in
    heap = []
    for e in a:
        if len(heap) < k:
            # insert a tuple with -1 * get distance to make it a max heap
            heappush(heap, (-1*get_distance(point, e), e))
        else:
            curr_distance = get_distance(point, e)
            if curr_distance < -1 * heap[0][0]:
                heappop(heap)
                heappush(heap, (-1*curr_distance, e))

    return [e[1] for e in heap]


def nearest_neighbors_qs(a, point, k):
    comp_func = lambda x: get_distance(point, x)
    return _nearest_neighbors_qs(a,k, 0, len(a)-1, comp_func)


def _nearest_neighbors_qs(a, k, start, end, comp_func):
    pivot = partition(a, start, end, comp_func)

    if pivot + 1 == k:
        return a[:pivot+1]
    elif pivot + 1 > k:
        # search in the left half of the array
        return _nearest_neighbors_qs(a, k, start, pivot-1, comp_func)
    else:
        return _nearest_neighbors_qs(a, k, pivot+1, end, comp_func)


def partition(a, start, end, comp_func):
    pivot = a[start]
    left, right = start, end

    while left < right:
        while comp_func(a[left]) <= comp_func(pivot) and left < right:
            # keep moving left as long as element is less than or equal to pivot
            left += 1

        while comp_func(a[right]) > comp_func(pivot):
            right -= 1

        if left < right:
            swap(a, left, right)

    # at the end swap pivot with right
    swap(arr, start, right)
    return right


def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


P = (0, 0)
arr = [(2, 0), (1, 5), (1, 7), (0, -1), (7, 4), (5, 7), (8, 5), (4, 9)]
k = 4
print nearest_neighbors_heap(arr, P, k)
print nearest_neighbors_qs(arr, P, k)
print '\n'

arr = [(2, 0), (1, 5), (1, 7), (0, -1), (7, 4), (5, 7), (8, 5), (4, 9)]
print nearest_neighbors_qs(arr, P, k)
print nearest_neighbors_heap(arr, P, k)
print '\n'

arr = [(1, -3), (1, 2), (3, 4)]
print nearest_neighbors_qs(arr, P, 1)
print nearest_neighbors_heap(arr, P, 1)
print '\n'

arr = [(3, 6), (2, 4), (5, 3), (2, 7), (1, 8), (7, 9)]
print nearest_neighbors_qs(arr, P, 3)
print nearest_neighbors_heap(arr, P, 3)