//
// Created by nampc on 9/23/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		vector<int> dp(n + 1, 0), f(n + 1, INT_MAX);
		for (int i = 1; i <= n; i++)
		{
			dp[i] = min(dp[i - 1] + 1, f[a[i]]);
			f[a[i]] = min(f[a[i]], dp[i - 1]);
		}
		cout << n - dp[n] << std::endl;
	}
	return EXIT_SUCCESS;
}
