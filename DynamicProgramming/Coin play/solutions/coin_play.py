# Recursive solution
def max_win(coins):
    def _max_win_rec(i, j):
        if i == j:
            return coins[i]
        if j == i+1:
            return max(coins[i], coins[j])
        if i > j:
            return float('inf')

        # option 1
        # player 1 picks coin[i] and player 2 will try to maximize from coin i + 1 and j, so will have to min of i + 2 and j - 1
        # option 2
        # player 1 picks coin[j] and player 2 will try to maximize from coin i and j-1, so will have to min of i + 1 and j - 2
        return max(coins[i] + min(_max_win_rec(i+2, j), _max_win_rec(i+1, j-1)), coins[j] + min(_max_win_rec(i+1, j-1), _max_win_rec(i, j-2)))

    return _max_win_rec(0, len(coins)-1)


# DP solution
def coins_max_profit_dp(coins):
    n = len(coins)

    dp = [[0] * n for _ in range(n)]

    for i in range(n):
        dp[i][i] = coins[i]

    # for any case where i > j we have inf, so we can ignore that (anything below the diagonal
    # the diagonal is i == j which from recursion we know is equal to the coins array
    # in recursion i goes from 0 -> end and j goes from end -> 0; so reverse that in dp
    # i goes from end -> 0 and j goes from 0 -> end (we make it go only from we only want from diagonal going forward
    # apply some boundary conditions to check for i, j bounds
    for i in range(n-1, -1, -1):
        for j in range(i, n):
            if i == j:
                dp[i][j] = coins[i]
                continue

            o1 = dp[i+2][j] if i < n-2 else float('inf')
            o2 = dp[i+1][j-1] if i < n - 1 and j > 0 else float('inf')
            o3 = dp[i][j-2] if j > 1 else float('inf')

            dp[i][j] = max(coins[i] + min(o1, o2), coins[j] + min(o2, o3))

    return dp[0][n-1]


c = [8, 15, 3, 7]
print max_win(c)
print coins_max_profit_dp(c)
