//
// Created by nampc on 9/10/2023.
//
#include <bits/stdc++.h>

using namespace std;

struct dsu
{
	explicit dsu(int n)
	{
		root.assign(n, -1);
	}

	vector<int> root;

	int find(int v)
	{
		return (root[v] < 0 ? v : (root[v] = find(root[v])));
	}

	void merge(int u, int v)
	{
		if ((u = find(u)) == (v = find(v)))
			return;

		if (root[u] > root[v])
		{
			swap(u, v);
		}

		root[u] += root[v];
		root[v] = u;
	}
};

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		c[i]--;
	}

	dsu dsu(n);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		u--, v--;
		dsu.merge(u, v);
	}

	vector<vector<int>> css(n);

	for (int i = 0; i < n; i++)
		css[dsu.find(i)].push_back(i);

	map<int, int> cnt;
	int ans = 0;
	for (auto& cc : css)
	{
		if (!cc.empty())
		{
			cnt.clear();
			int mx = INT_MIN;
			int tot = (int)cc.size();
			for (auto i : cc)
			{
				cnt[c[i]]++;
				mx = max(mx, cnt[c[i]]);
			}
			ans += tot - mx;
		}
	}

	cout << ans << endl;

	return EXIT_SUCCESS;
}
