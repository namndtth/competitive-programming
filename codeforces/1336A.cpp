//
// Created by nampc on 12/9/2023.
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORRN(i, b, a) for (int i = b; i >= a; i--)

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vii = vector<pair<int, int>>;

void dfs(const vvi& adj, vi& depth, vi& num_children, int u, int p)
{
	num_children[u] = 1;
	for (auto v : adj[u])
	{
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		dfs(adj, depth, num_children, v, u);
		num_children[u] += num_children[v];
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	vvi adj(n);
	vi depth(n, 1), num_children(n, 0), det(n, 0);

	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(adj, depth, num_children, 0, -1);

	FOR(i, 0, n) det[i] = depth[i] - num_children[i];
	sort(det.begin(), det.end(), greater<>());
	cout << accumulate(det.begin(), det.begin() + k, 0ll) << endl;

	return EXIT_SUCCESS;
}
