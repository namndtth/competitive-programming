from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        dp = [[0] * n for _ in range(m)]

        dp[0][0] = grid[0][0]

        for i in range(0, m):
            for j in range(0, n):
                if i == 0 and j > 0:
                    dp[i][j] = dp[i][j - 1] + grid[i][j]
                elif j == 0 and i > 0:
                    dp[i][j] = dp[i - 1][j] + grid[i][j]
                elif i > 0 and j > 0:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]

        return dp[m - 1][n - 1]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.minPathSum([[1]])
