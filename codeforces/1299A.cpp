//
// Created by nampc on 11/20/2023.
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
	int n;
	cin >> n;
	vi a(n);
	FOR(i, 0, n) cin >> a[i];
	vi pre(n + 1, INT_MAX), suf(n + 1, INT_MAX);
	FOR(i, 0, n) pre[i + 1] = pre[i] & (~a[i]);
	FORR(i, n, 0) suf[i] = suf[i + 1] & (~a[i]);

	int ans = -1, pos = 0;
	FOR(i, 0, n)
	{
		if ((a[i] & pre[i] & suf[i + 1]) > ans)
		{
			ans = a[i] & pre[i] & suf[i + 1];
			pos = i;
		}
	}
	swap(a[0], a[pos]);
	FOR(i, 0, n) cout << a[i] << " ";
	return EXIT_SUCCESS;
}
