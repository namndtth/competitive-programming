//
// Created by nampc on 10/15/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<long long> h(n), sum(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
		sum[i + 1] = sum[i] + h[i];
	}
	long long mn = LLONG_MAX;
	int ans = -1;
	for (int i = k; i <= n; i++)
	{
		if (mn > sum[i] - sum[i - k])
		{
			ans = i - k + 1;
			mn = sum[i] - sum[i - k];
		}
	}

	cout << ans << endl;
	return 0;
}
