from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        amount_plus_one = amount + 1
        dp = [10 ** 9] * amount_plus_one
        dp[0] = 0
        for i in range(1, amount_plus_one):
            for coin in coins:
                if i - coin >= 0:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        return -1 if dp[amount] == 10 ** 9 else dp[amount]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.coinChange([1, 2, 5], 11)
