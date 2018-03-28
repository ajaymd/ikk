def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


def merger_first_into_second(A1, A2):
    if not A1 or len(A2) != 2*len(A1):
        return None

    n = len(A1)
    # move elements of second array to the end
    j = 0
    for i in range(n, 2*n):
        swap(arr2, i, j)
        j += 1

    # now we can merge start of A1 with end of A2
    j, k = 0, n
    for i in range(2*n):
        if j == n:
            A2[i] = A2[k]
            k += 1
        elif k == 2*n:
            A2[i] = A1[j]
            j += 1
        elif A1[j] < A2[k]:
            A2[i] = A1[j]
            j += 1
        else:
            A2[i] = A2[k]
            k += 1
    return A2


arr1 = [1, 3, 5]
arr2 = [2, 4, 6, 0, 0, 0]
print merger_first_into_second(arr1, arr2)