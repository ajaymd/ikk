def how_many_BSTs(n):
    def how_many_bsts_memo(n, memo):
        if n in memo:
            return memo[n]

        if n == 0 or n == 1:
            memo[n] = 1
            return 1

        result = 0
        for i in range(n):
            result += how_many_bsts_memo(i, memo) * how_many_bsts_memo(n - i - 1, memo)
        memo[n] = result
        return result
    return how_many_bsts_memo(n, dict())


def how_many_bsts_no_memo(n):

    if n == 0 or n == 1:
        return 1

    result = 0
    for i in range(n):
        result += how_many_bsts_no_memo(i) * how_many_bsts_no_memo(n - i - 1)
    return result


num = 50
print how_many_BSTs(num)
# print how_many_bsts_no_memo(num)