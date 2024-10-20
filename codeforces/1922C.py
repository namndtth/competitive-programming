def solve():
    n = int(input())
    a = list(map(int, input().split()))

    l = [0] * n
    r = [0] * n

    l[1], r[n - 2] = 1, 1

    for i in range(1, n - 1):
        l[i + 1] = l[i] + (1 if a[i + 1] - a[i] < a[i] - a[i - 1] else a[i + 1] - a[i])

    for i in range(n - 2, 0, -1):
        r[i - 1] = r[i] + (1 if a[i] - a[i - 1] < a[i + 1] - a[i] else a[i] - a[i - 1])

    for _ in range(int(input())):
        u, v = map(int, input().split())

        u -= 1
        v -= 1

        if u < v:
            print(l[v] - l[u])
        else:
            print(r[v] - r[u])


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
