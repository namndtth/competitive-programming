def solve():
    n = int(input())
    a = list(map(int, input().split()))

    ans = 1
    dp = [1] * n
    for i in range(1, n):
        if a[i] > a[i - 1]:
            dp[i] = dp[i - 1] + 1
            ans = max(ans, dp[i])

    print(ans)


if __name__ == '__main__':
    solve()
