def solve():
    n, s = map(int, input().split())
    arr = list(map(int, input().split()))

    arr.sort()

    ans = 0
    median = arr[n // 2]
    if median < s:
        for i in range(n // 2, n):
            if arr[i] < s:
                ans += s - arr[i]
    elif median > s:
        for i in range(n // 2, -1, -1):
            if arr[i] > s:
                ans += arr[i] - s

    print(ans)


if __name__ == '__main__':
    solve()
