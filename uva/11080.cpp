#include <bits/stdc++.h>
using namespace std;

#define oo 1000000000
vector<vector<int> > grid;
vector<int> color;
int ans;
int checkBipartite(int src)
{
    int total_node = 1;
    int num_guard = 0;
    queue<int> q;
    q.push(src);
    color[src] = 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (int i = 0; i < (int)grid[u].size(); i++)
        {
            int v = grid[u][i];
            if (color[v] == oo)
            {
                total_node++;
                color[v] = 1 - color[u];
                q.push(v);
                if (color[v] == 1)
                    num_guard++;
            }
            else if (color[v] == color[u])
                return -1;
        }
    }
    return min(num_guard, total_node - num_guard);
}

int main()
{
//    freopen("data.inp", "r", stdin);
//    freopen("data.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int v, e, x, y, num_guard = 0;
        cin >> v >> e;

        ans = 0;
        grid.clear();
        grid.resize(v);
        color.assign(v, oo);

        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            grid[x].push_back(y);
            grid[y].push_back(x);
        }

        for (int i = 0; i < v; i++)
        {
            if (color[i] == oo)
            {
                if ((int)grid[i].size() == 0)
                {
                    ans++;
                    color[i] = 0;
                    continue;
                }
                num_guard = checkBipartite(i);
                if (num_guard == -1)
                    break;
                else
                    ans += num_guard;
            }
        }
        if (num_guard == -1)
        {
            cout << -1 << endl;
            continue;
        }
        else
            cout << ans << endl;
    }
}
