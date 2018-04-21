from heapq import heappush, heappop


def mergeArrays(arrs):
    heap = []
    k = len(arrs)
    n = len(arrs[0])
    output = []

    # put the first elements in the array
    for i in range(k):
        heappush(heap, (arrs[i][0], i, 0))

    for _ in range(k*n):
        curr_min, arr_idx, item_idx = heappop(heap)
        output.append(curr_min)
        next_item_idx = item_idx+1
        if next_item_idx < n:
            heappush(heap, (arrs[arr_idx][next_item_idx], arr_idx, next_item_idx))

    return output


ars = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]
print mergeArrays(ars)

ars2 = [[6, 10, 15], [7, 9, 18]]
print mergeArrays(ars2)
