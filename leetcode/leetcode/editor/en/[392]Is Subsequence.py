# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        if not t:
            return False

        n, m = len(s), len(t)
        dp = [[False] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if s[i] == t[j]:
                    if i == 0:
                        dp[i][j] = True
                    elif i > 0 and j > 0:
                        dp[i][j] |= dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]

        return dp[n - 1][m - 1]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.isSubsequence(s="abc", t="ahbgdc")
