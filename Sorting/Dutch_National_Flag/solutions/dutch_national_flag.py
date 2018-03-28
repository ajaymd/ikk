FIRST_CHAR = 'R'
SECOND_CHAR = 'G'
THIRD_CHAR = 'B'


def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


def dutch_flag_sort(balls):
    if not balls or len(balls) == 1:
        return balls

    arr = list(balls)
    # maintain 4 regions
    # 0 -> low - R
    # low -> mid - G
    # mid -> high - unknown
    # high -> end - B
    low, mid, high = 0, 0, len(arr) - 1

    while mid <= high:
        if arr[mid] == FIRST_CHAR:
            swap(arr, mid, low)
            # increase the low and mid regions
            low += 1
            mid += 1
        elif arr[mid] == SECOND_CHAR:
            # low to mid is in the right place
            mid += 1
        else:
            # will be last character
            swap(arr, mid, high)
            # lower the high number
            high -= 1

    return ''.join(arr)


print dutch_flag_sort('GBGGRBRG')