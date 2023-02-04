#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> adj[N];
vector<int> par;
vector<int> num_children;

int ans;
int dfs(int u)
{
    for (int i = 0; i < (int)adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == par[u])
            continue;

        par[v] = u;
        num_children[u] += 1 + dfs(v);
    }
    return num_children[u];
}

int main()
{
    freopen("data.inp", "r", stdin);

    int n; cin >> n;

    int u, v;

    ans = 0;

    par.assign(n, -1);
    num_children.assign(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n % 2 != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    dfs(0);
    int ans = -1;
    for (int i = 0; i < (int)num_children.size(); i++)
        if (num_children[i] % 2 != 0)
            ans++;
    cout << ans << endl;
    return 0;
}
