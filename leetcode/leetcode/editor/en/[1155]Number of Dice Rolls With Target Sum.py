# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        n_plus_one = n + 1
        k_plus_one = k + 1
        target_plus_one = target + 1

        dp = [[0] * target_plus_one for _ in range(n_plus_one)]

        dp[0][0] = 1
        for num_dices in range(1, n_plus_one):
            for target in range(1, target_plus_one):
                for face in range(1, k_plus_one):
                    if face <= target <= num_dices * k:
                        dp[num_dices][target] += dp[num_dices - 1][target - face]

        return dp[n][target] % (10 ** 9 + 7)


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.numRollsToTarget(30, 30, 500)
