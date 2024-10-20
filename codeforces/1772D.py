def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]

    sorted_arr = sorted(arr)

    if arr == sorted_arr:
        print(0)
    elif arr[::-1] == sorted_arr:
        print(arr[0])
    else:
        mx = (arr[0] + arr[1]) // 2
        for i in range(n - 1):
            if abs(arr[i] - mx) > abs(arr[i + 1] - mx):
                print(-1)
                return
        print(mx)


if __name__ == '__main__':
    # for _ in range(int(input())):
    #     solve()
    a = [5, 500, 10]
    for i in range(1000):
        tmp = [abs(x - i) for x in a]
        if tmp == sorted(tmp):
            print(i)
            break
