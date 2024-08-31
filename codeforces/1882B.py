from typing import *


def solve():
    n = int(input())

    superset = set()
    sets: List[Set] = []
    for _ in range(n):
        s = {int(x) for x in input().split()[1:]}
        sets.append(s)
        superset |= s

    ans = 0
    for i in superset:
        union_set = set()
        for S in sets:
            if i in S:
                continue
            union_set |= S
        ans = max(ans, len(union_set))

    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
