#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)

const int maxn = 1e5 + 5;
typedef vector<int> vi;

vi f(maxn);

int root(int v)
{
    return f[v] == v ? v : root(f[v]);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q, x, y, t;
    cin >> n >> q;
    FOR(i, 1, n)
        f[i] = i;
    FOR(i, 1, q)
    {
        cin >> x >> y;
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (f[x] < f[y])
                swap(x, y);
            f[y] = x;
        }
    }
    FOR(i, 1, n)
        cout << root(i) << " ";
    return 0;
}
