//
// Created by nampc on 10/25/2023.
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
	int n;
	cin >> n;
	vll a(n);
	FOR(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());
	ll base_high = 1;
	while (pow(base_high, n - 1) <= a[n - 1])
		base_high++;
	ll base_low = base_high - 1;
	ll res_low = base_low == 0 ? LLONG_MAX : 0, res_high = 0;
	if (n > 63)
	{
		base_high = 1;
		res_low = LLONG_MAX;
	}
	FOR(i, 0, n)
	{
		if (base_high == 1)
			res_high += a[i] - 1;
		else
		{
			res_high += abs(pow(base_high, i) - a[i]);
			if (base_low > 0)
				res_low += abs(pow(base_low, i) - a[i]);
		}
	}
	cout << min(res_low, res_high) << endl;
	return EXIT_SUCCESS;
}
