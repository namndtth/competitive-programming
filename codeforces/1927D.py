def solve():
    n = int(input())
    a = list(map(int, input().split()))

    p = [-1] * n

    for i in range(1, n):
        p[i] = p[i - 1]
        if a[i] != a[i - 1]:
            p[i] = i - 1

    q = int(input())
    for i in range(q):
        l, r = map(int, input().split())

        l -= 1
        r -= 1

        if p[r] < l:
            print('-1 -1')
        else:
            print(p[r] + 1, r + 1)


def main():
    tc = int(input())
    for _ in range(tc):
        solve()
        if _ + 1 != tc:
            print()


if __name__ == '__main__':
    main()
