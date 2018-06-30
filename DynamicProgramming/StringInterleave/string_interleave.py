# https://leetcode.com/problems/interleaving-string/description/


def string_interleave_rec(s1, s2, s3):
    len_s1 = len(s1)
    len_s2 = len(s2)
    len_s3 = len(s3)
    if len_s3 != len_s1 + len_s2:
        return False

    def _string_interleave(i, j):
        # base case
        if i == len_s1 and j == len_s2 and i + j == len_s3:
            return True

        if i < len_s1 and j < len_s2 and s1[i] == s2[j] and s2[j] == s3[i+j]:
            # if all 3 are same take from either string
            return _string_interleave(i+1, j) or _string_interleave(i, j+1)
        elif i < len_s1 and s1[i] == s3[i+j]:
            return _string_interleave(i+1, j)
        elif j < len_s2 and s2[j] == s3[i+j]:
            return _string_interleave(i, j+1)
        else:
            return False

    return _string_interleave(0, 0)


def string_interleave_dp(s1, s2, s3):
    len_s1 = len(s1)
    len_s2 = len(s2)
    len_s3 = len(s3)
    if len_s3 != len_s1 + len_s2:
        return False

    dp = [[False] * (len_s2+1) for _ in range(len_s1+1)]

    # recursion is going from start to end, so dp will go from end to start
    # initial values are i == len_s1 and j == len_s2
    dp[len_s1][len_s2] = True
    # we also need to pre-populate the last row and last column
    # to do that, we need to do a suffix match
    # for row, column is exhausted and we need to match the row and vice versa for column
    # fill last column (match with s1)
    for i in range(len_s1-1, -1, -1):
        # to get corresponding character of s3, do a difference of lengths and add i
        dp[i][len_s2] = dp[i+1][len_s2] and s1[i] == s3[len_s3-len_s1+i]

    # fill last row (match with s2)
    for j in range(len_s2-1, -1, -1):
        # to get corresponding character of s3, do a difference of lengths and add j
        dp[len_s1][j] = dp[len_s1][j+1] and s2[j] == s3[len_s3-len_s2+j]

    for i in range(len_s1-1, -1, -1):
        for j in range(len_s2-1, -1, -1):
            if i < len_s1 and j < len_s2 and s1[i] == s2[j] and s2[j] == s3[i + j]:
                dp[i][j] = dp[i+1][j] or dp[i][j+1]
            elif i < len_s1 and s1[i] == s3[i+j]:
                dp[i][j] = dp[i+1][j]
            elif j < len_s2 and s2[j] == s3[i+j]:
                dp[i][j] = dp[i][j+1]

    return dp[0][0]



str1 = 'abc'
str2 = 'defg'
str3 = 'abdcefg'
print string_interleave_rec(str1, str2, str3)
print string_interleave_dp(str1, str2, str3)
print '\n'
c = '1234'
a = '123'
b = '123'
print string_interleave_rec(a, b, c)
print string_interleave_dp(a, b, c)
print '\n'
c = '112233'
a = '123'
b = '123'
print string_interleave_rec(a, b, c)
print string_interleave_dp(a, b, c)

print '\n'
c = '123456'
a = '123456'
b = ''
print string_interleave_rec(a, b, c)
print string_interleave_dp(a, b, c)

print '\n'
c = '12345678'
a = '1234'
b = '5678'
print string_interleave_rec(a, b, c)
print string_interleave_dp(a, b, c)

print '\n'
c = '12345678'
a = '1233'
b = '5678'
print string_interleave_rec(a, b, c)
print string_interleave_dp(a, b, c)

print '\n'
c = 'XXXXZY'
a = 'XXY'
b = 'XXZ'
print string_interleave_dp(a, b, c)
print string_interleave_rec(a, b, c)

print '\n'
c = 'XXXXZY'
a = 'XYX'
b = 'XXZ'
print string_interleave_dp(a, b, c)
print string_interleave_rec(a, b, c)