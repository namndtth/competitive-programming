class Solution:
    def __init__(self):
        mx = 2 * (10 ** 5) + 5
        self.dp = [self.sum_digits(x) for x in range(0, mx)]
        for i in range(1, len(self.dp)):
            self.dp[i] += self.dp[i - 1]

    def sum_digits(self, x):
        res = 0
        while x > 0:
            res += x % 10
            x //= 10
        return res

    def solve(self):
        n = int(input())
        print(self.dp[n])

    def solve_all(self):
        for _ in range(int(input())):
            self.solve()


if __name__ == '__main__':
    sol = Solution()
    sol.solve_all()
