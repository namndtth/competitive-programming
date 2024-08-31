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

    def get_num_cc(self):
        cc = set()
        for i in range(1, len(self.par)):
            cc.add(self.get_root(i))

        return len(cc)


def solve():
    n, m = map(int, input().split())

    dsu = DSU(n)
    languages = []
    has_learned_language = 0
    for i in range(n):
        k, *a = [int(x) for x in input().split()]
        has_learned_language += k
        languages.append(a)

    for i in range(n):
        for j in range(i + 1, n):
            for lang in languages[j]:
                if lang in languages[i]:
                    dsu.merge(i + 1, j + 1)

    print(n if has_learned_language == 0 else dsu.get_num_cc() - 1)


if __name__ == '__main__':
    solve()
