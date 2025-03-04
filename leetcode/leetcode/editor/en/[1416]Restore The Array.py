# leetcode submit region begin(Prohibit modification and deletion)


class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        n = len(s)
        dp = [0] * (n + 1)

        dp[n] = 1

        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                dp[i] = 0
            else:
                j = i
                num = 0
                while num <= k and j < n:
                    num = num * 10 + int(s[j])
                    if num <= k:
                        dp[i] += dp[j + 1]
                    j += 1

        return dp[0] % (10 ** 9 + 7)

    def numberOfArraysImpl(self, s, k, i):
        if i < len(s) and int(s[i]) == 0:
            return 0

        if i == len(s):
            return 1

        if self.dp[i] != -1:
            return self.dp[i]

        res = 0
        num = 0
        while num <= k and i < len(s):
            num = num * 10 + int(s[i])
            if num <= k:
                self.dp[i + 1] = self.numberOfArraysImpl(s, k, i + 1)
                res += self.dp[i + 1]

            i += 1

        return res


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    print(sol.numberOfArrays('1234567890', 90))
