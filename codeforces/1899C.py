def solve():
    n = int(input())
    a = list(map(int, input().split()))

    ans = a[0]
    dp = a[0]
    for i in range(1, n):
        if (a[i] & 1) != (a[i - 1] & 1):
            dp = max(dp + a[i], a[i])
        else:
            dp = a[i]
        ans = max(ans, dp)

    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
