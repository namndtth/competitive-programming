INF = 10 ** 9
denoms = [1, 5, 10, 20, 100]
memo = {denom: 1 for denom in denoms}


def dp(num):
    if num == 0:
        return 0

    if num < 0:
        return INF

    if num in memo:
        return memo[num]

    res = INF
    memo.update({num: res})

    for denom in denoms:
        num_bill = num // denom
        res = min(res, dp(num - denom * num_bill) + num_bill)

    memo[num] = res

    return res


def solve():
    n = int(input())
    ans = dp(n)
    print(ans)


if __name__ == '__main__':
    solve()
