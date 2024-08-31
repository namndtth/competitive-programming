//
// Created by nampc on 9/23/2023.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> ans(100);
		if (k <= n / 2)
		{
			for (int i = 0; i < 2 * k; i += 2)
				ans[i] = 1;
			for (int i = 0; i < n; i++)
				if (!ans[i])
					ans[i] = -1000;
		}
		else
		{
			int j = 0;
			while (j * j + j <= 2 * k)
				j++;
			j--;
			for (int i = 0; i < j; i++)
				ans[i] = 1;
			int r = 2 * k - (j * j + j);
			while (r > 0)
			{
				ans[j + 1] = 1;
				r--;
				j += 2;
			}
			for (int i = 0; i < n; i++)
				if (!ans[i])
					ans[i] = -1000;
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << (i == n - 1 ? "\n" : " ");
	}
	return EXIT_SUCCESS;
}
