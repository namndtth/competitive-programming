import math


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def divisorGame(self, n: int) -> bool:
        dp = [False] * 1010

        dp[1] = False
        dp[2] = True

        for i in range(3, n + 1):
            for j in range(1, int(math.sqrt(n)) + 1):
                if i % j == 0 and not dp[i - j]:
                    dp[i] = True
                    break

        return dp[n]
# leetcode submit region end(Prohibit modification and deletion)
