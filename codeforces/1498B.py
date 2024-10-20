from math import log2


def all_zeros(counts: list[int]):
    result = 0
    for c in counts:
        result += c

    return result == 0


def solve():
    n, W = map(int, input().split())
    widths = [int(w) for w in input().split()]

    counts: list[int] = [0 for _ in range(20)]
    for w in widths:
        counts[int(log2(w))] += 1

    space = W
    height = 1

    while not all_zeros(counts):
        largest = -1

        for size, count in list(enumerate(counts))[::-1]:
            if count > 0 and (1 << size) <= space:
                largest = (1 << size)
                space -= largest
                counts[size] -= 1
                break

        if largest == -1:
            height += 1
            space = W

    print(height)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
