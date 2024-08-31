import sys

input = sys.stdin.readline


def solve():
    n: int = int(input())
    a: list[int] = [int(x) for x in input().strip(' ').split(' ')]

    ans = 0
    for i in range(0, n, 2):
        ans += a[i]
    v1 = [a[i + 1] - a[i] for i in range(0, n - 1, 2)]
    v2 = [a[i] - a[i + 1] for i in range(1, n - 1, 2)]

    csum = 0
    msum = 0
    added = 0
    for x in v1:
        csum += x
        msum = min(csum, msum)
        added = max(added, csum - msum)

    csum = 0
    msum = 0
    for x in v2:
        csum += x
        msum = min(csum, msum)
        added = max(added, csum - msum)

    print(ans + added)


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        solve()
        tc -= 1
