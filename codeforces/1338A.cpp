#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORDN(i, b, a) for (int i = b; i >= a; i--)

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int mx = -2e9;
		int val = 0;
		FOR(i, 0, n)
		{
			int a;
			cin >> a;
			mx = max(mx, a);
			val = max(val, mx - a);
		}
		ll res = 0;
		while ((1LL << res) - 1 < val)
		{
			res++;
		}
		cout << res << endl;
	}
	return 0;
}
