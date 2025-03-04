from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        dp = [[0] * n for _ in range(2)]
        dp[0][0] = 0
        dp[1][0] = 1

        for i in range(1, n):
            if nums1[i - 1] >= nums1[i] or nums2[i - 1] >= nums2[i]:
                dp[0][i] = dp[1][i - 1]
                dp[1][i] = dp[0][i - 1] + 1
            elif nums1[i - 1] < nums1[i] and nums2[i - 1] < nums2[i]:
                dp[0][i] = dp[0][i - 1]
                dp[1][i] = dp[1][i - 1] + 1
                if nums1[i - 1] < nums2[i] and nums2[i - 1] < nums1[i]:
                    dp[0][i] = min(dp[0][i], dp[1][i - 1])
                    dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1)

        return min(dp[0][n - 1], dp[1][n - 1])


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    print(sol.minSwap([0, 3, 5, 8, 9], nums2=[2, 1, 4, 6, 9]))
