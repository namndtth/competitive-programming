def precompute():
    dp: list[bool] = [False] * (10 ** 6 + 10)

    dp[2020] = True
    dp[2021] = True
    for i in range(2022, 10 ** 6 + 5):
        dp[i] = dp[i - 2020] or dp[i - 2021]

    return dp


def solve(dp: list[int]):
    n = int(input())
    print('YES' if dp[n] else 'NO')


if __name__ == '__main__':
    computed = precompute()
    for _ in range(int(input())):
        solve(computed)
