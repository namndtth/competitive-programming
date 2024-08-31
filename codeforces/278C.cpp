#include <bits/stdc++.h>
#define MAXN 101
using namespace std;

using vi = vector<int>;

struct dsu
{
	explicit dsu(int n)
	{
		par.resize(n + 1);
		for (int i = 0; i <= n; i++)
			par[i] = -1;
	}

	vector<int> par;

	int find(int u)
	{
		return par[u] < 0 ? u : (par[u] = find(par[u]));
	}

	void merge(int u, int v)
	{
		u = find(u), v = find(v);
		if (u == v)
			return;

		if (par[v] < par[u]) swap(u, v);
		par[u] += par[v];
		par[v] = u;
	}
};
int main()
{
	vector<vi> employees(MAXN);
	vector<vi> languages(MAXN);
	int n, m, k, l, tot = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		tot += k;
		for (int j = 0; j < k; j++)
		{
			cin >> l;
			languages[l].push_back(i);
			employees[i].push_back(l);
		}
	}
	if (tot == 0)
	{
		cout << n << endl;
		return 0;
	}
	dsu dsu(n);
	for (int i = 1; i <= m; i++)
	{
		if (languages[i].empty())
			continue;
		for (auto e : languages[i])
		{
			dsu.merge(e, languages[i][0]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dsu.find(i) == i)
			ans++;
	}
	cout << ans - 1 << endl;
	return EXIT_SUCCESS;
}
