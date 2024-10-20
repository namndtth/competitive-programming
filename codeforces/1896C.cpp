//
// Created by nampc on 11/30/2023.
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
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, x;
		cin >> n >> x;
		vii a(n), b(n);
		FOR(i, 0, n)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		FOR(i, 0, n)
		{
			cin >> b[i].first;
			b[i].second = i;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		bool ok = true;
		vi ans(2 * n + 1);
		FOR(i, n - x, n)
		{
			if (a[i].first > b[i - n + x].first) ans[a[i].second] = b[i - n + x].first;
			else
			{
				ok = false;
				break;
			}

		}
		if (ok)
		{
			FOR(i, 0, n - x)
			{
				if (a[i].first <= b[i + x].first) ans[a[i].second] = b[i + x].first;
				else
				{
					ok = false;
					break;
				}
			}
		}
		if (!ok) cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			FOR(i, 0, n) cout << ans[i] << ' ';
			cout << endl;
		}
	}
	return EXIT_SUCCESS;
}
