
#https://leetcode.com/problems/expression-add-operators/discuss/71968/Clean-Python-DFS-with-comments
# dfs() parameters:
# num: remaining num string
# temp: temporary string with operators added
# cur: current result of  "temp" string
# last: last multiply-level number in "temp". if next operator is multiply, cur and last will be updated
# res: result to return


class Solution(object):
    def addOperators(self, num, target):
        res, self.target = [], target
        for i in range(1, len(num) + 1):
            # For hacker rank leading zeros are fine so commenting out to pass test cases
            # if i > 1 and num[0] == "0":  # prevent "0*" as a number (number with leading zeros)
                # continue
            # generate every possible concatenation
            self.dfs(num[i:], num[:i], int(num[:i]), int(num[:i]), res)  # this step put first number in the string
        return res

    def dfs(self, num, temp, cur, last, res):
        if not num:
            if cur == self.target:
                res.append(temp)
            return
        for i in range(1, len(num) + 1):
            val = num[:i]
            # For hacker rank leading zeros are fine so commenting out to pass test cases
            # if i > 1 and num[0] == "0":  # prevent "0*" as a number (number with leading zeros)
                # continue
            # insert an operator at every possible location
            self.dfs(num[i:], temp + "+" + val, cur + int(val), int(val), res)
            # we don't have option for - so commenting out
            # self.dfs(num[i:], temp + "-" + val, cur - int(val), -int(val), res)
            # a + b * c => s * c => (s - b) + b * c => using last to do that
            self.dfs(num[i:], temp + "*" + val, cur - last + last * int(val), last * int(val), res)


def generate_all_expressions(s, target):
    sol = Solution()
    return sol.addOperators(s, target)