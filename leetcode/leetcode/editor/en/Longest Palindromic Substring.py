# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[0] * n for _ in range(n)]

        for i in range(n):
            dp[i][i] = 1

        ans = 1
        tb = (0, 0)

        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = 1
                ans = 2
                tb = (i, i + 1)

        for i in range(2, n):
            for j in reversed(range(i)):
                if (dp[j + 1][i - 1] == 1) and (s[i] == s[j]):
                    dp[j][i] = 1
                    if ans < i - j + 1:
                        ans = max(ans, i - j + 1)
                        tb = (j, i)

        return s[tb[0]: tb[1] + 1]


# leetcode submit region end(Prohibit modification and deletion)
sol = Solution()
print(sol.longestPalindrome('aabcbaaaa'))
