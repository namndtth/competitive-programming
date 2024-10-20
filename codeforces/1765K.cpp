//
// Created by nampc on 10/22/2023.
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORDN(i, b, a) for (int i = b; i >= a; i--)

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;

vvi grid, visited;

void bfs(int u, int v)
{
	if (visited[u][v])
		return;

	visited[u][v] = 1;

	if (v == n)
	{
		fs
	}
}

int main()
{
	int n;
	cin >> n;
	grid.resize(n, vi(n));
	visited.resize(n, vi(n, 0));

	FOR(i, 0, n) FOR(j, 0, n) cin >> grid[i][j];

}
