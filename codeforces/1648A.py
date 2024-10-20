from collections import defaultdict


def solve():
    n, m = map(int, input().split())
    grid = [[int(x) for x in input().split()] for _ in range(n)]

    colors = defaultdict(list)

    for i, row in enumerate(grid):
        for j, color in enumerate(row):
            colors[color].append((i, j))

    ans = 0
    for cells in colors.values():
        sorted_rows = sorted(cells, key=lambda x: x[0])

        k = len(sorted_rows)
        for i in range(k):
            ans += (2 * i + 1 - k) * sorted_rows[i][0]

        sorted_cols = sorted(cells, key=lambda x: x[1])
        k = len(sorted_cols)
        for i in range(k):
            ans += (2 * i + 1 - k) * sorted_cols[i][1]

    print(ans)


if __name__ == '__main__':
    solve()
