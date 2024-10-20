def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]

    cnt = {0: 0, 1: 0}
    for x in b:
        cnt[x] += 1

    c = sorted(a)
    if a == c or (cnt[0] != 0 and cnt[1] != 0):
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
