#include <bits/stdc++.h>
using namespace std;
#define EXPLORED 2
#define VISITED 1
#define UNVISITED 0
int const MAX = (int)1e6;

vector<int> dfs_num;
vector<int> dfs_parent;
vector<vector<int >> g;

void graph_check(int src)
{
    dfs_num[src] = EXPLORED;
    for (int u = 0; u < (int)g[src].size(); u++)
    {
        int v = g[src][u];
        if (dfs_num[v] == UNVISITED) // explored -> unvisited: tree edge
        {
            dfs_parent[v] = src;
            graph_check(v);
        }
        else if (dfs_num[v] == EXPLORED) // explored -> explored: bi/back edge
        {
            if (v == dfs_parent[src])
                printf(" Two ways (%d, %d)-(%d, %d)\n", src, v, v, src);
            else
                printf(" Back Edge (%d, %d) (Cycle)\n", src, v);
        }
        else if (dfs_num[v] == VISITED) // explored -> visited: forward/cross edge
        {
            printf(" Forward/Cross Edge (%d, %d)\n", src, v);
        }
    }
    dfs_num[src] = VISITED;
}

int main()
{
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    int vertices, edges, u, v;;

    cin >> vertices >> edges;

    g.resize(vertices + 1);
    dfs_num.assign(vertices + 1, UNVISITED);
    dfs_parent.assign(vertices + 1, -1);
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < vertices; i++)
        if (dfs_num[i] == UNVISITED)
        {
            cout << i << endl;
            graph_check(i);
        }
    return 0;
}
