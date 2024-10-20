import math


def solve():
    W, H = map(int, input().split())
    x1, y1, x2, y2 = map(int, input().split())
    w1, h1 = x2 - x1, y2 - y1
    w2, h2 = map(int, input().split())

    ans = math.inf
    if w1 + w2 <= W:
        if x1 >= w2 or W - x2 >= w2:
            ans = 0
        else:
            ans = min(ans, w2 - x1, w2 - (W - x2))

    if h1 + h2 <= H:
        if y1 >= h2 or H - y2 >= h2:
            ans = 0
        else:
            ans = min(ans, h2 - y1, h2 - (H - y2))

    return ans if ans != math.inf else -1


if __name__ == '__main__':
    for _ in range(int(input())):
        print(solve())
