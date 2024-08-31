//
// Created by nampc on 10/15/2023.
//
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	int n, k, d;
	cin >> n >> k >> d;
	vector<vector<ll>> dp(n, vector<ll>(2, 0));
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i >= d)
		{
			dp[i] += dp[i - d];
		}
	}
}
