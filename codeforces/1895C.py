n = int(input())
arr = input().split()

cnt = [[0] * 50 for i in range(10)]

for y in arr:
    cnt[len(y)][sum([int(c) for c in y])] += 1

ans = 0
for num in arr:
    for lenr in range(len(num) % 2, len(num) + 1, 2):
        l = len(num) + lenr
        suml = sum([int(c) for c in num[:l // 2]])
        sumr = sum([int(c) for c in num[l // 2:]])
        if suml - sumr >= 0:
            ans += cnt[lenr][suml - sumr]

for num in arr:
    # iterate to len(num)
    # because we must skip case ab then ba with len(a) == len(b)
    for lenl in range(len(num) % 2, len(num), 2):
        l = len(num) + lenl
        suml = sum([int(c) for c in num[-l // 2:]])
        sumr = sum([int(c) for c in num[:-l // 2]])
        if suml - sumr >= 0:
            ans += cnt[lenl][suml - sumr]

print(ans)
