import math


def solve():
    n, x0, y0 = map(int, input().split())

    cnt = set()

    for i in range(n):
        x1, y1 = map(int, input().split())
        a = y1 - y0
        b = x1 - x0

        z = math.gcd(int(math.fabs(a)), int(math.fabs(b)))

        if a == 0:
            b = 1
        elif b == 0:
            a = 1
        else:
            if a < 0:
                z = -z
            a //= z
            b //= z

        cnt.add((a, b))

    print(len(cnt))


if __name__ == '__main__':
    solve()
