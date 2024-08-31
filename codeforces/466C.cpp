//
// Created by nam on 12/10/2023.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n), sum(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	if (sum[n] % 3 != 0)
	{
		cout << 0 << endl;
		return EXIT_SUCCESS;
	}

	ll sumEachPart = sum[n] / 3;
	set<ll> fi, se;
	for (int i = 1; i < n; i++)
	{
		if (sum[i] == sumEachPart)
			fi.insert(i);
		if (sum[i] == 2 * sumEachPart)
			se.insert(i);
	}
	ll ans = 0, res = 0;
	for (auto it = fi.rbegin(); it != fi.rend(); it++)
	{
		auto pos = se.upper_bound(*it);
		res += distance(pos, se.end());
		ans += res;
		se.erase(pos, se.end());
	}
	cout << ans << endl;
	return EXIT_SUCCESS;
}
