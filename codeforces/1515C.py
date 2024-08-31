from queue import PriorityQueue


def solve():
    n, m, x = map(int, input().split())
    arr = [int(x) for x in input().split()]

    pq = PriorityQueue()
    for i in range(m):
        pq.put((0, i + 1))

    print('YES')
    for x in arr:
        h, i = pq.get()
        pq.put((h + x, i))
        print(i, end=' ' if x != arr else '\n')


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
