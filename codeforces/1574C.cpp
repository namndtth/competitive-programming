#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve()
{
	int n;
	cin >> n;

	ll sum{ 0 };
	vector<ll> a(n);
	for (auto& x : a)
	{
		cin >> x;
		sum += x;
	}

	sort(a.begin(), a.end());

	int m;
	cin >> m;

	while (m--)
	{
		ll x, y;
		cin >> x >> y;

		int i = lower_bound(a.begin(), a.end(), x) - a.begin();
		ll ans = 2e18;
		if (i > 0) ans = min(ans, x - a[i - 1] + max(0LL, y - (sum - a[i - 1])));
		if (i < n) ans = min(ans, max(0LL, y - (sum - a[i])));
		cout << ans << endl;
	}
}

int main()
{
	solve();

	return EXIT_SUCCESS;
}
