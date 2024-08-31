import time

MOD = 10 ** 9 + 7


def add(x, y):
    sm = x + y
    return sm if sm < MOD else sm - MOD


def solve():
    n, k = map(int, input().split())

    dp = [[0] * (n + 1) for _ in range(k + 1)]

    for i in range(1, n + 1):
        dp[1][i] = 1

    for l in range(1, k):
        for x in range(1, n + 1):
            for i in range(1, 2001):
                if x * i > n:
                    break
                dp[l + 1][x * i] += dp[l][x]

    ans = 0
    for i in range(1, n + 1):
        ans = sum(dp[k]) % MOD

    print(ans)


if __name__ == '__main__':
    solve()
