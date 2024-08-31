//
// Created by nampc on 9/17/2023.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll tc;
	cin >> tc;
	ll n;
	vector<ll> c;
	while (tc--)
	{
		cin >> n;
		c.clear();
		c.resize(n);
		for (ll i = 0; i < n; i++)
			cin >> c[i];
		vector<ll> mn(2, LLONG_MAX);
		vector<ll> cnt(2, 0);
		ll sum = 0;
		ll ans = LLONG_MAX;
		for (ll i = 0; i < n; i++)
		{
			mn[i % 2] = min(mn[i % 2], c[i]);
			cnt[i % 2]++;
			sum += c[i];
			if (i > 0)
				ans = min(ans, sum + mn[0] * (n - cnt[0]) + mn[1] * (n - cnt[1]));
		}
		cout << ans << endl;
	}
	return EXIT_SUCCESS;
}
