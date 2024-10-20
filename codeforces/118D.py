def recursive(n1, n2, k1, k2, K1, K2):
    if n1 == 0 and n2 == 0 and k1 <= K1 and k2 <= K2:
        return 1

    if k1 > K1 or k2 > K2 or n1 < 0 or n2 < 0:
        return 0

    # if n1 == 0:
    #     return recursive(0, n2 - 1, 0, k2 + 1, K1, K2)
    #
    # if n2 == 0:
    #     return recursive(n1 - 1, 0, k1 + 1, 0, K1, K2)

    return recursive(n1 - 1, n2, k1 + 1, 0, K1, K2) + recursive(n1, n2 - 1, 0, k2 + 1, K1, K2)


def solve():
    n1, n2, k1, k2 = map(int, input().split())

    dp = [[[[0] * (k2 + 2) for _ in range(k1 + 2)] for _ in range(n2 + 1)] for _ in range(n1 + 1)]

    for j1 in range(0, k1 + 1):
        for j2 in range(0, k2 + 1):
            dp[0][0][j1][j2] = 1

    for i1 in range(0, n1 + 1):
        for i2 in range(0, n2 + 1):
            for j1 in range(0, k1 + 1):
                for j2 in range(0, k2 + 1):
                    if i1 == 0 and i2 == 0:
                        continue
                    if i1 == 0:
                        dp[i1][i2][j1][j2] = dp[0][i2 - 1][0][j2 + 1]
                    elif i2 == 0:
                        dp[i1][i2][j1][j2] = dp[i1 - 1][0][j1 + 1][0]
                    else:
                        dp[i1][i2][j1][j2] = dp[i1 - 1][i2][j1 + 1][0] + dp[i1][i2 - 1][0][j2 + 1]

    print(dp[n1][n2][0][0] % (10 ** 8))


if __name__ == '__main__':
    solve()
