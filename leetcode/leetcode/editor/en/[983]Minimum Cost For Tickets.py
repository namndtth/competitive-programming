from typing import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = len(days)
        dp = [10 ** 9] * (n + 1)

        dp[0] = 0
        dp[1] = min(costs)

        for i in range(2, n + 1):
            for j in range(1, i + 1):
                if days[i - 1] - days[j - 1] < 30:
                    dp[i] = min(dp[i], dp[j - 1] + costs[2])
                if days[i - 1] - days[j - 1] < 7:
                    dp[i] = min(dp[i], dp[j - 1] + costs[1])
                if days[i - 1] - days[j - 1] < 1:
                    dp[i] = min(dp[i], dp[j - 1] + costs[0])
        print(dp[-1])
        return dp[-1]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.mincostTickets([1, 4, 6, 7, 8, 20],
                       [2, 7, 15])
