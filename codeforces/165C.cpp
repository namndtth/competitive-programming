//
// Created by nampc on 10/14/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	cin >> k;
	string st;
	cin >> st;
	int n = st.size();
	vector<int> sum(n + 1, 0);
	vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + st[i - 1] - '0';
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (sum[i] - k >= 0)
			ans += cnt[sum[i] - k];
		cnt[sum[i]]++;
	}
	cout << ans << endl;
	return EXIT_SUCCESS;
}
