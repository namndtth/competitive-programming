def f(x):
    res = 0

    while x > 0:
        x //= 10
        res += 1

    return res


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    sa, sb = {}, {}
    for i in range(n):
        sa[a[i]], sb[b[i]] = sa.get(a[i], 0) + 1, sb.get(b[i], 0) + 1

    cnt_a = {i: 0 for i in range(1, 10)}
    cnt_b = {i: 0 for i in range(1, 10)}

    ans = 0

    for i in range(n):
        if a[i] in sb and sb[a[i]] > 0:
            sb[a[i]] -= 1
        elif a[i] not in sb or sb[a[i]] <= 0:
            if f(a[i]) > 1:
                cnt_a[f(a[i])] += 1
                ans += 1
            else:
                cnt_a[a[i]] += 1

        if b[i] in sa and sa[b[i]] > 0:
            sa[b[i]] -= 1
        elif b[i] not in sa or sa[b[i]] <= 0:
            if f(b[i]) > 1:
                cnt_b[f(b[i])] += 1
                ans += 1
            else:
                cnt_b[b[i]] += 1

    for i in range(2, 10):
        ans += max(cnt_a[i], cnt_b[i]) - min(cnt_a[i], cnt_b[i])

    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
