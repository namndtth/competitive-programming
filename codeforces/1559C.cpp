#include <bits/stdc++.h>

using namespace std;

void dfs(int u, const vector<vector<int>>& grid, vector<bool>& visited, vector<int>& children)
{
	if (all_of(visited.begin(), visited.end(), [](bool x) { return x; }))
	{
		int c = 0;
		cout << c + 1 << " ";
		while (children[c] != -1)
		{
			cout << children[c] + 1 << " ";
			c = children[c];
		}
		cout << endl;
		return;
	}

	for (auto& v : grid[u])
	{
		if (!visited[v])
		{
			visited[v] = true;
			children[u] = v;
			dfs(v, grid, visited, children);
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	vector<vector<int>> grid(n + 1);

	for (int i = 0; i < n - 1; i++)
		grid[i].push_back(i + 1);

	int u;
	for (int i = 0; i < n; i++)
	{
		cin >> u;
		if (!u)
			grid[i].push_back(n);
		else
			grid[n].push_back(i);
	}

	vector<bool> visited(n + 1, false);
	vector<int> children(n + 1, -1);

	visited[0] = true;
	dfs(0, grid, visited, children);

	if (!all_of(visited.begin(), visited.end(), [](bool x) { return x; })) cout << -1 << endl;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		solve();
	}
	return EXIT_SUCCESS;
}
