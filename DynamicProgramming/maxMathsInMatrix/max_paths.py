# min version of same problem - https://leetcode.com/problems/minimum-path-sum/description/


def max_paths_rec(grid):
    num_rows, num_cols = len(grid), len(grid[0])

    def _max_paths(r, c):
        if r == num_rows - 1 and c == num_cols - 1:
            return grid[r][c]

        if r == num_rows or c == num_cols:
            return float('-inf')

        return grid[r][c] + max(_max_paths(r, c+1), _max_paths(r+1, c))
    return _max_paths(0, 0)


def max_paths_memo(grid):
    num_rows, num_cols = len(grid), len(grid[0])
    # seed memo with last cell of the grid
    memo = {(num_rows-1, num_cols-1): grid[num_rows-1][num_cols-1]}

    def _max_paths(r, c):
        if (r, c) in memo:
            return memo[r, c]

        if r == num_rows or c == num_cols:
            return float('-inf')

        memo[r, c] = grid[r][c] + max(_max_paths(r, c+1), _max_paths(r+1, c))
        return memo[r, c]
    ans = _max_paths(0, 0)
    # print len(memo)
    # print memo
    return ans


# using m * n grid
def max_paths_dp(grid):
    num_rows, num_cols = len(grid), len(grid[0])
    dp = [[None] * num_cols for _ in range(num_rows)]

    # fill last col, last row
    dp[num_rows-1][num_cols-1] = grid[num_rows-1][num_cols-1]

    # fill bottom row
    for i in range(num_cols-2, -1, -1):
        dp[num_rows-1][i] = dp[num_rows-1][i+1] + grid[num_rows-1][i]

    # fill right most col
    for i in range(num_rows-2, -1, -1):
        dp[i][num_cols-1] = dp[i+1][num_cols-1] + grid[i][num_cols-1]

    # fill rest of dp table
    for r in range(num_rows-2, -1, -1):
        for c in range(num_cols-2, -1, -1):
            dp[r][c] = grid[r][c] + max(dp[r][c+1], dp[r+1][c])

    # print dp
    return dp[0][0]


# using (m + 1) * (n + 1) grid
# this will work for the max case as max of 0 and any number will be 0
# however for the min paths case (https://leetcode.com/problems/minimum-path-sum/description/), will have to
# deal with special cases for the edge of the dp table as min of positive number and 0 will be 0
def max_paths_dp2(grid):
    num_rows, num_cols = len(grid), len(grid[0])
    # pre fill with 0s so bottom and right most are already zero
    dp = [[0] * (num_cols+1) for _ in range(num_rows+1)]

    # fill rest of dp table
    for r in range(num_rows-1, -1, -1):
        for c in range(num_cols-1, -1, -1):
            dp[r][c] = grid[r][c] + max(dp[r][c+1], dp[r+1][c])

    # print dp
    return dp[0][0]


# Recover path
def max_paths_recover_path(grid):
    num_rows, num_cols = len(grid), len(grid[0])
    # pre fill with 0s so bottom and right most are already zero
    dp = [[0] * (num_cols+1) for _ in range(num_rows+1)]

    # fill rest of dp table
    for r in range(num_rows-1, -1, -1):
        for c in range(num_cols-1, -1, -1):
            dp[r][c] = grid[r][c] + max(dp[r][c+1], dp[r+1][c])

    # have dp table, going to start from cell 0, 0 and go to cell num_rows-1, num_cols-1
    # going to have to take n + m - 1 steps
    r, c = 0, 0

    # Printing path

    for _ in range(num_rows+num_cols-1):
    # one more way - use the while loop instead of for loop
    # while r <= num_rows - 1 and c <= num_cols - 1:
        print 'current cell is ', grid[r][c]
        if dp[r + 1][c] > dp[r][c + 1]:
            print 'down'
            r += 1
        else:
            print 'right'
            c += 1




g = [[18, 3, 5, 200, 57],
        [0, 2, 12, 21, 45],
        [82, 1, 100, 32, 8],
        [67, 5, 92, 7, 23],
        [71, 58, 6, 87, 90]]

print max_paths_rec(g)
print max_paths_memo(g)
print max_paths_dp(g)
print max_paths_dp2(g)
print '\n'
print max_paths_recover_path(g)