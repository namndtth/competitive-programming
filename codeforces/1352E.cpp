//
// Created by nampc on 9/26/2023.
//
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), s(n + 1, 0);
	map<int, int> f;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0, cnt = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			cnt++;
			if (sum > n)
				break;
			if (cnt >= 2)
				s[sum] = 1;
		}
	}

	int ans = 0;
	for (const auto& [fi, se] : f)
	{
		if (s[fi])
			ans += se;
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
//	tc = 1;
	while (tc--)
		solve();
	return EXIT_SUCCESS;
}
