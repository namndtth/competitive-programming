#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 200010;

vector<int> distances;
vector<int> adj[MAXN];

int go(int u, int p, int depth)
{
    int children = 0;
    for (auto v: adj[u])
    {
        if (v == p)
            continue;
        children += 1 + go(v, u, depth + 1);
    }
    if (p != -1)
        distances.push_back(depth - children);
    return children;
}

void run()
{
    int i, n, k;
    cin >> n >> k;
    for (i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    go(0, -1, 0);

    sort(distances.rbegin(), distances.rend());

    ll ret = 0;
    for (i = 0; i < min(k, (int)distances.size()); i++)
    {
        ret += distances[i];
    }
    cout << ret << endl;
}

int main()
{
    freopen("data.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    run();
}
