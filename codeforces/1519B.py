def solve():
    n, m, k = map(int, input().split())
    print('YES' if (n * m - 1 == k) else 'NO')


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
