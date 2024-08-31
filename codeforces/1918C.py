def solve():
    a, b, r = map(int, input().split())
    if a < b:
        a, b = b, a

    bin_a = bin(a)[2:]
    bin_b = bin(b)[2:]
    bin_b = '0' * (len(bin_a) - len(bin_b)) + bin_b

    mx, x, first_bit = len(bin_a) - 1, 0, False
    for i in range(mx + 1):
        if bin_a[i] != bin_b[i]:
            if not first_bit:
                first_bit = True
            elif bin_a[i] == '1' and x + (1 << (mx - i)) <= r:
                x += (1 << (mx - i))
                a ^= 1 << (mx - i)
                b ^= 1 << (mx - i)

    print(a - b)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
