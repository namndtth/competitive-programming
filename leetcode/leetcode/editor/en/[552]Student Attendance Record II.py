# leetcode submit region begin(Prohibit modification and deletion)
from functools import lru_cache

MOD = 10 ** 9 + 7


class Solution:
    def checkRecord(self, n: int) -> int:
        dp = [[[0] * 4 for _ in range(3)] for _ in range(n + 1)]

        for i in range(1, 3):
            for j in range(1, 4):
                dp[0][i][j] = 1

        for i in range(1, n + 1):
            for j in range(1, 3):
                for k in range(1, 4):
                    dp[i][j][k] = (dp[i - 1][j][3] + dp[i - 1][j - 1][3] + dp[i - 1][j][k - 1]) % MOD

        return dp[n][2][3] % MOD

    @lru_cache(maxsize=None)
    def checkRecordImpl(self, n, num_absent, num_late):
        if num_absent == 0 or num_late == 0:
            return 0

        if n == 0:
            return 1

        return (self.checkRecordImpl(n - 1, num_absent, 3) + self.checkRecordImpl(n - 1, num_absent - 1, 3)
                + self.checkRecordImpl(n - 1, num_absent, num_late - 1))


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    print(sol.checkRecord(10101))
