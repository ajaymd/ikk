# ------------------------------------------ START ------------------------------------------


def check_if_sum_possible(arr, k):

    # generate all subsets and check if any of them sum to the target
    def _check_sum_possible(so_far, idx):
        # base condition
        if idx == len(arr):
            # so_far check makes sure that so_far is not an empty array (requirement of question)
            if so_far and sum(so_far) == k:
                return True
            return False

        # take element and recurse, don't take element and recurse
        return _check_sum_possible(so_far + [arr[idx]], idx+1) or _check_sum_possible(so_far, idx+1)

    return _check_sum_possible([], 0)

# ------------------------------------------ STOP ------------------------------------------


# SAMPLE RUNS/TESTS
A = [2, 4, 8]
check_k = 6
print(check_if_sum_possible(A, check_k))

B = [2, 4, 8]
check_k = 5
print(check_if_sum_possible(B, check_k))

C = [1, 1]
check_k = 0
print(check_if_sum_possible(C, check_k))

D = [2, 10, 20]
check_k = 0
print(check_if_sum_possible(D, check_k))