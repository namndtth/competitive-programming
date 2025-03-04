from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        N = len(nums)

        dp = [[0] * N for _ in range(N)]

        for L in range(N - 1, -1, -1):
            for R in range(L, N):
                for i in range(L, R + 1):
                    coins = (1 if L - 1 < 0 else nums[L - 1]) * nums[i] * (1 if R + 1 >= N else nums[R + 1])
                    coins += (0 if i - 1 < 0 else dp[L][i - 1]) + (0 if i + 1 >= N else dp[i + 1][R])
                    dp[L][R] = max(dp[L][R], coins)

        print(dp[0][N - 1])
        return dp[0][N - 1]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.maxCoins([3, 1, 5, 8])
