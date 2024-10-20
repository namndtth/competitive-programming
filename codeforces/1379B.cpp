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

void solve(ll l, ll r, ll m)
{
	ll range = r - l, a = 0, b = 0, c = 0;
	FORN(i, l, r)
	{
		ll n = (m + range) / i;
		if (n > 0 && m - range <= i * n && i * n <= m + range)
		{
			ll x = m - i * n;
			if (x > 0) a = i, c = l, b = l + x;
			else a = i, b = l, c = l - x;
			break;
		}
	}
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		ll l, r, m;
		cin >> l >> r >> m;
		solve(l, r, m);
	}
	return EXIT_SUCCESS;
}
