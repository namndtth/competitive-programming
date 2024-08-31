def next(x):
    return x + x % 10


def solve():
    n = int(input())
    arr = list(map(int, input().split()))

    flag5 = False
    for i in range(n):
        if arr[i] % 5 == 0:
            flag5 = True
            arr[i] = next(arr[i])

    if flag5:
        print('YES' if min(arr) == max(arr) else 'NO')
    else:
        flag2, flag12 = False, False
        for i in range(n):
            while arr[i] % 10 != 2:
                arr[i] = next(arr[i])
            if arr[i] % 20 == 2:
                flag2 = True
            if arr[i] % 20 == 12:
                flag12 = True

        print('NO' if flag2 & flag12 else 'YES')


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
