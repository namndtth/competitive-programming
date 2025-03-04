from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.insert(0, 0)
        cuts.append(n)
        cuts = sorted(cuts)

        num_cuts = len(cuts)

        dp = [[10 ** 9] * num_cuts for _ in range(num_cuts)]

        for L in range(num_cuts - 1, -1, -1):
            for R in range(L + 1, num_cuts):
                if L + 1 == R:
                    dp[L][R] = 0
                    continue

                for cut in range(L + 1, R):
                    dp[L][R] = min(dp[L][R], dp[L][cut] + dp[cut][R] + cuts[R] - cuts[L])

        return dp[0][num_cuts - 1]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.minCost(9, [5, 6, 1, 4, 2])
