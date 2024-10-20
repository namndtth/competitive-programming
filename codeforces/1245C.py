MOD = 10 ** 9 + 7


def add(x, y):
    result = x + y
    return result if result < MOD else result - MOD


def solve():
    st = input()
    n = len(st)

    for c in st:
        if c in ('w', 'm'):
            print(0)
            return

    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 2 if st[0:2] in ('uu', 'nn') else 1

    for i in range(2, n):
        letters = st[i - 1] + st[i]
        if letters == 'uu' or letters == 'nn':
            dp[i] = add(dp[i - 1], dp[i - 2])
        else:
            dp[i] = dp[i - 1]

    print(dp[-2])


if __name__ == '__main__':
    solve()
