//
// Created by nampc on 12/12/2023.
//
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORRN(i, b, a) for (int i = b; i >= a; i--)
#define F first
#define S second
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vii = vector<pair<int, int>>;

ll read()
{
	ll x;
	cin >> x;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = read();
	while (tc--)
	{
		int n = read();

		vll a(n), b(n);
		FOR(i, 0, n) a[i] = read(), b[i] = read();

		a.push_back(a[0]), b.push_back(b[0]);

		ll mn = LLONG_MAX, mnp = -1;
		FOR(i, 0, n)
		{
			if (mn > a[i + 1] - max(0ll, a[i + 1] - b[i]))
			{
				mn = a[i + 1] - max(0ll, a[i + 1] - b[i]);
				mnp = i;
			}
		}

		ll ans = a[mnp + 1];
		FOR(p, mnp + 1, n)
			ans += max(0ll, a[p + 1] - b[p]);
		FOR(p, 0, mnp)
			ans += max(0ll, a[p + 1] - b[p]);

		cout << ans << endl;
	}
	return 0;
}
