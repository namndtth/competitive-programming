//
// Created by NAMND on 3/8/2023.
//
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k, x;
	cin >> n >> k;
	map<int, int> f;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		f[x]++;
	}
	int total_elements{};
	int ans = 0;
	for (auto e: f)
	{
		total_elements += e.second;
		if (total_elements >= k)
		{
			ans = e.first;
			break;
		}
	}
	if (k == 0 && ans > 1)
		cout << 1 << endl;
	else if (total_elements == k)
		cout << ans << endl;
	else cout << -1 << endl;
}

int main()
{
	solve();
	return EXIT_SUCCESS;
}