def solve():
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    commands = input()

    l, r = 0, n - 1
    for c in commands[:n - 1]:
        if c == 'L':
            l += 1
        elif c == 'R':
            r -= 1

    b = [0] * n
    b[n - 1] = arr[l] % m

    for i in range(n - 2, -1, -1):
        if commands[i] == 'L':
            l -= 1
            b[i] = (b[i + 1] * arr[l]) % m
        elif commands[i] == 'R':
            r += 1
            b[i] = (b[i + 1] * arr[r]) % m

    print(' '.join(map(str, b)) + '\n')


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
