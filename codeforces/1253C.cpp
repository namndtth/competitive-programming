//
// Created by nampc on 11/19/2023.
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORRN(i, b, a) for (int i = b; i >= a; i--)

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vii = vector<pair<int, int>>;

int main()
{
	ll n, m;
	cin >> n >> m;
	vll a(n);
	FOR(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());
	vll s(n + 1, 0);
	FOR(i, 0, n) s[i + 1] = s[i] + a[i];

	vll ans(n + 1, 0);
	FORN(i, 1, n)
	{
		ans[i] = s[i];
		if (i > m)
			ans[i] += ans[i - m];
		cout << ans[i] << " ";
	}
	return EXIT_SUCCESS;
}
