//
// Created by nampc on 10/14/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), d(n);
	int ans = d[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i > 0)
		{
			d[i] = (a[i] >= a[i - 1]) ? (d[i - 1] + 1) : 1;
			ans = max(ans, d[i]);
		}
	}
	cout << ans << endl;
	return EXIT_SUCCESS;
}
