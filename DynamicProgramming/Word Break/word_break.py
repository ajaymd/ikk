class Solution(object):

    # This is word break I which returns a boolean
    # https://leetcode.com/problems/word-break/description/
    def wordBreakRec(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        if not s or s in wordDict:
            return True

        n = len(s)

        def _word_break(start):
            if start == n:
                return True

            for i in range(start+1, n+1):
                if s[start:i] in wordDict and _word_break(i):
                    return True

            return False

        return _word_break(0)

    def wordBreakDP(self, s, wordDict):
        if not s or s in wordDict:
            return True

        n = len(s)
        # init dp array
        dp = [False] * n + [True]
        for i in range(n-1, -1, -1):
            for j in range(n, i-1, -1):
                if dp[j] and s[i:j] in wordDict:
                    dp[i] = True
                    break
        return dp[0]

    # Find all possible word breaks
    # https://leetcode.com/problems/word-break-ii/description/
    def wordBreak2DP(self, s, wordDict):
        n = len(s)
        # init dp array
        dp = [None] * n + [True]
        for i in range(n-1, -1, -1):
            for j in range(n, i-1, -1):
                if dp[j] and s[i:j] in wordDict:
                    if dp[i] is None:
                        dp[i] = []
                    dp[i].append(s[i:j])

        # if dp[0] is not None only then we can solve
        output = []
        if not dp[0]:
            return output

        # regular dfs - base case when we have reached end of dp arr, so_far is a solution, so add it to output
        def dfs(pos, so_far):
            if pos == len(dp)-1:
                output.append(' '.join([x for x in so_far]))
                return

            for e in dp[pos]:
                so_far.append(e)
                dfs(pos+len(e), so_far)
                so_far.pop()

        dfs(0, [])
        return output


sol = Solution()
s = 'catsanddog'
d = ['cat', 'cats', 'and', 'sand', 'dog']
print sol.wordBreak2DP(s, d)