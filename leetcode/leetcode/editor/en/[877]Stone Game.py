from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[0] * (n + 2) for _ in range(n + 2)]

        for size in range(1, n + 1):
            for i in range(n - size + 1):
                j = i + size - 1
                parity = (n - size) % 2
                if parity == 0:
                    dp[i][j] = max(piles[i] + dp[i + 1][j], piles[j] + dp[i][j - 1])
                else:
                    dp[i][j] = min(-piles[i] + dp[i + 1][j], -piles[j] + dp[i][j - 1])

        print(dp[0][n - 1])
        return dp[0][n - 1] > 0


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.stoneGame([3, 7, 2, 3])
