#include <bits/stdc++.h>
using namespace std;
#define UNVISITED 0

typedef vector<int> vi;

vi dfs_low, dfs_num, dfs_parent, articulation_vertex;
vector<vector<int>> AdjList;
int dfsNumberCounter, rootChildren, dfsRoot;

void articulationPointAndBridge(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        int v = AdjList[u][j];
        if (dfs_num[v] == UNVISITED)
        {
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = true;

            if (dfs_low[v] > dfs_num[u])
                printf("Edge (%d, %d) is a bridge\n", u, v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main()
{
    int v, e;
    int v >> e;
    dfsNumberCounter = 0;
    dfs_num.assign(v, UNVISITED);
    dfs_low.assign(v, 0);
    dfs_parent.assign(v, 0);
    articulation_vertex.assign(v, 0);
    printf("Bridges:\n");
    for (int i = 0; i < v; i++)
    {
        if (dfs_num[i] == UNVISITED)
        {
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1);
        }
    }
    printf("Articulation Points: \n");
    for (int i = 0; i < v; i++)
        if (articulation_vertex[i])
            printf("Vertex %d\n", i);
    return 0;
}

