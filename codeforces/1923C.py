def solve():
    n, num_queries = map(int, input().split())
    arr = [int(x) for x in input().split()]

    sm = [0] * (n + 1)
    cnt1 = [0] * (n + 1)
    for i in range(n):
        sm[i + 1] = arr[i] + sm[i]
        cnt1[i + 1] = cnt1[i] + 1 if arr[i] == 1 else cnt1[i]

    for _ in range(num_queries):
        l, r = map(int, input().split())

        if (r - l + 1) + (cnt1[r] - cnt1[l - 1]) > sm[r] - sm[l - 1] or l == r:
            print('NO')
        else:
            print('YES')


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
