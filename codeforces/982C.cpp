#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORDN(i, b, a) for (int i = b; i >= a; i--)

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;

vvi adj;
vi num_children;
vi used;

int dfs(int u)
{
	if (used[u])
		return 0;

	used[u] = 1;
	FOR(i, 0, adj[u].size())
	{
		int v = adj[u][i];
		if (u == v)
			continue;
		num_children[u] += dfs(v);
	}
	return ++num_children[u];
}

int main()
{
	int n;
	cin >> n;

	adj.resize(n);
	num_children.assign(n, 0);
	used.assign(n, 0);

	int u, v;
	FOR(i, 0, n - 1)
	{
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (n % 2 == 0)
	{
		dfs(0);

		int num_ccs = 0;
		FOR(i, 1, n)
		{
			if (num_children[i] % 2 == 0)
				num_ccs++;
		}
		cout << num_ccs << endl;
	}
	else {
		cout << "-1" << endl;
	}
	return EXIT_SUCCESS;
}
