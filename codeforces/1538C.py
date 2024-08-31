def solve():
    n, l, r = map(int, input().split())
    a = [int(x) for x in input().split()]


def lower_bound(a: list[int], x: int) -> int:
    low, high = 0, len(a)
    while low < high:
        mid = (low + high) // 2
        if a[mid] > x:
            high = mid
        elif a[mid] < x:
            return 0

