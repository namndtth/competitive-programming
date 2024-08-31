def solve():
    st = input()
    n = len(st)

    dp = [0] * n
    dp[0] = 1
    prev = 0

    cnt = 0 if st[0] != '?' else 1
    for i in range(1, n):
        dp[i] = dp[i - 1] + 1

        if st[i] == '?':
            cnt += 1
            dp[i] += (i - prev)

        elif (st[i] == '0' and st[i] != st[i - 1]) or (st[i] == '1' and st[i] != st[i - 1]):
            if (cnt > 0 and (i - cnt - 1 >= 0) and (cnt % 2 == 0 and st[i - cnt - 1] == st[i]) or
                    (cnt % 2 == 1 and st[i - cnt - 1] != st[i])):
                dp[i] += cnt
                prev = i - cnt
            else:
                dp[i] += (i - prev)
            cnt = 0

        elif st[i] == st[i - 1]:
            prev = i

    print(dp[n - 1])


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
