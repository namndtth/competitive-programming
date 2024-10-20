import math

n = int(input())
a = input().split()
b = input().split()

dishes = [(int(x), int(y)) for x, y in zip(a, b)]

dishes.sort(reverse=True)

prev_x = math.inf
cur_s = 0
ans = 0
for (x, y) in dishes:
    if x < y:
        break
    cur_s += y
    ans = cur_s
    if x <= cur_s <= prev_x:
        break
    prev_x = x
print(ans)
