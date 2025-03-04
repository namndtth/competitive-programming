# leetcode submit region begin(Prohibit modification and deletion)
import math


class Solution:
    def __init__(self):
        self.squares = []
        for i in range(1, int(math.sqrt(10 ** 4)) + 1):
            self.squares.append(i * i)

    def numSquares(self, n: int) -> int:
        dp = [10 ** 9] * (n + 1)
        for x in range(1, n + 1):
            if x in self.squares:
                dp[x] = 1
            else:
                for y in self.squares:
                    if y > x:
                        break
                    dp[x] = min(dp[x - y] + 1, dp[x])

        print(dp[n])
        return dp[n]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.numSquares(12)
