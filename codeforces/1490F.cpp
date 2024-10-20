//
// Created by nampc on 10/26/2023.
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

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;

		map<ll, ll> mp;
		ll x;
		FOR(i, 0, n)
		{
			cin >> x;
			mp[x]++;
		}
		vll cnt;
		for (auto& it : mp)
			cnt.push_back(it.second);

		sort(cnt.begin(), cnt.end());

		ll sz = cnt.size();
		vll sum(sz + 1, 0);
		FORN(i, 1, sz) sum[i] = sum[i - 1] + cnt[i - 1];

		ll ans = INT_MAX, res;
		FORN(i, 1, sz)
		{
			res = sum[i - 1] + (sum[sz] - sum[i]) - (sz - i) * cnt[i - 1];
			ans = min(ans, res);
		}
		cout << ans << endl;
	}
	return EXIT_SUCCESS;
}
