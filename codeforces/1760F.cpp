//
// Created by nampc on 11/9/2023.
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

bool can(const vll& a, vll& s, ll c, ll d, ll k)
{

}

int main()
{
	ll n, c, d;
	cin >> n >> c >> d;
	vll a(n), s(n);
	FOR(i, 0, n) cin >> a[i];

	s[0] = 0;
	FOR(i, 1, n) s[i] = s[i - 1] + a[i];

	ll l = 0, r = LLONG_MAX;
	while (l < r)
	{
		int m = l + (r - l) / 2;
		if (can(a, s, c, d, m))
			l = m + 1;
		else
			r = m - 1;
	}
	if (l == 0) cout << "Impossible" << endl;
	else if (l == LLONG_MAX) cout << "Infinity" << endl;
	else cout << l << endl;
}
