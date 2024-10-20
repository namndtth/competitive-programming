#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b - 1; i >= a; i--)
#define FORDN(i, b, a) for (int i = b; i >= a; i--)

int main()
{
	int n;
	cin >> n;
	vector<long long> a(n + 2, 0), inc(n + 2, 0), desc(n + 2, 0);


	FORN(i, 1, n) cin >> a[i]; a[n + 1] = LLONG_MAX;

	FORN(i, 1, n) inc[i] = a[i] > a[i - 1] ? inc[i - 1] + 1 : 1;
	FORDN(i, n, 1) desc[i] = a[i] < a[i + 1] ? desc[i + 1] + 1 : 1;

	long long ans = INT_MIN;
	FORN(i, 1, n)
	{
		if (a[i - 1] < a[i])
			ans = max(ans, inc[i - 1] + desc[i]);
		if (a[i - 1] < a[i + 1])
			ans = max(ans, inc[i - 1] + desc[i + 1]);
	}
	cout << ans << endl;
	return 0;
}
