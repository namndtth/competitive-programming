//
// Created by nam on 19/05/2023.
//
#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> adj_list;
vector<int> dp;
vector<int> cats;
vector<bool> is_visited;
int ans = 0;
int n, m;

void dfs(int u)
{
    is_visited[u] = true;
    if (dp[u] > m)
        return;
    int cnt = 0;
    for (auto& v: adj_list[u])
    {
        if (is_visited[v]) continue;
        dp[v] = dp[u] + 1;
        if (cats[v] == 0) dp[v] = 0;
        dfs(v);
        cnt++;
    }
    if (cnt == 0) ans++;
}

void solve()
{
    cin >> n >> m;

    dp.resize(n);
    cats.resize(n);
    is_visited.resize(n);

    for (auto& cat: cats)
        cin >> cat;
    fill(dp.begin(), dp.end(), 0);
    fill(is_visited.begin(), is_visited.end(), false);

    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        x--, y--;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    dp[0] = (cats[0] == 0 ? 0 : 1);
    dfs(0);
    cout << ans << endl;
}

int main()
{
//    solve();
    return EXIT_SUCCESS;
}