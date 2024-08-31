def solve():
    n = int(input())

    cnt = dict()
    for _ in range(n):
        st = input()
        if st not in cnt:
            print('OK')
            cnt[st] = 1
        else:
            print(st + str(cnt[st]))
            cnt[st] += 1


if __name__ == '__main__':
    solve()
