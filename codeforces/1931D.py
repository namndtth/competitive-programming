def solve():
    n, x, y = map(int, input().split())
    arr = [int(x) for x in input().split()]

    ans = 0
    cnt = dict()
    for e in arr:
        xx, yy = e % x, e % y
        # cal ((x - e % x) % x, e % y) if its value equal (e % x, e % y) then add to ans
        ans += cnt.get(((x - xx) % x, yy), 0)

        # cal (e % x, e % y)
        cnt[(xx, yy)] = cnt.get((xx, yy), 0) + 1
    print(ans)


for _ in range(int(input())):
    solve()
