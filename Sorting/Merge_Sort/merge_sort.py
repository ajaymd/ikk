# Naive merge sort as described in Sedgewick
def ms_naive(arr):
    if not arr or len(arr) == 1:
        return arr
    mid = int(len(arr)/2)
    left = ms_naive(arr[:mid])
    right = ms_naive(arr[mid:])
    return merge_naive(left, right)


def merge_naive(left, right):
    if not left and not right:
        return []
    if not left:
        return right
    if not right:
        return left
    output = []
    while left and right:
        if left[0] < right[0]:
            output.append(left.pop(0))
        else:
            output.append(right.pop(0))

    output.extend(left or right)
    return output


# Merge sort
def merge_sort(arr):
    if not arr or len(arr) == 1:
        return arr
    # make auxillary array
    aux = [None for _ in arr]
    ms(arr, aux, 0, len(arr)-1)


def ms(arr, aux, low, high):
    if high <= low:
        return
    mid = int((low+high)/2)
    ms(arr, aux, low, mid)
    ms(arr, aux, mid+1, high)
    merge(arr, aux, low, mid, high)


def merge(a, aux, low, mid, high):
    if high <= low:
        return

    for i, val in enumerate(a[low:high+1]):
        aux[low+i] = val

    # low and high are inclusive
    i, j = low, mid+1
    for k in range(low, high+1):
        # 1st array is done
        if i > mid:
            a[k] = aux[j]
            j += 1
        elif j > high:
            # 2nd array is done
            a[k] = aux[i]
            i += 1
        elif aux[i] < aux[j]:
            a[k] = aux[i]
            i += 1
        else:
            a[k] = aux[j]
            j += 1


# Bottom up merge sort without recursion
def bottom_up_ms(a):
    if not a or len(a) < 2:
        return

    n = len(a)
    aux = [None for _ in a]
    size = 1
    while size < n:
        low = 0
        while low < n - size:
            merge(a, aux, low, low+size-1, min(low+size+size-1, n-1))
            low += size + size
        size += size


A = [1, 2, 3, 4, 0, 1.5, 2.5, 7, 8]
output = ms_naive(A)
print output

A = [1, 2, 3, 4, 0, 1.5, 2.5, 7, 8]
merge_sort(A)
print A

A = [1, 2, 3, 4, 0, 1.5, 2.5, 7, 8]
bottom_up_ms(A)
print A