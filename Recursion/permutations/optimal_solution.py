# This is for the case without repeats

# ------------------------------------------ START ------------------------------------------


def permute(arr):
    """
    :type arr: List[int]
    :rtype: List[List[int]]
    """
    if not arr:
        return [[]]

    def swap(i, j):
        arr[i], arr[j] = arr[j], arr[i]

    output = []

    def _perms(idx):
        if idx == len(arr):
            # make deep copy otherwise each arr in output will be the same!
            output.append([x for x in arr])
            return

        for i in range(idx, len(arr)):
            swap(i, idx)
            _perms(idx + 1)
            # swap back after recursing
            swap(i, idx)

    _perms(0)
    return output


# ------------------------------------------ STOP ------------------------------------------


# MAIN / TEST
ip = [1, 2, 3]
print(permute(ip))
