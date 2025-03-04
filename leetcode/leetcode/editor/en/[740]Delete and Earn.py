from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        cnt = {}
        for x in nums:
            cnt[x] = cnt.get(x, 0) + 1

        mx = max(cnt.keys()) + 1
        dp = [0] * mx

        for x in range(1, mx):
            if x in cnt:
                dp[x] = max(dp[x - 1], dp[x - 2] + x * cnt[x])
            else:
                dp[x] = dp[x - 1]

        return dp[mx - 1]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.deleteAndEarn(nums=[1, 1, 1, 2, 4, 5, 5, 5, 6])
