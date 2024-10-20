def get_primes():
    primes = []

    n = 32
    is_primes = [True] * n
    is_primes[0] = False
    is_primes[1] = False
    for i in range(2, n):
        for j in range(i * 2, n, i):
            is_primes[j] = False

    for i, x in enumerate(is_primes):
        if x:
            primes.append(i)

    return primes


def solve():
    n = int(input())
    a = list(map(int, input().split()))

    primes = get_primes()

    groups = [[] for _ in range(12)]
    m = set()
    for i, x in enumerate(a):
        for j, y in enumerate(primes):
            if x % y == 0:
                m.add(y)
                groups[j].append(i)
                break

    c = 1
    ans = [0] * n
    for x in groups:
        if not x:
            continue

        for y in x:
            ans[y] = c
        c += 1

    print(len(m))
    print(' '.join(map(str, ans)))


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
