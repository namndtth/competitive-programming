//
// Created by NAMND on 4/1/2023.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		if (n == 1)
			cout << 0 << endl;
		else
		{
			cout << n - 1 << endl;
			if (((a[0] + a[n - 1]) % 2) == 0)
				a[0] = a[n - 1];
			else
				a[n - 1] = a[0];
			cout << 1 << " " << n << endl;

			for (int i = 1; i < n - 1; i++)
			{
				if (((a[i] + a[0]) % 2) == 0)
					cout << i + 1 << " " << n << endl;
				else
					cout << 1 << " " << i + 1 << endl;
			}
		}
	}
	return EXIT_SUCCESS;
}