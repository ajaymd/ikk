# https://leetcode.com/problems/edit-distance/description/


def edit_distance(str1, str2):
    def edit_distance_rec(i, j):
        # returns number of steps to convert S1[i:] to S2[j:]
        if i == len(str1) and j == len(str2):
            return 0
        # s1 is exhausted
        # need to add characters to it
        if i == len(str1):
            return len(str2) - j

        # s2 is exhausted
        # need to remove characters from it
        if j == len(str2):
            return len(str1) - i

        # min of 3 operations - insert, delete and replace
        # del f(i+1, j); insert f(i, j+1); replace f(i+1, j+1)
        if str1[i] != str2[j]:
            return min(edit_distance_rec(i+1, j), edit_distance_rec(i, j+1), edit_distance_rec(i+1, j+1)) + 1
        else:
            return edit_distance_rec(i+1, j+1)

    return edit_distance_rec(0, 0)


def edit_distance_dp(str1, str2):
    # create dp table
    m, n = len(str1), len(str2)
    if m == 0 and n == 0:
        return 0

    dp = [[None] * (n + 1) for _ in range(m+1)]

    # last row and column will be 0 as that's the first recursive case (base condition)
    dp[m][n] = 0

    # fill last row and last column (s1 exhaused, s2 exhausted cases)

    # fill last row, row remains same dp[m] and col goes from n to 0
    for i in range(n, -1, -1):
        dp[m][i] = n - i

    # fill last column, column remains same row goes from m to 0
    for i in range(m, -1, -1):
        dp[i][n] = m - i

    # now fill backwards each row and col
    # row will be outer index and col will be inner index
    # col goes n-1 -> 0, row goes m-1 -> 0
    for r in range(m-1,-1, -1):
        for c in range(n-1, -1, -1):
            if str1[r] == str2[c]:
                # copy over diagonal
                dp[r][c] = dp[r+1][c+1]
            # else find min of the 3 surrounding cells and add 1 (look at recursive code)
            else:
                dp[r][c] = min(dp[r+1][c], dp[r][c+1], dp[r+1][c+1]) + 1

    return dp[0][0]


s1 = 'kitten'
s2 = 'sitting'
print edit_distance(s1, s2)
print edit_distance_dp(s1, s2)

s1 = 'abc'
s2 = 'dbac'
print edit_distance(s1, s2)
print edit_distance_dp(s1, s2)