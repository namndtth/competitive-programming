//
// Created by nampc on 9/23/2023.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll> h, v, diag1, diag2;
ll n, x, y;

int main()
{
	ll tc; cin >> tc;
	while (tc--)
	{
		h.clear(), v.clear(), diag1.clear(), diag2.clear();
		cin >> n;
		for (ll i = 0; i < n; i++)
		{
			cin >> x >> y;
			v[x]++;
			h[y]++;
			diag1[x - y]++;
			diag2[x + y]++;
		}
		long long ans = 0;
		for (const auto& item : h)
			ans += item.second * (item.second - 1);
		for (const auto& item : v)
			ans += item.second * (item.second - 1);
		for (const auto& item : diag1)
			ans += item.second * (item.second - 1);
		for (const auto& item : diag2)
			ans += item.second * (item.second - 1);
		cout << ans << endl;
	}
	return EXIT_SUCCESS;
}
