def solve():
    n = int(input())
    a = [int(x) for x in input().split()]

    a.sort()

    ans = 1
    s = a[0]
    for i in range(1, n):
        if a[i] >= s:
            ans += 1
            s += a[i]

    print(ans)


if __name__ == '__main__':
    solve()
