class DSU:
    def __init__(self, n):
        self.par = [-1] * (n + 1)

    def merge(self, x, y):
        x = self.get_root(x)
        y = self.get_root(y)

        if x == y:
            return

        # number of ele in x smaller than in y
        if self.par[x] > self.par[y]:
            x, y = y, x

        self.par[x] += self.par[y]
        self.par[y] = x

    def get_root(self, v):
        if self.par[v] < 0:
            return v
        self.par[v] = self.get_root(self.par[v])
        return self.par[v]

    def get_num_members(self, v):
        v = self.get_root(v)
        return -self.par[v]


def solve():
    n, m = map(int, input().split())

    dsu = DSU(n)

    for i in range(m):
        k, *a = [int(x) for x in input().split()]
        for j in range(k - 1):
            dsu.merge(a[j], a[j + 1])

    ans = ''
    for i in range(n):
        ans += str(dsu.get_num_members(i + 1)) + ' '

    print(ans)


if __name__ == '__main__':
    solve()
