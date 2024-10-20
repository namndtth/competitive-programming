def solve():
    n = int(input())
    a = list(map(int, input().split()))

    count_unique = [0] * (n + 1)
    pos = {}

    for i in range(n - 1, -1, -1):
        if a[i] not in pos:
            count_unique[i] = count_unique[i + 1] + 1
            pos[a[i]] = {'first': i, 'last': i}
        else:
            count_unique[i] = count_unique[i + 1]
            pos[a[i]]['last'] = i

    ans = 0
    for i in range(n - 1):
        if pos[a[i]]['last'] < i:
            continue

        ans += count_unique[i + 1]

    print(ans)


if __name__ == '__main__':
    solve()
