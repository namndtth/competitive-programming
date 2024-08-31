import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))

    s = 0
    m = {s}

    for i, x in enumerate(a):
        s += x * (-1 if i & 1 else 1)
        if s in m:
            print('YES')
            return
        else:
            m.add(s)

    print('NO')


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
