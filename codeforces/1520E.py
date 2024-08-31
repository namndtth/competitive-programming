def solve():
    n = int(input())
    pos = [idx for idx, x in enumerate(input()) if x == '*']

    total_shift_left = 0
    prev = 0
    for x in pos[1:]:
        total_shift_left += x - prev - 1
        prev += 1

    total_shift_right = 0
    prev = n - 1
    for x in pos[-2::-1]:
        total_shift_right += prev - x - 1
        prev -= 1

    total_shift_mid = 0
    if pos:
        mid = len(pos) // 2
        prev_left, prev_right = pos[mid], pos[mid]
        for x in pos[mid + 1:]:
            total_shift_mid += x - prev_left - 1
            prev_left += 1

        if mid - 1 >= 0:
            for x in pos[mid - 1::-1]:
                total_shift_mid += prev_right - x - 1
                prev_right -= 1

    ans = min(total_shift_left, total_shift_right, total_shift_mid)
    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
