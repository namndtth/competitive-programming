//
// Created by nampc on 10/29/2023.
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
	int n, m;
	cin >> n >> m;
	vll a(n), b(m);
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, m) cin >> b[i];

	ll lo, hi;
	ll ans = INT_MIN;
	FOR(i, 0, n)
	{
		auto it = lower_bound(b.begin(), b.end(), a[i]);
		if (it == b.begin()) {
			hi = *it;
			ans = max(ans, hi - a[i]);
		} else if (it == b.end()) {
			lo = *(it - 1);
			ans = max(ans, a[i] - lo);
		} else {
			hi = *it;
			lo = *(it - 1);
			ans = max(ans, min(hi - a[i], a[i] - lo));
		}
	}
	cout << ans << endl;
	return EXIT_SUCCESS;
}
