//
// Created by nampc on 9/4/2023.
//
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> bad;
vector<int> d;

// Calculate number of bad district from 0 to leaf districts.
// If d[u] == 1 then it's the only bad node from it to leaf.
// If d[u] >= 2 then it must include another bad districts after that node.
void traversal(int v, int v_ancestor = -1)
{
	d[v] = bad[v];
	int sz = g[v].size();
	for (int i = 0; i < sz; i++)
	{
		int u = g[v][i];
		if (v_ancestor == u)
			continue;
		traversal(u, v);
		d[v] += d[u];
	}
}

int main()
{
	int n;
	cin >> n;

	g.resize(n);
	bad.resize(n);
	d.resize(n);

	int u, v, t;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v >> t;

		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);

		if (t == 2)
		{
			bad[u] = 1;
			bad[v] = 1;
		}
	}

	traversal(0);

	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		if (bad[i] && d[i] == 1)
			ans.push_back(i + 1);
	}

	cout << ans.size() << endl;

	for (const auto& item : ans)
		cout << item <<  " ";
	return EXIT_SUCCESS;
}
