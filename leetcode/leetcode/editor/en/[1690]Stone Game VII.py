from typing import List

# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        n = len(stones)

        prefix_sum = [0] * (n + 1)
        for idx, stone in enumerate(stones):
            prefix_sum[idx + 1] = prefix_sum[idx] + stone

        dp = [[0] * (n + 2) for _ in range(n + 2)]

        for L in range(n - 1, 0, -1):
            for R in range(L + 1, n + 1, 1):
                turn = (n - (R - L + 1)) % 2
                if turn == 0:
                    dp[L][R] = max(dp[L + 1][R] + prefix_sum[R] - prefix_sum[L],
                                   dp[L][R - 1] + prefix_sum[R - 1] - prefix_sum[L - 1])
                else:
                    dp[L][R] = min(dp[L + 1][R] - prefix_sum[R] + prefix_sum[L],
                                   dp[L][R - 1] - prefix_sum[R - 1] + prefix_sum[L - 1])

        return dp[1][n]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.stoneGameVII([7, 90, 5, 1, 100, 10, 10, 2])
