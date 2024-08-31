//
// Created by nampc on 9/22/2023.
//
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vector<long long> dp;
vector<vi> e;
int n, k, m, x;
vector<bool> used;
long long dfs(int v)
{
	if (used[v])
		return dp[v];

	used[v] = true;

	long long sum = 0;
	for (int u: e[v])
		sum += dfs(u);

	if (!e[v].empty())
		dp[v] = min(dp[v], sum);

	return dp[v];
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> k;
		dp.resize(n);
		used.assign(n, false);
		for (int i = 0; i < n; i++)
			cin >> dp[i];

		for (int i = 0; i < k; i++)
		{
			cin >> x;
			dp[--x] = 0;
		}

		e.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> m;
			e[i].resize(m);
			for (int j = 0; j < m; j++)
			{
				cin >> e[i][j];
				e[i][j]--;
			}
		}

		for (int i = 0; i < n; i++)
			dfs(i);
		for (int i = 0; i < n; i++)
			cout << dp[i] << (i == n - 1 ? "\n" : " ");
	}
	return EXIT_SUCCESS;
}
