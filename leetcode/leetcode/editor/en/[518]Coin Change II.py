from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [[0] * (len(coins) + 1) for _ in range(amount + 1)]
        for i in range(1, len(coins) + 1):
            dp[0][i] = 1

        for i in range(1, amount + 1):
            for j in range(1, len(coins) + 1):
                dp[i][j] = dp[i][j - 1]
                if i >= coins[j - 1]:
                    dp[i][j] += dp[i - coins[j - 1]][j]

        print(dp[amount][len(coins)])
        return dp[amount][len(coins)]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.change(3, [2])
