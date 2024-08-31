def get_min_amount_next_bet(total_bet, k):
    next_bet = total_bet // (k - 1)
    if next_bet * (k - 1) <= total_bet:
        next_bet += 1
    return next_bet


def solve():
    k, x, a = map(int, input().split())

    total_bet = 1
    for i in range(1, x + 1):
        next_bet = get_min_amount_next_bet(total_bet, k)
        total_bet += next_bet

    print('YES' if a >= total_bet else 'NO')


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
