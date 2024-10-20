def solve():
    n = int(input())
    arr = list(map(int, input().split()))

    suf = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        suf[i] = suf[i + 1] + arr[i]

    ans = suf[0]
    for s in suf[1:]:
        if s > 0:
            ans += s

    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
