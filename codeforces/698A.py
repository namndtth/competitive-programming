def solve():
    n = int(input())
    a = list(map(int, input().split()))

    # dp max day will not have rest => work, 0 if rest, 1 if contest, 2 if gym
    #
    dp = [[0] * 3 for _ in range(n + 1)]

    for i in range(1, n + 1):
        if a[i - 1] == 0:
            dp[i][0] = max(dp[i - 1])
        elif a[i - 1] == 1:
            dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1)
            dp[i][2] = max(dp[i - 1])
        elif a[i - 1] == 2:
            dp[i][1] = max(dp[i - 1])
            dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1)
        elif a[i - 1] == 3:
            dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1)
            dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1)

    print(n - max(dp[n]))


if __name__ == '__main__':
    solve()
