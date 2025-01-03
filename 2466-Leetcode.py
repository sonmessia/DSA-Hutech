class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        mod = 10**9 + 7
        dp = [-1] * (high + 1)

        def solve(low, high, zero, one, length) -> int:
            if length > high:
                return 0
            if dp[length] != -1:
                return dp[length]
            ans = 1 if length >= low else 0
            ans = (ans + solve(low, high, zero, one, length + zero)) % mod
            ans = (ans + solve(low, high, zero, one, length + one)) % mod
            dp[length] = ans
            return dp[length]
        
        return solve(low, high, zero, one, 0)


s = Solution()
print(s.countGoodStrings(3, 3, 1, 1))