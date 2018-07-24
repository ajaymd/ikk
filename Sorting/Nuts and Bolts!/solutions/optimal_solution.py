# ------------------------------------------ START ------------------------------------------

from random import randint
from itertools import starmap


def solve(nuts, bolts):
    def _match_paris(low, high):
        if low >= high:
            return

        # choose a random bolt as partition
        idx = randint(low, high)
        pivot = partition(nuts, low, high, bolts[idx])
        # now partition bolts using the pivot from above
        partition(bolts, low, high, nuts[pivot])

        # recursively partition the rest of the arrays
        _match_paris(low, pivot-1)
        _match_paris(pivot+1, high)

    _match_paris(0, len(nuts)-1)
    # print(nuts)
    # print(bolts)

    # Making it match IK OJ's expected output
    # Can do this instead of using map
    # output = []
    # for i, nut in enumerate(nuts):
    #     output.append('%s %s' % (nut, bolts[i]))
    #
    # return output
    return list(starmap(lambda i, nut: '%s %s' % (nut, bolts[i]), enumerate(nuts)))


def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


def partition(arr, low, high, pivot):
    # We want to partition in such a way that everything less than the pivot is
    # towards the beginning and everything greater than the pivot is towards the end
    # We maintain 2 areas 0 -> i (less than pivot) and i to end greater than pivot
    # if we get an element less than pivot we swap and extend both areas
    # if we get an element greater than pivot we can just extend the second area
    # if we get an element equal to pivot we move it to the end and then swap back
    # to the right place at the end of the while loop
    i, j = low, low
    while j < high:
        if arr[j] < pivot:
            swap(arr, i, j)
            j += 1
            i += 1
        elif arr[j] == pivot:
            swap(arr, j, high)
        else:
            j += 1

    swap(arr, i, high)
    return i

# ------------------------------------------ STOP ------------------------------------------

# TEST RUN


NUTS = [4, 32, 5, 7]
BOLTS = [32, 7, 5, 4]
print(solve(NUTS, BOLTS))