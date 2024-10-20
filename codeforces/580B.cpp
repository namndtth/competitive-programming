//
// Created by nampc on 10/28/2023.
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
using vll = vector<ll>;
using vii = vector<pair<int, int>>;

int main()
{
	int n, d;
	cin >> n >> d;

	vii f;
	FOR(i, 0, n)
	{
		int m, s;
		cin >> m >> s;
		f.emplace_back(m, s);
	}

	sort(f.begin(), f.end());

	vll sm, sf;sm.push_back(0), sf.push_back(0);
	for (auto& [m, s]: f)
	{
		sm.push_back(m);
		sf.push_back(s + sf.back());
	}

	ll ans = INT_MIN;
	FORN(i, 1, n)
	{
		auto it = lower_bound(sm.begin(), sm.end(), sm[i] + d);
		int pos = distance(sm.begin(), it);
		if (sm[pos - 1] > sm[i] + d) continue;
		ans = max(ans, sf[pos - 1] - sf[i - 1]);
	}
	cout << ans << endl;

	return EXIT_SUCCESS;
}
