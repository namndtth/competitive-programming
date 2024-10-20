def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]

    sa = [0] * (n + 2)
    sb = [0] * (n + 2)
    for i in range(1, n + 1):
        sa[i] = sa[i - 1] + a[i - 1]
        sb[i] = sb[i - 1] + b[i - 1]

    ans = 1e9
    for i in range(1, n + 1):
        bob = max(sb[i - 1], sa[n] - sa[i])
        ans = min(ans, bob)

    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
