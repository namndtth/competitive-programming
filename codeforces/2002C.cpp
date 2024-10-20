#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

ll distance(const pll& s, const pll& g)
{
	ll x = s.first - g.first;
	ll y = s.second - g.second;
	return x * x + y * y;
}

void solve()
{
	int n;
	cin >> n;

	vector<pll> coords(n);
	for (auto& p : coords)
		cin >> p.first >> p.second;

	pll start, goal;
	cin >> start.first >> start.second >> goal.first >> goal.second;

	ll sg_distance = distance(start, goal);

	for (const auto& p : coords)
	{
		if (distance(p, goal) <= sg_distance)
		{
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
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
