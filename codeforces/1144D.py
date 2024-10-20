def solve():
    n = int(input())
    a = list(map(int, input().split()))

    cnt = {}
    for x in a:
        if x not in cnt:
            cnt[x] = 1
        else:
            cnt[x] += 1

    k = max(cnt, key=cnt.get)
    pos = a.index(k)

    print(n - cnt[k])

    for i in range(pos - 1, -1, -1):
        if a[i] < k:
            print(1, i + 1, i + 2)
        elif a[i] > k:
            print(2, i + 1, i + 2)

    for i in range(pos + 1, n):
        if a[i] < k:
            print(1, i + 1, i)
        elif a[i] > k:
            print(2, i + 1, i)


if __name__ == '__main__':
    solve()
