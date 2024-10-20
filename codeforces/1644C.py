def solve():
    n, x = map(int, input().split())
    a = [int(e) for e in input().split()]

    INF = 10 ** 9
    mx = [-INF for i in range(n + 1)]
    mx[0] = 0

    # max sum of each seg of length l
    for l in range(n):
        s = 0
        # sum of sub seg
        for r in range(l, n):
            s += a[r]
            mx[r - l + 1] = max(mx[r - l + 1], s)

    ans = [0] * (n + 1)
    for k in range(n + 1):
        best = 0
        for l in range(n + 1):
            best = max(best, mx[l] + min(k, l) * x)
        ans[k] = best

    print(' '.join(map(str, ans)))


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
