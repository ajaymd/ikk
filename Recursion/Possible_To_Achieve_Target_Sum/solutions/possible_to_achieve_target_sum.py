def check_if_sum_possible(arr, k):
    if not arr:
        return False

    # generate all subsets and check if any of them sum to the target
    def _check_sum_possible(so_far, rest):
        # base condition
        if not rest:
            if sum(so_far) == k:
                return True
            return False

        # take element and recurse
        return _check_sum_possible(so_far + [rest[0]], rest[1:]) or _check_sum_possible(so_far, rest[1:])

    return _check_sum_possible([], arr)


A = [2, 4, 8]
check_k = 6
print check_if_sum_possible(A, check_k)

B = [2, 4, 8]
check_k = 5
print check_if_sum_possible(B, check_k)