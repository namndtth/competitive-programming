//
// Created by nampc on 11/5/2023.
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
	ll n;
	cin >> n;

	ll low = pow(n, 1.0 / 10);
	ll high = low + 1;

	ll ans = 0;
	ll mn = LLONG_MAX;
	FOR(i, 0, 10)
	{
		ll res = 1;
		FORN(j, 0, 10) if (j <= i) res *= high; else res *= low;
		if (res >= n && res < mn) mn = res, ans = i;
	}

	const string st = "codeforces";

	if (n == 1)
		cout << st << endl;
	else
	{
		FOR(i, 0, 10)
		{
			if (i < ans) FOR(j, 0, high) cout << st[i];
			else
				FOR(j, 0, low) cout << st[i];
		}
	}
	return EXIT_SUCCESS;
}
