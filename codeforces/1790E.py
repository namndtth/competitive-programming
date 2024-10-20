def solve():
    x = int(input())
    a = x + x // 2
    b = x - x // 2
    if a ^ b == x:
        print(a, b)
    else:
        print(-1)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
