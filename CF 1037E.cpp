#include <iostream>
#include <set>
using namespace std;

const int maxn = 2e5 + 9;
int ans[maxn];
set<int> s;
set<int> w[maxn];
pair<int, int> e[maxn];
int n, m, k;
void erase(int u)//delete u & its neighbor in set and w
{
	if (w[u].size() < k && s.find(u) != s.end())//if u's number of neighbors < k && existing in s then delete it
	{
		s.erase(u);
		for (auto v : w[u])//every neighbor in u -> erase u from v
		{
			w[v].erase(u);
			erase(v);//call recursive with neighbor of u
		}
	}
}
int main()
{
	int u, v, i, j;
	cin >> n >> m >> k;
	i = m;
	for (i = 1; i <= m; i++)
	{
		cin >> u >> v;
		w[u].insert(v);
		w[v].insert(u);
		e[i] = { u,v };
	}
	for (i = 1; i <= n; i++)
		s.insert(i);
	for (i = 1; i <= n; i++)//iterate s & delete all of vertex that have number of neighbors < k
		erase(i);
	for (i = m; i >= 1; i--)
	{
		ans[i] = s.size();//the answer = total element in set that satify the request
		u = e[i].first, v = e[i].second;
		w[u].erase(v);
		w[v].erase(u);
		erase(u);
		erase(v);
	}
	for (i = 1; i <= m; i++)
		cout << ans[i] << "\n";
	return 0;
}
