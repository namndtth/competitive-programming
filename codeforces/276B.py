def solve():
    s = input()
    cnt = {}
    for x in s:
        cnt[x] = cnt[x] + 1 if x in cnt else 1

    odd, even = 0, 0
    for v in cnt.values():
        if v & 1:
            odd += 1
        else:
            even += 1

    if odd in [0, 1]:
        print('First')
    elif odd == 2:
        print('Second')
    elif odd & 1:
        print('First')
    else:
        print('Second')


if __name__ == '__main__':
    solve()
