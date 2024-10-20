
def solve():
    n = int(input())
    a = [input() for _ in range(2)]

    ans_cnt = 1
    ans_str = a[0][0]
    for i in range(0, n):
        if i == n - 1:
            ans_str += a[1][n - 1]
            break

        if a[0][i + 1] == a[1][i]:
            ans_cnt += 1
            ans_str += a[0][i + 1]
            continue

        if a[0][i + 1] == '0' and a[1][i] == '1':
            ans_cnt = 1
            ans_str += '0'
            continue

        if a[0][i + 1] == '1' and a[1][i] == '0':
            ans_str += a[1][i:]
            break

    print(ans_str)
    print(ans_cnt)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
