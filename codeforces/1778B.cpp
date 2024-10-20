//
// Created by NAMND on 3/24/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, d;
		cin >> n >> m >> d;
		map<int, int> value_idx;
		int value;
		for (int i = 0; i < n; ++i)
		{
			cin >> value;
			value_idx[value] = i + 1;
		}
		vector<int> a;
		for (int i = 0; i < m; ++i)
		{
			cin >> value;
			a.push_back(value_idx[value]);
		}
		int ans = INT_MAX;
		for (int i = 0; i < m - 1; i++)
		{
			if (a[i] >= a[i + 1] || a[i + 1] > a[i] + d)
				ans = 0;
			else
			{
				int dist = abs(a[i + 1] - a[i]);
				ans = min(ans, dist);
				int needed = d - (a[i + 1] - a[i]) + 1;
				if (n - a[i + 1] + a[i] - 1 >= needed)
					ans = min(ans, needed);
			}
		}
		cout << ans << endl;
	}
	return EXIT_SUCCESS;
}