def solve():
    n = int(input())

    triangular_number = set()
    i = 1
    while i * (i + 1) // 2 <= int(1e9):
        triangular_number.add(i * (i + 1) // 2)
        i += 1

    for k in triangular_number:
        if n - k in triangular_number:
            print('YES')
            return

    print('NO')


if __name__ == '__main__':
    solve()
