from bisect import bisect_left, bisect_right


def solve():
    n, k = map(int, input().split())
    arr = [int(x) for x in input().split()]

    if k >= 3:
        print(0)
        return

    arr.sort()

    ans = arr[0]
    for i in range(1, n):
        ans = min(ans, arr[i] - arr[i - 1])

    if k > 1:
        s = set()
        for i in range(n):
            for j in range(n):
                if i != j:
                    s.add(abs(arr[i] - arr[j]))

        for x in s:
            p = bisect_left(arr, x)
            if p == 0:
                ans = min(ans, arr[p] - x)
            elif p == n - 1:
                ans = min(ans, x - arr[p - 1])
            else:
                ans = min(ans, arr[p] - x, x - arr[p - 1])
    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
