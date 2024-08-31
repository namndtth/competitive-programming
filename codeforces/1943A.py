def solve():
    n = int(input())
    a = [int(x) for x in input().split()]

    cnt = {}
    for x in a:
        if x in cnt:
            cnt[x] += 1
        else:
            cnt[x] = 1

    b = [k for k in cnt.keys()]
    b.sort()

    cnt_once = 0
    for i in range(n):
        if i not in cnt:
            return i

        if cnt[i] == 1:
            cnt_once += 1
            if cnt_once == 2:
                return i

    return n


if __name__ == '__main__':
    for _ in range(int(input())):
        print(solve())
