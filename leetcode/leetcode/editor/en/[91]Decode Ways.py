# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0

        n = len(s)
        if n == 1:
            return 1

        dp = [0] * n
        dp[0] = 1

        if s[1] == '0':
            if s[0] > '2':
                return 0
            dp[1] = 1
        elif 11 <= int(s[0:2]) <= 26:
            dp[1] = 2
        else:
            dp[1] = 1

        for i in range(2, n):
            if s[i - 1: i + 1] == '00':
                return 0

            dp[i] = dp[i - 1]
            if s[i] == '0':
                if s[i - 1] > '2':
                    return 0

                dp[i] = dp[i - 2]
            elif 11 <= int(s[i - 1: i + 1]) <= 26:
                dp[i] += dp[i - 2]

        print(dp[-1])
        return dp[-1]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.numDecodings("27")
