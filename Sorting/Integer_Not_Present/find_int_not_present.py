import random


def find_missing_number(arr):
    bit_arr = 0
    for e in arr:
        bit_arr |= 1 << e

    for i in range(1, len(arr)+1):
        if not bit_arr & 1 << i:
            return i


def check_missing_number(n):
    arr = random.sample(range(1,n+1), n)

    # Remove a random number from array

    e = random.randint(1,n)
    arr = arr[:e] + arr[e+1:]
    # print 'input array is '
    # print arr

    print 'Missing number is: ', find_missing_number(arr)


check_missing_number(1000)
