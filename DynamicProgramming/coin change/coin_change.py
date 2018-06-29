# https://leetcode.com/problems/coin-change/description/
# rec
class Solution(object):
    def coin_change_rec(self, coins, amount):
        def _coin_change(a):
            if a == 0:
                return 0
            ans = float('inf')
            for coin in coins:
                if coin <= a:
                    ans = min(ans, _coin_change(a - coin))
            return ans + 1

        out = _coin_change(amount)
        return out if out != float('inf') else -1


sol = Solution()
c = [1, 2, 5]
a = 11
print sol.coin_change_rec(c, a)
c = [2]
a = 3
print sol.coin_change_rec(c, a)


# memo
class Solution(object):
    def coin_change_memo(self, coins, amount):

        memo = {0: 0}
        def _coin_change(a):
            if a in memo:
                return memo[a]
            ans = float('inf')
            for coin in coins:
                if coin <= a:
                    ans = min(ans, _coin_change(a - coin))
            memo[a] = ans + 1
            return ans + 1

        out = _coin_change(amount)
        return out if out != float('inf') else -1

print '\n'
sol = Solution()
c = [1, 2, 5]
a = 11
print sol.coin_change_memo(c, a)
c = [2]
a = 3
print sol.coin_change_memo(c, a)
c = [413,213,453,20,150,321,254,396,487,234]
a = 5629
print sol.coin_change_memo(c, a)

# dp
class Solution(object):
    def coinChange(self, coins, amount):
        dp = [0] + [float('inf')] * amount

        for i in range(1, amount+1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], dp[i-coin])
            # based on recursion, add 1 after calculating
            dp[i] = dp[i] + 1

        return dp[-1] if dp[-1] != float('inf') else -1

    def print_coins_rec(self, coins, amount):
        dp = [0] + [float('inf')] * amount

        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], dp[i - coin])
            # based on recursion, add 1 after calculating
            dp[i] = dp[i] + 1

        # not possible!
        if dp[-1] == float('inf'):
            return None

        output = []

        def print_coins(a):
            if a == 0:
                return
            for coin in coins:
                if dp[a-coin] == dp[a] - 1:
                    output.append(coin)
                    # this return statement is to force a return from base condition
                    return print_coins(a-coin)
        print_coins(amount)
        return output

    def print_coins_iterative(self, coins, amount):
        dp = [0] + [float('inf')] * amount

        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], dp[i - coin])
            # based on recursion, add 1 after calculating
            dp[i] = dp[i] + 1

        # not possible!
        if dp[-1] == float('inf'):
            return None

        output = []
        a = amount
        while a != 0 and dp[a] != float('inf'):
            for coin in coins:
                if dp[a-coin] == dp[a] - 1:
                    output.append(coin)
                    a -= coin
                    break

        return output



print '\n'
sol = Solution()
c = [1, 2, 5]
a = 11
print sol.coinChange(c, a)
print sol.print_coins_rec(c, a)
c = [2]
a = 3
print sol.coinChange(c, a)
c = [413,213,453,20,150,321,254,396,487,234]
a = 5629
print sol.coinChange(c, a)
print sol.print_coins_rec(c, a)
print sol.print_coins_iterative(c, a)
